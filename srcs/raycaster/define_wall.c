/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanauth <sanauth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:43:09 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/03/05 10:46:00 by sanauth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

//hauteur de la map = data->nb_line
//hauteur de la map en pixel data->nb_line * SIZE
//largeur de la map = data->max_len
//largeur de la map en pixel = data->max_len * SIZE
//SIZE = 64;

float ft_find_wall(t_data *data, float x_point, float y_point, t_fov *fov, int i)
{
	float wall_start;
	float wall_end;
	float wall_diff;
	(void) data;
	if (fov[i].wall_orientation == 'N' || fov[i].wall_orientation == 'S')
	{
		wall_start = floor(x_point / SIZE);
		wall_end = ceil(x_point / SIZE);
		wall_diff = ((x_point - (wall_start * SIZE)) / SIZE);
	}
	else
	{
		wall_start = floor(y_point / SIZE);
		wall_end = ceil(y_point /  SIZE);
		wall_diff = ((y_point - (wall_start * SIZE)) / SIZE);
	}
	//printf("wall_start= %f, wall_diff = %f\n", wall_start, wall_diff);
	return (wall_diff);
}



