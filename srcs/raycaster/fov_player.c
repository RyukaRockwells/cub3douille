/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fov_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:05:02 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/02/19 23:24:48 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static double	ft_absolute(double nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

static void	bresenham(t_data *data, double d_x, double d_y)
{
	double	decision;
	double	x;
	double	y;
	double	diff_x;
	double	diff_y;

	diff_x = ft_absolute(d_x - (data->pos.x * SIZE));
	diff_y = ft_absolute(d_y - (data->pos.y * SIZE));
	x = (data->pos.x * SIZE);
	y = (data->pos.y * SIZE);
	decision = 2 * diff_y - diff_x;
	while (x <= d_x)
	{
		mlx_pixel_put(data->mlx, data->win, x, y, 0x00A52A2A);
		if (decision <= 0)
			decision += (2 * diff_y);
		else
		{
			decision += (2 * (diff_y - diff_x));
			if (d_y > (data->pos.y * SIZE))
				y += 1;
			else
				y += -1;
		}
		x++;
	}
}

static void	draw_point(t_data *data, int degrees)
{
	int		i;
	int		j;
	// int		init_i;
	// int		init_j;
	double	pt_h;
	double	pt_v;

	if ((int)degrees % 90 == 0)
	{
		pt_h = sqrt(pow(((data->pos.x * SIZE + (SIZE / 2)) - data->hor.x), 2) + pow(((data->pos.y * SIZE + (SIZE / 2)) - data->hor.y), 2));
		pt_v = sqrt(pow(((data->pos.x * SIZE + (SIZE / 2)) - data->ver.x), 2) + pow(((data->pos.y * SIZE + (SIZE / 2)) - data->ver.y), 2));
		fprintf(stderr, "sqrt => degrees = %d | pt_h = %f | pt_v = %f\n", degrees, pt_h, pt_v);
	}
	else
	{
		pt_h = fabs(((double)(data->pos.x * SIZE + (SIZE / 2)) - data->hor.x) / cos(degrees * M_PI / 180));
		pt_v = fabs(((double)(data->pos.y * SIZE + (SIZE / 2)) - data->ver.y) / sin(degrees * M_PI / 180));
		fprintf(stderr, "fabs => degrees = %d | pt_h = %f | pt_v = %f\n", degrees, pt_h, pt_v);
	}
	if (pt_h > pt_v)
	{
		i = data->ver.x - 1;
		j = data->ver.y - 1;
		fprintf(stderr, "ver => x = %d | y = %d\n", i, j);
		fprintf(stderr, "pos => x = %f | y = %f\n\n", data->pos.x, data->pos.y);
	}
	else
	{
		i = data->hor.x - 1;
		j = data->hor.y - 1;
		fprintf(stderr, "data->degrees = %f\n", data->degrees);
		fprintf(stderr, "hor => x = %d | y = %d\n", i, j);
		fprintf(stderr, "ver => x = %f | y = %f\n", data->ver.x, data->ver.y);
		fprintf(stderr, "pos => x = %f | y = %f\n", data->pos.x, data->pos.y);
		fprintf(stderr, "y = %f\n", floor(data->pos.y) * SIZE - 0.00001);
		fprintf(stderr, "x = %f\n\n", (data->pos.x * SIZE) + ((floor(data->pos.y) * SIZE - 0.00001) - (data->pos.y * SIZE)) / tan(156.0 * (M_PI / 180)));
	}
	if (degrees == 186.0)
	{
		pt_h = sqrt(pow(((data->pos.x * SIZE + (SIZE / 2)) - data->hor.x), 2) + pow(((data->pos.y * SIZE + (SIZE / 2)) - data->hor.y), 2));
		pt_v = sqrt(pow(((data->pos.x * SIZE + (SIZE / 2)) - data->ver.x), 2) + pow(((data->pos.y * SIZE + (SIZE / 2)) - data->ver.y), 2));
		fprintf(stderr, "sqrt ==> pt_h = %f | pt_v = %f\n", pt_h, pt_v);
		pt_h = fabs(((double)(data->pos.x * SIZE + (SIZE / 2)) - data->hor.x) / cos(degrees * M_PI / 180));
		pt_v = fabs(((double)(data->pos.y * SIZE + (SIZE / 2)) - data->ver.y) / sin(degrees * M_PI / 180));
		fprintf(stderr, "fabs ==> pt_h = %f | pt_v = %f\n", pt_h, pt_v);
	}
	// if (i == 263 && j == 254)
	// {
	// 	init_i = i + 1;
	// 	init_j = j + 1;
	// 	while (i <= init_i + 1)
	// 	{
	// 		j = init_j - 1;
	// 		while (j <= init_j + 1)
	// 		{
	// 			mlx_pixel_put(data->mlx, data->win, \
	// 			i, j, 0X0000FF7F);
	// 			j++;
	// 		}
	// 		i++;
	// 	}
	// }
	bresenham(data, i, j);
	// fprintf(stderr, "pt_h = %f | pt_v = %f\n", pt_h, pt_v);
	// fprintf(stderr, "pt_hy = %f | pt_vy = %f\n", pt_hy, pt_vy);
	// if (i == -1 || j == -1)
	// 	return ;
	// init_i = i + 1;
	// init_j = j + 1;
	// while (i <= init_i + 1)
	// {
	// 	j = init_j - 1;
	// 	while (j <= init_j + 1)
	// 	{
	// 		mlx_pixel_put(data->mlx, data->win, \
	// 		i, j, 0X0000FF7F);
	// 		j++;
	// 	}
	// 	i++;
	// }
}

void	ft_fov(t_data *data)
{
	double	initial_degrees;
	int		result;
	int		nb_ray;

	nb_ray = 0;
	initial_degrees = data->degrees;
	if (data->degrees == 0.0)
		data->degrees = 360.0;
	result = (int)(initial_degrees - 30) % 360;
	if (result < 0)
		result += 360;
	while (data->degrees > result)
	{
		find_h_intersection(data, data->degrees);
		finding_v_intersection(data, data->degrees);
		data->degrees -= (60/10);
		nb_ray++;
		draw_point(data, data->degrees);
	}
	data->degrees = initial_degrees;
	while (data->degrees < ((int)(initial_degrees + 30) % 360))
	{
		find_h_intersection(data, data->degrees);
		finding_v_intersection(data, data->degrees);
		data->degrees += (60/10);
		nb_ray++;
		draw_point(data, data->degrees);
	}
	fprintf(stderr, "nb_ray = %d\n", nb_ray);
	data->degrees = initial_degrees;
}
