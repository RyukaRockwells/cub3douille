/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 22:36:08 by nicole            #+#    #+#             */
/*   Updated: 2023/03/03 15:21:17 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	check_in_map(t_data *data)
{
	if (ft_check_outline(data) == 1)
		ft_map_error(data, "Error\nFirst or last line not close\n");
	else if (ft_check_first_char(data) == 1)
		ft_map_error(data, "Error\nWrong first char\n");
	else if (ft_check_last_char(data) == 1)
		ft_map_error(data, "Error\nWrong last char\n");
	else if (ft_verify_content(data) == 1)
		ft_map_error(data, "Error\nWrong char in map\n");
	else if (ft_count_pos(data) == 1)
		ft_map_error(data, "Error\nToo much start position\n");
	else if (ft_count_pos(data) == 2)
		ft_map_error(data, "Error\nNo start position\n");
	else if (ft_check_zero(data) == 1)
		ft_map_error(data, "Error\nMap not close\n");
}

int	ft_count_pos(t_data *data)
{
	int	count;
	int	i;
	int	j;

	i = 0;
	j = 0;
	count = 0;
	while (data->map[i][j] != '\0')
	{
		if (data->map[i][j] == 'N' || data->map[i][j] == 'W' ||
			data->map[i][j] == 'E' || data->map[i][j] == 'S')
			count++;
		j++;
		if (j == (int)ft_strlen(data->map[i]) && i < mapline(data->map) - 1)
		{
			i++;
			j = 0;
		}
	}
	if (count > 1)
		return (1);
	else if (count == 0)
		return (2);
	return (0);
}

int	ft_verify_content(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i][j] != '\0')
	{
		if (data->map[i][j] != 'N' && data->map[i][j] != 'E' &&
			data->map[i][j] != 'W' && data->map[i][j] != 'S' &&
			data->map[i][j] != '0' && data->map[i][j] != '1' &&
			data->map[i][j] != ' ' && data->map[i][j] != '\n')
			return (1);
		if (j == (int)ft_strlen(data->map[i]) - 1 && i < mapline(data->map) - 1)
		{
			i++;
			j = 0;
		}
		else
		j++;
	}
	return (0);
}

int	ft_check_around(t_data *data, int i, int j)
{
	if (data->map[i][j + 1] != ' ' && data->map[i][j - 1] != ' '
	&& data->map[i + 1][j] != ' ' && data->map[i - 1][j] != ' '
	&& data->map[i][j + 1] != '\n' && data->map[i][j - 1] != '\n'
	&& data->map[i + 1][j] != '\n' && data->map[i - 1][j] != '\n')
		return (0);
	return (1);
}

int	ft_check_zero(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i][j] && j <= (int)ft_strlen(data->map[i]) - 1)
	{
		if (data->map[i][j] == '0')
		{
			if (ft_check_around(data, i, j) == 1)
			{
				return (1);
			}
		}
		if (j == (int)ft_strlen(data->map[i]) - 1 && i < mapline(data->map) - 1)
		{
			i++;
			j = 0;
		}
		j++;
	}
	return (0);
}
