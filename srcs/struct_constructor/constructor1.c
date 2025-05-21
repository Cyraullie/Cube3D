/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilian <kilian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:42:35 by ktintim-          #+#    #+#             */
/*   Updated: 2025/05/21 19:39:44 by kilian           ###   ########.fr       */
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

void	image_constructor(t_img *img, void *mlx, int height, int width)
{
	img->height = height;
	img->width = width;
	img->ptr = mlx_new_image(mlx, img->width, img->height);
	img->addr = mlx_get_data_addr(img->ptr, &img->bpp, \
		&img->line_length, &img->endian);
}

void	character_constructor(t_character *character, void *mlx)
{
	character->square = malloc(sizeof(t_img));
	image_constructor(character->square, mlx, 64, 64);
	draw_panel(character->square->addr, \
				character->square->line_length, 16711680);
	character->fov = 0;
	character->x_pose = 0;
	character->y_pose = 0;
}

void	data_constructor(t_data *data)
{
	int	bpp;
	int	endian;

	bpp = 32;
	endian = 0;
	data->texture = malloc(sizeof(t_texture));
	data->window = malloc(sizeof(t_window));
	data->character = malloc(sizeof(t_character));
	window_constructor(data->window);
	texture_constructor(data->texture);
	character_constructor(data->character, data->window->mlx);
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
