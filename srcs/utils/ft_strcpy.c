/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 13:20:02 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/03/05 13:20:33 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*ft_strcpy(char *dest, char *str, t_data *data)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			break ;
		else
			dest[i] = str[i];
		i++;
	}
	while (i < (max_line(data->file)))
		dest[i++] = ' ';
	dest[i] = '\0';
	return (dest);
}
