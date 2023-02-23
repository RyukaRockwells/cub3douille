/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fov_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:05:02 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/02/23 18:00:38 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	bresenham(t_data *data, double d_x, double d_y)
{
	double	dist_x;
	double	dist_y;
	double	x;
	double	y;
	double	x_inc;
	double	y_inc;
	double	error;
	double	error_bis;

	dist_x = d_x - (data->pos.x * SIZE);
	dist_y = d_y - (data->pos.y * SIZE);
	x = data->pos.x * SIZE;
	y = data->pos.y * SIZE;
	if (d_x > data->pos.x)
		x_inc = 1;
	else
		x_inc = -1;
	if (d_y > data->pos.y)
		y_inc = 1;
	else
		y_inc = -1;
	error = 0;
	error_bis = 0;
	// while 
}

static void	draw_point(t_data *data, t_ver *ver, t_hor *hor)
{
	double		i;
	double		j;
	double		dist_h;
	double		dist_v;

	dist_h = sqrt(pow(((data->pos.x * SIZE) - hor->x), 2) + pow(((data->pos.y * SIZE) - hor->y), 2));
	dist_v = sqrt(pow(((data->pos.x * SIZE) - ver->x), 2) + pow(((data->pos.y * SIZE) - ver->y), 2));
	if ((ver->x != -1 && ver->y != -1) && (dist_h >= dist_v || (hor->x == -1 && hor->y == -1)))
	{
		i = ver->x;
		j = ver->y;
	}
	else if ((hor->x != -1 && hor->y != -1) && (dist_v >= dist_h || (ver->x == -1 && ver->y == -1)))
	{
		i = hor->x;
		j = hor->y;
	}
	else
		return ;
	bresenham(data, i, j);
 	mlx_pixel_put(data->mlx, data->win, i, j, 0xFFFFFFFF);
}

void	ft_fov(t_data *data)
{
	t_ver	ver;
	t_hor	hor;
	double	initial_degrees;
	double	result;

	initial_degrees = data->degrees;
	if (data->degrees == 0.0)
		data->degrees = M_PI * 2;
	result = (initial_degrees - 0.523599);
	if (result < 0)
		result += M_PI * 2;
	while (data->degrees > result)
	{
		hor = find_h_intersection(data, data->degrees);
		ver = finding_v_intersection(data, data->degrees);
		draw_point(data, &ver, &hor);
		data->degrees -= 0.00327249;
	}
	data->degrees = initial_degrees;
	while (data->degrees < (initial_degrees + 0.523599))
	{
		hor = find_h_intersection(data, data->degrees);
		ver = finding_v_intersection(data, data->degrees);
		draw_point(data, &ver, &hor);
		data->degrees += 0.00327249;
	}
}
