/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_ft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:44:24 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/03/07 19:48:25 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	check_hit_move(t_data *data, double x, double y)
{
	double	hit_box1[2];
	double	hit_box2[2];
	double	hit_box3[2];
	double	hit_box4[2];

	hit_box1[0] = x - HITBOX_LEN;
	hit_box1[1] = y - HITBOX_LEN;
	hit_box2[0] = x + HITBOX_LEN;
	hit_box2[1] = y - HITBOX_LEN;
	hit_box3[0] = x + HITBOX_LEN;
	hit_box3[1] = y + HITBOX_LEN;
	hit_box4[0] = x - HITBOX_LEN;
	hit_box4[1] = y + HITBOX_LEN;
	if (data->map[(int)floor(hit_box1[1])][(int)floor(hit_box1[0])] == '1')
		return (1);
	if (data->map[(int)floor(hit_box2[1])][(int)floor(hit_box2[0])] == '1')
		return (1);
	if (data->map[(int)floor(hit_box3[1])][(int)floor(hit_box3[0])] == '1')
		return (1);
	if (data->map[(int)floor(hit_box4[1])][(int)floor(hit_box4[0])] == '1')
		return (1);
	return (0);
}

static void	move_to_left_right(t_data *data, int key)
{
	if (key == 'a'
		&& check_hit_move(data, data->pos.x + (sin(data->rad) * 10) / SIZE, \
		data->pos.y - (cos(data->rad) * 10) / SIZE) == 0)
	{
		data->pos.x += (sin(data->rad) * 10) / SIZE;
		data->pos.y -= (cos(data->rad) * 10) / SIZE;
	}
	else if (key == 'd'
		&& check_hit_move(data, data->pos.x - (sin(data->rad) * 10) / SIZE, \
		data->pos.y + (cos(data->rad) * 10) / SIZE) == 0)
	{
		data->pos.x -= (sin(data->rad) * 10) / SIZE;
		data->pos.y += (cos(data->rad) * 10) / SIZE;
	}
}

void	move_player(int key, t_data *data)
{
	if (key == 'w'
		&& check_hit_move(data, data->pos.x + (cos(data->rad) * 10) / SIZE, \
		data->pos.y + (sin(data->rad) * 10) / SIZE) == 0)
	{
		data->pos.x += (cos(data->rad) * 10) / SIZE;
		data->pos.y += (sin(data->rad) * 10) / SIZE;
	}
	else if (key == 's'
		&& check_hit_move(data, data->pos.x - (cos(data->rad) * 10) / SIZE, \
		data->pos.y - (sin(data->rad) * 10) / SIZE) == 0)
	{
		data->pos.x -= (cos(data->rad) * 10) / SIZE;
		data->pos.y -= (sin(data->rad) * 10) / SIZE;
	}
	move_to_left_right(data, key);
}
