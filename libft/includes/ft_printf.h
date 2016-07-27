/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <eseveno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 09:04:49 by eseveno           #+#    #+#             */
/*   Updated: 2014/12/09 13:31:41 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <locale.h>
# include <wchar.h>

typedef struct	s_s
{
	char		*opt;
	int			larg;
	int			prec;
	char		*size;
	char		type;
}				t_s;

typedef struct	s_f
{
	int			(*ptr_f)(va_list ap, t_s *s);
	char		type;
}				t_f;

int				display_ulong(va_list ap, t_s *s,
							char *(f)(unsigned long long));
int				display_uint(va_list ap, t_s *s,
							char *(f)(unsigned long long));
int				display_ushort(va_list ap, t_s *s,
							char *(f)(unsigned long long));
int				display_uchar(va_list ap, t_s *s,
							char *(f)(unsigned long long));
int				display_long(va_list ap, t_s *s);
int				display_int(va_list ap, t_s *s);
int				display_short(va_list ap, t_s *s);
int				display_char(va_list ap, t_s *s);
int				displaynbr(int nbr, char *str, t_s *s);
int				type_d(va_list ap, t_s *s);
int				type_ws(va_list ap, t_s *s);
int				type_s(va_list ap, t_s *s);
int				type_p(va_list ap, t_s *s);
int				type_o(va_list ap, t_s *s);
int				type_x(va_list ap, t_s *s);
int				type_u(va_list ap, t_s *s);
int				type_c(va_list ap, t_s *s);
int				type_cmaj(va_list ap, t_s *s);
int				ft_putwint(wint_t c);
int				ft_putwstr(wint_t *s, int oct);
int				get_lenwchar(wint_t c);
int				get_lenstrwchar(wint_t *s);
int				put_space_return_len(int larg, int i, t_s *s);
int				istype(char c, char *opt);
int				getspec(const char *format, int *i, t_s *s);
int				ft_printf(const char *format, ...);

#endif
