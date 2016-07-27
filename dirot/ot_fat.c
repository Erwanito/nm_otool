/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ot_fat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:48:35 by eseveno           #+#    #+#             */
/*   Updated: 2016/03/21 15:48:35 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

void		ot_fat(void *ptr, char *file)
{
	struct fat_header	*header;
	struct fat_arch		*arch;
	uint32_t			i;
	size_t				offset;

	header = (struct fat_header *)ptr;
	if (isopt('f'))
		print_fat_header(header);
	offset = sizeof(struct fat_header);
	i = 0;
	if (isopt('f') && !isopt('t'))
		return ;
	while (i < bswap_32(header->nfat_arch))
	{
		arch = (struct fat_arch *)(ptr + offset);
		ft_otool(ptr + bswap_32(arch->offset), file);
		offset += sizeof(struct fat_arch);
		if (i < bswap_32(header->nfat_arch) - 1)
			ft_putchar('\n');
		i++;
	}
}
