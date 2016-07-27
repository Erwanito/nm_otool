/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displaynbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <eseveno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 09:04:49 by eseveno           #+#    #+#             */
/*   Updated: 2014/12/09 13:31:41 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putzero(int *len, char *str, int larg, int prec)
{
	if (prec == -1)
		prec = 0;
	if (prec > 0 && prec < larg)
	{
		*len = larg - prec;
		ft_putnchar(' ', *len);
	}
	if (str[0] == '-' || str[0] == '+' || str[0] == ' ')
	{
		ft_putchar(str[0]);
		str++;
	}
	if (str[0] == '0' && (str[1] == 'X' || str[1] == 'x'))
	{
		ft_putchar(str[0]);
		ft_putchar(str[1]);
		str += 2;
	}
	ft_putnchar('0', larg - *len - prec);
	if (larg > *len)
		*len = larg;
	ft_putstr(str);
}

int		fill_with_space(char *place, char *str, int larg, int len)
{
	if (!place)
		ft_putnchar(' ', larg - len);
	ft_putstr(str);
	if (place)
		ft_putnchar(' ', larg - len);
	return (larg);
}

char	*startzero(char *str, int *len, int *prec, int *x)
{
	char *tmp;

	tmp = str;
	if (str[0] == '0')
	{
		*x = 1;
		if (str[1] == 'X')
			*x = 2;
		str = ft_strsub(str, 2, *len);
		*len -= 2;
		*prec += 2;
		free(tmp);
	}
	else if (str[0] == '-')
	{
		str = ft_strsub(str, 1, *len);
		*len -= 1;
		*prec += 1;
		free(tmp);
	}
	return (str);
}

char	*add_zero(char *str, int prec, int *len, int sign)
{
	char	*tmp;
	int		i;
	int		x;

	x = 0;
	if (sign < 0 || (str[0] == '0' && (str[1] == 'X' || str[1] == 'x')))
	{
		if (str[0] != '-')
			sign = 0;
		str = startzero(str, len, &prec, &x);
	}
	tmp = ft_strnew(prec - *len);
	i = 0;
	while (i < prec - *len)
	{
		if (sign < 0 && i == 0)
			tmp[i] = '-';
		else if (x > 0 && i == 1)
			tmp[1] = (x == 1) ? 'x' : 'X';
		else
			tmp[i] = '0';
		i++;
	}
	*len = prec;
	return (ft_strjoin_free_all(tmp, str));
}

int		displaynbr(int sign, char *str, t_s *s)
{
	int	len;

	if (ft_strcmp(str, "0") == 0 && s->prec == 0 && (istype(s->type, "dDiuUxX")
						|| ((istype(s->type, "oO") && !istype('#', s->opt)))))
		str = ft_strnew(1);
	if (ft_strchr(s->opt, '+') && sign >= 0)
		str = ft_strjoin_free_second("+", str);
	else if (ft_strchr(s->opt, ' ') && sign >= 0)
		str = ft_strjoin_free_second(" ", str);
	len = ft_strlen(str);
	if (s->prec > len)
		str = add_zero(str, s->prec, &len, sign);
	if (!s->opt || ft_strchr(s->opt, '-') || ft_strchr(s->opt, '0') == 0)
	{
		if (s->larg > len)
			len = fill_with_space(ft_strchr(s->opt, '-'), str, s->larg, len);
		else
			ft_putstr(str);
	}
	else
		putzero(&len, str, s->larg, s->prec);
	free(str);
	return (len);
}
