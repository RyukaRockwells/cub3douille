/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:38:14 by nicole            #+#    #+#             */
/*   Updated: 2023/01/21 22:55:03 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	check_file(char *file)
{
	if (!ft_strrchr((char *)file, '.'))
		return (1);
	if (ft_strcmp(ft_strrchr((char *)file, '.'), ".cub") != 0)
		return (1);
	return (0);
}

