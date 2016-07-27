/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_64.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:48:35 by eseveno           #+#    #+#             */
/*   Updated: 2016/03/21 15:48:35 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "nm.h"

static void		add_section_64(struct load_command *lc, t_list **sct)
{
	unsigned int					i;
	struct section_64				*sec;
	struct segment_command_64		*seg;

	i = 0;
	seg = (struct segment_command_64 *)lc;
	sec = (struct section_64 *)(seg + sizeof(seg) / sizeof(void*));
	while (i < seg->nsects)
	{
		add_sct_elem(sec->sectname, sct);
		sec = (struct section_64 *)(((void*)sec) + sizeof(struct section_64));
		i++;
	}
}

t_list			*get_section_64(struct load_command *lc,
	struct mach_header_64 *h)
{
	unsigned int	i;
	t_list			*sct;

	i = 0;
	sct = NULL;
	while (i < h->ncmds)
	{
		if (lc->cmd == LC_SEGMENT_64)
			add_section_64(lc, &sct);
		lc += lc->cmdsize / sizeof(void *);
		i++;
	}
	return (sct);
}

void			ft_addmid64(t_64 **list, t_64 *add)
{
	t_64	*tmp;

	tmp = (*list)->next;
	(*list)->next = add;
	add->next = tmp;
}

void			print_output_64(int *nsyms, int stroff,
	t_list *sct, void *ptr)
{
	int				i;
	char			*stringtable;
	struct nlist_64	*a;
	t_64			*list;

	list = NULL;
	a = ptr + nsyms[2];
	stringtable = ptr + stroff;
	i = -1;
	while (++i < nsyms[1])
		add_link64(&list, a[i].n_value, get_char(a[i].n_type, a[i].n_sect,
		a[i].n_value, sct), stringtable + a[i].n_un.n_strx);
	while (list != NULL)
	{
		if (list->type == 'z')
			i = i + 1 - 1;
		else if (list->value > 0)
			ft_printf("%016llx %c %s\n", list->value, list->type, list->name);
		else if (list->type == 'T')
			ft_printf("%016llx %c %s\n", list->value, list->type, list->name);
		else
			ft_printf("                 %c %s\n", list->type, list->name);
		list = list->next;
	}
}

void			handle_64(void *ptr)
{
	struct mach_header_64	*header;
	struct load_command		*lc;
	struct symtab_command	*sym;
	int						*i;
	t_list					*sct;

	i = (int *)malloc(sizeof(int) * 5);
	i[0] = 0;
	header = (struct mach_header_64 *)ptr;
	i[3] = header->ncmds;
	lc = (void *)ptr + sizeof(*header);
	sct = get_section_64(lc, header);
	while (i[0] < i[3])
	{
		if (lc->cmd == LC_SYMTAB)
		{
			sym = (struct symtab_command *)lc;
			i[1] = sym->nsyms;
			i[2] = sym->symoff;
			print_output_64(i, sym->stroff, sct, ptr);
		}
		lc = (void *)lc + lc->cmdsize;
		i[0]++;
	}
}
