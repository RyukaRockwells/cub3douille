# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/21 00:48:03 by nicole            #+#    #+#              #
#    Updated: 2023/01/30 15:21:51 by nchow-yu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PRINTF	=	ft_printf/libftprintf.a
LIBFT	=	srcs/libft/libft.a
GNL		=	$(addprefix srcs/get_next_line/, get_next_line.c get_next_line_utils.c)
ERROR	=	$(addprefix srcs/error/, ft_error.c ft_error_utils.c)
C_FILE	=	$(addprefix srcs/parser/check_get_file/, check_file.c get_file.c)
C_MAP	=	$(addprefix srcs/parser/check_get_map/, check_map.c get_map.c)
C_PARAMS	=	$(addprefix srcs/parser/check_get_params/, check_params.c get_params.c)
FREE	=	$(addprefix srcs/all_free/, all_free.c)
UTILS	=	$(addprefix srcs/utils/, ft_strcmp.c ft_strcpy.c ft_is_space.c)
PARSER	= 	$(addprefix srcs/parser/, init.c) ${C_FILE} ${C_MAP} ${C_PARAMS} 
SRCS	=	srcs/main.c ${GNL} ${ERROR} ${FREE} ${UTILS} ${PARSER}
OBJS	=	${SRCS:.c=.o}
CC		=	clang
CFLAGS	=	-Wall -Werror -Wextra #-g3 -fsanitize=address
HEADER	=	includes/cub3d.h
NAME	=	cub3d

%.o:	%.c
	${CC} ${CFLAGS} -g3 -I/usr/include -Imlx_linux -c $< -o ${<:.c=.o}

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
