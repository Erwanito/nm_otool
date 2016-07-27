/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <eseveno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 09:04:49 by eseveno           #+#    #+#             */
/*   Updated: 2014/12/09 13:31:41 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		type_p(va_list ap, t_s *s)
{
	void			*tmp;
	char			*str;
	unsigned long	nbr;
	int				i;

	i = 0;
	tmp = va_arg(ap, void*);
	nbr = (unsigned long long)tmp;
	if (nbr == 0 && s->prec == 0)
		str = ft_strnew(1);
	else
		str = ft_dectostrhex(nbr);
	str = ft_strjoin_free_second("0x", str);
	while (str[i])
	{
		if (ft_isupper(str[i]))
			str[i] = str[i] + 32;
		i++;
	}
	return (displaynbr(-1, str, s));
}

int		type_u(va_list ap, t_s *s)
{
	if (s->type == 'U')
		return (display_ulong(ap, s, ft_utoa));
	if (ft_strcmp(s->size, "hh") == 0)
		return (display_uchar(ap, s, ft_utoa));
	else if (ft_strcmp(s->size, "h") == 0)
		return (display_ushort(ap, s, ft_utoa));
	else if (ft_strcmp(s->size, "l") == 0 || ft_strcmp(s->size, "ll") == 0
			|| ft_strcmp(s->size, "j") == 0 || ft_strcmp(s->size, "z") == 0)
		return (display_ulong(ap, s, ft_utoa));
	else
		return (display_uint(ap, s, ft_utoa));
}

int		type_x(va_list ap, t_s *s)
{
	if (ft_strcmp(s->size, "hh") == 0)
		return (display_uchar(ap, s, ft_dectostrhex));
	else if (ft_strcmp(s->size, "h") == 0)
		return (display_ushort(ap, s, ft_dectostrhex));
	else if (ft_strcmp(s->size, "l") == 0 || ft_strcmp(s->size, "ll") == 0
			|| ft_strcmp(s->size, "j") == 0 || ft_strcmp(s->size, "z") == 0)
		return (display_ulong(ap, s, ft_dectostrhex));
	else
		return (display_uint(ap, s, ft_dectostrhex));
}

int		type_o(va_list ap, t_s *s)
{
	if (s->type == 'O')
		return (display_ulong(ap, s, ft_dectostroct));
	if (ft_strcmp(s->size, "hh") == 0)
		return (display_uchar(ap, s, ft_dectostroct));
	else if (ft_strcmp(s->size, "h") == 0)
		return (display_ushort(ap, s, ft_dectostroct));
	else if (ft_strcmp(s->size, "l") == 0 || ft_strcmp(s->size, "ll") == 0
			|| ft_strcmp(s->size, "j") == 0 || ft_strcmp(s->size, "z") == 0)
		return (display_ulong(ap, s, ft_dectostroct));
	else
		return (display_uint(ap, s, ft_dectostroct));
}
