/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_ar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:48:35 by eseveno           #+#    #+#             */
/*   Updated: 2016/03/21 15:48:35 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

static void		print_ar(t_list *lst, void *ptr)
{
	char		*name;
	uint32_t	off;
	uint32_t	size;

	while (lst)
	{
		off = ((t_ar *)(lst->content))->off;
		name = ptr + off + sizeof(struct ar_hdr);
		ft_printf("\n%s(%s):\n", g_e.name, name);
		size = ft_atoi(ptr + off + sizeof(AR_EFMT1) - 1);
		ft_nm(ptr + off + sizeof(struct ar_hdr) + size);
		lst = lst->next;
	}
}

static void		order_off(t_list **lst)
{
	t_list		*cur;
	uint32_t	tmp;
	int			stop;

	cur = *lst;
	stop = 1;
	while (stop)
	{
		stop = 0;
		cur = *lst;
		while (cur->next)
		{
			if (((t_ar *)(cur->content))->off
				> ((t_ar *)(cur->next->content))->off)
			{
				stop = 1;
				tmp = ((t_ar *)(cur->content))->off;
				((t_ar *)(cur->content))->off =
				((t_ar *)(cur->next->content))->off;
				((t_ar *)(cur->next->content))->off = tmp;
			}
			cur = cur->next;
		}
	}
}

static void		add_off(uint32_t off, t_list **lst)
{
	t_list		*new;
	t_list		*tmp;
	t_ar		*cont;

	tmp = *lst;
	while (tmp)
	{
		if (((t_ar *)(tmp->content))->off == off)
			return ;
		tmp = tmp->next;
	}
	cont = (t_ar *)malloc(sizeof(t_ar));
	cont->off = off;
	new = ft_lstnew_ptr(cont, sizeof(t_ar));
	ft_lstadd_end(lst, new);
}

void			handle_ar(void *ptr)
{
	struct ar_hdr	*ar;
	struct ranlib	*rlib;
	uint32_t		size;
	uint32_t		i;
	t_list			*lst;

	ar = (struct ar_hdr *)(ptr + SARMAG);
	size = ft_atoi((void *)ar + sizeof(AR_EFMT1) - 1);
	rlib = (void *)ar + sizeof(struct ar_hdr) + size + sizeof(uint32_t);
	size = *(uint32_t *)((void *)ar + sizeof(struct ar_hdr) + size);
	lst = NULL;
	i = 0;
	while (i < size / sizeof(struct ranlib))
	{
		add_off(rlib[i].ran_off, &lst);
		i++;
	}
	order_off(&lst);
	print_ar(lst, ptr);
}
