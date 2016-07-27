#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsourd-b <bsourd-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/07 17:55:59 by bsourd-b          #+#    #+#              #
#    Updated: 2015/02/23 18:38:43 by bsourd-b         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CPATH	= .
OPATH	= obj
HPATH	= includes

FLAGS	= -Wall -Wextra -Werror -O3
CC		= gcc $(FLAGS)

NAME	= libft.a

SRC	= ft_printf.c \
display_type.c \
display_type_u.c \
displaynbr.c \
ext_char.c \
ext_char_tools.c \
spec.c \
type_c.c \
type_d.c \
type_o.c \
type_s.c \
ft_bzero.c \
ft_isprint.c \
ft_memmove.c \
ft_putendl_fd.c \
ft_strcat.c \
ft_strncat.c \
ft_isalnum.c \
ft_memccpy.c \
ft_memset.c \
ft_putnbr.c \
ft_strchr.c \
ft_strncpy.c \
ft_isalpha.c \
ft_memchr.c \
ft_putchar.c \
ft_putnbr_fd.c \
ft_strcpy.c \
ft_strrchr.c \
ft_isascii.c \
ft_memcmp.c \
ft_putchar_fd.c \
ft_putstr.c \
ft_strdup.c \
ft_tolower.c \
ft_isdigit.c \
ft_memcpy.c \
ft_putendl.c \
ft_putstr_fd.c \
ft_strlen.c \
ft_toupper.c \
ft_strstr.c \
ft_strnstr.c \
ft_strcmp.c \
ft_strncmp.c \
ft_memalloc.c \
ft_memdel.c \
ft_strnew.c \
ft_strdel.c \
ft_strclr.c \
ft_striter.c \
ft_striteri.c \
ft_strmap.c \
ft_strmapi.c \
ft_strequ.c \
ft_strnequ.c \
ft_strsub.c \
ft_strjoin.c \
ft_strtrim.c \
ft_strlcat.c \
ft_itoa.c \
ft_atoi.c \
ft_strsplit.c \
ft_lstnew.c \
ft_lstdelone.c \
ft_lstdel.c \
ft_lstadd.c \
ft_lstiter.c \
ft_lstmap.c \
ft_realloc.c \
ft_nbrlen.c \
ft_pathcat.c \
ft_strcmp_nc.c \
ft_isblank.c \
ft_isspace.c \
ft_tablen.c \
ft_strjoin_free.c \
ft_putnchar.c \
get_next_line.c \
ft_lnbrlen.c \
ft_ntoa.c \
ft_unbrlen.c \
ft_utoa.c \
ft_itoa_ob.c \
ft_dectostrhex.c \
ft_dectostroct.c \
ft_isupper.c \
ft_bintodec.c \
ft_power.c \
ft_free_tab.c \
ft_aton.c \
is_all_digit.c \
ft_lstadd_end.c \
ft_lstnew_ptr.c \
ft_lpnew_ptr.c \
ft_lpadd_end.c \
ft_lpdel.c \
ft_lpdelone.c

CFILE	= $(patsubst %, $(OPATH)/%, $(SRC)) 
OFILE	= $(patsubst %.c,$(OPATH)/%.o, $(SRC)) 

C_END	= "\033[0m"
C_GOOD	= "\033[32m"
C_GREY  = "\033[1;30m"
C_BAD	= "\033[31m"
C_BLUE	= "\033[34;1m"

all: $(NAME)

$(NAME): $(OPATH) $(OFILE)
	@ar rc $(NAME) $(OFILE)
	@ranlib $(NAME)
	@echo "✅  ["$(C_GOOD) libft $(C_END)"] Library Created"

$(OPATH):
	@echo "⛏  ["$(C_BLUE) libft $(C_END)"] Compiling library"
	@mkdir $(OPATH)

$(OPATH)/%.o: $(CPATH)/%.c
	@$(CC) -o $@ -c $^ -I $(HPATH)

clean:
	@rm -rf $(OPATH)
	@echo "⚰  ["$(C_GREY) libft $(C_END)"] Library building directory deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

re: fclean all

.PHONY: all clean fclean re 