/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:10:40 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/02/24 12:19:57 by nchow-yu         ###   ########.fr       */
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
	if (hor.x >= ((data->max_len - 1) * SIZE)
		|| hor.y >= ((data->nb_line - 1) * SIZE)
		|| hor.x <= 0 || hor.y <= 0)
	{
		hor.x = -1;
		hor.y = -1;
	}
	return (hor);
}

static t_hor	next_intersection(t_hor hor, double rad)
{
	double	old_x;
	double	old_y;
	double	delta_x;
	double	delta_y;

	old_x = hor.x;
	old_y = hor.y;
	if (rad > 0.0 && rad < M_PI)
		delta_y = SIZE;
	else
		delta_y = -SIZE;
	delta_x = delta_y / tan(rad);
	hor.x = old_x + delta_x;
	hor.y = old_y + delta_y;
	return (hor);
}

t_hor	find_h_intersection(t_data *data, double rad)
{
	t_hor	hor;

	hor = first_point_ray(data, rad);
	if (hor.x == -1 && hor.y == -1)
		return (hor);
	while ((data->map[(int)(round(hor.y * 1000 / SIZE) / 1000)] \
		[(int)(round(hor.x * 1000 / SIZE) / 1000)] != '1')
		&& data->map[(int)(round(hor.y * 1000 / SIZE) / 1000)] \
		[(int)(round(hor.x * 1000 / SIZE) / 1000)] != ' ')
	{
		hor = next_intersection(hor, rad);
		if (hor.x >= ((data->max_len - 1) * SIZE)
			|| hor.y >= ((data->nb_line - 1) * SIZE)
			|| hor.x < 0 || hor.y < 0)
			break ;
	}
	return (hor);
}
