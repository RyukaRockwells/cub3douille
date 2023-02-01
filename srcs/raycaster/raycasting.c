/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanauth <sanauth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:10:40 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/02/01 16:24:46 by sanauth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	finding_h_intersection(t_data *data)
{
	double	ay;
	double	ax;
	int		i;
	int		j;

	fprintf(stderr, "Formule\n");
	fprintf(stderr, "A.y = rounded_down(Py/32) * (32) - 1\n");
	ay = floor((data->pos.y * SIZE) / SIZE) * (SIZE) - 1;
	fprintf(stderr, "Formule\n");
	fprintf(stderr, "A.x = Px + (Py-A.y)/tan(ALPHA)\n");
	ax = (data->pos.x * SIZE) + ((data->pos.y * SIZE) - ay) / tan(60 * (PI / 180));
	fprintf(stderr, "ax = %f | ay = %f\n", ax, ay);
	fprintf(stderr, "coord = %d, %d\n", (int)(ay / SIZE), (int)(ax / SIZE));
	//show result in map
	i = ax - 1;
	while (i <= ax + 1)
	{
		j = ay - 1;
		while (j <= ay + 1)
		{
			mlx_pixel_put(data->mlx, data->win, \
			i, j, 0x00DC140C);
			j++;
		}
		i++;
	}
	fprintf(stderr, "char = %c\n%s\n", data->map[10][26], data->map[10]);
	// i = (int)(ax / SIZE);
	// j = (int)(ay / SIZE);
	// if (data->map[i][j] == '0')
	// 	fprintf(stderr, "Nothing\n");
	// else if (data->map[i][j] == '1')
	// 	fprintf(stderr, "It's a wall\n");
	// i = ax;
	// j = ay;
	// fprintf(stderr, "p.x = %f | p.y = %f\n", data->pos.x * SIZE, data->pos.y * SIZE);
	// fprintf(stderr, "ax = %f | ay = %f\n", ax, ay);
	// while (i != (data->pos.x * SIZE) && j != (data->pos.y * SIZE))
	// {
	// 	mlx_pixel_put(data->mlx, data->win, \
	// 	i, j, 0x00DC143C);
	// 	if (i != (data->pos.x * SIZE))
	// 		i--;
	// 	if (j != (data->pos.y * SIZE))
	// 		j--;
	// }
}

