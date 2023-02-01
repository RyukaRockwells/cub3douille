/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanauth <sanauth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:41:13 by nicole            #+#    #+#             */
/*   Updated: 2023/02/01 10:26:41 by sanauth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	ft_count_rgb(t_data *data)
{
	int	i;
	int	countf;
	int	countc;

	i = 0;
	countf = 0;
	countc = 0;
	while (data->file[i] && countf < 3 && countc < 3)
	{
		if (data->file[i][0] == 'F')
			countf++;
		if (data->file[i][0] == 'C')
			countc++;
		i++;
	}
	if (countf > 1 || countc > 1)
		return (1);
	return (0);
}

int	ft_count_directions(t_data *data)
{
	int	i;
	int	paths;

	i = 0;
	paths = 0;
	while (data->file[i] && paths <= 5)
	{
		if ((data->file[i][0] == 'N' && data->file[i][1] == 'O')
		|| (data->file[i][0] == 'S' && data->file[i][1] == 'O')
		|| (data->file[i][0] == 'W' && data->file[i][1] == 'E')
		|| (data->file[i][0] == 'E' && data->file[i][1] == 'A'))
			paths++;
		i++;
	}
	if (paths > 4)
		return (1);
	return (0);
}

int	ft_empty_line(t_data *data, int i)
{
	int	j;

	j = 0;
	printf("emptyline\n");
	while (j <= (int)ft_strlen(data->file[i]) && data->file[i][j] == ' ')
		j++;
	if (data->file[i][j] == '\n' || data->file[i][j] == '\0')
		return (0);
	//if (j == ((int)ft_strlen(data->file[i]) - 1))
	//	return (0);
	return (j);
}

int	ft_line_ok(t_data *data, int i, int j)
{
	printf("lineok\n");
	if ((data->file[i][j] == 'N' && data->file[i][j + 1] == 'O')
	|| (data->file[i][j] == 'S' && data->file[i][j + 1] == 'O')
	|| (data->file[i][j] == 'W' && data->file[i][j + 1] == 'E')
	|| (data->file[i][j] == 'E' && data->file[i][j + 1] == 'A')
	|| (data->file[i][j] == 'F') || (data->file[i][j] == 'C')
	|| (data->file[i][j] == '1') || (data->file[i][j] == '0')
	|| (data->file[i][j] == '\n') || (data->file[i][j] == ' '))
		return (0);
	else
		return (1);
	return (0);
}

int	ft_is_file_clear(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->nb_line)
	{
		j = 0;
		if (data->file[i][j] == ' ' || data->file[i][j] == '\n')
			j = ft_empty_line(data, i);
		else
			j = 0;
		printf("data->file[i][j] = %c | i = %d | j = %d\n", data->file[i][j], i, j);
		printf("coucou\n");
		if (ft_line_ok(data, i, j) == 1)
			return (1);
		else
		i++;
	}
	return (0);
}
