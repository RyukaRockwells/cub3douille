/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendernorm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanauth <sanauth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:21:20 by sanauth           #+#    #+#             */
/*   Updated: 2023/03/06 13:39:57 by sanauth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static double	ft_calculate_wall_heigth(double wall_dist)
{
	double	wall_height;

	wall_height = (double)(HEIGTH / wall_dist)*SIZE;
	return (wall_height);
}

static double	ft_define_wall_pixel_start(double wall_height)
{
	double	wall_pixel_start;

	wall_pixel_start = (HEIGTH / 2) - (wall_height / 2);
	if (wall_pixel_start < 0)
		wall_pixel_start = 0;
	return (wall_pixel_start);
}

void	ft_start_draw(t_data *data, t_fov *fov)
{
	data->col = 0;
	(void)fov;
	ft_put_3d(data);
	while (data->col < 640)
	{
		fov[data->col].dist = fov[data->col].dist * \
		cos((fov[data->col].degrees - \
		(data->rad * (180 / M_PI))) * (M_PI / 180));
		data->wall_height = ft_calculate_wall_heigth(fov[data->col].dist);
		data->pxl_start = \
		ft_define_wall_pixel_start(data->wall_height);
		ft_write_wall(data, fov);
		data->col++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->render.img, 0, 0);
}

void	ft_fill_buffer(t_data *data, int txt_index, t_imge *text_choose)
{
	data->render.addr[((int)data->pxl_start * data->render.line_size) + \
	(data->col * 4)] = text_choose->addr[(txt_index * text_choose->bpp) / 8];
	data->render.addr[((int)data->pxl_start * data->render.line_size) + \
	(data->col * 4) + 1] = \
	text_choose->addr[(txt_index * text_choose->bpp) / 8 + 1];
	data->render.addr[((int)data->pxl_start * data->render.line_size) + \
	(data->col * 4) + 2] = \
	text_choose->addr[(txt_index * text_choose->bpp) / 8 + 2];
	data->render.addr[((int)data->pxl_start * data->render.line_size) + \
	(data->col * 4) + 3] = (char)0;
}
