/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <eseveno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 09:04:49 by eseveno           #+#    #+#             */
/*   Updated: 2014/12/09 13:31:41 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_start(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	return (i);
}

size_t	get_end(char const *s)
{
	size_t	len;

	len = ft_strlen(s) - 1;
	while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
		len--;
	return (len);
}

char	*ft_strtrim(char const *s)
{
	char	*s2;
	size_t	start;
	size_t	len;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	start = get_start(s);
	if (s[start] == '\0')
	{
		s2 = (char *)malloc(sizeof(*s2) * 1);
		if (!s2)
			return (NULL);
		s2[0] = '\0';
		return (s2);
	}
	len = get_end(s) - start;
	s2 = (char *)malloc(sizeof(*s2) * (len + 1));
	if (!s2)
		return (NULL);
	while (start <= get_end(s))
		s2[i++] = s[start++];
	s2[i] = '\0';
	return (s2);
}
