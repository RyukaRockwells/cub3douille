/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanauth <sanauth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 00:53:40 by nicole            #+#    #+#             */
/*   Updated: 2023/01/30 09:57:34 by sanauth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i] != NULL)
		ft_putstr_fd(data->map[i++], 1);
}

int	main(int nb, char **argv)
{
	t_data	data;

	if (nb != 2)
		nb_arg_error();
	else if (check_file(argv[1]) == 1)
		file_error();
	data.file = get_file(argv[1]);
	if (data.file[0] == NULL)
		file_invalid(&data);
	data.map = get_map(&data);
	print_map(&data);
	check_in_map(&data);
	ft_free_str(data.file);
	ft_free_str(data.map);
}
