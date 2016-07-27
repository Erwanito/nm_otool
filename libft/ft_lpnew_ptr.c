/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lpnew_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <eseveno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 09:04:49 by eseveno           #+#    #+#             */
/*   Updated: 2014/12/09 13:31:41 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lp	*ft_lpnew_ptr(void *content, size_t content_size)
{
	t_lp	*list;

	list = (t_lp *)malloc(sizeof(t_lp));
	if (!list)
		return (NULL);
	list->next = NULL;
	list->prev = NULL;
	if (!content || !content_size)
	{
		list->content = NULL;
		list->content_size = 0;
		return (list);
	}
	else
	{
		list->content = (void *)content;
		list->content_size = content_size;
		return (list);
	}
}
