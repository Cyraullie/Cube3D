/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:42:35 by ktintim-          #+#    #+#             */
/*   Updated: 2025/05/26 10:44:09 by ktintim-         ###   ########.fr       */
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
	draw_square(character->square, 30, 16711680);
	draw_line(character->square, 65535);
	character->angle_view = 180.0;
	character->x_pose = 200.0;
	character->y_pose = 200.0;
}

void	data_constructor(t_data *data)
{
	data->texture = malloc(sizeof(t_texture));
	data->window = malloc(sizeof(t_window));
	data->character = malloc(sizeof(t_character));
	data->key = malloc(sizeof(t_key));
	window_constructor(data->window);
	texture_constructor(data->texture);
	character_constructor(data->character, data->window->mlx);
	key_constructor(data->key);
}
