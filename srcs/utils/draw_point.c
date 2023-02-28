/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:14:13 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/02/28 11:14:42 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_point(t_data *data, double i, double j)
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

