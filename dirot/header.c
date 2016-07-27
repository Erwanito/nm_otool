/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:48:35 by eseveno           #+#    #+#             */
/*   Updated: 2016/03/21 15:48:35 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

void		print_header(struct mach_header_64 *header)
{
	ft_printf("Mach header\n");
	ft_printf("      magic cputype cpusubtype  caps    ");
	ft_printf("filetype ncmds sizeofcmds      flags\n");
	ft_printf(" %p %d%11u  0x%.2x%12u%6u%11u 0x%.8x\n", header->magic
		, header->cputype, CPU_SUBTYPE_X86_64_ALL, (header->cpusubtype
			& CPU_SUBTYPE_MASK) / 0x1000000
		, header->filetype, header->ncmds, header->sizeofcmds
		, header->flags);
}

static void	ft_fat_arch(struct fat_arch *arch, uint32_t i)
{
	ft_printf("architecture %u\n", i);
	ft_printf("    cputype %u\n", bswap_32(arch->cputype));
	ft_printf("    cpusubtype 3\n");
	ft_printf("    capabilities 0x%x\n", (bswap_32(arch->cpusubtype)
			& CPU_SUBTYPE_MASK) / 0x1000000);
	ft_printf("    offset %u\n", bswap_32(arch->offset));
	ft_printf("    size %u\n", bswap_32(arch->size));
	ft_printf("    align 2^%u (%u)\n", bswap_32(arch->align)
		, ft_power(bswap_32(arch->align), 2));
}

void		print_fat_header(struct fat_header *fat)
{
	struct fat_arch				*arch;
	uint32_t					i;

	i = 0;
	ft_printf("Fat headers\n");
	ft_printf("fat_magic %p\n", bswap_32(fat->magic));
	ft_printf("nfat_arch %u\n", bswap_32(fat->nfat_arch));
	arch = (struct fat_arch *)(fat + 1);
	while (i < bswap_32(fat->nfat_arch))
	{
		ft_fat_arch(arch, i);
		i++;
		arch++;
	}
}
