/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendernorm2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanauth <sanauth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:21:16 by sanauth           #+#    #+#             */
/*   Updated: 2023/02/28 11:21:17 by sanauth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_put_3d(t_data *data)
{
	int	x;
	int	y;
	int	color;
	int	color2;

	x = 0;
	y = 0;
	color = 0x87CEEB;
	color2 = 0x484473;
	data->buffer = NULL;
	data->new_img = mlx_new_image(data->mlx, WIDTH, HEIGTH);
	data->buffer = mlx_get_data_addr(data->new_img, &data->bpp, \
	&data->nb_line_map, &data->endian);
	ft_write_sky(data, x, y);
	ft_write_floor(data, x, y);
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
			data->buffer[(y * data->nb_line_map) + (x * 4)] = \
			(char)ft_atoi(tab[0]);
			data->buffer[(y * data->nb_line_map) + (x * 4) + 1] = \
			(char)ft_atoi(tab[1]);
			data->buffer[(y * data->nb_line_map) + (x * 4) + 2] = \
			(char)ft_atoi(tab[2]);
			data->buffer[(y * data->nb_line_map) + (x * 4) + 3] = \
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
	y = HEIGTH / 2;
	while (y < HEIGTH)
	{
		x = 0;
		while (x < WIDTH)
		{
			data->buffer[(y * data->nb_line_map) + (x * 4)] = \
			(char)ft_atoi(tab[0]);
			data->buffer[(y * data->nb_line_map) + (x * 4) + 1] = \
			(char)ft_atoi(tab[1]);
			data->buffer[(y * data->nb_line_map) + (x * 4) + 2] = \
			(char)ft_atoi(tab[2]);
			data->buffer[(y * data->nb_line_map) + (x * 4) + 3] = \
			(char)0;
			x++;
		}
		y++;
	}
	ft_free(tab);
}

void	ft_write_wall(t_data *data, int pixel_start, int nb_pixel, int column)
{
	int		wall_pixel_end;
	char	*txt_data;
	int		txt_index;
	float	wall_height_ratio;
	int		txt_column;

	wall_pixel_end = pixel_start + nb_pixel;
	txt_data = load_texture("./textures/debug_north.xpm", data);
	while (pixel_start < wall_pixel_end)
	{
		wall_height_ratio = (float) \
		(wall_pixel_end - pixel_start) / nb_pixel;
		txt_column = (int) \
		((1 - wall_height_ratio) * data->texture.txt_height);
		txt_index = txt_column * data->texture.txt_width + \
		(column % data->texture.txt_width);
		data->buffer[(pixel_start * data->nb_line_map) + (column * 4)] = \
		txt_data[(txt_index * data->texture.txt_bpp) / 8];
		data->buffer[(pixel_start * data->nb_line_map) + (column * 4) + 1] = \
		txt_data[(txt_index * data->texture.txt_bpp) / 8 + 1];
		data->buffer[(pixel_start * data->nb_line_map) + (column * 4) + 2] = \
		txt_data[(txt_index * data->texture.txt_bpp) / 8 + 2];
		data->buffer[(pixel_start * data->nb_line_map) + (column * 4) + 3] = 0;
		pixel_start++;
	}
}

char	*load_texture(char *filename, t_data *data)
{
	char	*texture_data;

	data->texture.img = NULL;
	data->texture.img = mlx_xpm_file_to_image(data->mlx, \
	filename, &data->texture.txt_width, &data->texture.txt_height);
	if (!data->texture.img)
		return (NULL);
	texture_data = mlx_get_data_addr(data->texture.img, \
	&data->texture.txt_bpp, &data->texture.txt_line_size, \
	&data->texture.txt_endian);
	if (!texture_data)
	{
		mlx_destroy_image(data->mlx, data->texture.img);
		return (NULL);
	}
	return (texture_data);
}