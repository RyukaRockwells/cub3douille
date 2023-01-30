/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanauth <sanauth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 01:22:11 by nicole            #+#    #+#             */
/*   Updated: 2023/01/30 13:30:30 by sanauth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_inmap_error(t_data *data, char *str)
{
	ft_putstr_fd(str, 2);
	ft_free(data->file);
	ft_free(data->map);
	exit(EXIT_FAILURE);
}
