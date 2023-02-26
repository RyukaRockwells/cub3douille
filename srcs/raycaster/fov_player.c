/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fov_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:05:02 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/02/25 13:29:39 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	draw_point(t_data *data, double i, double j)
{
	double	init_i;
	double	init_j;

	init_i = i;
	init_j = j;
	i -= 2;
	j -= 2;
	while (i <= init_i + 2)
	{
		j = init_j - 2;
		while (j <= init_j + 2)
			mlx_pixel_put(data->mlx, data->win, i, j++, 0xFFFFFFFF);
		i++;
	}
}

static void	choose_pointtodist(t_data *data, t_ver *ver, t_hor *hor)
{
	double		i;
	double		j;
	double		dist_h;
	double		dist_v;

	dist_h = sqrt(pow(((data->pos.x * SIZE) - hor->x), 2) \
		+ pow(((data->pos.y * SIZE) - hor->y), 2));
	dist_v = sqrt(pow(((data->pos.x * SIZE) - ver->x), 2) \
		+ pow(((data->pos.y * SIZE) - ver->y), 2));
	if ((ver->x != -1 && ver->y != -1)
		&& (dist_h >= dist_v || (hor->x == -1 && hor->y == -1)))
	{
		i = ver->x;
		j = ver->y;
	}
	else if ((hor->x != -1 && hor->y != -1)
		&& (dist_v >= dist_h || (ver->x == -1 && ver->y == -1)))
	{
		i = hor->x;
		j = hor->y;
	}
	else
		return ;
	draw_point(data, i, j);
}

static void	call_ft_for_dist(t_data *data)
{
	t_ver	ver;
	t_hor	hor;

	hor = find_h_intersection(data, data->rad);
	ver = finding_v_intersection(data, data->rad);
	choose_pointtodist(data, &ver, &hor);
}

void	ft_fov(t_data *data)
{
	double	initial_rad;
	double	result;

	initial_rad = data->rad;
	if (data->rad == 0.0)
		data->rad = M_PI * 2;
	result = (initial_rad - 0.523599);
	if (result < 0)
		result += M_PI * 2;
	fprintf(stderr, "min = %f\n", result * (180 / M_PI));
	while (data->rad > result)
	{
		call_ft_for_dist(data);
		data->rad -= 0.00327249;
	}
	data->rad = initial_rad;
	result = (initial_rad + 0.523599);
	if (result > 6.2832)
		result -= M_PI * 2;
	fprintf(stderr, "min = %f\n", result * (180 / M_PI));
	while (data->rad < result)
	{
		call_ft_for_dist(data);
		data->rad += 0.00327249;
	}
	data->rad = initial_rad;
	fprintf(stderr, "degrees = %f\n", data->rad * (180 / M_PI));
}
