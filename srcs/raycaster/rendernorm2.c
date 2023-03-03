/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendernorm2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanauth <sanauth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:21:16 by sanauth           #+#    #+#             */
/*   Updated: 2023/03/03 13:49:36 by sanauth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/struct.h"

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

void	ft_write_wall(t_data *data, t_fov *fov, double pixel_start, double nb_pixel, int column)
{
	double	wall_pixel_end;
	char	*txt_data;
	int		txt_index;
	float	wall_height_ratio;
	int		txt_column;

	printf("column2 = %d\n", column);
	//wall_pixel_end = pixel_start + nb_pixel;
	txt_data = load_texture(data, fov, column);
	wall_pixel_end = nb_pixel / 2 + HEIGTH / 2;
	if (wall_pixel_end >= HEIGTH)
	{
		wall_pixel_end = HEIGTH - 1;
	}
	while (pixel_start < wall_pixel_end)
	{
		wall_height_ratio = (float)(wall_pixel_end - pixel_start) / nb_pixel;
		txt_column = (int)((1 - wall_height_ratio) * data->texture.txt_height);
		txt_index = txt_column * data->texture.txt_width + (column % (data->texture.txt_width));
		data->buffer[((int)pixel_start * data->nb_line_map) + (column * 4)] = txt_data[(txt_index * data->texture.txt_bpp) / 8];
		data->buffer[((int)pixel_start * data->nb_line_map) + (column * 4) + 1] = txt_data[(txt_index * data->texture.txt_bpp) / 8 + 1];
		data->buffer[((int)pixel_start * data->nb_line_map) + (column * 4) + 2] = txt_data[(txt_index * data->texture.txt_bpp) / 8 + 2];
		data->buffer[((int)pixel_start * data->nb_line_map) + (column * 4) + 3] = 0;
		pixel_start++;
	}
}

char	*load_texture(t_data *data, t_fov *fov, int column)
{
	char	*texture_data;
	char	*filename;


	printf("column1 = %d\n", column);
	filename = ft_choose_texture(data, fov, column);
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

char	*ft_choose_texture(t_data *data, t_fov *fov, int column)
{
	char	*filename = NULL;

	printf("column = %d\n", column);
	printf("column = %d , fov[column].wall_orientation = %c\n", column, fov[column].wall_orientation);

	if (fov[column].wall_orientation == 'N')
		filename = data->params.north;
	else if (fov[column].wall_orientation== 'S')
		filename = data->params.south;
	else if (fov[column].wall_orientation == 'E')
		filename = data->params.east;
	else if (fov[column].wall_orientation == 'W')
		filename = data->params.west;
	printf("filename = %s\n", filename);
	return (filename);
}
