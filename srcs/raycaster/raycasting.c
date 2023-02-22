/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:10:40 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/02/22 20:24:24 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_hor	find_h_intersection(t_data *data, double degrees)
{
	t_hor	hor;
	double	old_x;
	double	old_y;
	double	delta_x;
	double	ya;
	double	i;
	double	j;

	if (degrees > 0.0 && degrees < 180.0)
		hor.y = floor(data->pos.y) * (SIZE) + SIZE;
	else
		hor.y = floor(data->pos.y) * (SIZE) - 1;
	hor.x = (data->pos.x * SIZE) + (hor.y - (data->pos.y * SIZE)) / tan(degrees * (M_PI / 180));
	if (hor.x >= ((data->max_len - 1) * SIZE) || hor.y >= ((data->nb_line - 1) * SIZE)
		|| hor.x <= 0 || hor.y <= 0)
	{
		// fprintf(stderr, "hor - x = %f | y = %f\n", hor.x, hor.y);
		// fprintf(stderr, "hor - degrees = %f\n", degrees);
		hor.x = -1;
		hor.y = -1;
		return (hor);
	}
	while ((data->map[(int)(round(hor.y * 100 / SIZE) / 100)][(int)(round(hor.x * 100 / SIZE) / 100)] != '1')
		&& data->map[(int)(round(hor.y * 100 / SIZE) / 100)][(int)(round(hor.x * 100 / SIZE) / 100)] != ' ')
	{
		old_x = hor.x;
		old_y = hor.y;
		if (degrees > 0.0 && degrees < 180.0)
			ya = SIZE;
		else
			ya = -SIZE;
		delta_x = (ya - 1) / tan(degrees * (M_PI / 180));
		hor.x = old_x + delta_x;
		hor.y = old_y + ya;
		if (hor.x >= ((data->max_len - 1) * SIZE)
			|| hor.y >= ((data->nb_line - 1) * SIZE)
			|| hor.x < 0 || hor.y < 0)
			break ;
	}
	i = hor.x - 1;
	j = hor.y - 1;
	while (i <= hor.x + 1)
	{
		j = hor.y - 1;
		while (j <= hor.y + 1)
		{
			mlx_pixel_put(data->mlx, data->win, \
			i, j, 0x00F4A460);
			j++;
		}
		i++;
	}
	return (hor);
}

t_ver	finding_v_intersection(t_data *data, double degrees)
{
	t_ver	ver;
	double	xa;
	double	ya;
	double	last_x;
	double	last_y;
	double	i;
	double	j;

	if ((degrees < 90.0) || (degrees > 270.0))
		ver.x = floor(data->pos.x) * (SIZE) + SIZE;
	else
		ver.x = floor(data->pos.x) * (SIZE) - 1;
	ver.y = (data->pos.y * SIZE) + (ver.x - (data->pos.x * SIZE)) * tan(degrees * (M_PI / 180));
	if ((ver.y >= (data->nb_line - 1) * SIZE) || (ver.x >= (data->max_len - 1) * SIZE)
		|| ver.x <= 0 || ver.y <= 0)
	{
		// fprintf(stderr, "ver - x = %f | y = %f\n", ver.x, ver.y);
		// fprintf(stderr, "ver - degrees = %f\n", degrees);		
		ver.x = -1;
		ver.y = -1;
		return (ver);
	}
	while ((data->map[(int)(round(ver.y * 100) / 100) / SIZE][(int)(round(ver.x * 100) / 100) / SIZE] != '1')
		&& data->map[(int)(round(ver.y * 100) / 100) / SIZE][(int)(round(ver.x * 100) / 100) / SIZE] != ' ')
	{
		last_x = ver.x;
		last_y = ver.y;
		if ((degrees < 90.0) || (degrees > 270.0))
			xa = SIZE;
		else
			xa = -SIZE;
		ya = (xa - 1) * tan(degrees * (M_PI / 180));
		ver.y = last_y + ya;
		ver.x = last_x + xa;
		if ((ver.y >= (data->nb_line - 1) * SIZE) || (ver.x >= (data->max_len - 1) * SIZE)
			|| ver.y < 0 || ver.x < 0)
			break ;
	}
	i = ver.x - 1;
	j = ver.y - 1;
	while (i <= ver.x + 1)
	{
		j = ver.y - 1;
		while (j <= ver.y + 1)
		{
			mlx_pixel_put(data->mlx, data->win, \
			i, j, 0x00F5F5F5);
			j++;
		}
		i++;
	}
	return (ver);
}
