/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 00:53:40 by nicole            #+#    #+#             */
/*   Updated: 2023/01/22 18:25:13 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int nb, char **argv)
{
	t_data	data;
	int		i;

	if (nb != 2)
		nb_arg_error();
	else if (check_file(argv[1]) == 1)
		file_error();
	data.file = get_file(argv[1]);
	if (data.file[0] == NULL)
		file_invalid(&data);
	data.map = get_map(&data);
	get_params(&data);
	i = 0;
	while (data.map[i] != NULL)
		ft_putstr_fd(data.map[i++], 1);
	fprintf(stderr, "north = |%s|", data.params.north);
	ft_free_str(data.file);
	ft_free_str(data.map);
}
