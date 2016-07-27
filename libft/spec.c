/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <eseveno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 09:04:49 by eseveno           #+#    #+#             */
/*   Updated: 2014/12/09 13:31:41 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			istype(char c, char *opt)
{
	int i;

	i = 0;
	while (opt[i])
	{
		if (c == opt[i])
			return (1);
		i++;
	}
	return (0);
}

static void	get_opt(const char *format, int *i, t_s *s)
{
	int c;

	c = 0;
	s->opt = ft_strnew(5);
	while (istype(format[*i], "-+#0 "))
	{
		if (ft_strchr(s->opt, format[*i]) == NULL)
			s->opt[c++] = format[*i];
		*i += 1;
	}
}

static void	getflag(const char *format, int *i, t_s *s)
{
	int c;

	c = 0;
	s->size = ft_strnew(2);
	while (istype(format[*i], "hljz") && c < 2)
	{
		s->size[c] = format[*i];
		c++;
		*i += 1;
	}
}

static int	getint(const char *format, int *i)
{
	char	*s;
	int		c;

	c = *i;
	while (ft_isdigit(format[c]))
		c++;
	s = ft_strnew(c);
	c = 0;
	while (ft_isdigit(format[*i]))
	{
		s[c] = format[*i];
		c++;
		*i += 1;
	}
	c = ft_atoi(s);
	free(s);
	return (c);
}

int			getspec(const char *format, int *i, t_s *s)
{
	s->opt = NULL;
	s->size = NULL;
	s->larg = -1;
	s->prec = -1;
	s->type = -1;
	*i += 1;
	get_opt(format, i, s);
	s->larg = getint(format, i);
	if (format[*i] == '.')
	{
		*i += 1;
		s->prec = getint(format, i);
	}
	getflag(format, i, s);
	if (istype(format[*i], "sSpdDioOuUxXcC"))
		s->type = format[*i];
	return (0);
}
