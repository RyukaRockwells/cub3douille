/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 09:15:20 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/03/04 13:42:51 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	error_xpm_to_img(t_data *data)
{
	ft_putstr_fd("Error\nYour image is not xpm\n", 2);
	ft_close_error(data);
}

void	error_choose_textures(t_data *data)
{
	ft_putstr_fd("Error\nYour orientation is incorrect\n", 2);
	ft_close(data);
}
