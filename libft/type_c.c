/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <eseveno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 09:04:49 by eseveno           #+#    #+#             */
/*   Updated: 2014/12/09 13:31:41 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	display_char_ascii(char c, t_s *s)
{
	int	len;

	len = 1;
	if ((ft_strchr(s->opt, '0') || ft_strchr(s->opt, '-') == 0) && s->larg > 1)
		len = put_space_return_len(s->larg, 1, s);
	write(1, &c, 1);
	if (ft_strchr(s->opt, '0') == 0 && ft_strchr(s->opt, '-') && s->larg > 1)
		len = put_space_return_len(s->larg, 1, s);
	return (len);
}

int	display_wchar(wint_t c, t_s *s)
{
	int	len;
	int	len2;
	int	i;

	i = get_lenwchar(c);
	len = 0;
	if ((ft_strchr(s->opt, '0') || ft_strchr(s->opt, '-') == 0) && s->larg > i)
		len = put_space_return_len(s->larg, i, s);
	len2 = ft_putwint(c);
	if (ft_strchr(s->opt, '0') == 0 && ft_strchr(s->opt, '-') && s->larg > 1)
		len = put_space_return_len(s->larg, i, s);
	if (len2 > len)
		len = len2;
	return (len);
}

int	type_cmaj(va_list ap, t_s *s)
{
	wint_t	c;

	(void)s;
	c = va_arg(ap, wint_t);
	return (display_wchar(c, s));
}

int	type_c(va_list ap, t_s *s)
{
	char	c;
	int		tmp;

	if (ft_strcmp(s->size, "l") || ft_strcmp(s->size, "ll"))
		return (type_cmaj(ap, s));
	tmp = va_arg(ap, int);
	c = (char)tmp;
	return (display_char_ascii(c, s));
}
