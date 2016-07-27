/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <eseveno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 09:04:49 by eseveno           #+#    #+#             */
/*   Updated: 2014/12/09 13:31:41 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*read_line(int const fd, char *str, int *ret)
{
	char	buf[BUFF_SIZE + 1];

	while (!(ft_strchr((const char *)str, '\n')) && *ret != 0)
	{
		*ret = read(fd, buf, BUFF_SIZE);
		if (*ret < 0 || (*ret == 0 && !str))
			return (NULL);
		buf[*ret] = '\0';
		if (!str)
			str = ft_strdup(buf);
		else
		{
			if (!(str = ft_realloc(str, ft_strlen(str) + ft_strlen(buf))))
				return (NULL);
			str = ft_strcat(str, buf);
		}
	}
	return (str);
}

static char	*get_end(char *str, int *i)
{
	int		j;
	int		k;
	char	*end;

	*i = 0;
	j = 0;
	while (str[*i] != '\n' && str[*i])
		*i = *i + 1;
	k = *i;
	if (!str[k + 1])
		return (NULL);
	if (!(end = ft_strnew(ft_strlen(str) - (k - 1))))
		return (NULL);
	k++;
	while (str[k])
	{
		end[j] = str[k];
		j++;
		k++;
	}
	return (end);
}

int			if_end(char **line, char *str)
{
	*line = NULL;
	free(str);
	return (0);
}

int			get_next_line(int const fd, char **line)
{
	static char	*end = NULL;
	char		*str;
	int			ret;
	int			i;

	ret = 1;
	str = NULL;
	if (!line)
		return (-1);
	if (end)
	{
		str = ft_strdup((const char *)end);
		free(end);
	}
	if (!str || ft_strchr((const char *)str, '\n') == NULL)
		str = read_line(fd, str, &ret);
	if (ret == 0 && !str)
		return (if_end(line, str));
	if (!str || ret < 0)
		return (-1);
	end = get_end(str, &i);
	*line = ft_strsub(str, 0, i);
	free(str);
	return (1);
}
