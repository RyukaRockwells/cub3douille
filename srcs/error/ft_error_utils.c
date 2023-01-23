/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 09:15:20 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/01/23 10:33:41 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	error_xpm(char *path)
{
	ft_putstr_fd("Error\nYour image not exist\nPATH_IMG = ", 2);
	ft_putstr_fd(path, 2);
	ft_putstr_fd("\n", 2);
}

void	error_rgb(void)
{
	ft_putstr_fd("Error\nYour rgb color is not valid\n", 2);
	ft_putstr_fd("The rgb colors must not contain spaces and must", 2);
	ft_putstr_fd(" contain 3 numbers from 0 to 255 separated by commas\n", 2);
}

void	error_missing_params(t_data *data)
{
	ft_putstr_fd("Your file.cub does not contain five parameters:\n", 2);
	ft_putstr_fd("NO [path]\nSO [path]\nWE [path]\nEA [path]\nF [rgb]\nC [rgb]\n", 2);
	ft_free_all_params(data);
	ft_free_str(data->file);
	ft_free_str(data->map);
	exit(EXIT_FAILURE);
}
