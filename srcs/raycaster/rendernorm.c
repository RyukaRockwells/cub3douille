/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendernorm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanauth <sanauth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:21:20 by sanauth           #+#    #+#             */
/*   Updated: 2023/03/01 09:59:05 by sanauth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/struct.h"

void	ft_start_draw(t_data *data, t_fov *fov)
{
	double	wall_height;
	double	wall_pixel_start;
	int		i;

	i = 1;
	ft_put_3d(data);
	while (i < 640)
	{
		wall_height = ft_calculate_wall_heigth(fov[i].dist, fov[i].degrees, i);
		wall_pixel_start = \
		ft_define_wall_pixel_start(wall_height);
		ft_choose_texture(data, fov[i].wall_orientation);
		ft_write_wall(data, wall_pixel_start, wall_height, i);
		i++;
	}
	free(fov);
	mlx_put_image_to_window(data->mlx, data->win, data->new_img, 0, 0);
}


/*int	ft_calculate_wall_heigth(int wall_dist, int column)
{
	int		proj_width;
	int		proj_dist;
	int		wall_height;
	//float	angle;
	//float	corrected_dist;

(void)(column);
	wall_dist = wall_dist * 15;
	proj_width = 640;
	proj_dist = ((proj_width / 2) / tan((FOV / 2) * (M_PI / 180)));
	//angle = atan2(column - (WIDTH / 2), proj_dist);
	//corrected_dist = wall_dist / cos(angle * (M_PI / 180));
	wall_height = (wall_dist * SIZE) / proj_dist;
	return (wall_height);
}*/

double	ft_define_wall_pixel_start(double wall_height)
{
	double	wall_pixel_start;

	wall_pixel_start = (HEIGTH / 2) - (wall_height / 2);
	if (wall_pixel_start < 0)
		wall_pixel_start = 0;
	return (wall_pixel_start);
}

double	ft_calculate_wall_heigth(double wall_dist, double degree, int column)
{
	double	wall_height;

(void)(column);
	(void)(degree);
	//if (column < 320)
	//	degree = 180 - degree;
	//else
	//	degree = 540 - degree;
	//wall_dist = tan(degree) * (WIDTH / 2);
	//wall_dist = (WIDTH * WIDTH / 4) + (wall_dist * wall_dist);
	//wall_dist = sqrt(wall_dist);
	printf("wall dist = %f\n", wall_dist);
	wall_height = ((HEIGTH) *64 / (wall_dist));
	printf("wall height = %f\n", wall_height);
	return (wall_height);
}
