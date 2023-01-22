# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/21 00:48:03 by nicole            #+#    #+#              #
#    Updated: 2023/01/22 16:21:38 by nchow-yu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PRINTF	=	ft_printf/libftprintf.a
LIBFT	=	srcs/libft/libft.a
GNL		=	$(addprefix srcs/get_next_line/, get_next_line.c get_next_line_utils.c)
ERROR	=	$(addprefix srcs/error/, ft_error.c)
C_FILE	=	$(addprefix srcs/parser/check_get_file/, check_file.c get_file.c)
C_MAP	=	$(addprefix srcs/parser/check_get_map/, get_map.c)
FREE	=	$(addprefix srcs/all_free/, all_free.c)
UTILS	=	$(addprefix srcs/utils/, ft_strcmp.c ft_strcpy.c)
SRCS	=	srcs/main.c ${GNL} ${ERROR} ${C_FILE} ${C_MAP} ${FREE} ${UTILS}
OBJS	=	${SRCS:.c=.o}
CC		=	clang
CFLAGS	=	-Wall -Werror -Wextra -g3 #-fsanitize=address
HEADER	=	includes/cub3d.h
NAME	=	cub3d

%.o:	%.c
	${CC} ${CFLAGS} -g3 -I/usr/include -Imlx_linux -O3 -c $< -o ${<:.c=.o}

all:	${OBJS} ${NAME}

${NAME}:	${OBJS} ${LIBFT}
	${CC} ${CFLAGS} ${OBJS} ${LIBFT} -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o ${NAME}

${LIBFT}:
	make -C srcs/libft

clean:
	rm -rf ${OBJS} ${OBJSBONUS}
	make clean -C srcs/libft

fclean:    clean
	rm -rf ${NAME}
	make fclean -C srcs/libft

re:	fclean all

.PHONY:	all clean fclean re
