/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fov_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:05:02 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/02/24 13:00:07 by nchow-yu         ###   ########.fr       */
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

	hor = find_h_intersection(data, data->degrees);
	ver = finding_v_intersection(data, data->degrees);
	choose_pointtodist(data, &ver, &hor);
}

void	ft_fov(t_data *data)
{
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
		call_ft_for_dist(data);
		data->degrees -= 0.00327249;
	}
	data->degrees = initial_degrees;
	while (data->degrees < (initial_degrees + 0.523599))
	{
		call_ft_for_dist(data);
		data->degrees += 0.00327249;
	}
}
