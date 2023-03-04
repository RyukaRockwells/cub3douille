/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_horizontal_intersections.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:10:40 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/03/04 19:46:21 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_coord	set_hor_at_neg(t_coord hor)
{
	hor.x = -1;
	hor.y = -1;
	return (hor);
}

static t_coord	first_point_ray(t_data *data, double rad)
{
	t_coord	hor;

	if (fmod(rad, M_PI * 2) > 0.0 && fmod(rad, M_PI * 2) < M_PI)
	{
		hor.y = floor(data->pos.y) * (SIZE) + SIZE;
		hor.x = (data->pos.x * SIZE) + \
			((hor.y - (data->pos.y * SIZE)) / tan(rad));
	}
	else
	{
		hor.y = floor(data->pos.y) * (SIZE) - 1;
		hor.x = (data->pos.x * SIZE) + \
			(((hor.y + 1) - (data->pos.y * SIZE)) / tan(rad));
	}
	if (hor.x >= ((maplenmax(data->map) - 1) * SIZE)
		|| hor.y >= ((mapline(data->map) - 1) * SIZE)
		|| hor.x <= 0 || hor.y <= 0)
		hor = set_hor_at_neg(hor);
	return (hor);
}

static t_coord	next_intersection_hor(t_coord hor, double rad)
{
	double	old_x;
	double	old_y;
	double	delta_x;
	double	delta_y;

	old_x = hor.x;
	old_y = hor.y;
	if (fmod(rad, M_PI * 2) > 0.0 && fmod(rad, M_PI * 2) < M_PI)
		delta_y = SIZE;
	else
		delta_y = -SIZE;
	delta_x = delta_y / tan(rad);
	hor.x = old_x + delta_x;
	hor.y = old_y + delta_y;
	return (hor);
}

t_coord	find_h_intersection(t_data *data, double rad)
{
	t_coord	hor;

	if (fmod(rad, M_PI * 2) == 0.0 || fmod(rad, M_PI * 2) == M_PI)
	{
		hor.x = -1;
		hor.y = -1;
		return (hor);
	}
	hor = first_point_ray(data, rad);
	if (hor.x == -1 && hor.y == -1)
		return (hor);
	while ((data->map[(int)(hor.y / SIZE)] \
		[(int)(hor.x / SIZE)] != '1')
		&& data->map[(int)(hor.y / SIZE)] \
		[(int)(hor.x / SIZE)] != ' ')
	{
		hor = next_intersection_hor(hor, rad);
		if (hor.x >= ((maplenmax(data->map) - 1) * SIZE)
			|| hor.y >= ((mapline(data->map) - 1) * SIZE)
			|| hor.x < 0 || hor.y < 0)
			break ;
	}
	return (hor);
}
