/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:48:35 by eseveno           #+#    #+#             */
/*   Updated: 2016/03/21 15:48:35 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

int				error(t_err err)
{
	char		*errors[NERR];

	errors[OPEN] = "Open error";
	errors[FSTAT] = "Fstat error";
	errors[MMAP] = "Mmap error";
	errors[MUNMAP] = "Munmap error";
	errors[BIN] = "Unsupported format";
	if (err == USE_OT)
		return (ot_usage());
	ft_printf("%s\n", errors[err]);
	return (-1);
}

int				ot_usage(void)
{
	ft_printf("Usage: ft_otool [-tfh] <file>\n");
	ft_printf("\t -t print the text section (default option)\n");
	ft_printf("\t -f print the fat headers\n");
	ft_printf("\t -h print the mach header\n");
	return (-1);
}

void			ft_otool(void *ptr, char *file)
{
	uint32_t	magic;

	magic = *(uint32_t *)ptr;
	if (!ft_strncmp(ptr, ARMAG, SARMAG))
		ot_ar(ptr, file);
	if (magic == MH_MAGIC || magic == MH_CIGAM)
		ot_32(ptr);
	else if (magic == MH_MAGIC_64 || magic == MH_CIGAM_64)
		ot_64(ptr);
	else if (magic == FAT_MAGIC || magic == FAT_CIGAM)
		ot_fat(ptr, file);
	else
		return ;
}

static int		manage_file(char *file)
{
	int				fd;
	struct stat		buf;
	void			*ptr;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (error(OPEN));
	else if (fstat(fd, &buf) == -1)
		return (error(FSTAT));
	else if ((ptr = mmap(0, buf.st_size, PROT_READ,
		MAP_PRIVATE, fd, 0)) == MAP_FAILED)
		return (error(MMAP));
	ft_otool(ptr, file);
	if (fd != -1 && munmap(ptr, buf.st_size) < 0)
		return (error(MUNMAP));
	return (1);
}

int				main(int ac, char **av)
{
	int		c;
	int		c_av;

	c = 1;
	if (ac == 1)
		return (error(USE_OT));
	if (ac >= 2)
	{
		if (ft_getopt(av, &c_av, "tfh") == -2)
			return (error(USE_OT));
		ac -= c_av;
		av += c_av;
	}
	while (c < ac)
	{
		ft_printf("%s:\n", av[c]);
		manage_file(av[c]);
		c++;
	}
	return (0);
}
