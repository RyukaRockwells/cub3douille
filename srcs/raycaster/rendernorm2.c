/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendernorm2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:21:16 by sanauth           #+#    #+#             */
/*   Updated: 2023/03/05 11:43:23 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/struct.h"

void	ft_put_3d(t_data *data)
{
	int	x;
	int	y;
	int	color;
	int	color2;

	x = 0;
	y = 0;
	color = 0x87CEEB;
	color2 = 0x484473;
	data->buffer = NULL;
	data->new_img = mlx_new_image(data->mlx, WIDTH, HEIGTH);
	data->buffer = mlx_get_data_addr(data->new_img, &data->bpp, \
	&data->nb_line_map, &data->endian);
	ft_write_sky(data, x, y);
	ft_write_floor(data, x, y);
}
