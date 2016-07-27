/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <eseveno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 09:04:49 by eseveno           #+#    #+#             */
/*   Updated: 2014/12/09 13:31:41 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned char	*temp;

	i = 0;
	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	temp = (unsigned char *)malloc(sizeof(*temp) * len);
	while (i < len)
	{
		temp[i] = s2[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		s1[i] = temp[i];
		i++;
	}
	free(temp);
	return (dst);
}
