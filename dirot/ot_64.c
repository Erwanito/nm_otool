/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ot_64.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:48:35 by eseveno           #+#    #+#             */
/*   Updated: 2016/03/21 15:48:35 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

static void	ft_segment2(void *ptr, struct section_64 *section)
{
	uint32_t		i;

	i = 0;
	while (i < section->size)
	{
		ft_printf("%02x ", *((unsigned char *)ptr
			+ section->offset + i));
		i++;
		if (!(i % 16) && i < section->size)
			ft_printf("\n%016llx ", section->addr + i);
	}
	ft_printf("\n");
}

void		segment_stuff(struct segment_command_64 *segment, void *ptr)
{
	struct section_64	*section;
	uint32_t			i;

	i = 0;
	while (i < segment->nsects)
	{
		section = (struct section_64 *)((void *)segment
			+ sizeof(struct segment_command_64) + i
			* sizeof(struct section_64));
		if (!ft_strcmp(section->sectname, "__text"))
		{
			ft_printf("(%s,%s) section\n", section->segname
				, section->sectname, section->offset);
			ft_printf("%016llx ", section->addr);
			ft_segment2(ptr, section);
		}
		i++;
	}
}

void		ot_64(void *ptr)
{
	struct mach_header_64	*header;
	struct load_command		*lc;
	uint32_t				i;

	header = (struct mach_header_64 *)ptr;
	if (isopt('h'))
		print_header(header);
	lc = (void *)ptr + sizeof(struct mach_header_64);
	i = 0;
	while (i < header->ncmds)
	{
		if (lc->cmd == LC_SEGMENT_64)
			segment_stuff((struct segment_command_64 *)lc, ptr);
		lc = (void *)lc + lc->cmdsize;
		i++;
	}
}
