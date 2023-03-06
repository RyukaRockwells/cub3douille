/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendernorm2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:21:16 by sanauth           #+#    #+#             */
/*   Updated: 2023/03/06 18:22:24 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	ft_put_3d(t_data *data)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (data->render.img == NULL)
		data->render.img = mlx_new_image(data->mlx, WIDTH, HEIGTH);
	data->render.addr = mlx_get_data_addr(data->render.img, &data->render.bpp, \
	&data->render.line_size, &data->render.endian);
	ft_write_sky(data, x, y);
	ft_write_floor(data, x, HEIGTH / 2);
}
