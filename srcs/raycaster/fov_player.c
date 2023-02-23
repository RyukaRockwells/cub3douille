/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fov_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:05:02 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/02/23 13:31:35 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// static double	ft_absolute(double nb)
// {
// 	if (nb < 0)
// 		return (-nb);
// 	return (nb);
// }

// static void	bresenham_we(t_data *data, double d_x, double d_y)
// {
// 	double	decision;
// 	double	x;
// 	double	y;
// 	double	diff_x;
// 	double	diff_y;
// 	// double	i;
// 	// double	j;

// 	diff_x = ft_absolute(d_x - (data->pos.x * SIZE));
// 	diff_y = ft_absolute(d_y - (data->pos.y * SIZE));
// 	x = (data->pos.x * SIZE);
// 	y = (data->pos.y * SIZE);
// 	decision = 2 * diff_y - diff_x;
// 	if (x <= d_x)
// 	{
// 		while (x <= d_x)
// 		{
// 			mlx_pixel_put(data->mlx, data->win, x, y, 0x0000F0FF);
// 			if (decision <= 0)
// 				decision += (2 * diff_y);
// 			else
// 			{
// 				decision += (2 * (diff_y - diff_x));
// 				if (d_y > (data->pos.y * SIZE))
// 					y += 1;
// 				else
// 					y += -1;
// 			}
// 			x++;
// 		}
// 	}
// 	else if (x >= d_x)
// 	{
// 		while (x >= d_x)
// 		{
// 			mlx_pixel_put(data->mlx, data->win, x, y, 0x0000F0FF);
// 			if (decision <= 0)
// 				decision += (2 * diff_y);
// 			else
// 			{
// 				decision += (2 * (diff_y - diff_x));
// 				if (d_y > (data->pos.y * SIZE))
// 					y += 1;
// 				else
// 					y += -1;
// 			}
// 			x--;
// 		}
// 	}
// 	// i = d_x - 1;
// 	// j = d_y - 1;
// 	// while (i <= d_x + 1)
// 	// {
// 	// 	j = d_y - 1;
// 	// 	while (j <= d_y + 1)
// 	// 	{
// 	// 		mlx_pixel_put(data->mlx, data->win, \
// 	// 		i, j, 0xFFF00FFF);
// 	// 		j++;
// 	// 	}
// 	// 	i++;
// 	// }
// }

// static void	bresenham_ns(t_data *data, double d_x, double d_y)
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
// 	if (y <= d_y)
// 	{
// 		while (y <= d_y)
// 		{
// 			mlx_pixel_put(data->mlx, data->win, x, y, 0x0000F0FF);
// 			if (decision <= 0)
// 				decision += (2 * diff_x);
// 			else
// 			{
// 				decision += (2 * (diff_x - diff_y));
// 				if (d_x > (data->pos.x * SIZE))
// 					x += 1;
// 				else
// 					x += -1;
// 			}
// 			y++;
// 		}
// 	}
// 	else if (y >= d_y)
// 	{
// 		while (y >= d_y)
// 		{
// 			mlx_pixel_put(data->mlx, data->win, x, y, 0x0000F0FF);
// 			if (decision <= 0)
// 				decision += (2 * diff_x);
// 			else
// 			{
// 				decision += (2 * (diff_x - diff_y));
// 				if (d_x > (data->pos.x * SIZE))
// 					x += 1;
// 				else
// 					x += -1;
// 			}
// 			y--;
// 		}
// 	}
// }

static void	draw_point(t_data *data, double degrees, t_ver *ver, t_hor *hor)
{
	double		i;
	double		j;
	// int		tmp_i;
	// int		tmp_j;
	double	dist_h;
	double	dist_v;

	// (void)degrees;
	fprintf(stderr, "draw hor - x = %f | y = %f | degrees = %f\n", hor->x, hor->y, degrees);
	// fprintf(stderr, "draw ver - x = %f | y = %f\n", ver->x, ver->y);
	// fprintf(stderr, "hor - x = %f | y = %f\n", hor->x, hor->y);
	// // fprintf(stderr, "ver - x = %f | y = %f\n\n", ver->x, ver->y);
	// dist_h = sqrt(pow(((data->pos.x * SIZE) - hor->x), 2) + pow(((data->pos.y * SIZE) - hor->y), 2));
	// dist_v = sqrt(pow(((data->pos.x * SIZE) - ver->x), 2) + pow(((data->pos.y * SIZE) - ver->y), 2));
	dist_h = fabs((hor->x - (data->pos.x * SIZE))) / cos(degrees * (M_PI / 180));
	dist_v = fabs((ver->y - (data->pos.y * SIZE))) / sin(degrees * (M_PI / 180));
	fprintf(stderr, "permadi java = (%f - %f) * %f ", hor->x, (data->pos.x * SIZE), cos(degrees * (M_PI / 180)));
	fprintf(stderr, "= %f\n", (hor->x - (data->pos.x * SIZE)) * (1.0f / cos(degrees * (M_PI / 180))));
	fprintf(stderr, "dist_h = %f | dist_v = %f\n\n", dist_h, dist_v);
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
	{
		fprintf(stderr, "no show\n");
		return ;
	}
	// if (degrees >= 0 && degrees <= 180)
	// 	bresenham_ns(data, i, j);
	// else
	// 	bresenham_we(data, i, j);
	// tmp_i = i - 1;
	// tmp_j = j - 1;
	// while (tmp_i <= i + 1)
	// {
	// 	tmp_j = j - 1;
	// 	while (tmp_j <= j + 1)
	// 	{
	// 		mlx_pixel_put(data->mlx, data->win, \
	// 		tmp_i, tmp_j, 0X00A52A2A);
	// 		tmp_j++;
	// 	}
	// 	tmp_i++;
	// }
 	mlx_pixel_put(data->mlx, data->win, i, j, 0xFFFFFFFF);
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
	// fprintf(stderr, "degrees = %f\n", data->degrees);
	result = (int)(initial_degrees - 30);
	if (result < 0)
		result += 360;
	while (data->degrees > 0)
	{
		data->degrees = 5.8447;
		hor = find_h_intersection(data, data->degrees);
		ver = finding_v_intersection(data, data->degrees);
		draw_point(data, data->degrees, &ver, &hor);
		data->degrees -= 0.1875;
		nb_ray++;
		return ;
	}
	// data->degrees = initial_degrees;
	// while (data->degrees < ((int)(initial_degrees + 30)))
	// {
	// 	hor = find_h_intersection(data, data->degrees);
	// 	ver = finding_v_intersection(data, data->degrees);
	// 	draw_point(data, data->degrees, &ver, &hor);
	// 	data->degrees += 0.1875;
	// 	nb_ray++;
	// 	// return ;
	// }
	fprintf(stderr, "nb_ray = %d\n", nb_ray);
	data->degrees = initial_degrees;
}
