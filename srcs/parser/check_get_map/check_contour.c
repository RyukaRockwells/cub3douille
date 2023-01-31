/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_contour.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanauth <sanauth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 22:36:08 by nicole            #+#    #+#             */
/*   Updated: 2023/01/31 10:19:19 by sanauth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	ft_check_outline(t_data *data)
{
	int	j;

	j = 0;
	while (data->map[0][j] != '\0')
	{
		if (data->map[0][j] == '1' || data->map[0][j] == ' '
		|| data->map[0][j] == '\n')
			j++;
		else
			return (1);
	}
	j = 0;
	while (data->map[data->nb_line - 1][j] != '\0')
	{
		if (data->map[data->nb_line - 1][j] == ' '
		|| data->map[data->nb_line - 1][j] == '1'
		|| data->map[data->nb_line - 1][j] == '\n')
			j++;
		else
			return (1);
	}
	return (0);
}

int	ft_check_out_char(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->nb_line)
	{
		j = 0;
		while (data->map[i][j] == ' ')
			j++;
		if (data->map[i][j] == '1'
		&& (data->map[i][(int)ft_strlen(data->map[i]) - 1] == '1'))
			i++;
		else
			return (1);
	}
	return (0);
}
