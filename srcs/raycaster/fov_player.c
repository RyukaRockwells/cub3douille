/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fov_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:05:02 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/02/20 19:30:59 by nchow-yu         ###   ########.fr       */
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
		mlx_pixel_put(data->mlx, data->win, x, y, 0x0000F0FF);
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

static void	draw_point(t_data *data, int degrees, t_ver *ver, t_hor *hor)
{
	double		i;
	double		j;
	int		init_i;
	int		init_j;
	double	pt_h;
	double	pt_v;

	(void)degrees;
	fprintf(stderr, "hor - x = %f | y = %f\n", hor->x, hor->y);
	fprintf(stderr, "ver - x = %f | y = %f\n\n", ver->x, ver->y);
	// if ((ver->x == -1 && ver->y == -1) || (hor->x == -1 && hor->y == -1))
	// 	return ;
	// if ((int)degrees % 90 == 0)
	// {
	pt_h = sqrt(pow(((data->pos.x * SIZE) - hor->x), 2) + pow(((data->pos.y * SIZE) - hor->y), 2));
	pt_v = sqrt(pow(((data->pos.x * SIZE) - ver->x), 2) + pow(((data->pos.y * SIZE) - ver->y), 2));
	// }
	// else
	// {
	// 	pt_h = fabs(((double)(data->pos.x * SIZE + (SIZE / 2)) - data->hor.x) / cos(degrees * M_PI / 180));
	// 	pt_v = fabs(((double)(data->pos.y * SIZE + (SIZE / 2)) - data->ver.y) / sin(degrees * M_PI / 180));
	// }
	if (pt_h > pt_v || (hor->x == -1 && hor->y == -1))
	{
		i = ver->x;
		j = ver->y;
	}
	else
	{
		i = hor->x;
		j = hor->y;
	}
	bresenham(data, i, j);
	init_i = i + 1;
	init_j = j + 1;
	while (i <= init_i + 1)
	{
		j = init_j - 1;
		while (j <= init_j + 1)
		{
			mlx_pixel_put(data->mlx, data->win, \
			i, j, 0X00A52A2A);
			j++;
		}
		i++;
	}
}

void	ft_fov(t_data *data)
{
	t_ver	ver;
	t_hor	hor;
	double	initial_degrees;
	int		result;
	int		nb_ray;

	nb_ray = 0;
	initial_degrees = data->degrees;
	if (data->degrees == 0.0)
		data->degrees = 360.0;
	fprintf(stderr, "degrees = %f\n", data->degrees);
	result = (int)(initial_degrees - 30) % 360;
	if (result < 0)
		result += 360;
	while (data->degrees > result)
	{
		hor = find_h_intersection(data, data->degrees);
		ver = finding_v_intersection(data, data->degrees);
		draw_point(data, data->degrees, &ver, &hor);
		data->degrees -= 0.09375;
		nb_ray++;
	}
	data->degrees = initial_degrees;
	while (data->degrees < ((int)(initial_degrees + 30) % 360))
	{
		hor = find_h_intersection(data, data->degrees);
		ver = finding_v_intersection(data, data->degrees);
		draw_point(data, data->degrees, &ver, &hor);
		data->degrees += 0.09375;
		nb_ray++;
	}
	fprintf(stderr, "nb_ray = %d\n", nb_ray);
	data->degrees = initial_degrees;
}
