/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_fat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:48:35 by eseveno           #+#    #+#             */
/*   Updated: 2016/03/21 15:48:35 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

uint32_t	bswap_32(uint32_t toswap)
{
	uint32_t	swap;

	swap = ((toswap >> 24) & 0xff) | ((toswap << 8) & 0xff0000) |
			((toswap >> 8) & 0xff00) | ((toswap << 24) & 0xff000000);
	return (swap);
}

int			ft_verif(void *ptr)
{
	int		magic_number;

	magic_number = *(int *)ptr;
	if (magic_number == (int)MH_MAGIC_64)
	{
		handle_64(ptr);
		return (1);
	}
	else
		return (0);
}

void		handle_fat(void *ptr)
{
	struct fat_header	*header;
	struct fat_arch		*arch;
	size_t				offset;
	uint32_t			i;

	i = -1;
	offset = sizeof(struct fat_header);
	header = (struct fat_header *)ptr;
	while (++i < bswap_32(header->nfat_arch))
	{
		arch = (struct fat_arch *)(ptr + offset);
		if (ft_verif(ptr + bswap_32(arch->offset)) == 1)
			return ;
		offset += sizeof(struct fat_arch);
	}
	i = 0;
	while (i < bswap_32(header->nfat_arch))
	{
		arch = (struct fat_arch *)(ptr + offset);
		ft_nm(ptr + bswap_32(arch->offset));
		offset += sizeof(struct fat_arch);
		if (i < bswap_32(header->nfat_arch) - 1)
			ft_putchar('\n');
		i++;
	}
}
