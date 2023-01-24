/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 00:55:10 by nicole            #+#    #+#             */
/*   Updated: 2023/01/24 14:18:56 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WIDTH 640
# define HEIGTH 480

# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include "struct.h"
# include "../mlx_linux/mlx.h"
# include "../srcs/lib/libft/libft.h"
# include "../srcs/lib/get_next_line/get_next_line.h"

//init.c
void	init_struct(t_data *data);
void	init_window(t_data *data);

//utils/ft_strcmp.c
int		ft_strcmp(const char *s1, const char *s2);

//utils/ft_strcpy.c
char	*ft_strcpy(t_data *data, char *dest, char *str);

//utils/ft_is_space.c
int		ft_is_space(char c);

//free/all_free.c
void	ft_free_str(char **str);
void	ft_free_all_params(t_data *data);

//error/ft_error.c
void	nb_arg_error(void);
void	file_error(void);
void	fd_error(char *file, int fd);
void	file_invalid(t_data *data);
void	map_error(t_data *data);

//error/ft_error_utils.c
void	error_xpm(char *path);
void	error_rgb(void);
void	error_missing_params(t_data *data);

//mlx_ft/close.c
void	ft_close(t_data *win);

//**********//
//**PARSER**//
//**********//
//check_get_file/check_file.c
int		check_file(char *file);

//check_get_file/get_file.c
char	**get_file(char *file);

//check_get_map/get_map.c
char	**get_map(t_data *data);

//check_get_params/get_params.c
void	get_params(t_data *data);

//check_get_params/check_params.c
void	check_params(t_data *data);

//parser.c
void	ft_parsing(t_data *data, int nb, char **argv);

#endif
