/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_32.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:48:35 by eseveno           #+#    #+#             */
/*   Updated: 2016/03/21 15:48:35 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "nm.h"

char		ft_type(uint8_t type, int value)
{
	if (type == 15)
		return ('T');
	if (type == 1 && value == 0)
		return ('U');
	if (type == 14)
		return ('t');
	if (type == 1 && value)
		return ('C');
	else
		return ('O');
}

void		ft_newmaillon32(t_32 **add, uint32_t value, char type, char *name)
{
	(*add) = (t_32 *)malloc(sizeof(t_32));
	(*add)->value = value;
	(*add)->type = type;
	(*add)->name = ft_strdup(name);
	(*add)->next = NULL;
}

void		add_link32(t_32 **list, uint32_t value, char type, char *name)
{
	t_32	*add;
	t_32	*start;

	ft_newmaillon32(&add, value, type, name);
	if (!(*list))
	{
		(*list) = add;
		return ;
	}
	if (ft_addebut32(list, add) == 1)
		return ;
	start = (*list);
	while (((*list)->next) && (ft_strcmp((*list)->next->name, name) < 0))
		(*list) = (*list)->next;
	if (!(*list)->next)
		(*list)->next = add;
	else
		ft_addmid32(list, add);
	(*list) = start;
}

void		print_output_32(int *nsyms, int stroff, t_list *sct, void *ptr)
{
	int				i;
	char			*stringtable;
	struct nlist	*a;
	t_32			*list;

	list = NULL;
	a = ptr + nsyms[2];
	stringtable = ptr + stroff;
	i = -1;
	while (++i < nsyms[1])
		add_link32(&list, a[i].n_value, get_char(a[i].n_type, a[i].n_sect,
		a[i].n_value, sct), stringtable + a[i].n_un.n_strx);
	while (list != NULL)
	{
		if (list->type == 'z')
			i = i + 1 - 1;
		else if (list->value > 0)
			ft_printf("%08llx %c %s\n", list->value, list->type, list->name);
		else if (list->type == 'T')
			ft_printf("%8llx %c %s\n", list->value, list->type, list->name);
		else
			ft_printf("         %c %s\n", list->type, list->name);
		list = list->next;
	}
}

void		handle_32(void *ptr)
{
	int						*i;
	struct mach_header		*header;
	struct load_command		*lc;
	struct symtab_command	*sym;
	t_list					*sct;

	i = (int *)malloc(sizeof(int) * 5);
	i[0] = 0;
	header = (struct mach_header *)ptr;
	i[3] = header->ncmds;
	lc = (void *)ptr + sizeof(*header);
	sct = get_section_32(lc, header);
	while (i[0] < i[3])
	{
		if (lc->cmd == LC_SYMTAB)
		{
			sym = (struct symtab_command *)lc;
			i[1] = sym->nsyms;
			i[2] = sym->symoff;
			print_output_32(i, sym->stroff, sct, ptr);
		}
		lc = (void *)lc + lc->cmdsize;
		i[0]++;
	}
}
