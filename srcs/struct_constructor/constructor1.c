/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:42:35 by ktintim-          #+#    #+#             */
/*   Updated: 2025/05/20 11:10:41 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	window_constructor(t_window *window)
{
	window->mlx = mlx_init();
	window->win = mlx_new_window(window->mlx, 960, 512, "Cub3D");
}

void	texture_constructor(t_texture *texture)
{
	texture->north = NULL;
	texture->south = NULL;
	texture->west = NULL;
	texture->east = NULL;
	texture->n_path = NULL;
	texture->s_path = NULL;
	texture->w_path = NULL;
	texture->e_path = NULL;
}

void	data_constructor(t_data *data)
{
	int	bpp;
	int	endian;

	bpp = 32;
	endian = 0;
	data->texture = malloc(sizeof(t_texture));
	data->window = malloc(sizeof(t_window));
	window_constructor(data->window);
	texture_constructor(data->texture);
	data->texture->black_img = mlx_new_image(data->window->mlx, 64, 64);
	data->texture->black_img_data = mlx_get_data_addr(data->texture->black_img, \
		&bpp, &(data->texture->black_img_line_size), &endian);
	data->texture->white_img = mlx_new_image(data->window->mlx, 64, 64);
	data->texture->white_img_data = mlx_get_data_addr(data->texture->white_img, \
		&bpp, &(data->texture->white_img_line_size), &endian);
	draw_panel(data->texture->white_img_data, \
		data->texture->white_img_line_size, 16777215);
	draw_panel(data->texture->black_img_data, \
		data->texture->black_img_line_size, 0);
}
