/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <eseveno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 09:04:49 by eseveno           #+#    #+#             */
/*   Updated: 2014/12/09 13:31:41 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_f	g_tab[] =
{
	{&type_s, 's'},
	{&type_ws, 'S'},
	{&type_p, 'p'},
	{&type_d, 'd'},
	{&type_d, 'D'},
	{&type_d, 'i'},
	{&type_o, 'o'},
	{&type_o, 'O'},
	{&type_u, 'u'},
	{&type_u, 'U'},
	{&type_x, 'x'},
	{&type_x, 'X'},
	{&type_c, 'c'},
	{&type_cmaj, 'C'},
	{NULL, 0}
};

void	free_struct(t_s *s)
{
	if (s->opt)
		free(s->opt);
	if (s->size)
		free(s->size);
	free(s);
}

int		if_no_type(int *i, t_s *s, const char *format)
{
	int	ret;

	ret = 0;
	if ((ft_strchr(s->opt, '0') || ft_strchr(s->opt, '-') == 0) && s->larg > 1)
		ret = put_space_return_len(s->larg, 1, s);
	if (format[*i])
	{
		write(1, &format[*i], 1);
		if (ret == 0)
			ret = 1;
	}
	else
		*i -= 1;
	if (ft_strchr(s->opt, '0') == 0 && ft_strchr(s->opt, '-') && s->larg > 1)
		ret = put_space_return_len(s->larg, 1, s);
	return (ret);
}

int		global_display(const char *format, int *i, va_list ap)
{
	int	c;
	int	ret;
	t_s *spec;

	spec = (t_s *)malloc(sizeof(t_s));
	getspec(format, i, spec);
	c = 0;
	ret = 0;
	while (g_tab[c].type)
	{
		if (g_tab[c].type == spec->type)
			ret = (g_tab[c].ptr_f(ap, spec));
		c++;
	}
	if (spec->type == -1)
		ret = if_no_type(i, spec, format);
	free_struct(spec);
	return (ret);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
			ret = ret + (global_display(format, &i, ap));
		else
		{
			ft_putchar(format[i]);
			ret++;
		}
		i++;
	}
	return (ret);
}
