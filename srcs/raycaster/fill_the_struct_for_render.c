/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_the_struct_for_render.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:44:37 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/03/02 16:35:10 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_fov	fill_the_struct_for_render(double rad, double d, char i, t_coord *coord, t_data *data)
{
	t_fov	fov;

	fov.degrees = rad * (180 / M_PI);
	fov.dist = d;
	fov.x = coord->x;
	fov.y = corrd->y;
	fov.wall_orientation = '\0';
	if (i == 'H')
	{
		if (rad > 0.0 && rad < M_PI)
			fov.wall_orientation = 'S';
		else
			fov.wall_orientation = 'N';
	}
	else if (i == 'V')
	{
		if (rad < (M_PI / 2) || rad > (M_PI * 1.5))
			fov.wall_orientation = 'E';
		else
			fov.wall_orientation = 'W';
	}
	draw_point(data, coord->x, coord->y);
	return (fov);
}
//Je dois le mettre dans un tableau
//Relire le sujet!!!!!!


//if you want to see fov, add in choose_dist:
/*
	t_coord	*point;

	point.x = v.x / h.x;
	point.y = v.y / h.y;
	draw_point(data, point.x, point.y);
*/
