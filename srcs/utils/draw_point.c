/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:14:13 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/03/06 22:26:06 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <X11/Xlib.h>
#include "../../mlx_linux/mlx_int.h"

void	draw_point(t_data *data, double i, double j, int color)
{
	double	init_i;
	double	init_j;

	init_i = i;
	init_j = j;
	i -= 1;
	j -= 1;
	while (i <= init_i + 1)
	{
		j = init_j - 1;
		while (j <= init_j + 1)
			mlx_pixel_put(data->mlx, data->win, i, j++, color);
		i++;
	}
	XFlush(((t_xvar *)data->mlx)->display);
}
