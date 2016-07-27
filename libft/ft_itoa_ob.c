/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ob.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <eseveno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 09:04:49 by eseveno           #+#    #+#             */
/*   Updated: 2014/12/09 13:31:41 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(unsigned long long n, int base)
{
	int	len;

	len = 1;
	while (n > (unsigned int)(base - 1))
	{
		n /= base;
		len++;
	}
	return (len);
}

char		*ft_itoa_ob(unsigned long long n, int base)
{
	char	*str;
	int		len;

	if (n == 0)
		return (ft_strdup("0"));
	len = get_len(n, base);
	if (!(str = (char *)malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	len--;
	while (n != 0)
	{
		str[len] = (n % base) + 48;
		n /= base;
		len--;
	}
	return (str);
}
