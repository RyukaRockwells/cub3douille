/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:39:32 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/03/06 18:15:44 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define WIDTH 640
# define HEIGTH 400
# define SIZE 64
# define FOV 60

typedef struct s_imge
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		line_size;
	int		endian;
}	t_imge;

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
	double	x;
	double	y;
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
	double		rad;
	double		pxl_start;
	int			txt_index;
	double		wall_height;
	int			col;
	t_fov		*fov;
	t_params	params;
	t_pos		pos;
	t_imge		render;
	t_imge		textures[4];
}	t_data;

#endif
