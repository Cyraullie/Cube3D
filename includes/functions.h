/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:46:40 by ktintim-          #+#    #+#             */
/*   Updated: 2025/05/19 16:23:09 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H


void	window_constructor(t_window *window);
void	texture_constructor(t_texture *texture);
void	data_constructor(t_data *data);

void	test(char *file, t_data *data);
int	check_texture(t_texture *txtr);
void	strip_newline(char *str);
void	free_array(char **tab);
int	check_map(t_map *map);

#endif