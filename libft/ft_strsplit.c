/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <eseveno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 09:04:49 by eseveno           #+#    #+#             */
/*   Updated: 2014/12/09 13:31:41 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		count(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] && s[i] != c)
		{
			i++;
			j++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (j);
}

char	*add(char const *s, char c, int *i)
{
	char	*str;
	int		len;
	int		count;

	len = *i;
	count = 0;
	while (s[len] != c && s[len])
		len++;
	str = (char *)malloc(sizeof(*str) * ((len - *i) - 1));
	if (str)
	{
		while (*i < len)
		{
			str[count] = s[*i];
			count++;
			*i += 1;
		}
		str[count] = '\0';
		return (str);
	}
	return (NULL);
}

char	**ft_strsplit(char const *s, char c)
{
	int		*i;
	int		vi;
	int		j;
	char	**tab;

	vi = 0;
	i = &vi;
	j = 0;
	tab = NULL;
	if (s)
		tab = (char **)malloc(sizeof(char *) * (count(s, c) + 1));
	if (tab)
	{
		while (j < count(s, c))
		{
			while (s[*i] == c)
				*i += 1;
			if (s[*i] != c && s[*i])
				tab[j++] = add(s, c, i);
		}
		tab[j] = 0;
		return (tab);
	}
	return (NULL);
}
