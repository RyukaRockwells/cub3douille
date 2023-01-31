/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanauth <sanauth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 22:51:21 by nicole            #+#    #+#             */
/*   Updated: 2023/01/31 12:58:08 by sanauth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static int	get_first_line_map(char **file)
{
	int	i;
	int	j;

	i = 0;
	while (file[i] != NULL)
	{
		j = 0;
		while (file[i][j] != '\0')
		{
			if (file[i][j] == '1' && file[i][j + 1] == '1')
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

static int	get_nb_line_map(char **file)
{
	int	nb;
	int	i;
	int	j;

	nb = 0;
	i = get_first_line_map(file);
	while (file[i] != NULL)
	{
		j = 0;
		while (file[i][j] != '\0')
		{
			if (file[i][j] == '1')
			{
				nb++;
				j = 0;
				break ;
			}
			j++;
		}
		i++;
	}
	return (nb);
}

char	**get_map(t_data *data)
{
	int		i;
	int		j;
	int		nb_line_map;
	char	**map;

	i = get_first_line_map(data->file);
	j = 0;
	nb_line_map = get_nb_line_map(data->file);
	if (nb_line_map <= 3)
		map_error(data);
	map = malloc(sizeof(char *) * (nb_line_map + 1));
	if (map == NULL)
		exit(EXIT_FAILURE);
	while (j < nb_line_map)
	{
		map[j] = malloc(sizeof(char) * (data->max_len + 1));
		if (map[j] == NULL)
			exit(EXIT_FAILURE);
		map[j] = ft_strcpy(data, map[j], data->file[i++]);
		j++;
	}
	map[j] = NULL;
	data->nb_line = nb_line_map;
	return (map);
}

void	ft_print_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		printf("%s\n", data->map[i++]);
	}
	exit(0);
}
