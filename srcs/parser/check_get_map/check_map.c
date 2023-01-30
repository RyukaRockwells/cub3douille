/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanauth <sanauth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 22:36:08 by nicole            #+#    #+#             */
/*   Updated: 2023/01/30 13:28:07 by sanauth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	check_in_map(t_data *data)
{
	if (ft_verify_content(data) == 1)
		ft_inmap_error(data, "MAP ERROR: wrong char in map\n");
	else if (ft_count_pos(data) == 1)
		ft_inmap_error(data, "MAP ERROR: too much start position\n");
	else if (ft_check_zero(data) == 1)
		ft_inmap_error(data, "MAP ERROR: map not close\n");
	else
		ft_inmap_error(data, "MAP OK\n"); // a retirer
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
		if (data->map[i][j] == 'N' || data->map[i][j] == 'O' ||
			data->map[i][j] == 'P' || data->map[i][j] == 'S')
			count++;
		j++;
		if (data->map[i][j - 1] == '\n' && i < 13) //remplacer 13 par nbline
		{
			i++;
			j = 0;
		}
	}
	//printf("Count = %d\n", count);
	if (count > 1)
		return (1);
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
		//printf("BOUCLE = %c, i = %d\n", data->map[i][j], i);
		if (data->map[i][j] != 'N' && data->map[i][j] != 'O' &&
			data->map[i][j] != 'P' && data->map[i][j] != 'S' &&
			data->map[i][j] != '0' && data->map[i][j] != '1' &&
			data->map[i][j] != ' ' && data->map[i][j] != '\n')
			return (1);
		if (data->map[i][j] == '\n' && i < 13) // remplacer par nb_line
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
	while (data->map[i][j])
	{
		if (data->map[i][j] == '0')
		{
			if (ft_check_around(data, i, j) == 1)
				return (1);
		}
		if (data->map[i][j] == '\n' && i < 13) // remplacer par nb_line
		{
			i++;
			j = 0;
		}
		else
		j++;
	}
	return (0);
}
