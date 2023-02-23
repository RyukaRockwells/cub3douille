/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:10:40 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/02/23 16:12:26 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_hor	first_point_ray(t_data *data, double rad)
{
	t_hor	hor;

	if (rad > 0.0 && rad < M_PI)
		hor.y = floor(data->pos.y) * (SIZE) + SIZE;
	else
		hor.y = floor(data->pos.y) * (SIZE) - 1;
	hor.x = (data->pos.x * SIZE) + (hor.y - (data->pos.y * SIZE)) / tan(rad);
	if (hor.x >= ((data->max_len - 1) * SIZE) || hor.y >= ((data->nb_line - 1) * SIZE)
		|| hor.x <= 0 || hor.y <= 0)
	{
		hor.x = -1;
		hor.y = -1;
		return (hor);
	}
	return (hor);
}

t_hor	find_h_intersection(t_data *data, double rad)
{
	t_hor	hor;
	double	old_x;
	double	old_y;
	double	delta_x;
	double	delta_y;

	hor = first_point_ray(data, rad);
	if (hor.x == -1 && hor.y == -1)
		return (hor);
	while ((data->map[(int)(round(hor.y * 1000 / SIZE) / 1000)][(int)(round(hor.x * 1000 / SIZE) / 1000)] != '1')
		&& data->map[(int)(round(hor.y * 1000 / SIZE) / 1000)][(int)(round(hor.x * 1000 / SIZE) / 1000)] != ' ')
	{
		old_x = hor.x;
		old_y = hor.y;
		if (rad > 0.0 && rad < M_PI)
			delta_y = SIZE;
		else
			delta_y = -SIZE;
		delta_x = delta_y / tan(rad);
		hor.x = old_x + delta_x;
		hor.y = old_y + delta_y;
		if (hor.x >= ((data->max_len - 1) * SIZE)
			|| hor.y >= ((data->nb_line - 1) * SIZE)
			|| hor.x < 0 || hor.y < 0)
			break ;
	}
	return (hor);
}

t_ver	finding_v_intersection(t_data *data, double rad)
{
	t_ver	ver;
	double	delta_x;
	double	delta_y;
	double	last_x;
	double	last_y;

	if ((rad < (M_PI / 2)) || (rad > (M_PI * 1.5)))
		ver.x = floor(data->pos.x) * (SIZE) + SIZE;
	else
		ver.x = floor(data->pos.x) * (SIZE) - 1;
	ver.y = (data->pos.y * SIZE) + (ver.x - (data->pos.x * SIZE)) * tan(rad);
	if ((ver.y >= (data->nb_line - 1) * SIZE) || (ver.x >= (data->max_len - 1) * SIZE)
		|| ver.x <= 0 || ver.y <= 0)
	{	
		ver.x = -1;
		ver.y = -1;
		return (ver);
	}
	while ((data->map[(int)(round(ver.y * 1000) / 1000) / SIZE][(int)(round(ver.x * 1000) / 1000) / SIZE] != '1')
		&& data->map[(int)(round(ver.y * 1000) / 1000) / SIZE][(int)(round(ver.x * 1000) / 1000) / SIZE] != ' ')
	{
		last_x = ver.x;
		last_y = ver.y;
		if ((rad < (M_PI / 2)) || (rad > (M_PI * 1.5)))
			delta_x = SIZE;
		else
			delta_x = -SIZE;
		delta_y = delta_x * tan(rad);
		ver.y = last_y + delta_y;
		ver.x = last_x + delta_x;
		if ((ver.y >= (data->nb_line - 1) * SIZE) || (ver.x >= (data->max_len - 1) * SIZE)
			|| ver.y < 0 || ver.x < 0)
			break ;
	}
	return (ver);
}
