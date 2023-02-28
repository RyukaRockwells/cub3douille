/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fov_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:05:02 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/02/28 11:05:09 by nchow-yu         ###   ########.fr       */
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

//for norme remove line 61
static void	choose_pointtodist(t_data *data, t_ver *ver, t_hor *hor, double rad)
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
		fill_the_struct_for_render(rad, dist_v, 'V');
	}
	else if ((hor->x != -1 && hor->y != -1)
		&& (dist_v >= dist_h || (ver->x == -1 && ver->y == -1)))
	{
		i = hor->x;
		j = hor->y;
		fill_the_struct_for_render(rad, dist_h, 'H');
	}
	else
		return ;
	draw_point(data, i, j);
}

static void	call_ft_for_dist(t_data *data, double rad)
{
	t_ver	ver;
	t_hor	hor;

	hor = find_h_intersection(data, rad);
	ver = finding_v_intersection(data, rad);
	choose_pointtodist(data, &ver, &hor, rad);
}

static void	check_all_left_intersect(t_data *data)
{
	double	tmp_rad;
	double	res;

	tmp_rad = data->rad;
	res = (data->rad - 0.523599);
	if (res < 0)
	{
		tmp_rad += M_PI * 2;
		res += M_PI * 2;
	}
	while (tmp_rad > res)
	{
		call_ft_for_dist(data, tmp_rad);
		tmp_rad -= 0.00327249;
	}
}

void	ft_fov(t_data *data)
{
	double	tmp_rad;
	double	result;

	check_all_left_intersect(data);
	tmp_rad = data->rad;
	result = (data->rad + 0.523599);
	if (result > 6.2832)
	{
		tmp_rad -= M_PI * 2;
		result -= M_PI * 2;
	}
	while (tmp_rad < result)
	{
		call_ft_for_dist(data, tmp_rad);
		tmp_rad += 0.00327249;
	}
}
