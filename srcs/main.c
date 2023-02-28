/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanauth <sanauth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 00:53:40 by nicole            #+#    #+#             */
/*   Updated: 2023/02/28 11:12:52 by sanauth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	refresh_window(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	draw_mini_map(data);
	p_mini_map(data);
	ft_fov(data);
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
	else if (key == 'w'
		&& data->map[(int)(data->pos.y + ((sin(data->rad) * 10) / SIZE))] \
		[(int)(data->pos.x + ((cos(data->rad) * 10) / SIZE))] != '1')
	{
		data->pos.x += (cos(data->rad) * 10) / SIZE;
		data->pos.y += (sin(data->rad) * 10) / SIZE;
	}
	else if (key == 's'
		&& data->map[(int)(data->pos.y - ((sin(data->rad) * 10) / SIZE))] \
		[(int)(data->pos.x - ((cos(data->rad) * 10) / SIZE))] != '1')
	{
		data->pos.x -= (cos(data->rad) * 10) / SIZE;
		data->pos.y -= (sin(data->rad) * 10) / SIZE;
	}
	else if (key == 'a')
		data->rad -= 0.0175;
	else if (key == 'd')
		data->rad += 0.0175;
	if (data->rad < 0.0)
		data->rad += M_PI * 2;
	else if (data->rad > 6.2832)
		data->rad -= M_PI * 2;
	if (key == 'w' || key == 's' || key == 'a' || key == 'd')
		refresh_window(data);
	return (1);
}

int	main(int nb, char **argv)
{
	t_data	data;

	data.max_len = 0;
	data.rad = 0.0;
	ft_parsing(&data, nb, argv);
	init_pos_player(&data);
	init_rad(&data);
	init_window(&data);
	init_textures(&data);
	//draw_mini_map(&data);
	//p_mini_map(&data);
	ft_fov(&data);
	ft_start_draw(&data);
	mlx_hook(data.win, 2, 1L << 0, ft_key_catch, &data);
	mlx_hook(data.win, 17, 0, ft_close_cursor, &data);
	mlx_loop(data.mlx);
}
