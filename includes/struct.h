/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanauth <sanauth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:39:32 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/03/06 13:20:48 by sanauth          ###   ########.fr       */
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

typedef struct s_buff
{
	void	*img_buff;
	int		bpp;
	int		line_size;
	int		endian;
	char	*buff;
}	t_buff;

// typedef struct s_texture
// {
// 	void	*img;
// 	int		*addr;
// 	int		txt_bpp;
// 	int		txt_width;
// 	int		txt_height;
// 	int		txt_line_size;
// 	int		txt_endian;
// }	t_texture;

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
	// char		*render;
	// int			line_size;
	// int			bpp;
	// int			endian;
	// void		*new_img;
	// t_buff		*win;
	// t_texture	texture;
}	t_data;

#endif

//On peut extraire max_len et nb_line mais faut faire des fonctions int qui
//retourne ces valeurs pour pouvoir quand même les utiliser sans tout casser
