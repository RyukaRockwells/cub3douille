/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanauth <sanauth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 00:55:10 by nicole            #+#    #+#             */
/*   Updated: 2023/02/01 09:40:18 by sanauth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

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
void	init_pos_player(t_data *data);

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
void	ft_map_error(t_data *data, char *str);
void	error_xpm_to_img(t_data *data);
void	ft_close_error(t_data *data);

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

//check_get_map/check_contour.c
int		ft_check_outline(t_data *data);
int		ft_check_last_char(t_data *data);
int		ft_check_first_char(t_data *data);

//check_get_params/get_params.c
void	get_params(t_data *data);

//check_get_params/check_params.c
void	check_params(t_data *data);

//check_get_params/count_params.c
int		ft_count_rgb(t_data *data);
int		ft_count_directions(t_data *data);
int		ft_is_file_clear(t_data *data);
int		ft_line_ok(t_data *data, int i, int J);
int		ft_empty_line(t_data *data, int i);

//parser.c
void	ft_parsing(t_data *data, int nb, char **argv);
void	ft_print_map(t_data *data);

//***********//
//**TEXTURE**//
//***********//
//init_textures.c
void	init_textures(t_data *data);

//****** *****//
//**MINI_MAP**//
//******* ****//
//mini_map.c
void	p_mini_map(t_data *data);
void	draw_mini_map(t_data *data);

void	check_in_map(t_data *data);
int		ft_count_pos(t_data *data);
int		ft_verify_content(t_data *data);
void	print_map(t_data *data);
int		ft_check_around(t_data *data, int i, int j);
int		ft_check_zero(t_data *data);
#endif
