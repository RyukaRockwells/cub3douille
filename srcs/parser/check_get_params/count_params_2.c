/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_params_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanauth <sanauth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:41:13 by nicole            #+#    #+#             */
/*   Updated: 2023/02/01 11:45:40 by sanauth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	ft_no_upmap(t_data *data)
{
	int	i;
	int	j;

	i = data->nb_line;
	j = 0;
	while ((i > 0) && ((data->file[i][j] == '1') || (data->file[i][j] == '0')
		|| (data->file[i][j] == '\n') || (data->file[i][j] == ' ')))
		i--;
	i += 1;
	while (i >= 0)
	{
		//printf("data->file[i][j] = %c | i = %d | j = %d\n", data->file[i][j], i, j);
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
