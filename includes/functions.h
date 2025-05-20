/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:46:40 by ktintim-          #+#    #+#             */
/*   Updated: 2025/05/20 16:26:24 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H
//constructor.c
void	window_constructor(t_window *window);
void	texture_constructor(t_texture *texture);
void	data_constructor(t_data *data);
//parsing.c
void	parsing(char *file, t_data *data);
//checking_utils.c
int		is_valid_map_char(char c);
//parsing_utils.c
void	strip_newline(char *str);
void	get_map_dimensions(char **lines, t_map *map);
void	copy_map(char **lines, t_map *map);
//check_parsing.c
int		check_texture(t_texture *txtr);
int		check_map(t_map *map);
//free.c
void	free_array(char **tab);
//map.c
int		integrity_check(t_map *map);

#endif