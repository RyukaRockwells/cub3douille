/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanauth <sanauth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 00:53:40 by nicole            #+#    #+#             */
/*   Updated: 2023/02/14 12:47:43 by sanauth          ###   ########.fr       */
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
	double		degrees;
	int		init_degrees;
	int		nb_ray;

	data.max_len = 0;
	nb_ray = 0;
	ft_parsing(&data, nb, argv);
	init_window(&data);
	init_textures(&data);
	init_pos_player(&data);
	draw_mini_map(&data);
	p_mini_map(&data);
	if (data.map[(int)data.pos.y][(int)data.pos.x] == 'N')
		degrees = 90.0;
	else if (data.map[(int)data.pos.y][(int)data.pos.x] == 'S')
		degrees = 270.0;
	else if (data.map[(int)data.pos.y][(int)data.pos.x] == 'W')
		degrees = 0.0;
	else if (data.map[(int)data.pos.y][(int)data.pos.x] == 'E')
		degrees = 180.0;
	else
	{
		fprintf(stderr, "degrees is NULL\n");
		degrees = 0.0;
	}
	init_degrees = degrees;
	fprintf(stderr, "degrees = %f\n", degrees);
	//find_h_intersection(&data, degrees);
	//finding_v_intersection(&data, degrees);
	while (degrees >= (init_degrees - 30))
	{
		fprintf(stderr, "RIGHT - Enter in find_h\n");
		find_h_intersection(&data, degrees);
		//fprintf(stderr, "LEFT - Enter in find_v\n");
		// finding_v_intersection(&data, degrees, 0x00FF1493, 0X001E90FF);
		if (degrees == 0.0)
			degrees = 360.0;
		degrees -= 0.09375;
		nb_ray++;
		fprintf(stderr, "Right - degrees = %f\n", degrees);
	}
	// degrees = init_degrees;
	// fprintf(stderr, "\n\ndegrees = %f\n\n", degrees);
	// while (degrees <= (init_degrees + 30))
	// {
	// 	fprintf(stderr, "Right - Enter in find_h\n");
	// 	find_h_intersection(&data, degrees);
	// 	// fprintf(stderr, "LEFT - Enter in find_v\n");
	// 	// finding_v_intersection(&data, degrees, 0x00FF1493, 0X001E90FF);
	// 	if (degrees == 0.0)
	// 		degrees = 360.0;
	// 	degrees += 0.09375;
	// 	nb_ray++;
	// 	fprintf(stderr, "Left - degrees = %f\n", degrees);
	// }
	fprintf(stderr, "nb_ray = %d\n", nb_ray);
//	draw_in_window(&data);
	mlx_key_hook(data.win, ft_key_close, &data);
	mlx_hook(data.win, 17, 0, ft_close_cursor, &data);
	mlx_loop(data.mlx);
}
