/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ot_32.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:48:35 by eseveno           #+#    #+#             */
/*   Updated: 2016/03/21 15:48:35 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

static void	ft_segment2(void *ptr, struct section *section)
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

static void	segment_stuff(struct segment_command *segment, void *ptr)
{
	struct section	*sct;
	uint32_t		i;

	i = 0;
	while (i < segment->nsects)
	{
		sct = (struct section *)((void *)segment
			+ sizeof(struct segment_command) + i
			* sizeof(struct section));
		if (!ft_strcmp(sct->sectname, "__text"))
		{
			ft_printf("(%s,%s) section\n", sct->segname
				, sct->sectname, sct->offset);
			ft_printf("%016llx ", sct->addr);
			ft_segment2(ptr, sct);
		}
		i++;
	}
}

void		ot_32(void *ptr)
{
	struct mach_header		*header;
	struct load_command		*lc;
	uint32_t				i;

	header = (struct mach_header *)ptr;
	lc = (void *)ptr + sizeof(struct mach_header);
	i = 0;
	while (i < header->ncmds)
	{
		if (lc->cmd == LC_SEGMENT)
			segment_stuff((struct segment_command *)lc, ptr);
		lc = (void *)lc + lc->cmdsize;
		i++;
	}
}
