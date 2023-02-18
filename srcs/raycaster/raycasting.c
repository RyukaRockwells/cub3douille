/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:10:40 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/02/18 12:23:36 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// static double	ft_absolute(double nb)
// {
// 	if (nb < 0)
// 		return (-nb);
// 	return (nb);
// }

// static void	bresenham(t_data *data, double d_x, double d_y)
// {
// 	double	decision;
// 	double	x;
// 	double	y;
// 	double	diff_x;
// 	double	diff_y;

// 	diff_x = ft_absolute(d_x - (data->pos.x * SIZE));
// 	diff_y = ft_absolute(d_y - (data->pos.y * SIZE));
// 	x = (data->pos.x * SIZE);
// 	y = (data->pos.y * SIZE);
// 	decision = 2 * diff_y - diff_x;
// 	while (x <= d_x)
// 	{
// 		mlx_pixel_put(data->mlx, data->win, x, y, 0x00FF00);
// 		if (decision <= 0)
// 			decision += (2 * diff_y);
// 		else
// 		{
// 			decision += (2 * (diff_y - diff_x));
// 			if (d_y > (data->pos.y * SIZE))
// 				y += 1;
// 			else
// 				y += -1;
// 		}
// 		x++;
// 	}
// }

void	find_h_intersection(t_data *data, double degrees)
{
	double	ax;
	double	ay;
	double	old_x;
	double	old_y;
	double	next_x;
	double	ya;
	// double		i;
	// double		j;

	if (degrees == 180.0 || degrees == 90.0
		|| degrees == 270.0 || degrees == 0.0)
		return ;
	else if (degrees >= 0.1 && degrees <= 179.9)
		ay = floor(data->pos.y) * (SIZE) - 0.00001;
	else if (degrees >= 181.0 && degrees <= 360.0)
		ay = floor(data->pos.y) * (SIZE) + SIZE;
	else
		return ;
	ax = (data->pos.x * SIZE) + (ay - (data->pos.y * SIZE)) / tan(degrees * (M_PI / 180));
	if (ax >= ((data->max_len - 1) * SIZE) || ay >= ((data->nb_line - 1) * SIZE)
		|| ax <= 0 || ay <= 0)
		return ;
	while ((data->map[(int)ay / SIZE][(int)ax / SIZE] != '1'
		&& data->map[(int)ay / SIZE][(int)ax / SIZE] != ' '))
	{
		// i = ax - 1;
		// while (i <= ax + 1)
		// {
		// 	j = ay - 1;
		// 	while (j <= ay + 1)
		// 	{
		// 		mlx_pixel_put(data->mlx, data->win, \
		// 		i, j, 0x00006400);
		// 		j++;
		// 	}
		// 	i++;
		// }
		old_x = ax;
		old_y = ay;
		if (degrees >= 0.1 && degrees <= 179.9)
			ya = -SIZE;
		else if (degrees >= 181.0 && degrees <= 360.0)
			ya = SIZE;
		next_x = (ya - 1) / tan(degrees * (M_PI / 180));
		ax = old_x + next_x;
		ay = old_y + ya;
		if (ax < 0 || ay < 0)
			break ;
	}
	data->hor.x = ax;
	data->hor.y = ay;
	old_x = ax;
	old_y = ay;
	//bresenham(data, old_x, old_y);
	// i = old_x - 1;
	// j = old_y - 1;
	// while (i <= old_x + 1)
	// {
	// 	j = old_y - 1;
	// 	while (j <= old_y + 1)
	// 	{
	// 		mlx_pixel_put(data->mlx, data->win, \
	// 		i, j, 0x00F4A460);
	// 		j++;
	// 	}
	// 	i++;
	// }
}

