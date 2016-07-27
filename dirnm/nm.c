/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:48:35 by eseveno           #+#    #+#             */
/*   Updated: 2016/03/21 15:48:35 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "nm.h"

void		ft_nm(void *ptr)
{
	int magic_number;

	magic_number = *(int *)ptr;
	if (ft_strncmp(ptr, ARMAG, SARMAG) == 0)
		handle_ar(ptr);
	else if (magic_number == (int)MH_MAGIC_64)
	{
		handle_64(ptr);
	}
	else if (magic_number == (int)MH_MAGIC)
	{
		handle_32(ptr);
	}
	else if (magic_number == (int)FAT_CIGAM)
	{
		handle_fat(ptr);
	}
}

char		sectype(t_list *sct, uint8_t n_sect)
{
	t_list	*tmp;
	t_sct	*cur;

	tmp = sct;
	while (tmp)
	{
		cur = (t_sct *)(tmp->content);
		if (cur->n == n_sect)
		{
			if (!ft_strcmp(cur->name, SECT_DATA))
				return ('D');
			else if (!ft_strcmp(cur->name, SECT_BSS))
				return ('B');
			else if (!ft_strcmp(cur->name, SECT_TEXT))
				return ('T');
			else
				return ('S');
		}
		tmp = tmp->next;
	}
	return ('D');
}

char		get_char(uint8_t type, uint8_t n_sect, int value, t_list *sct)
{
	char	c;

	c = '?';
	if ((type & N_TYPE) == N_UNDF)
	{
		if (value)
			c = 'C';
		else
			c = 'U';
	}
	else if ((type & N_TYPE) == N_ABS)
		c = 'A';
	else if ((type & N_TYPE) == N_PBUD)
		c = 'U';
	else if ((type & N_TYPE) == N_INDR)
		c = 'I';
	else if ((type & N_TYPE) == N_SECT)
		c = sectype(sct, n_sect);
	if ((type & N_STAB) != 0)
		c = 'Z';
	if ((type & N_EXT) == 0 && c != '?')
		c += 32;
	return (c);
}

void		ft_file(char *av, int ac)
{
	int			fd;
	void		*ptr;
	struct stat	buf;

	if ((fd = open(av, O_RDONLY)) < 0)
	{
		ft_printf("%s\n", "open failed");
		return ;
	}
	if (fstat(fd, &buf) < 0)
	{
		ft_printf("fstat\n");
		return ;
	}
	if ((ptr = mmap(0, buf.st_size, PROT_READ,
		MAP_PRIVATE, fd, 0)) == MAP_FAILED)
	{
		ft_printf("%s\n", "mmap");
		return ;
	}
	if (ac > 2)
		ft_printf("%s:\n", av);
	ft_nm(ptr);
	munmap(ptr, buf.st_size);
}

int			main(int ac, char **av)
{
	int i;

	i = 1;
	while (i < ac)
	{
		g_e.name = ft_strdup(av[i]);
		ft_file(av[i], ac);
		i++;
		ft_strdel(&g_e.name);
	}
}
