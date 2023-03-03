/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:48:31 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/03/03 15:19:02 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	maplenmax(char **map)
{
	int	i;
	int	max_len;

	i = 0;
	max_len = 0;
	while (map[i] != NULL)
	{
		if ((int)ft_strlen(map[i]) > max_len)
			max_len = ft_strlen(map[i]);
		i++;
	}
	return (max_len);
}

int	mapline(char **map)
{
	int	i;
	int	nb_line;

	i = 0;
	nb_line = 0;
	while (map[i] != NULL)
	{
		nb_line++;
		i++;
	}
	return (nb_line);
}

int	max_line(char **file)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (file[i] != NULL)
	{
		if ((int)ft_strlen(file[i]) > max)
			max = ft_strlen(file[i]);
		i++;
	}
	return (max);
}
