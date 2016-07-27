# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eseveno <eseveno@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/18 09:49:24 by eseveno           #+#    #+#              #
#    Updated: 2015/06/10 11:17:31 by eseveno          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 =			ft_nm

NAME2 =			ft_otool

CC =			gcc $(FLAGS) $(INCLUDES)

LIBFT =			-L./libft -lft

LIB =			./libft/libft.a

INCLUDES =		-I./includes -I./libft/includes

SRC1 =			dirnm/file_32.c dirnm/file_64.c dirnm/file_ar.c dirnm/file_fat.c dirnm/nm.c dirnm/section.c dirnm/maillon.c

SRC2 =			dirot/ot_32.c dirot/ot_64.c dirot/ot_ar.c dirot/ot_fat.c dirot/otool.c dirot/header.c dirot/option.c

OBJ1 =			$(SRC1:.c=.o)

OBJ2 =			$(SRC2:.c=.o)

FLAGS =			-Wall -Wextra -Werror

all:			$(NAME1) $(NAME2)

$(LIB):
				Make -C libft

$(NAME1):		$(LIB) $(OBJ1)
				$(CC) -o $(NAME1) $(OBJ1) $(LIBFT)

$(NAME2):		$(LIB) $(OBJ2)
				$(CC) -o $(NAME2) $(OBJ2) $(LIBFT)

clean:
				Make -C libft clean
				rm -f $(OBJ1) $(OBJ2)

fclean:
				Make -C libft fclean
				rm -f $(OBJ1) $(OBJ2) $(NAME1) $(NAME2)

re:				fclean all

.PHONY:			all clean re fclean
.SILENT:

%.o:			%.c
				$(CC) -c $< -o $@