void	finding_v_intersection(t_data *data, double degrees, int color_in, int color_out)
{
	double	bx;
	double	by;
	double	xa;
	double	ya;
	double	last_x;
	double	last_y;
	// int		i;
	// int		j;

	if (degrees == 180.0 || degrees == 90.0
		|| degrees == 270.0 || degrees == 0.0)
		return ;
	else if ((degrees >= 0.0 && degrees <= 90.0) || (degrees >= 360.0 && degrees >= 270.0))
		bx = floor(data->pos.x) * (SIZE) - 0.00001;
	else if (degrees >= 90.0 && degrees <= 270.0)
		bx = floor(data->pos.x) * (SIZE) + SIZE;
	else
		return ;
	by = (data->pos.y * SIZE) + (bx - (data->pos.x * SIZE)) * tan(degrees * (M_PI / 180));
	if ((by > (data->nb_line - 1) * SIZE) || (bx > (data->max_len - 1) * SIZE)
		|| bx <= 0 || by <= 0)
		return ;
	while ((data->map[(int)by / SIZE][(int)bx / SIZE] != '1')
		&& data->map[(int)by / SIZE][(int)bx / SIZE] != ' ')
	{
		// i = bx - 1;
		// while (i <= bx + 1)
		// {
		// 	j = by - 1;
		// 	while (j <= by + 1)
		// 	{
		// 		mlx_pixel_put(data->mlx, data->win, \
		// 		i, j, color_in);
		// 		j++;
		// 	}
		// 	i++;
		// }
		last_x = bx;
		last_y = by;
		if ((degrees >= 0.0 && degrees <= 90.0) || (degrees >= 360.0 && degrees >= 270.0))
			xa = -SIZE;
		else if (degrees >= 90.0 && degrees <= 270.0)
			xa = SIZE;
		ya = (xa - 1) * tan(degrees * (M_PI / 180));
		by = last_y + ya;
		bx = last_x + xa;
		if (by < 0 || bx < 0)
			break ;
	}
	data->ver.x = bx;
	data->ver.y = by;
	last_x = bx;
	last_y = by;
	//bresenham(data, last_x, last_y);
	// i = last_x - 1;
	// while (i <= last_x + 1)
	// {
	// 	j = last_y - 1;
	// 	while (j <= last_y + 1)
	// 	{
	// 		mlx_pixel_put(data->mlx, data->win, \
	// 		i, j, color_out);
	// 		j++;
	// 	}
	// 	i++;
	// }
	(void)color_in;
	(void)color_out;
}
/*
void bresenham(void *mlx, void *win, int x0, int y0, int x1, int y1)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int x = x0;
    int y = y0;
    int d = 2 * dy - dx;
    int incrE = 2 * dy;
    int incrNE = 2 * (dy - dx);

    while (x <= x1)
    {
        mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
        if (d <= 0)
        {
            d += incrE;
            x++;
        }
        else
        {
            d += incrNE;
            x++;
            y += (y1 > y0 ? 1 : -1);
        }
    }
}

Steps of finding intersections with vertical grid lines:

    Find coordinate of the first intersection (point B in this example).
    The ray is facing right in the picture, so B.x = rounded_down(Px/64) * (64) + 64.
    If the ray had been facing left B.x = rounded_down(Px/64) * (64) – 1.
    A.y = Py + (Px-A.x)*tan(ALPHA);
    Find Xa. (Note: Xa is just the width of the grid; however, if the ray is facing right, Xa will be positive, if the ray is facing left, Ya will be negative.)
    Find Ya using the equation given above.
    Check the grid at the intersection point. If there is a wall on the grid, stop and calculate the distance.
    If there is no wall, extend the to the next intersection point. Notice that the coordinate of the next intersection point -call it (Xnew,Ynew) is just Xnew=Xold+Xa, and Ynew=YOld+Ya.
	














	
	A.x = Px + (Py-A.y)/tan(ALPHA); - HORIZONTALE
	A.y = Py + (Px-A.x)*tan(ALPHA); - VERTICALE

	ax = (data->pos.x * SIZE) + ((data->pos.y * SIZE) - ay) / tan(degrees * (PI / 180));
	ay = (data->pos.y * SIZE) + ((data->pos.x * SIZE) - ax) * tan(degrees * (PI / 180));
	

*/
