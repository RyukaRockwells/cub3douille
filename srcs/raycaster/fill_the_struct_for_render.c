/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_the_struct_for_render.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:44:37 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/03/06 22:27:00 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

//Pour afficher la vision joueur
//mettre en arg de la fonction t_data *data
//et mettre avant return :

t_fov	fill_the_struct_for_render(t_data *data, double rad, double d, char i, t_coord *coord)
{
	t_fov	fov;

	fov.degrees = rad * (180 / M_PI);
	fov.dist = d;
	fov.x = coord->x;
	fov.y = coord->y;
	fov.wall_orientation = '\0';
	if (i == 'H')
	{
		if (fmod(rad, M_PI * 2) > 0.0 && fmod(rad, M_PI * 2) < M_PI)
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
	draw_point(data, (coord->x / SIZE) * 5, (coord->y / SIZE) * 5, 0x000000);
	return (fov);
}
