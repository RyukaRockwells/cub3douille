/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:39:32 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/01/24 14:09:06 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_pos
{
	double	x;
	double	y;
}	t_pos;

typedef struct s_dir
{
	double	x;
	double	y;
}	t_dir;

typedef struct s_plan
{
	double	x;
	double	y;
}	t_plan;

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
	void		*mlx;
	void		*win;
	int			max_len;
	t_params	params;
	t_pos		pos;
	t_dir		dir;
}	t_data;

#endif
