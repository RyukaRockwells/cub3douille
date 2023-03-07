/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_params_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:41:13 by nicole            #+#    #+#             */
/*   Updated: 2023/03/07 15:38:33 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	ft_no_upmap(t_data *data)
{
	int	i;
	int	j;

	i = mapline(data->map);
	j = 0;
	while ((i > 0) && ((data->file[i][j] == '1') || (data->file[i][j] == '0')
		|| (data->file[i][j] == '\n') || (data->file[i][j] == ' ')))
		i--;
	i += 1;
	while (i >= 0)
	{
		if ((data->file[i][j] == 'N' && data->file[i][j + 1] == 'O')
			|| (data->file[i][j] == 'S' && data->file[i][j + 1] == 'O')
			|| (data->file[i][j] == 'W' && data->file[i][j + 1] == 'E')
			|| (data->file[i][j] == 'E' && data->file[i][j + 1] == 'A')
			|| (data->file[i][j] == 'F') || (data->file[i][j] == 'C')
			|| (data->file[i][j] == '\n') || (ft_empty_line(data, i) == 0))
			i--;
		else
			return (1);
	}
	return (0);
}

int	ft_check_param_length(t_data *data)
{
	if (ft_strlen(data->params.ceiling) > 11 \
	|| ft_strlen(data->params.floor) > 11)
	{
		ft_free_all_params(data);
		ft_free_str(data->map);
		return (1);
	}
	return (0);
}
