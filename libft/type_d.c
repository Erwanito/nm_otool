/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <eseveno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 09:04:49 by eseveno           #+#    #+#             */
/*   Updated: 2014/12/09 13:31:41 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		type_d(va_list ap, t_s *s)
{
	if (s->type == 'D')
		return (display_long(ap, s));
	if (ft_strcmp(s->size, "hh") == 0)
		return (display_char(ap, s));
	else if (ft_strcmp(s->size, "h") == 0)
		return (display_short(ap, s));
	else if (ft_strcmp(s->size, "l") == 0 || ft_strcmp(s->size, "ll") == 0
			|| ft_strcmp(s->size, "j") == 0 || ft_strcmp(s->size, "z") == 0)
		return (display_long(ap, s));
	else
		return (display_int(ap, s));
}
