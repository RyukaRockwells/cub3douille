/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 00:53:40 by nicole            #+#    #+#             */
/*   Updated: 2023/02/24 12:00:53 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	ft_close_cursor(t_data *data)
{
	ft_close(data);
	return (1);
}

static int	ft_key_catch(int key, t_data *data)
{
	// draw_mini_map(data);
	// p_mini_map(data);
	if (key == 65307)
		ft_close(data);
	// else if (key == 'd')
	// 	data->pos.y +=  0.00327249;
	// else if (key == 'a')
	// 	data->pos.y -=  0.00327249;
	// if (key == 'a' || key == 'd' || key == 'w' || key == 's')
	// {
	// 	mlx_clear_window(data->mlx, data->win);
	// 	draw_mini_map(data);
	// 	p_mini_map(data);
	// 	ft_fov(data);
	// }
	return (1);
}

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
	mlx_key_hook(data.win, ft_key_catch, &data);
	mlx_hook(data.win, 17, 0, ft_close_cursor, &data);
	mlx_loop(data.mlx);
}
