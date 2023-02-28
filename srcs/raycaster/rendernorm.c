/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendernorm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanauth <sanauth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:21:20 by sanauth           #+#    #+#             */
/*   Updated: 2023/02/28 11:21:21 by sanauth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	*ft_tab_test(void)
{
	int	*tab;
	int	i;
	int	j;

	tab = malloc(sizeof(int) * 640);
	if (tab == NULL)
		return (NULL);
	i = 0;
	j = 6000;
	while (i < 200)
	{
		tab[i] = j;
		i++;
		j += 0;
	}	
	while (i >= 200 && i < 400)
	{
		tab[i] = j;
		i++;
		j -= 50;
	}
	j = j + 2000;
	while (i >= 400 && i < 600)
	{
		tab[i] = j;
		i++;
		j += 35;
	}
	while (i >= 600 && i < 640)
	{
		tab[i] = j;
		i++;
		j -= 20;
	}
	return (tab);
}

void	ft_start_draw(t_data *data)
{
	int	wall_height;
	int	wall_pixel_start;
	int	i;
	int	*tab;

	tab = ft_tab_test(); // a remplacer par tableau de rayons
	i = 0;
	ft_put_3d(data);
	while (i < 640)
	{
		wall_height = ft_calculate_wall_heigth(tab[i], wall_height, i);
		wall_pixel_start = \
		ft_define_wall_pixel_start(wall_height, wall_pixel_start);
		ft_write_wall(data, wall_pixel_start, wall_height, i);
		i++;
	}
	free(tab);
	mlx_put_image_to_window(data->mlx, data->win, data->new_img, 0, 0);
}

int	ft_calculate_wall_heigth(int wall_dist, int wall_height, int column)
{
	int		proj_width;
	int		fov;
	int		proj_dist;
	float	angle;
	float	corrected_dist;

	proj_width = 640;
	fov = 60;
	proj_dist = ((proj_width / 2) / tan((fov / 2) * (M_PI / 180)));
	angle = atan2(column - (WIDTH / 2), proj_dist);
	corrected_dist = wall_dist / cos(angle * (M_PI / 180));
	wall_height = (corrected_dist * SIZE) / proj_dist;
	return (wall_height);
}

int	ft_define_wall_pixel_start(int wall_height, int wall_pixel_start)
{
	int	proj_height;

	proj_height = 400;
	wall_pixel_start = (proj_height / 2) - (wall_height / 2);
	return (wall_pixel_start);
}
