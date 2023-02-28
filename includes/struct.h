/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:39:32 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/02/28 11:18:57 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define WIDTH 320
# define HEIGTH 200
# define SIZE 32

typedef struct s_img
{
	void	*img;
	int		x;
	int		y;
}	t_img;

typedef struct s_pos
{
	char	dir_view;
	double	x;
	double	y;
	double	dx;
	double	dy;
}	t_pos;

typedef struct s_coord
{
	double	x;
	double	y;
}	t_coord;

typedef struct s_fov
{
	double	degrees;
	double	dist;
	char	wall_orientation;
}	t_fov;

typedef struct s_params
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*floor;
	char	*ceiling;
}	t_params;

typedef struct s_data
{
	char		**file;
	char		**map;
	void		*mlx;
	void		*win;
	int			max_len;
	int			nb_line;
	double		rad;
	t_params	params;
	t_pos		pos;
	t_img		img;
	t_img		textures[4];
}	t_data;

#endif
