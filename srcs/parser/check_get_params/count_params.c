/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanauth <sanauth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:41:13 by nicole            #+#    #+#             */
/*   Updated: 2023/01/31 16:40:15 by sanauth          ###   ########.fr       */
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
