/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <eseveno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 09:04:49 by eseveno           #+#    #+#             */
/*   Updated: 2014/12/09 13:31:41 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	unsigned int	len;
	unsigned int	i;

	len = ft_strlen(s2);
	i = 0;
	if (len == 0)
		return ((char*)s1);
	else if (ft_strlen(s1) < len)
		return (NULL);
	while (s1[i + len - 1] != '\0')
	{
		if (ft_memcmp(s1 + i, s2, len) == 0)
			return ((char*)s1 + i);
		i++;
	}
	return (NULL);
}
