/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dectooct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <eseveno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 09:04:49 by eseveno           #+#    #+#             */
/*   Updated: 2014/12/09 13:31:41 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long	ft_dectooct(unsigned long long n)
{
	unsigned long long	oct;
	unsigned long long	tmp;
	int					c;

	oct = 0;
	c = 0;
	while (n != 0)
	{
		tmp = n % 8;
		n = n / 8;
		if (c == 0)
			oct = tmp;
		else
			oct = oct + (tmp * (c * 10));
		c++;
	}
	return (oct);
}
