/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:46:40 by ktintim-          #+#    #+#             */
/*   Updated: 2025/05/20 10:52:05 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

//struct_constructor
	//constructor1.c
void	window_constructor(t_window *window);
void	texture_constructor(t_texture *texture);
void	data_constructor(t_data *data);

//raycasting
	//mlx_action.c
void	mlx_action(t_data *data, char *map[8]);
int		close_window(void *param);
	//key_handler.c
int		key_handler(int key, void *param);
	//draw_panel.c
void	draw_panel(char *img_data, int size_line, int color);
void	draw_map(t_data *data, char *map[8]);

#endif