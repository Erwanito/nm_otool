/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_type_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <eseveno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 09:04:49 by eseveno           #+#    #+#             */
/*   Updated: 2014/12/09 13:31:41 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*hexa_opt(t_s *s, char *str)
{
	int	i;

	i = 0;
	if ((s->type == 'x' || s->type == 'X') && ft_strchr(s->opt, '#')
		&& ft_strcmp(str, "0") != 0)
		str = ft_strjoin_free_second("0X", str);
	if ((s->type == 'o' || s->type == 'O') && ft_strchr(s->opt, '#')
		&& ft_strcmp(str, "0") != 0)
		str = ft_strjoin_free_second("0", str);
	if (s->type == 'x')
	{
		while (str[i])
		{
			if (ft_isupper(str[i]))
				str[i] = str[i] + 32;
			i++;
		}
	}
	return (str);
}

int		display_uchar(va_list ap, t_s *s, char *(f)(unsigned long long))
{
	unsigned char	c;
	char			*str;
	unsigned int	tmp;

	tmp = va_arg(ap, unsigned int);
	c = (unsigned char)tmp;
	str = f((unsigned long long)c);
	if (s->type == 'x' || s->type == 'X' || s->type == 'o' || s->type == 'O')
		str = hexa_opt(s, str);
	return (displaynbr(-1, str, s));
}

int		display_ushort(va_list ap, t_s *s, char *(f)(unsigned long long))
{
	unsigned short	nbr;
	char			*str;
	unsigned int	tmp;

	tmp = va_arg(ap, unsigned int);
	nbr = (unsigned short)tmp;
	str = f((unsigned long long)nbr);
	if (s->type == 'x' || s->type == 'X' || s->type == 'o' || s->type == 'O')
		str = hexa_opt(s, str);
	return (displaynbr(-1, str, s));
}

int		display_uint(va_list ap, t_s *s, char *(f)(unsigned long long))
{
	unsigned int	nbr;
	char			*str;

	nbr = va_arg(ap, unsigned int);
	str = f((unsigned long long)nbr);
	if (s->type == 'x' || s->type == 'X' || s->type == 'o' || s->type == 'O')
		str = hexa_opt(s, str);
	return (displaynbr(-1, str, s));
}

int		display_ulong(va_list ap, t_s *s, char *(f)(unsigned long long))
{
	unsigned long long	nbr;
	char				*str;

	nbr = va_arg(ap, unsigned long long);
	str = f(nbr);
	if (s->type == 'x' || s->type == 'X' || s->type == 'o' || s->type == 'O')
		str = hexa_opt(s, str);
	return (displaynbr(-1, str, s));
}
