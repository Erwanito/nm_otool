/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maillon.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:48:35 by eseveno           #+#    #+#             */
/*   Updated: 2016/03/21 15:48:35 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

int			ft_addebut32(t_32 **list, t_32 *add)
{
	if (ft_strcmp((*list)->name, add->name) > 0)
	{
		add->next = *list;
		*list = add;
		return (1);
	}
	if (!(*list)->next)
	{
		(*list)->next = add;
		return (1);
	}
	return (0);
}

void		ft_addmid32(t_32 **list, t_32 *add)
{
	t_32	*tmp;

	tmp = (*list)->next;
	(*list)->next = add;
	add->next = tmp;
}

void		ft_newmaillon64(t_64 **add, uint64_t value,
			uint8_t type, char *name)
{
	(*add) = (t_64 *)malloc(sizeof(t_64));
	(*add)->value = value;
	(*add)->type = type;
	(*add)->name = ft_strdup(name);
	(*add)->next = NULL;
}

void		add_link64(t_64 **list, uint64_t value, uint8_t type, char *name)
{
	t_64	*add;
	t_64	*start;

	ft_newmaillon64(&add, value, type, name);
	if (!(*list))
	{
		(*list) = add;
		return ;
	}
	if (ft_addebut64(list, add) == 1)
		return ;
	start = (*list);
	while (((*list)->next) && (ft_strcmp((*list)->next->name, name) < 0))
		(*list) = (*list)->next;
	if (!(*list)->next)
		(*list)->next = add;
	else
		ft_addmid64(list, add);
	(*list) = start;
}

int			ft_addebut64(t_64 **list, t_64 *add)
{
	if (ft_strcmp((*list)->name, add->name) > 0)
	{
		add->next = *list;
		*list = add;
		return (1);
	}
	if (!(*list)->next)
	{
		(*list)->next = add;
		return (1);
	}
	return (0);
}
