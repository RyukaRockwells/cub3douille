/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanauth <sanauth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:41:13 by nicole            #+#    #+#             */
/*   Updated: 2023/01/31 15:25:19 by sanauth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static int	count_line_file(char *file)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	line = "null";
	fd = open(file, O_RDONLY);
	if (fd < 0)
		fd_error(file, fd);
	while (line != NULL)
	{
		line = get_next_line(fd);
		free(line);
		count++;
	}
	close(fd);
	return (count);
}

char	**get_file(char *file)
{
	int		fd;
	char	**content;
	int		i;
	int		j;

	i = 0;
	j = count_line_file(file);
	content = malloc(sizeof(char *) * (j + 1));
	if (content == NULL)
		exit(EXIT_FAILURE);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		fd_error(file, fd);
	while (i < j)
		content[i++] = get_next_line(fd);
	content[i] = NULL;
	close (fd);
	return (content);
}
