/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_ft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:44:24 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/02/28 10:46:54 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	move_to_left_right(t_data *data, int key)
{
	if (key == 'a'
		&& data->map[(int)(data->pos.y - ((cos(data->rad) * 10) / SIZE))] \
		[(int)(data->pos.x + ((sin(data->rad) * 10) / SIZE))] != '1')
	{
		data->pos.x += (sin(data->rad) * 10) / SIZE;
		data->pos.y -= (cos(data->rad) * 10) / SIZE;
	}
	else if (key == 'd'
		&& data->map[(int)(data->pos.y + ((cos(data->rad) * 10) / SIZE))] \
		[(int)(data->pos.x - ((sin(data->rad) * 10) / SIZE))] != '1')
	{
		data->pos.x -= (sin(data->rad) * 10) / SIZE;
		data->pos.y += (cos(data->rad) * 10) / SIZE;
	}
}

void	move_player(int key, t_data *data)
{
	if (key == 'w'
		&& data->map[(int)(data->pos.y + ((sin(data->rad) * 10) / SIZE))] \
		[(int)(data->pos.x + ((cos(data->rad) * 10) / SIZE))] != '1')
	{
		data->pos.x += (cos(data->rad) * 10) / SIZE;
		data->pos.y += (sin(data->rad) * 10) / SIZE;
	}
	else if (key == 's'
		&& data->map[(int)(data->pos.y - ((sin(data->rad) * 10) / SIZE))] \
		[(int)(data->pos.x - ((cos(data->rad) * 10) / SIZE))] != '1')
	{
		data->pos.x -= (cos(data->rad) * 10) / SIZE;
		data->pos.y -= (sin(data->rad) * 10) / SIZE;
	}
	move_to_left_right(data, key);
}
