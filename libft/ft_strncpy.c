/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <eseveno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 09:04:49 by eseveno           #+#    #+#             */
/*   Updated: 2014/12/09 13:31:41 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	unsigned int	len_src;

	len_src = ft_strlen(src);
	if (len_src < n)
	{
		dst = ft_memcpy(dst, src, len_src);
		while (len_src < n)
		{
			dst[len_src] = 0;
			len_src++;
		}
	}
	else
	{
		dst = ft_memcpy(dst, src, n);
	}
	return (dst);
}
