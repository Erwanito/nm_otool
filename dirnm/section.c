/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   section.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:48:35 by eseveno           #+#    #+#             */
/*   Updated: 2016/03/21 15:48:35 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

void		add_sct_elem(char *name, t_list **sct)
{
	t_list			*new;
	static uint32_t	n = 1;

	if (*sct == NULL)
		n = 1;
	g_s = (t_sct *)malloc(sizeof(t_sct));
	g_s->name = ft_strdup(name);
	g_s->n = n;
	new = ft_lstnew_ptr(g_s, sizeof(t_sct));
	ft_lstadd_end(sct, new);
	n++;
}

static void	add_section(struct load_command *lc, t_list **sct)
{
	unsigned int				i;
	struct section				*sec;
	struct segment_command		*seg;

	i = 0;
	seg = (struct segment_command *)lc;
	sec = (struct section *)(seg + sizeof(seg) / sizeof(void*));
	while (i < seg->nsects)
	{
		add_sct_elem(sec->sectname, sct);
		sec = (struct section *)(((void*)sec) + sizeof(struct section));
		i++;
	}
}

t_list		*get_section_32(struct load_command *lc, struct mach_header *h)
{
	unsigned int	i;
	t_list			*sct;

	i = 0;
	sct = NULL;
	while (i < h->ncmds)
	{
		if (lc->cmd == LC_SEGMENT)
			add_section(lc, &sct);
		lc += lc->cmdsize / sizeof(void *);
		i++;
	}
	return (sct);
}
