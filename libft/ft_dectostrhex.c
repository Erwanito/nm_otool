/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dectostrhex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <eseveno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 09:04:49 by eseveno           #+#    #+#             */
/*   Updated: 2014/12/09 13:31:41 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	hexatochar(int i)
{
	char	c;

	if (i < 10)
		c = i + 48;
	else if (i == 10)
		c = 'A';
	else if (i == 11)
		c = 'B';
	else if (i == 12)
		c = 'C';
	else if (i == 13)
		c = 'D';
	else if (i == 14)
		c = 'E';
	else
		c = 'F';
	return (c);
}

static int	get_len(unsigned long long n)
{
	int	len;

	len = 1;
	while (n > 15)
	{
		n /= 16;
		len++;
	}
	return (len);
}

char		*ft_dectostrhex(unsigned long long n)
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
		str[len] = hexatochar((int)(n % 16));
		n = n / 16;
		len--;
	}
	return (str);
}
