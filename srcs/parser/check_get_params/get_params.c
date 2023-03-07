/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanauth <sanauth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:18:04 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/03/07 14:21:18 by sanauth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static char	*get_str_params(char *str)
{
	int		i;
	int		start;
	int		len;
	char	*params;

	i = 0;
	len = 0;
	while (ft_is_space(str[i]) == 1)
		i++;
	start = i;
	while (str[i] != '\0')
	{
		if (ft_is_space(str[i]) == 1)
			break ;
		len++;
		i++;
	}
	params = ft_substr(str + start, 0, len);
	return (params);
}

static void	get_wall_params(t_data *data, int i, int j)
{
	if (data->file[i][j] == 'N' && data->file[i][j + 1] == 'O')
	{
		j += 2;
		data->params.north = get_str_params(data->file[i] + j);
	}
	else if (data->file[i][j] == 'S' && data->file[i][j + 1] == 'O')
	{
		j += 2;
		data->params.south = get_str_params(data->file[i] + j);
	}
	else if (data->file[i][j] == 'W' && data->file[i][j + 1] == 'E')
	{
		j += 2;
		data->params.west = get_str_params(data->file[i] + j);
	}
	else if (data->file[i][j] == 'E' && data->file[i][j + 1] == 'A')
	{
		j += 2;
		data->params.east = get_str_params(data->file[i] + j);
	}
}

void	get_params(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->file[i] != NULL)
	{
		j = 0;
		while (ft_is_space(data->file[i][j]) == 1)
			j++;
		if ((data->file[i][j] == 'N' && data->file[i][j + 1] == 'O')
			|| (data->file[i][j] == 'S' && data->file[i][j + 1] == 'O')
			|| (data->file[i][j] == 'W' && data->file[i][j + 1] == 'E')
			|| (data->file[i][j] == 'E' && data->file[i][j + 1] == 'A'))
			get_wall_params(data, i, j);
		else if (data->file[i][j] == 'F' && data->file[i][j + 1] == ' ')
			data->params.floor = get_str_params(data->file[i] + (j + 1));
		else if (data->file[i][j] == 'C' && data->file[i][j + 1] == ' ')
			data->params.ceiling = get_str_params(data->file[i] + (j + 1));
		i++;
	}
	if (ft_check_param_length(data) == 1)
		file_invalid(data);
}
