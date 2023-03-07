/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_the_struct_for_render.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:44:37 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/03/07 13:30:58 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

//Pour afficher la vision joueur
//mettre en arg de la fonction t_data *data
//et mettre avant return :

t_fov	fill_the_struct_for_render(double rad, double d, char i, t_coord *coord)
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
	return (fov);
}
