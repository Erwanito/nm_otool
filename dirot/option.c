/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:48:35 by eseveno           #+#    #+#             */
/*   Updated: 2016/03/21 15:48:35 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

char		*g_optarg;

int			isopt(char c)
{
	int	i;

	if (!g_optarg)
		return (0);
	i = 0;
	while (g_optarg[i])
	{
		if (g_optarg[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	check_opt(char *str, int i, char *pos_opt)
{
	if (str[1] == '-')
		return (-1);
	if (ft_strchr(pos_opt, str[i]) == NULL)
		return (-2);
	return (1);
}

int			ft_getopt(char **av, int *i_av, char *pos_opt)
{
	int	i;
	int	j;
	int	c_op;

	g_optarg = ft_strnew(ft_strlen(pos_opt));
	i = 1;
	j = 1;
	c_op = 0;
	while (av[i] && av[i][0] == '-' && av[i][1] != '\0')
	{
		*i_av = *i_av + 1;
		while (av[i][j])
		{
			if (check_opt(av[i], j, pos_opt) < 0)
				return (check_opt(av[i], j, pos_opt));
			if (ft_strchr(g_optarg, av[i][j]) == NULL)
				g_optarg[c_op++] = av[i][j];
			j++;
		}
		i++;
		j = 1;
	}
	return (-1);
}

uint32_t	bswap_32(uint32_t toswap)
{
	uint32_t	swap;

	swap = ((toswap >> 24) & 0xff) | ((toswap << 8) & 0xff0000) |
			((toswap >> 8) & 0xff00) | ((toswap << 24) & 0xff000000);
	return (swap);
}
