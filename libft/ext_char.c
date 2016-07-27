/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ext_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <eseveno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 09:04:49 by eseveno           #+#    #+#             */
/*   Updated: 2014/12/09 13:31:41 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*g_mask[] =
{
	"0xxxxxxx",
	"110xxxxx10xxxxxx",
	"1110xxxx10xxxxxx10xxxxxx",
	"11110xxx10xxxxxx10xxxxxx10xxxxxx"
};

int	bin_to_dec(char *s)
{
	int	n;
	int	i;
	int	pwr;

	i = 7;
	n = 0;
	pwr = 0;
	while (i >= 0)
	{
		if (s[i] == '1')
		{
			n += ft_power(2, pwr);
		}
		i--;
		pwr++;
	}
	free(s);
	return (n);
}

int	convert_to_int(char *str, int mask)
{
	int	tab[4];

	tab[0] = bin_to_dec(ft_strsub(str, 0, 8));
	write(1, &tab[0], 1);
	(void)mask;
	if (mask > 0)
	{
		tab[1] = bin_to_dec(ft_strsub(str, 8, 8));
		write(1, &tab[1], 1);
	}
	if (mask > 1)
	{
		tab[2] = bin_to_dec(ft_strsub(str, 16, 8));
		write(1, &tab[2], 1);
	}
	if (mask > 2)
	{
		tab[3] = bin_to_dec(ft_strsub(str, 24, 8));
		write(1, &tab[3], 1);
	}
	return (mask + 1);
}

int	put_mask(char *bin, int mask)
{
	char	*new;
	int		i;
	int		j;

	i = ft_strlen(g_mask[mask]) - 1;
	new = ft_strnew(i + 1);
	j = ft_strlen(bin) - 1;
	while (i >= 0)
	{
		if (g_mask[mask][i] == 'x')
		{
			if (j >= 0)
				new[i] = bin[j];
			else
				new[i] = '0';
			j--;
		}
		else
			new[i] = g_mask[mask][i];
		i--;
	}
	free(bin);
	return (convert_to_int(new, mask));
}

int	ext_char(char *bin)
{
	int	len;

	len = ft_strlen(bin);
	if (len <= 7)
		return (put_mask(bin, 0));
	else if (len <= 11)
		return (put_mask(bin, 1));
	else if (len <= 16)
		return (put_mask(bin, 2));
	else
		return (put_mask(bin, 3));
}

int	ft_putwint(wint_t c)
{
	char *str;

	str = ft_itoa_ob((int)c, 2);
	return (ext_char(str));
}
