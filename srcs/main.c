/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 00:53:40 by nicole            #+#    #+#             */
/*   Updated: 2023/02/18 13:41:13 by nchow-yu         ###   ########.fr       */
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

static void	draw_point(t_data *data)
{
	int		i;
	int		j;
	int		init_i;
	int		init_j;
	double	pt_h;
	double	pt_v;

	pt_h = sqrt(pow((data->pos.x * SIZE) - data->hor.x, 2) + pow((data->pos.y * SIZE) - data->hor.y, 2));
	fprintf(stderr, "distance de hor =  %f\n", pt_h);
	pt_v = sqrt(pow((data->pos.x * SIZE) - data->ver.x, 2) + pow((data->pos.y * SIZE) - data->ver.y, 2));
	fprintf(stderr, "distance de ver =  %f\n", pt_v);
	if (pt_h > pt_v)
	{
		i = data->ver.x;
		j = data->ver.y;
	}
	else
	{
		fprintf(stderr, "hor\n");
		i = data->hor.x;
		j = data->hor.y;
	}
	fprintf(stderr, "ver | x = %f | y = %f\n", data->ver.x, data->ver.y);
	fprintf(stderr, "hor | x = %f | y = %f\n", data->hor.x, data->hor.y);
	init_i = i;
	init_j = j;
	i = i - 1;
	while (i <= init_i + 1)
	{
		j = init_j - 1;
		while (j <= init_j + 1)
		{
			mlx_pixel_put(data->mlx, data->win, \
			i, j, 0X0000FF7F);
			j++;
		}
		i++;
	}
}

int	main(int nb, char **argv)
{
	t_data	data;
	double	degrees;
	double	init_degrees;
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
		degrees = 360.0;
	else if (data.map[(int)data.pos.y][(int)data.pos.x] == 'E')
		degrees = 180.0;
	else
	{
		fprintf(stderr, "degrees is NULL\n");
		degrees = 0.0;
	}
	init_degrees = degrees;
	fprintf(stderr, "degrees = %f\n", degrees);
	while (degrees > (init_degrees - 30.0))
	{
		// fprintf(stderr, "LEFT - Enter in find_h\n");
		find_h_intersection(&data, degrees);
		// fprintf(stderr, "LEFT - Enter in find_v\n");
		finding_v_intersection(&data, degrees, 0x004682B4, 0X0000FF7F);
		if (degrees == 0.0)
			degrees = 360.0;
		degrees -= 0.09375;
		nb_ray++;
		draw_point(&data);
		// fprintf(stderr, "LEFT - degrees = %f\n", degrees);
	}
	if (init_degrees == 360.0)
	{
		init_degrees = 0.0;
		degrees = 0.0;
	}
	else
		degrees = init_degrees;
	fprintf(stderr, "\ndegrees = %f | max = %f\n\n", degrees, init_degrees + 30);
	while (degrees < (init_degrees + 30))
	{
		// fprintf(stderr, "RIGHT - Enter in find_h\n");
		find_h_intersection(&data, degrees);
		// fprintf(stderr, "RIGHT - Enter in find_v\n");
		finding_v_intersection(&data, degrees, 0x004682B4, 0X0000FF7F);
		if (degrees == 360.0)
			degrees = 0.0;
		degrees += 0.09375;
		nb_ray++;
		draw_point(&data);
		// fprintf(stderr, "RIGHT - degrees = %f\n", degrees);
	}
	fprintf(stderr, "nb_ray = %d\n", nb_ray);
//	draw_in_window(&data);
	mlx_key_hook(data.win, ft_key_close, &data);
	mlx_hook(data.win, 17, 0, ft_close_cursor, &data);
	mlx_loop(data.mlx);
}
