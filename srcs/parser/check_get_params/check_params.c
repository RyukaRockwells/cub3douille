/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 08:40:45 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/01/24 12:57:23 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static int	nb_line_split(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

static int	check_open_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		error_xpm(path);
		return (1);
	}
	return (0);
}

static int	check_color_rgb(char *color)
{
	char	**rgb;
	int		i;

	rgb = ft_split(color, ',');
	i = 0;
	if (rgb == NULL || nb_line_split(rgb) != 3)
	{
		error_rgb();
		ft_free_str(rgb);
		return (1);
	}
	while (rgb[i] != NULL)
	{
		if (ft_atoi(rgb[i]) < 0 || ft_atoi(rgb[i]) > 255)
		{
			error_rgb();
			ft_free_str(rgb);
			return (1);
		}
		i++;
	}
	ft_free_str(rgb);
	return (0);
}

void	check_params(t_data *data)
{
	if (data->params.north == NULL || data->params.south == NULL
		|| data->params.west == NULL || data->params.east == NULL
		|| data->params.floor == NULL || data->params.ceiling == NULL)
		error_missing_params(data);
	if (check_open_file(data->params.north) == 1
		|| check_open_file(data->params.south) == 1
		|| check_open_file(data->params.west) == 1
		|| check_open_file(data->params.east) == 1
		|| check_color_rgb(data->params.floor) == 1
		|| check_color_rgb(data->params.ceiling) == 1)
	{
		ft_free_all_params(data);
		ft_free_str(data->file);
		ft_free_str(data->map);
		exit(EXIT_FAILURE);
	}
}
