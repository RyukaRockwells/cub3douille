/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 00:53:40 by nicole            #+#    #+#             */
/*   Updated: 2023/03/06 22:00:38 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	refresh_window(t_data *data)
{
	if (data->fov != NULL)
		free(data->fov);
	data->fov = ft_fov(data);
	ft_start_draw(data, data->fov);
	draw_mini_map(data);
	p_mini_map(data);
}

static int	ft_close_cursor(t_data *data)
{
	ft_close(data);
	return (1);
}

static int	ft_key_catch(int key, t_data *data)
{
	if (key == 65307)
		ft_close(data);
	else if (key == 'w' || key == 's' || key == 'a' || key == 'd')
		move_player(key, data);
	else if (key == 65361)
		data->rad -= 0.0175;
	else if (key == 65363)
		data->rad += 0.0175;
	if (data->rad < 0.0)
		data->rad += M_PI * 2;
	else if (data->rad >= M_PI * 2)
		data->rad -= M_PI * 2;
	if (key == 65363 || key == 65361
		|| key == 'w' || key == 's' || key == 'a' || key == 'd')
		refresh_window(data);
	return (1);
}

int	main(int nb, char **argv)
{
	t_data	data;

	data.rad = 0.0;
	ft_parsing(&data, nb, argv);
	init_pos_player(&data);
	init_rad(&data);
	init_window(&data);
	init_textures(&data);
	data.fov = ft_fov(&data);
	ft_start_draw(&data, data.fov);
	draw_mini_map(&data);
	p_mini_map(&data);
	mlx_hook(data.win, 2, 1L << 0, ft_key_catch, &data);
	mlx_hook(data.win, 17, 0, ft_close_cursor, &data);
	mlx_loop(data.mlx);
}
