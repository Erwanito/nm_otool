/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <eseveno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 09:04:49 by eseveno           #+#    #+#             */
/*   Updated: 2014/12/09 13:31:41 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	display_char(va_list ap, t_s *s)
{
	char	c;
	char	*str;
	int		tmp;

	tmp = va_arg(ap, int);
	c = (char)tmp;
	str = ft_ntoa((long long)c);
	return (displaynbr(tmp, str, s));
}

int	display_short(va_list ap, t_s *s)
{
	short	nbr;
	char	*str;
	int		tmp;

	tmp = va_arg(ap, int);
	nbr = (short)tmp;
	str = ft_ntoa((long long)nbr);
	return (displaynbr(tmp, str, s));
}

int	display_int(va_list ap, t_s *s)
{
	int		nbr;
	char	*str;

	nbr = va_arg(ap, int);
	str = ft_ntoa((long long)nbr);
	return (displaynbr(nbr, str, s));
}

int	display_long(va_list ap, t_s *s)
{
	long long	nbr;
	char		*str;
	int			neg;

	neg = 1;
	nbr = va_arg(ap, long long);
	str = ft_ntoa(nbr);
	if (nbr < 0)
		neg = -1;
	return (displaynbr(neg, str, s));
}
