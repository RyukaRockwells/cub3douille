/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_the_struct_for_render.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:44:37 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/02/28 10:43:17 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	fill_the_struct_for_render(double rad, double dist, char intersect)
{
	t_fov	fov;

	fov.degrees = rad * (180 / M_PI);
	fov.dist = dist;
	if (intersect == 'H')
	{
		if (rad > 0.0 && rad < M_PI)
			fov.wall_orientation = 'S';
		else
			fov.wall_orientation = 'N';
	}
	else if (intersect == 'V')
	{
		if (rad < (M_PI / 2) || rad > (M_PI * 1.5))
			fov.wall_orientation = 'E';
		else
			fov.wall_orientation = 'W';
	}
	else
		return ;
}
//Je dois le mettre dans un tableau
//Relire le sujet
