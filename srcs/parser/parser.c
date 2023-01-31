/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanauth <sanauth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:54:31 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/01/31 13:17:39 by sanauth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_parsing(t_data *data, int nb, char **argv)
{
	int	i;

	i = 0;
	if (nb != 2)
		nb_arg_error();
	else if (check_file(argv[1]) == 1)
		file_error();
	init_struct(data);
	data->file = get_file(argv[1]);
	if (data->file[0] == NULL)
		file_invalid(data);
	while (data->file[i] != NULL)
	{
		if ((int)ft_strlen(data->file[i]) > data->max_len)
			data->max_len = ft_strlen(data->file[i]);
		i++;
	}
	data->map = get_map(data);
	get_params(data);
	check_params(data);
	ft_print_map(data);
	check_in_map(data);
}
