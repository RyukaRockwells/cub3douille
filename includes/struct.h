/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanauth <sanauth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:39:32 by nchow-yu          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/03/02 16:04:08 by sanauth          ###   ########.fr       */
=======
/*   Updated: 2023/03/01 17:29:43 by nchow-yu         ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define WIDTH 640
# define HEIGTH 400
# define SIZE 32
# define FOV 60

typedef struct s_imge
{
	void	*img;
	int		x;
	int		y;
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

typedef struct s_texture
{
	void	*img;
	int		*addr;
	int		txt_bpp;
	int		txt_width;
	int		txt_height;
	int		txt_line_size;
	int		txt_endian;
}	t_texture;

typedef struct s_data
{
	char		**file;
	char		**map;
	void		*mlx;
	void		*win;
	int			max_len;
	int			nb_line;
	double		rad;
	double		degrees;
	void		*new_img;
	int			nb_line_map;
	int			bpp;
	int			endian;
	char		*buffer;
	t_texture	texture;
	t_params	params;
	t_pos		pos;
	t_imge		img;
	t_imge		textures[4];
}	t_data;

#endif
