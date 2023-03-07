/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanauth <sanauth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 01:22:11 by nicole            #+#    #+#             */
/*   Updated: 2023/03/07 08:48:56 by sanauth          ###   ########.fr       */
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

void	ft_map_error(t_data *data, char *str)
{
	ft_free_all_params(data);
	ft_putstr_fd(str, 2);
	ft_free(data->file);
	ft_free(data->map);
	exit(EXIT_FAILURE);
}

void	ft_close_error(t_data *data)
{
	ft_free_str(data->map);
	if (data->textures[0].img != NULL)
		mlx_destroy_image(data->mlx, data->textures[0].img);
	if (data->textures[1].img != NULL)
		mlx_destroy_image(data->mlx, data->textures[1].img);
	if (data->textures[2].img != NULL)
		mlx_destroy_image(data->mlx, data->textures[2].img);
	if (data->textures[3].img != NULL)
		mlx_destroy_image(data->mlx, data->textures[3].img);
	mlx_clear_window(data->mlx, data->win);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	ft_free_all_params(data);
	free(data->mlx);
	data->mlx = NULL;
	ft_free_str(data->file);
	exit(EXIT_SUCCESS);
}
