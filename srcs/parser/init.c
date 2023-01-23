/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:43:09 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/01/23 10:44:23 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_struct(t_data *data)
{
	data->params.north = NULL;
	data->params.south = NULL;
	data->params.west = NULL;
	data->params.east = NULL;
	data->params.floor = NULL;
	data->params.ceiling = NULL;
}
