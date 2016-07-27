/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ext_char_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <eseveno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 09:04:49 by eseveno           #+#    #+#             */
/*   Updated: 2014/12/09 13:31:41 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_lenwchar(wint_t c)
{
	char	*str;
	int		len;

	str = ft_itoa_ob((int)c, 2);
	len = (ft_strlen(str));
	if (len <= 7)
		len = 1;
	else if (len <= 11)
		len = 2;
	else if (len <= 16)
		len = 3;
	else
		len = 4;
	free(str);
	return (len);
}

int	get_lenstrwchar(wint_t *s)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i])
	{
		len += get_lenwchar(s[i]);
		i++;
	}
	return (len);
}

int	ft_putwstr(wint_t *s, int oct)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (s[i] && (ret + get_lenwchar(s[i])) <= oct)
	{
		ret += ft_putwint(s[i]);
		i++;
	}
	return (ret);
}
