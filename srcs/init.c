/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:43:09 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/01/25 19:50:22 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_struct(t_data *data)
{
	data->params.north = NULL;
	data->params.south = NULL;
	data->params.west = NULL;
	data->params.east = NULL;
	data->params.floor = NULL;
	data->params.ceiling = NULL;
}

void	init_window(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		ft_close(data);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGTH, "Cub3D");
	if (data->win == NULL)
	{
		free(data->mlx);
		ft_close(data);
	}
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGTH);
}

void	init_pos_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i] != NULL)
	{
		j = 0;
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
				|| data->map[i][j] == 'W' || data->map[i][j] == 'E')
			{
				data->pos.x = j + 0.5;
				data->pos.y = i + 0.5;
			}
			j++;
		}
		i++;
	}
}
