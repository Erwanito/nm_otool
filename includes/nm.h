/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:48:35 by eseveno           #+#    #+#             */
/*   Updated: 2016/03/21 15:48:35 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_H
# define NM_H

# include <stdio.h>
# include <sys/mman.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <mach-o/fat.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <ar.h>
# include <mach-o/ranlib.h>
# include "libft.h"

typedef enum	e_err
{
	OPEN,
	FSTAT,
	MMAP,
	MUNMAP,
	BIN,
	USE_NM,
	USE_OT,
	NERR
}				t_err;

typedef struct	s_sct
{
	char		*name;
	uint8_t		n;
}				t_sct;

typedef struct	s_env
{
	char *name;
}				t_env;

typedef struct	s_32
{
	uint32_t	value;
	char		type;
	char		*name;
	struct s_32	*next;
}				t_32;

typedef struct	s_64
{
	uint64_t	value;
	char		type;
	char		*name;
	struct s_64	*next;
}				t_64;

typedef struct	s_ar
{
	uint32_t	off;
}				t_ar;

t_sct			*g_s;
t_env			g_e;

void			ft_newmaillon32(
					t_32 **add,
uint32_t value,
											char type, char *name);
int				ft_addebut32(t_32 **list, t_32 *add);
void			ft_addmid32(t_32 **list, t_32 *add);
void			add_link32(t_32 **list, uint32_t value, char type, char *name);
void			print_output_32(int *nsyms, int stroff, t_list *sct, void *ptr);
void			handle_32(void *ptr);
t_list			*get_section_32(struct load_command *lc, struct mach_header *h);
void			ft_newmaillon64(t_64 **add, uint64_t value,
	uint8_t type, char *name);
int				ft_addebut64(t_64 **list, t_64 *add);
void			ft_addmid64(t_64 **list, t_64 *add);
void			add_link64(
t_64 **list,
uint64_t value,
uint8_t type,
char *name);
void			print_output_64(int *nsyms, int stroff,
t_list *sct,
void *ptr);
void			handle_64(void *ptr);
void			ft_nm(void *ptr);
t_list			*get_section_64(struct load_command *lc,
	struct mach_header_64 *h);
void			handle_fat(void *ptr);
uint32_t		bswap_32(uint32_t toswap);
void			handle_ar(void *ptr);
char			ft_type(uint8_t type, int value);
char			sectype(t_list *sct, uint8_t n_sect);
char			get_char(uint8_t type, uint8_t n_sect, int value, t_list *sct);
void			add_sct_elem(char *name, t_list **sct);
int				ot_usage(void);
void			ft_otool(void *ptr, char *file);
void			ot_32(void *ptr);
void			ot_64(void *ptr);
void			ot_fat(void *ptr, char *file);
void			ot_ar(void *ptr, char *file);
void			print_header(struct mach_header_64 *header);
void			print_fat_header(struct fat_header *fat);
int				error(t_err err);
int				isopt(char c);
int				ft_getopt(char **av, int *i_av, char *pos_opt);
uint32_t		bswap_32(uint32_t toswap);

#endif
