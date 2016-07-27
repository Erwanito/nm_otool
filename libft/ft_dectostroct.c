/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dectostroct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <eseveno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 09:04:49 by eseveno           #+#    #+#             */
/*   Updated: 2014/12/09 13:31:41 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(unsigned long long n)
{
	int	len;

	len = 1;
	while (n > 7)
	{
		n /= 8;
		len++;
	}
	return (len);
}

char		*ft_dectostroct(unsigned long long n)
{
	char	*str;
	int		len;

	if (n == 0)
		return (ft_strdup("0"));
	len = get_len(n);
	if (!(str = (char *)malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	len--;
	while (n != 0)
	{
		str[len] = (n % 8) + 48;
		n /= 8;
		len--;
	}
	return (str);
}
