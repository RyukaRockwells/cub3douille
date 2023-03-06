/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanauth <sanauth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 00:55:10 by nicole            #+#    #+#             */
/*   Updated: 2023/03/06 13:40:12 by sanauth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include "struct.h"
# include "parser.h"
# include "../mlx_linux/mlx.h"
# include "../srcs/lib/libft/libft.h"
# include "../srcs/lib/get_next_line/get_next_line.h"

//init.c
void	init_struct(t_data *data);
void	init_window(t_data *data);
void	init_pos_player(t_data *data);
void	init_rad(t_data *data);

//free/all_free.c
void	ft_free_str(char **str);
void	ft_free_all_params(t_data *data);

//mlx_ft/close.c
void	ft_close(t_data *win);

//**********//
//**UTILS***//
//**********//
//ft_strcmp.c
int		ft_strcmp(const char *s1, const char *s2);

//ft_strcpy.c
char	*ft_strcpy(char *dest, char *str);
//ft_is_space.c
int		ft_is_space(char c);

//key_ft.c
void	move_player(int key, t_data *data);

//draw_point.c
void	draw_point(t_data *data, double i, double j, int color);

//height_map.c
int		maplenmax(char **map);
int		mapline(char **map);
int		max_line(char **file);

//**********//
//**ERROR***//
//**********//
//ft_error.c
void	nb_arg_error(void);
void	file_error(void);
void	fd_error(char *file, int fd);
void	file_invalid(t_data *data);
void	map_error(t_data *data);

//ft_error_utils.c
void	error_xpm(char *path);
void	error_rgb(void);
void	error_missing_params(t_data *data);
void	ft_map_error(t_data *data, char *str);
void	ft_close_error(t_data *data);

//ft_error_utils.c
void	error_xpm_to_img(t_data *data);
void	error_choose_textures(t_data *data);

//***********//
//**TEXTURE**//
//***********//
//init_textures.c
void	init_textures(t_data *data);

//************//
//**MINI_MAP**//
//************//
//mini_map.c
void	p_mini_map(t_data *data);
void	draw_mini_map(t_data *data);

void	check_in_map(t_data *data);
int		ft_count_pos(t_data *data);
int		ft_verify_content(t_data *data);
void	print_map(t_data *data);
int		ft_check_around(t_data *data, int i, int j);
int		ft_check_zero(t_data *data);

//*************//
//**RAYCASTER**//
//*************//
t_coord	find_h_intersection(t_data *data, double rad);
t_coord	finding_v_intersection(t_data *data, double rad);

//fov_player.c
t_fov	*ft_fov(t_data *data);
void	ft_put_3d(t_data *data);

//fill_the_struct_for_render.c
t_fov	fill_the_struct_for_render(double rad, double d, char i, t_coord *coord);

//render/rendernorm.c
void	ft_start_draw(t_data *data, t_fov *fov);
char	*load_texture(t_data *data,t_fov *fov, int column);
char	*ft_choose_texture(t_data *data, t_fov *fov, int column);

//*************//
//***RENDER***//
//************//
void	ft_write_sky(t_data *data, int x, int y);
void	ft_write_floor(t_data *data, int x, int y);
void	ft_write_wall(t_data *data, t_fov *fov);
void	ft_fill_buffer(t_data *data, int txt_index, t_imge *text_choose);

#endif
