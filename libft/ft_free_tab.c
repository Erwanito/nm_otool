/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <eseveno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 09:04:49 by eseveno           #+#    #+#             */
/*   Updated: 2014/12/09 13:31:41 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_free_str(char *str)
{
	if (!str)
		return (0);
	free(str);
	return (1);
}

int	ft_free_tab(char **tab, int size)
{
	int	i;

	i = 0;
	if (!tab)
		return (0);
	while (i != size && tab[i])
	{
		ft_free_str(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}
