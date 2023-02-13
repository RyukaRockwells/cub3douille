/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanauth <sanauth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:39:32 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/02/13 11:52:05 by sanauth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define WIDTH 1000
# define HEIGTH 1000
# define SIZE 17

typedef struct s_img
{
	void	*img;
	int		x;
	int		y;
}	t_img;

typedef struct s_pos
{
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
	t_params	params;
	t_pos		pos;
	t_dir		dir;
	t_img		img;
	t_img		textures[4];
}	t_data;

#endif
/*
	mlx_pixel_put(data->mlx, data->win, \
		data->pos.x * SIZE, data->pos.y * SIZE, 0x0000F0FF);
	mlx_pixel_put(data->mlx, data->win, \
		(data->pos.x * SIZE) + 1, data->pos.y * SIZE, 0x0000F0FF);
	mlx_pixel_put(data->mlx, data->win, \
		(data->pos.x * SIZE) + 2, data->pos.y * SIZE, 0x0000F0FF);
	mlx_pixel_put(data->mlx, data->win, \
		(data->pos.x * SIZE) - 1, data->pos.y * SIZE, 0x0000F0FF);
	mlx_pixel_put(data->mlx, data->win, \
		(data->pos.x * SIZE) - 2, data->pos.y * SIZE, 0x0000F0FF);
	mlx_pixel_put(data->mlx, data->win, \
		data->pos.x * SIZE, (data->pos.y * SIZE) + 1, 0x0000F0FF);
	mlx_pixel_put(data->mlx, data->win, \
		data->pos.x * SIZE, (data->pos.y * SIZE) + 2, 0x0000F0FF);
	mlx_pixel_put(data->mlx, data->win, \
		data->pos.x * SIZE, (data->pos.y * SIZE) + 1, 0x0000F0FF);
	mlx_pixel_put(data->mlx, data->win, \
		data->pos.x * SIZE, (data->pos.y * SIZE) - 2, 0x0000F0FF);

	int	i;
	int	j;

	i = data->pos.x - 2;
	while (i <= data->pos.x + 2)
	{
		j = data->pos.y - 2;
		while (j <= data->pos.y + 2)
		{
			mlx_pixel_put(data->mlx, data->win, (i * SIZE), (j * SIZE), 0x0000FFFF);
			j++;
		}
		i++;
	}
*/
