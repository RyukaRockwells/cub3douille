/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendernorm2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:21:16 by sanauth           #+#    #+#             */
/*   Updated: 2023/03/04 17:21:15 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	ft_put_3d(t_data *data)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	data->render.img = mlx_new_image(data->mlx, WIDTH, HEIGTH);
	data->render.addr = mlx_get_data_addr(data->render.img, &data->render.bpp, \
	&data->render.line_size, &data->render.endian);
	ft_write_sky(data, x, y);
	ft_write_floor(data, x, HEIGTH / 2);
}

// char	*load_texture(t_data *data, t_fov *fov, int column)
// {
// 	char	*texture_data;
// 	char	*filename;

// 	filename = ft_choose_texture(data, fov, column);
// 	data->texture.img = NULL;
// 	data->texture.img = mlx_xpm_file_to_image(data->mlx,
// 	filename, &data->texture.txt_width, &data->texture.txt_height);
// 	if (!data->texture.img)
// 		return (NULL);
// 	texture_data = mlx_get_data_addr(data->texture.img,
// 	&data->texture.txt_bpp, &data->texture.txt_line_size,
// 	&data->texture.txt_endian);
// 	if (!texture_data)
// 	{
// 		mlx_destroy_image(data->mlx, data->texture.img);
// 		return (NULL);
// 	}
// 	return (texture_data);
// }
// char	*ft_choose_texture(t_data *data, t_fov *fov, int column)
// {
// 	char	*filename;
// 	filename = NULL;
// 	printf("column = %d , fov[column].wall_orientation = %c\n", column, 
//	fov[column].wall_orientation);
// 	if (fov[column].wall_orientation == 'N')
// 		filename = data->params.north;
// 	else if (fov[column].wall_orientation == 'S')
// 		filename = data->params.south;
// 	else if (fov[column].wall_orientation == 'E')
// 		filename = data->params.east;
// 	else if (fov[column].wall_orientation == 'W')
// 		filename = data->params.west;
// 	return (filename);
// }
