/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_protection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:02:14 by ktintim-          #+#    #+#             */
/*   Updated: 2025/07/28 15:57:20 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	destroy_texture_image(t_texture *texture, void *mlx)
{
	if (texture->north->ptr)
		mlx_destroy_image(mlx, texture->north->ptr);
	if (texture->south->ptr)
		mlx_destroy_image(mlx, texture->south->ptr);
	if (texture->east->ptr)
		mlx_destroy_image(mlx, texture->east->ptr);
	if (texture->west->ptr)
		mlx_destroy_image(mlx, texture->west->ptr);
	if (texture->c_door->ptr)
		mlx_destroy_image(mlx, texture->c_door->ptr);
}

static void	free_data_texture(t_texture *texture, void *mlx)
{
	if (texture->n_path)
		free(texture->n_path);
	if (texture->s_path)
		free(texture->s_path);
	if (texture->w_path)
		free(texture->w_path);
	if (texture->e_path)
		free(texture->e_path);
	destroy_texture_image(texture, mlx);
	if (texture->north)
		free(texture->north);
	if (texture->south)
		free(texture->south);
	if (texture->west)
		free(texture->west);
	if (texture->east)
		free(texture->east);
	if (texture->c_door)
		free(texture->c_door);
	free(texture);
}

static void	free_data_map(t_map *map)
{
	if (map->map)
		free_array(map->map);
	free(map);
}

static void	free_data_window(t_window *window)
{
	if (window->mlx)
	{
		mlx_destroy_window(window->mlx, window->win);
		mlx_destroy_display(window->mlx);
		free(window->mlx);
	}
	free(window);
}

void	correct_free(t_data *data)
{
	if (data->texture->id)
		free(data->texture->id);
	if (data->texture)
		free_data_texture(data->texture, data->window->mlx);
	if (data->map)
		free_data_map(data->map);
	if (data->window)
		free_data_window(data->window);
	if (data->character)
		free(data->character);
	if (data->key)
		free(data->key);
}
