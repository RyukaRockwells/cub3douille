/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:10:40 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/02/19 23:13:22 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	find_h_intersection(t_data *data, double degrees)
{
	double	ax;
	double	ay;
	double	old_x;
	double	old_y;
	double	next_x;
	double	ya;

	if (degrees == 90.0 || degrees == 180.0 || degrees == 270.0)
		return ;
	else if (degrees >= 0.1 && degrees <= 179.9)
		ay = floor(data->pos.y) * (SIZE) - 0.00001;
	else if (degrees >= 181.0 && degrees <= 360.0)
		ay = floor(data->pos.y) * (SIZE) + SIZE;
	else
		return ;
	ax = (data->pos.x * SIZE) + (ay - (data->pos.y * SIZE)) / tan(degrees * (M_PI / 180));
	fprintf(stderr, "\ndegrees = %f | ax = %f | ay = %f\n", degrees, ax, ay);
	if (ax >= ((data->max_len - 1) * SIZE) || ay >= ((data->nb_line - 1) * SIZE)
		|| ax <= 0 || ay <= 0)
		return ;
	if (degrees == 90.0)
		fprintf(stderr, "Je suis pile poil au milieu\n");
	while ((data->map[(int)ay / SIZE][(int)ax / SIZE] != '1'
		&& data->map[(int)ay / SIZE][(int)ax / SIZE] != ' '))
	{
		old_x = ax;
		old_y = ay;
		if (degrees >= 0.1 && degrees <= 179.9)
			ya = -SIZE;
		else if (degrees >= 181.0 && degrees <= 360.0)
			ya = SIZE;
		next_x = (ya - 1) / tan(degrees * (M_PI / 180));
		ax = old_x + next_x;
		ay = old_y + ya;
		if (ax >= ((data->max_len - 1) * SIZE) || ay >= ((data->nb_line - 1) * SIZE)
			|| ax < 0 || ay < 0)
			break ;
	}
	data->hor.x = ax;
	data->hor.y = ay;
}

void	finding_v_intersection(t_data *data, double degrees)
{
	double	bx;
	double	by;
	double	xa;
	double	ya;
	double	last_x;
	double	last_y;

	if (degrees == 90.0 || degrees == 180.0 || degrees == 270.0)
		return ;
	else if ((degrees >= 0.0 && degrees <= 90.0) || (degrees >= 270.0 && degrees <= 360.0))
		bx = floor(data->pos.x) * (SIZE) - 0.00001;
	else if (degrees >= 90.0 && degrees <= 270.0)
		bx = floor(data->pos.x) * (SIZE) + SIZE;
	else
		return ;
	by = (data->pos.y * SIZE) + (bx - (data->pos.x * SIZE)) * tan(degrees * (M_PI / 180));
	if ((by >= (data->nb_line - 1) * SIZE) || (bx >= (data->max_len - 1) * SIZE)
		|| bx <= 0 || by <= 0)
		return ;
	while ((data->map[(int)by / SIZE][(int)bx / SIZE] != '1')
		&& data->map[(int)by / SIZE][(int)bx / SIZE] != ' ')
	{
		last_x = bx;
		last_y = by;
		if ((degrees >= 0.0 && degrees <= 90.0) || (degrees >= 270.0 && degrees <= 360.0))
			xa = -SIZE;
		else if (degrees >= 90.0 && degrees <= 270.0)
			xa = SIZE;
		ya = (xa - 1) * tan(degrees * (M_PI / 180));
		by = last_y + ya;
		bx = last_x + xa;
		if ((by >= (data->nb_line - 1) * SIZE) || (bx >= (data->max_len - 1) * SIZE)
			|| by < 0 || bx < 0)
			break ;
	}
	data->ver.x = bx;
	data->ver.y = by;
}
