/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:18:04 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/01/22 18:59:03 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static void	get_str_params(char *str)
{
	int		i;
	int		start;
	int		len;
	char	*params;

	i = 0;
	len = 0;
	fprintf(stderr, "str = |%s|", str);
	while (ft_is_space(str[i]) == 1)
		i++;
	if (str[i] == '1')
	{
		fprintf(stderr, "Error\n");
		return ;
	}
	start = i;
	while (str[i] != '\0')
	{
		if (ft_is_space(str[i]) == 0)
			len++;
		i++;
	}
	params = ft_substr(str + start, 0, len);
	fprintf(stderr, "str = |%s|\n", params);
	free(params);
}

void	get_params(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->file[i] != NULL)
	{
		j = 0;
		if (data->file[i][j] == 'N' && data->file[i][j + 1] == 'O')
		{
			j += 2;
			get_str_params(data->file[i] + j);
			while (ft_is_space(data->file[i][j]) == 1)
				j++;
			data->params.north = ft_substr(data->file[i], j, ft_strlen(data->file[i] + j));
		}
		i++;
	}
}
