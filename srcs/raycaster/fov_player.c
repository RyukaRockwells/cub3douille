/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fov_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:05:02 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/02/18 18:09:56 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	draw_point(t_data *data)
{
	int		i;
	int		j;
	int		init_i;
	int		init_j;
	double	pt_h;
	double	pt_v;

	pt_h = sqrt(pow((data->pos.x * SIZE) - data->hor.x, 2) + pow((data->pos.y * SIZE) - data->hor.y, 2));
	pt_v = sqrt(pow((data->pos.x * SIZE) - data->ver.x, 2) + pow((data->pos.y * SIZE) - data->ver.y, 2));
	if (pt_h > pt_v)
	{
		i = data->ver.x - 1;
		j = data->ver.y - 1;
	}
	else
	{
		i = data->hor.x - 1;
		j = data->hor.y - 1;
	}
	if (i == -1 || j == -1)
		return ;
	init_i = i + 1;
	init_j = j + 1;
	while (i <= init_i + 1)
	{
		j = init_j - 1;
		while (j <= init_j + 1)
		{
			mlx_pixel_put(data->mlx, data->win, \
			i, j, 0X0000FF7F);
			j++;
		}
		i++;
	}
}

void	ft_fov(t_data *data)
{
	double	initial_degrees;
	int		result;

	initial_degrees = data->degrees;
	if (data->degrees == 0.0)
		data->degrees = 360.0;
	result = (int)(initial_degrees - 30) % 360;
	if (result < 0)
		result += 360;
	while (data->degrees > result)
	{
		find_h_intersection(data, data->degrees);
		finding_v_intersection(data, data->degrees);
		data->degrees -= 0.09375;
		draw_point(data);
	}
	data->degrees = initial_degrees;
	while (data->degrees < ((int)(initial_degrees + 30) % 360))
	{
		find_h_intersection(data, data->degrees);
		finding_v_intersection(data, data->degrees);
		data->degrees += 0.09375;
		draw_point(data);
	}
	data->degrees = initial_degrees;
}
