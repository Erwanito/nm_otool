/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ntoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <eseveno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 09:04:49 by eseveno           #+#    #+#             */
/*   Updated: 2014/12/09 13:31:41 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

char	*to_str(int len, long long n, long long neg, char *str)
{
	while (len >= 0)
	{
		str[len] = (n % 10) + 48;
		n /= 10;
		len--;
	}
	if (neg < 0)
		str[0] = '-';
	return (str);
}

char	*ft_ntoa(long long n)
{
	char		*str;
	int			len;
	long long	neg;

	if (n == LLONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	if (n == 0)
		return (ft_strdup("0"));
	neg = n;
	len = ft_lnbrlen(n);
	if (!(str = (char *)malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	len--;
	if (n < 0)
		n = -n;
	return (to_str(len, n, neg, str));
}
