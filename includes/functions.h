/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilian <kilian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:46:40 by ktintim-          #+#    #+#             */
/*   Updated: 2025/05/21 21:11:20 by kilian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

//struct_constructor
	//constructor1.c
void	window_constructor(t_window *window);
void	texture_constructor(t_texture *texture);
void	data_constructor(t_data *data);
void	image_constructor(t_img *img, void *mlx, int height, int width);

//raycasting
	//mlx_action.c
void	mlx_action(t_data *data, char *map[8]);
int		close_window(void *param);
	//key_handler.c
int		key_handler(int key, void *param);
	//draw_panel.c
void	draw_square(t_img *img, int square_size, int color);
void	draw_map(t_data *data, char *map[8]);
void	draw_rotated_square(t_img *img, double angle_rad);
	//rotate_image.c
void	rotate_image(t_img *src, t_img *dest, double angle_degre);
#endif