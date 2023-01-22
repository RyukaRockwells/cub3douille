/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 00:55:10 by nicole            #+#    #+#             */
/*   Updated: 2023/01/22 18:25:21 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include "../srcs/libft/libft.h"
# include "../srcs/get_next_line/get_next_line.h"

typedef struct s_data	t_data;
typedef struct s_params	t_params;

typedef struct s_params
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*floor;
	char	*ceiling;
}	t_params;

typedef struct s_data
{
	char		**file;
	char		**map;
	t_params	params;
}	t_data;

//utils/ft_strcmp.c
int		ft_strcmp(const char *s1, const char *s2);

//utils/ft_strcpy.c
char	*ft_strcpy(char *dest, char *str);

//utils/ft_is_space.c
int		ft_is_space(char c);

//free/all_free.c
void	ft_free_str(char **str);

//error/ft_error.c
void	nb_arg_error(void);
void	file_error(void);
void	fd_error(char *file, int fd);
void	file_invalid(t_data *data);
void	map_error(t_data *data);

//**********//
//**PARSER**//
//**********//
//check_get_file/check_file.c
int		check_file(char *file);

//check_get_file/get_file.c
char	**get_file(char *file);

//check_get_map/get_map.c
char	**get_map(t_data *data);

//check_get_params/get_params.c
void	get_params(t_data *data);

#endif
