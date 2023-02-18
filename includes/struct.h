/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:39:32 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/02/18 16:59:52 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define WIDTH 640
# define HEIGTH 480
# define SIZE 32
# define PI 3.1415926

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
}	t_pos;

typedef struct s_dir
{
	double	x;
	double	y;
}	t_dir;

typedef struct s_plan
{
	double	x;
	double	y;
}	t_plan;

typedef struct s_hor
{
	double	x;
	double	y;
}	t_hor;

typedef struct s_ver
{
	double	x;
	double	y;
}	t_ver;

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
	double		degrees;
	t_params	params;
	t_pos		pos;
	t_dir		dir;
	t_hor		hor;
	t_ver		ver;
	t_img		img;
	t_img		textures[4];
}	t_data;

#endif
