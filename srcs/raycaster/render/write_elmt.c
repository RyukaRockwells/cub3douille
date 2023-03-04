/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_elmt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:28:55 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/03/04 19:23:37 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static t_imge	*choose_and_get_textures(t_data *data, t_fov *fov, int column)
{
	t_imge	*text_choose;

	if (fov[column].wall_orientation == 'N')
		text_choose = &data->textures[0];
	else if (fov[column].wall_orientation == 'S')
		text_choose = &data->textures[1];
	else if (fov[column].wall_orientation == 'W')
		text_choose = &data->textures[2];
	else if (fov[column].wall_orientation == 'E')
		text_choose = &data->textures[3];
	else
		return (NULL);
	return (text_choose);
}

void	ft_write_sky(t_data *data, int x, int y)
{
	char	**tab;

	tab = ft_split(data->params.ceiling, ',');
	while (y < HEIGTH / 2)
	{
		x = 0;
		while (x < WIDTH)
		{
			data->render.addr[(y * data->render.line_size) + (x * 4)] = \
			(char)ft_atoi(tab[0]);
			data->render.addr[(y * data->render.line_size) + (x * 4) + 1] = \
			(char)ft_atoi(tab[1]);
			data->render.addr[(y * data->render.line_size) + (x * 4) + 2] = \
			(char)ft_atoi(tab[2]);
			data->render.addr[(y * data->render.line_size) + (x * 4) + 3] = \
			(char)0;
			x++;
		}
		y++;
	}
	ft_free(tab);
}

void	ft_write_floor(t_data *data, int x, int y)
{
	char	**tab;

	tab = ft_split(data->params.floor, ',');
	while (y < HEIGTH)
	{
		x = 0;
		while (x < WIDTH)
		{
			data->render.addr[(y * data->render.line_size) + (x * 4)] = \
			(char)ft_atoi(tab[0]);
			data->render.addr[(y * data->render.line_size) + (x * 4) + 1] = \
			(char)ft_atoi(tab[1]);
			data->render.addr[(y * data->render.line_size) + (x * 4) + 2] = \
			(char)ft_atoi(tab[2]);
			data->render.addr[(y * data->render.line_size) + (x * 4) + 3] = \
			(char)0;
			x++;
		}
		y++;
	}
	ft_free(tab);
}

// void	ft_write_wall(t_data *data, t_fov *fov, int column)
// {
// 	double	proj_height;
// 	double	i;
// 	int		value;

// 	value = (WIDTH / 2) / tan((FOV / 2) * M_PI / 180);
// 	i = 0.0;
// 	proj_height = (double)ceil(SIZE / fov[column].dist * value);
// 	while (a < proj_height)
// 	{
// 		if ()
// 	}
// }

void	ft_write_wall(t_data *data, t_fov *fov, double pixel_start, double nb_pixel, int column)
{
	double	wall_pixel_end;
	t_imge	*text_choose;
	int		txt_index;
	double	wall_height_ratio;
	int		txt_column;

	//wall_pixel_end = pixel_start + nb_pixel;
	wall_height_ratio = 0.0;
	text_choose = choose_and_get_textures(data, fov, column);
	if (text_choose == NULL)
		error_choose_textures(data);
	wall_pixel_end = (nb_pixel / 2) + (HEIGTH / 2);
	if (wall_pixel_end >= HEIGTH)
		wall_pixel_end = HEIGTH - 1;
	while (pixel_start < wall_pixel_end)
	{
		wall_height_ratio = (wall_pixel_end - pixel_start) / nb_pixel;
		// txt_column = (int)((1 - wall_height_ratio) * text_choose->height);
		if (fov[column].wall_orientation == 'N'
			|| fov[column].wall_orientation == 'S')
			txt_column = (int)((1 - wall_height_ratio) * text_choose->height);
		else
			txt_column = (int)((1 - wall_height_ratio) * text_choose->height);
		txt_index = txt_column * text_choose->width + (column % (text_choose->width));//choix de la colonne de pixel de la texture
		data->render.addr[((int)pixel_start * data->render.line_size) + (column * 4)] = text_choose->addr[(txt_index * text_choose->bpp) / 8];
		data->render.addr[((int)pixel_start * data->render.line_size) + (column * 4) + 1] = text_choose->addr[(txt_index * text_choose->bpp) / 8 + 1];
		data->render.addr[((int)pixel_start * data->render.line_size) + (column * 4) + 2] = text_choose->addr[(txt_index * text_choose->bpp) / 8 + 2];
		data->render.addr[((int)pixel_start * data->render.line_size) + (column * 4) + 3] = (char)0;
		pixel_start++;
	}
}
