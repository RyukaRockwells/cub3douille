/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fov_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:05:02 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/03/04 19:47:15 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

//for norme remove line 61
static t_fov	choose_dist(t_data *data, t_coord *v, t_coord *h, double rad)
{
	double		d_h;
	double		d_v;
	t_fov		fov;

	fov.degrees = 0;
	fov.dist = 0;
	fov.x = 0.0;
	fov.y = 0.0;
	fov.wall_orientation = '\0';
	d_h = sqrt(pow(((data->pos.x * SIZE) - h->x), 2) \
		+ pow(((data->pos.y * SIZE) - h->y), 2));
	d_v = sqrt(pow(((data->pos.x * SIZE) - v->x), 2) \
		+ pow(((data->pos.y * SIZE) - v->y), 2));
	if ((v->x != -1 && v->y != -1)
		&& (d_h >= d_v || (h->x == -1 && h->y == -1)))
		fov = fill_the_struct_for_render(rad, d_v, 'V', v, data);
	else if ((h->x != -1 && h->y != -1)
		&& (d_v >= d_h || (v->x == -1 && v->y == -1)))
		fov = fill_the_struct_for_render(rad, d_h, 'H', h, data);
	return (fov);
}

static t_fov	call_ft_for_dist(t_data *data, double rad)
{
	t_coord	ver;
	t_coord	hor;
	t_fov	fov;

	hor = find_h_intersection(data, rad);
	ver = finding_v_intersection(data, rad);
	fov = choose_dist(data, &ver, &hor, rad);
	return (fov);
}

static t_fov	*check_all_left_intersect(t_data *data, t_fov *fov)
{
	double	tmp_rad;
	double	res;
	int		i;

	i = 319;
	tmp_rad = data->rad;
	res = (data->rad - 0.523599);
	if (res < 0)
	{
		tmp_rad += M_PI * 2;
		res += M_PI * 2;
	}
	while (tmp_rad > res)
	{
		fov[i] = call_ft_for_dist(data, fmod(tmp_rad, M_PI * 2));
		tmp_rad -= 0.00163625;
		i--;
	}
	return (fov);
}

t_fov	*ft_fov(t_data *data)
{
	double	tmp_rad;
	double	result;
	t_fov	*fov;
	int		i;

	fov = malloc(sizeof(t_fov) * WIDTH);
	fov = check_all_left_intersect(data, fov);
	tmp_rad = data->rad;
	result = (data->rad + 0.523599);
	if (result > 6.2832)
	{
		tmp_rad -= M_PI * 2;
		result -= M_PI * 2;
	}
	i = 320;
	while (tmp_rad < result)
	{
		fov[i] = call_ft_for_dist(data, fmod(tmp_rad, M_PI * 2));
		tmp_rad += 0.00163625;
		i++;
	}
	return (fov);
}
