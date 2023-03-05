/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendernorm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:21:20 by sanauth           #+#    #+#             */
/*   Updated: 2023/03/05 11:50:59 by nchow-yu         ###   ########.fr       */
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
	double	wall_height;
	double	wall_pixel_start;
	int		i;

	i = 1;
	(void)fov;
	ft_put_3d(data);
	while (i < 640)
	{
		fov[i].dist = fov[i].dist * cos((fov[i].degrees - \
			(data->rad * (180 / M_PI))) * (M_PI / 180));
		wall_height = ft_calculate_wall_heigth(fov[i].dist);
		wall_pixel_start = \
		ft_define_wall_pixel_start(wall_height);
		ft_write_wall(data, fov, wall_pixel_start, wall_height, i);
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->render.img, 0, 0);
}
