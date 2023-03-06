/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:13:21 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/03/06 20:17:20 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	p_mini_map(t_data *data)
{
	int	i;
	int	j;

	i = (data->pos.x * 5);
	while (i <= (data->pos.x * 5))
	{
		j = (data->pos.y * 5);
		while (j <= (data->pos.y * 5))
		{
			mlx_pixel_put(data->mlx, data->win, \
			i, j, 0xff0000);
			j++;
		}
		i++;
	}
}

static int	ft_is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

static void	draw_wall_mini_map(t_data *data, int x, int y)
{
	int	initial_x;
	int	initial_y;

	initial_x = x;
	initial_y = y;
	while (y < (initial_y + 5))
	{
		while (x < (initial_x + 5))
		{
			mlx_pixel_put(data->mlx, data->win, x, y, 0x00FF6800);
			x++;
		}
		x = initial_x;
		y++;
	}
}

static void	draw_other_elmt_map(t_data *data, int x, int y)
{
	int	initial_x;
	int	initial_y;

	initial_x = x;
	initial_y = y;
	while (y < (initial_y + 5))
	{
		mlx_pixel_put(data->mlx, data->win, x, y, 0x00FF6800);
		y++;
	}
	y = initial_y;
	while (x < (initial_x + 5))
	{
		mlx_pixel_put(data->mlx, data->win, x, y, 0x00FF6800);
		x++;
	}
}

void	draw_mini_map(t_data *data)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (data->map[i] != NULL)
	{
		x = 0;
		j = 0;
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] == '1')
				draw_wall_mini_map(data, x, y);
			if (data->map[i][j] == '0' || ft_is_player(data->map[i][j]) == 1)
				draw_other_elmt_map(data, x, y);
			x += 5;
			j++;
		}
		y += 5;
		i++;
	}
}
