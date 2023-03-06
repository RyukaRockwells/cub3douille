/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:27:52 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/03/06 19:36:33 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ft_destroy_all_img(t_data *data)
{
	if (data->textures[0].img != NULL)
		mlx_destroy_image(data->mlx, data->textures[0].img);
	if (data->textures[1].img != NULL)
		mlx_destroy_image(data->mlx, data->textures[1].img);
	if (data->textures[2].img != NULL)
		mlx_destroy_image(data->mlx, data->textures[2].img);
	if (data->textures[3].img != NULL)
		mlx_destroy_image(data->mlx, data->textures[3].img);
	if (data->render.img != NULL)
		mlx_destroy_image(data->mlx, data->render.img);
}

void	ft_close(t_data *data)
{
	if (data->fov != NULL)
		free(data->fov);
	ft_free_str(data->map);
	ft_destroy_all_img(data);
	mlx_clear_window(data->mlx, data->win);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	ft_free_all_params(data);
	free(data->mlx);
	data->mlx = NULL;
	ft_free_str(data->file);
	exit(EXIT_SUCCESS);
}
