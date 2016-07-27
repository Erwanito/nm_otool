/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <eseveno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 09:04:49 by eseveno           #+#    #+#             */
/*   Updated: 2014/12/09 13:31:41 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free_first(char *s1, const char *s2)
{
	char	*new;

	new = ft_strjoin((const char *)s1, s2);
	free(s1);
	return (new);
}

char	*ft_strjoin_free_second(const char *s1, char *s2)
{
	char	*new;

	new = ft_strjoin(s1, (const char *)s2);
	free(s2);
	return (new);
}

char	*ft_strjoin_free_all(char *s1, char *s2)
{
	char	*new;

	new = ft_strjoin((const char *)s1, (const char *)s2);
	free(s1);
	free(s2);
	return (new);
}
