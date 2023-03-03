/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:54:31 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/03/03 15:15:22 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_parsing(t_data *data, int nb, char **argv)
{
	if (nb != 2)
		nb_arg_error();
	else if (check_file(argv[1]) == 1)
		file_error();
	init_struct(data);
	data->file = get_file(argv[1]);
	if (data->file[0] == NULL)
		file_invalid(data);
	data->map = get_map(data);
	ft_parse_2(data);
	get_params(data);
	check_params(data);
	check_in_map(data);
}

void	ft_parse_2(t_data *data)
{
	if (ft_count_rgb(data) == 1 || ft_count_directions(data) == 1)
		ft_map_error(data, "Error\nToo much parameters\n");
	if (ft_is_file_clear(data) == 1 || ft_no_upmap(data) == 1)
		ft_map_error(data, "Error\nFile error\n");
}
