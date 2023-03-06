/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 22:51:21 by nicole            #+#    #+#             */
/*   Updated: 2023/03/05 13:20:42 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static int	get_first_line_map(char **file)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (file[i] != NULL)
		i++;
	i = i - 1;
	while (i > 0)
	{
		if (file[i][j] == 'C' || file[i][j] == 'F'
		|| (file[i][j] == 'E' && file[i][j + 1] == 'A')
		|| (file[i][j] == 'W' && file[i][j + 1] == 'E')
		|| (file[i][j] == 'S' && file[i][j + 1] == 'O')
		|| (file[i][j] == 'N' && file[i][j + 1] == 'O'))
			return (i + 1);
		else
		i--;
	}
	return (i);
}

static int	get_nb_line_map(char **file)
{
	int	nb;
	int	i;
	int	j;

	nb = 0;
	i = get_first_line_map(file) + 1;
	while (file[i] != NULL)
	{
		j = 0;
		while (file[i][j] != '\0')
		{
			if (file[i][j])
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

	i = get_first_line_map(data->file) + 1;
	j = 0;
	nb_line_map = get_nb_line_map(data->file);
	if (nb_line_map <= 3)
		map_error(data);
	map = malloc(sizeof(char *) * (nb_line_map + 1));
	if (map == NULL)
		exit(EXIT_FAILURE);
	while (j < nb_line_map)
	{
		map[j] = malloc(sizeof(char) * (max_line(data->file) + 1));
		if (map[j] == NULL)
			exit(EXIT_FAILURE);
		map[j] = ft_strcpy(map[j], data->file[i++], data);
		j++;
	}
	map[j] = NULL;
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
}
