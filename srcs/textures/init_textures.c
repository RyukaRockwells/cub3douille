/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:23:10 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/03/04 13:35:06 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	fill_in_struct_addr_img(t_data *data)
{
	data->textures[0].addr = mlx_get_data_addr(data->textures[0].img, \
		&data->textures[0].bpp, &data->textures[0].line_size, \
		&data->textures[0].endian);
	data->textures[1].addr = mlx_get_data_addr(data->textures[1].img, \
		&data->textures[1].bpp, &data->textures[1].line_size, \
		&data->textures[1].endian);
	data->textures[2].addr = mlx_get_data_addr(data->textures[2].img, \
		&data->textures[2].bpp, &data->textures[2].line_size, \
		&data->textures[2].endian);
	data->textures[3].addr = mlx_get_data_addr(data->textures[3].img, \
		&data->textures[3].bpp, &data->textures[3].line_size, \
		&data->textures[3].endian);
}

void	init_textures(t_data *data)
{
	data->textures[0].img = mlx_xpm_file_to_image(data->mlx, \
	data->params.north, &data->textures[0].width, &data->textures[0].height);
	if (data->textures[0].img == NULL)
		error_xpm_to_img(data);
	data->textures[1].img = mlx_xpm_file_to_image(data->mlx, \
	data->params.south, &data->textures[1].width, &data->textures[1].height);
	if (data->textures[1].img == NULL)
		error_xpm_to_img(data);
	data->textures[2].img = mlx_xpm_file_to_image(data->mlx, data->params.west, \
	&data->textures[2].width, &data->textures[2].height);
	if (data->textures[2].img == NULL)
		error_xpm_to_img(data);
	data->textures[3].img = mlx_xpm_file_to_image(data->mlx, data->params.east, \
	&data->textures[3].width, &data->textures[3].height);
	if (data->textures[3].img == NULL)
		error_xpm_to_img(data);
	fill_in_struct_addr_img(data);
}
