# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/21 00:48:03 by nicole            #+#    #+#              #
#    Updated: 2023/02/25 14:44:05 by nchow-yu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PRINTF	=	ft_printf/libftprintf.a
LIBFT	=	srcs/lib/libft/libft.a
GNL		=	$(addprefix srcs/lib/get_next_line/, get_next_line.c get_next_line_utils.c)
ERROR	=	$(addprefix srcs/error/, ft_error.c ft_error_utils.c ft_error_params.c)
C_FILE	=	$(addprefix srcs/parser/check_get_file/, check_file.c get_file.c)
C_MAP	=	$(addprefix srcs/parser/check_get_map/, check_map.c get_map.c check_contour.c)
C_PARAMS=	$(addprefix srcs/parser/check_get_params/, check_params.c get_params.c count_params.c count_params_2.c)
FREE	=	$(addprefix srcs/all_free/, all_free.c)
UTILS	=	$(addprefix srcs/utils/, ft_strcmp.c ft_strcpy.c ft_is_space.c)
MLX_FT	=	$(addprefix srcs/mlx_ft/, close.c)
PARSER	= 	$(addprefix srcs/parser/, parser.c) ${C_FILE} ${C_MAP} ${C_PARAMS} 
TEXTURE	=	$(addprefix srcs/textures/, init_textures.c)
M_MAP	=	$(addprefix srcs/mini_map/, mini_map.c)
RAYCAS	=	$(addprefix srcs/raycaster/, find_horizontal_intersections.c find_vertical_intersections.c\
			fov_player.c)
SRCS	=	$(addprefix srcs/, main.c init.c draw_ft.c) ${GNL} ${ERROR} ${FREE} ${UTILS} ${PARSER} ${MLX_FT}\
			${TEXTURE} ${M_MAP} ${RAYCAS}
OBJS	=	${SRCS:.c=.o}
CC		=	clang
CFLAGS	=	-Wall -Werror -Wextra -g3 #-fsanitize=address
HEADER	=	includes/cub3d.h
NAME	=	cub3D

%.o:	%.c
	${CC} ${CFLAGS} -g3 -I/usr/include -Imlx_linux -c $< -o ${<:.c=.o}

all:	${OBJS} ${NAME}

${NAME}:	${OBJS} ${LIBFT}
	${CC} ${CFLAGS} ${OBJS} ${LIBFT} -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o ${NAME}

${LIBFT}:
	make -C srcs/lib/libft

clean:
	rm -rf ${OBJS} ${OBJSBONUS}
	make clean -C srcs/lib/libft

fclean:    clean
	rm -rf ${NAME}
	make fclean -C srcs/lib/libft

re:	fclean all

.PHONY:	all clean fclean re
