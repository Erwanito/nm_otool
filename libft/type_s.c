/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <eseveno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 09:04:49 by eseveno           #+#    #+#             */
/*   Updated: 2014/12/09 13:31:41 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	strzero(void)
{
	write(1, "(null)", 6);
	return (6);
}

int	put_space_return_len(int larg, int i, t_s *s)
{
	if (ft_strchr(s->opt, '0'))
		ft_putnchar('0', larg - i);
	else
		ft_putnchar(' ', larg - i);
	return (larg);
}

int	get_wlen_prec(wchar_t *s, int oct)
{
	int ret;
	int	i;

	ret = 0;
	i = 0;
	while (s[i] && (ret + get_lenwchar(s[i])) <= oct)
	{
		ret += get_lenwchar(s[i]);
		i++;
	}
	return (ret);
}

int	type_ws(va_list ap, t_s *s)
{
	wchar_t	*str;
	int		len;
	int		oct;

	oct = 0;
	str = va_arg(ap, wchar_t*);
	if (!str)
		return (strzero());
	oct = get_lenstrwchar((wint_t *)str);
	if (s->prec != -1 && oct > s->prec)
		oct = get_wlen_prec(str, s->prec);
	len = oct;
	if ((ft_strchr(s->opt, '0') || ft_strchr(s->opt, '-') == 0)
		&& s->larg > oct)
		len = put_space_return_len(s->larg, oct, s);
	oct = ft_putwstr((wint_t *)str, oct);
	if (ft_strchr(s->opt, '0') == 0 && ft_strchr(s->opt, '-') && s->larg > oct)
		len = put_space_return_len(s->larg, oct, s);
	if (oct > len)
		len = oct;
	return (len);
}

int	type_s(va_list ap, t_s *s)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	if (ft_strcmp(s->size, "l") == 0 || ft_strcmp(s->size, "ll") == 0)
		return (type_ws(ap, s));
	str = va_arg(ap, char*);
	if (!str)
		return (strzero());
	i = ft_strlen(str);
	if (s->prec != -1 && i > s->prec)
		i = s->prec;
	len = i;
	if ((ft_strchr(s->opt, '0') || ft_strchr(s->opt, '-') == 0) && s->larg > i)
		len = put_space_return_len(s->larg, i, s);
	write(1, str, i);
	if (ft_strchr(s->opt, '0') == 0 && ft_strchr(s->opt, '-') && s->larg > i)
		len = put_space_return_len(s->larg, i, s);
	return (len);
}
