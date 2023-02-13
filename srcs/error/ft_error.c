/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanauth <sanauth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 01:22:11 by nicole            #+#    #+#             */
/*   Updated: 2023/02/13 09:51:36 by sanauth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	nb_arg_error(void)
{
	ft_putstr_fd("Error\nusage:\t./cub3d [file.cub]\n", 2);
	exit(EXIT_FAILURE);
}

void	file_error(void)
{
	ft_putstr_fd("Error\nThe file is incorrect [file.cub]\n", 2);
	exit(EXIT_FAILURE);
}

void	fd_error(char *file, int fd)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd("\n", 2);
	close(fd);
	exit(EXIT_FAILURE);
}

void	file_invalid(t_data *data)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("The file is invalid\n", 2);
	ft_free_str(data->file);
	exit(EXIT_FAILURE);
}

void	map_error(t_data *data)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("The map is invalid\n", 2);
	ft_free_str(data->file);
	exit(EXIT_FAILURE);
}
