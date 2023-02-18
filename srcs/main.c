/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 00:53:40 by nicole            #+#    #+#             */
/*   Updated: 2023/02/18 18:10:06 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	ft_close_cursor(t_data *data)
{
	ft_close(data);
	return (1);
}

static int	ft_key_close(int key, t_data *data)
{
	draw_mini_map(data);
	p_mini_map(data);
	if (key == 65307)
		ft_close(data);
	else if (key == 100)
		data->degrees += 0.09375;
	ft_fov(data);
	return (1);
}

// static double	ft_absolute(double nb)
// {
// 	if (nb < 0)
// 		return (-nb);
// 	return (nb);
// }

// static void	bresenham(t_data *data, double d_x, double d_y)
// {
// 	double	decision;
// 	double	x;
// 	double	y;
// 	double	diff_x;
// 	double	diff_y;

// 	diff_x = ft_absolute(d_x - (data->pos.x * SIZE));
// 	diff_y = ft_absolute(d_y - (data->pos.y * SIZE));
// 	x = (data->pos.x * SIZE);
// 	y = (data->pos.y * SIZE);
// 	decision = 2 * diff_y - diff_x;
// 	while (x <= d_x)
// 	{
// 		mlx_pixel_put(data->mlx, data->win, x, y, 0x00FF00);
// 		if (decision <= 0)
// 			decision += (2 * diff_y);
// 		else
// 		{
// 			decision += (2 * (diff_y - diff_x));
// 			if (d_y > (data->pos.y * SIZE))
// 				y += 1;
// 			else
// 				y += -1;
// 		}
// 		x++;
// 	}
// }

int	main(int nb, char **argv)
{
	t_data	data;

	data.max_len = 0;
	data.degrees = 0.0;
	ft_parsing(&data, nb, argv);
	init_pos_player(&data);
	init_degrees(&data);
	init_window(&data);
	init_textures(&data);
	draw_mini_map(&data);
	p_mini_map(&data);
	ft_fov(&data);
//	draw_in_window(&data);
	mlx_key_hook(data.win, ft_key_close, &data);
	mlx_hook(data.win, 17, 0, ft_close_cursor, &data);
	mlx_loop(data.mlx);
}
