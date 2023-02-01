/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanauth <sanauth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 00:53:40 by nicole            #+#    #+#             */
/*   Updated: 2023/02/01 16:24:00 by sanauth          ###   ########.fr       */
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
	if (key == 65307)
		ft_close(data);
	return (1);
}

int	main(int nb, char **argv)
{
	t_data	data;

	data.max_len = 0;
	ft_parsing(&data, nb, argv);
	init_window(&data);
	init_textures(&data);
	init_pos_player(&data);
	draw_mini_map(&data);
	p_mini_map(&data);
	finding_h_intersection(&data);
//	draw_in_window(&data);
	//draw_ray(&data);
	mlx_key_hook(data.win, ft_key_close, &data);
	mlx_hook(data.win, 17, 0, ft_close_cursor, &data);
	mlx_loop(data.mlx);
}
