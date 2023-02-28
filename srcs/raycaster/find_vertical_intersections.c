/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_vertical_intersections.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:10:38 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/02/27 16:38:47 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_ver	first_point_ray(t_data *data, double rad)
{
	t_ver	ver;

	if (rad < (M_PI / 2) || rad > (M_PI * 1.5))
		ver.x = floor(data->pos.x) * (SIZE) + SIZE;
	else
		ver.x = floor(data->pos.x) * (SIZE) - 1;
	ver.y = (data->pos.y * SIZE) + (ver.x - (data->pos.x * SIZE)) * tan(rad);
	if ((ver.y >= (data->nb_line - 1) * SIZE)
		|| (ver.x >= (data->max_len - 1) * SIZE)
		|| ver.x <= 0 || ver.y <= 0)
	{	
		ver.x = -1;
		ver.y = -1;
	}
	return (ver);
}

static t_ver	next_intersection(t_ver ver, double rad)
{
	double	delta_x;
	double	delta_y;
	double	last_x;
	double	last_y;

	last_x = ver.x;
	last_y = ver.y;
	if (rad < (M_PI / 2) || rad > (M_PI * 1.5))
		delta_x = SIZE;
	else
		delta_x = -SIZE;
	delta_y = delta_x * tan(rad);
	ver.y = last_y + delta_y;
	ver.x = last_x + delta_x;
	return (ver);
}

t_ver	finding_v_intersection(t_data *data, double rad)
{
	t_ver	ver;

	ver = first_point_ray(data, rad);
	if (ver.x == -1 && ver.y == -1)
		return (ver);
	while ((data->map[(int)(round(ver.y * 1000) / 1000) / SIZE] \
		[(int)(round(ver.x * 1000) / 1000) / SIZE] != '1')
		&& data->map[(int)(round(ver.y * 1000) / 1000) / SIZE] \
		[(int)(round(ver.x * 1000) / 1000) / SIZE] != ' ')
	{
		ver = next_intersection(ver, rad);
		if ((ver.y >= (data->nb_line - 1) * SIZE)
			|| (ver.x >= (data->max_len - 1) * SIZE)
			|| ver.y < 0 || ver.x < 0)
			break ;
	}
	return (ver);
}
