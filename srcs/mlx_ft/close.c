/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:27:52 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/01/25 18:56:31 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_close(t_data *data)
{
	ft_free_str(data->map);
	mlx_destroy_image(data->mlx, data->img.img);
	mlx_destroy_image(data->mlx, data->textures[0].img);
	mlx_destroy_image(data->mlx, data->textures[1].img);
	mlx_destroy_image(data->mlx, data->textures[2].img);
	mlx_destroy_image(data->mlx, data->textures[3].img);
	mlx_clear_window(data->mlx, data->win);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	ft_free_all_params(data);
	free(data->mlx);
	data->mlx = NULL;
	ft_free_str(data->file);
	exit(EXIT_SUCCESS);
}
