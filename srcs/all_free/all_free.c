/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:42:52 by nicole            #+#    #+#             */
/*   Updated: 2023/01/23 10:46:32 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
}

void	ft_free_all_params(t_data *data)
{
	if (data->params.north != NULL)
		free(data->params.north);
	if (data->params.south != NULL)
		free(data->params.south);
	if (data->params.west != NULL)
		free(data->params.west);
	if (data->params.east != NULL)
		free(data->params.east);
	if (data->params.floor != NULL)
		free(data->params.floor);
	if (data->params.ceiling != NULL)
		free(data->params.ceiling);
}
