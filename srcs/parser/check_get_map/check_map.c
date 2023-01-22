/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanauth <sanauth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 22:36:08 by nicole            #+#    #+#             */
/*   Updated: 2023/01/22 18:24:51 by sanauth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	check_in_map(t_data *data)
{
	int	ret;
	int	i;

	i = 0;
	ret = ft_check_char(data, i);
	if (ret == 500)
		printf("Map Error\n");
	else if (ret > 1)
		printf("Too much start\n");
	else
		printf("MAP OK\n");
}

int	ft_is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r')
		return (0);
	return (1);
}

int	ft_check_char(t_data *data, int i)
{
	int	j;
	int	count;

	j = 0;
	count = 0;
	fprintf(stderr, "data->nbline = %d\n", data->nb_line);
	while (data->map[i][j] != '\0' && i < data->nb_line)
	{	
		//printf("i = %d j = %d, data->map[i][j] = %c\n", i, j, data->map[i][j]);
		if (data->map[i][j] == 'N' || data->map[i][j] == 'O' || data->map[i][j] == 'P' ||
			data->map[i][j] == 'S')
			count++;
		else if (data->map[i][j] == '\n')
		{
			i++;
			j = 0;
		}
		if (data->map[i][j] == ' ' || data->map[i][j] == '1' || data->map[i][j] == '0')
			j++;
		else
		{
			printf("map[i][j] = %c\n", data->map[i][j]);
			return (500);
		}
	}
	return (count);
}
