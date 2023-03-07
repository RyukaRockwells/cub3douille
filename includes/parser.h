/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:48:19 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/03/07 13:31:34 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

//**********//
//**PARSER**//
//**********//
//check_get_file/check_file.c
int		check_file(char *file);

//check_get_file/get_file.c
char	**get_file(char *file);

//check_get_map/get_map.c
char	**get_map(t_data *data);

//check_get_map/check_contour.c
int		ft_check_outline(t_data *data);
int		ft_check_last_char(t_data *data);
int		ft_check_first_char(t_data *data);

//check_get_params/get_params.c
void	get_params(t_data *data);

//check_get_params/check_params.c
void	check_params(t_data *data);
int		ft_is_param(t_data *data);

//check_get_params/count_params.c
int		ft_count_rgb(t_data *data);
int		ft_count_directions(t_data *data);
int		ft_is_file_clear(t_data *data);
int		ft_line_ok(t_data *data, int i, int J);
int		ft_empty_line(t_data *data, int i);

//check_get_params/count_params_2.c
int		ft_no_upmap(t_data *data);

//parser.c
void	ft_parsing(t_data *data, int nb, char **argv);
void	ft_parse_2(t_data *data);
void	ft_print_map(t_data *data);

#endif
