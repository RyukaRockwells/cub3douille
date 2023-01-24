/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:43:09 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/01/24 12:53:26 by nchow-yu         ###   ########.fr       */
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
}
