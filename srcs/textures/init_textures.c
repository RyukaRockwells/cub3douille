/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:23:10 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/01/25 18:48:55 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_textures(t_data *data)
{
	data->textures[0].img = mlx_xpm_file_to_image(data->mlx, \
	data->params.north, &data->textures[0].x, &data->textures[0].y);
	if (data->textures[0].img == NULL)
		error_xpm_to_img(data);
	data->textures[1].img = mlx_xpm_file_to_image(data->mlx, \
	data->params.south, &data->textures[1].x, &data->textures[1].y);
	if (data->textures[1].img == NULL)
		error_xpm_to_img(data);
	data->textures[2].img = mlx_xpm_file_to_image(data->mlx, data->params.west, \
	&data->textures[2].x, &data->textures[2].y);
	if (data->textures[2].img == NULL)
		error_xpm_to_img(data);
	data->textures[3].img = mlx_xpm_file_to_image(data->mlx, data->params.east, \
	&data->textures[3].x, &data->textures[3].y);
	if (data->textures[3].img == NULL)
		error_xpm_to_img(data);
}
