/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_constructor.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 10:17:36 by ktintim-          #+#    #+#             */
/*   Updated: 2025/07/01 11:26:44 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/**
 * @brief constructor of texture structure
 * 
 * @param texture 
 */
void	texture_constructor(t_texture *texture)
{
	texture->north = malloc(sizeof(t_img));
	texture->south = malloc(sizeof(t_img));
	texture->west = malloc(sizeof(t_img));
	texture->east = malloc(sizeof(t_img));
	texture->c_door = malloc(sizeof(t_img));
	texture->o_door = malloc(sizeof(t_img));
	texture->n_path = NULL;
	texture->s_path = NULL;
	texture->w_path = NULL;
	texture->e_path = NULL;
}

/**
 * @brief constructor of image structure
 * 
 * @param img 
 * @param mlx 
 * @param height 
 * @param width 
 */
void	image_constructor(t_img *img, void *mlx, int height, int width)
{
	img->height = height;
	img->width = width;
	img->ptr = mlx_new_image(mlx, img->width, img->height);
	img->addr = mlx_get_data_addr(img->ptr, &img->bpp, \
		&img->line_length, &img->endian);
}

/**
 * @brief constructor of map structure
 * 
 * @param map 
 */
void	map_constructor(t_map *map)
{
	map->map = malloc(sizeof(char **));
	map->cols = 0;
	map->rows = 0;
	map->direction = 0.0;
	map->c_x = 0.0;
	map->c_y = 0.0;
}

void	xpm_img_constructor(t_img *img, char *path, void *mlx)
{
	img->ptr = mlx_xpm_file_to_image(mlx, path, &img->width, &img->height);
	img->addr = mlx_get_data_addr(img->ptr, &img->bpp, \
		&img->line_length, &img->endian);
}
