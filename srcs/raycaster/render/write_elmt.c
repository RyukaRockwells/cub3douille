/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_elmt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanauth <sanauth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:28:55 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/03/06 11:18:27 by sanauth          ###   ########.fr       */
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

static float	find_begin_wall(float x_point, float y_point, t_fov *fov, int i)
{
	float	wall_start;
	float	wall_end;
	float	wall_diff;

	if (fov[i].wall_orientation == 'N' || fov[i].wall_orientation == 'S')
	{
		wall_start = floor(x_point / SIZE);
		wall_end = ceil(x_point / SIZE);
		wall_diff = ((x_point - (wall_start * SIZE)) / SIZE);
	}
	else
	{
		wall_start = floor(y_point / SIZE);
		wall_end = ceil(y_point / SIZE);
		wall_diff = ((y_point - (wall_start * SIZE)) / SIZE);
	}
	return (wall_diff);
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

void ft_write_wall(t_data *data, t_fov *fov, double pxl_start, double wall_height, int col)
{
    double wall_pixel_end;
    t_imge *text_choose;
    int txt_index;
    int text_col;
    float percent_wall;

    percent_wall = find_begin_wall(fov[col].x, fov[col].y, fov, col);
    text_choose = choose_and_get_textures(data, fov, col);
    if (text_choose == NULL)
        error_choose_textures(data);
    wall_pixel_end = pxl_start + wall_height;
    while (pxl_start < wall_pixel_end && pxl_start < HEIGTH)
    {
        text_col = (int)(((pxl_start - HEIGTH / 2.0 + wall_height / 2.0) / wall_height) * text_choose->height);
        txt_index = text_col * text_choose->width + (percent_wall * (text_choose->width));
        if (txt_index >= 0 && txt_index < (text_choose->width * text_choose->height)) {
            data->render.addr[((int)pxl_start * data->render.line_size) + (col * 4)] = text_choose->addr[(txt_index * text_choose->bpp) / 8];
            data->render.addr[((int)pxl_start * data->render.line_size) + (col * 4) + 1] = text_choose->addr[(txt_index * text_choose->bpp) / 8 + 1];
            data->render.addr[((int)pxl_start * data->render.line_size) + (col * 4) + 2] = text_choose->addr[(txt_index * text_choose->bpp) / 8 + 2];
            data->render.addr[((int)pxl_start * data->render.line_size) + (col * 4) + 3] = (char)0;
        }
        pxl_start++;
    }
}

