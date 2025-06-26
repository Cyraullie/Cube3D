/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_constructor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:42:35 by ktintim-          #+#    #+#             */
/*   Updated: 2025/06/26 11:12:20 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"
//TODO a changer apres parce que plius comme ca :)
/**
 * @brief constructor of windows structure
 * 
 * @param window 
 * @param map 
 */
void	window_constructor(t_window *window)
{
	window->mlx = mlx_init();
	window->win = mlx_new_window(window->mlx, SCR_WIDTH, SCR_HEIGHT, "Cub3D");
}

/**
 * @brief constructor of key structure
 * 
 * @param key 
 */
void	key_constructor(t_key *key)
{
	key->w = false;
	key->s = false;
	key->a = false;
	key->d = false;
	key->e = false;
	key->left = false;
	key->right = false;
}

/**
 * @brief constructor of character structure
 * 
 * @param character 
 * @param mlx 
 * @param map 
 */
void	character_constructor(t_character *character, void *mlx, t_map *map)
{
	(void)mlx;
	character->angle_view = map->direction;
	character->x_pose = map->c_x;
	character->y_pose = map->c_y;
	character->plane_x = 0.0;
	character->plane_y = 0.66;
}

/**
 * @brief constructor of data structure
 * 
 * @param data 
 * @param argv 
 */
void	data_constructor(t_data *data, char *argv)
{
	int		fd;

	fd = open(argv, O_RDONLY);
	data->actual_frame = get_time();
	data->texture = malloc(sizeof(t_texture));
	data->map = malloc(sizeof(t_map));
	data->window = malloc(sizeof(t_window));
	data->character = malloc(sizeof(t_character));
	data->key = malloc(sizeof(t_key));
	map_constructor(data->map);
	texture_constructor(data->texture);
	parsing(fd, data);
	close(fd);
	window_constructor(data->window);
	xpm_img_constructor(data->texture->north, data->texture->n_path, \
						data->window->mlx);
	xpm_img_constructor(data->texture->south, data->texture->s_path, \
						data->window->mlx);
	xpm_img_constructor(data->texture->east, data->texture->e_path, \
						data->window->mlx);
	xpm_img_constructor(data->texture->west, data->texture->w_path, \
						data->window->mlx);
	character_constructor(data->character, data->window->mlx, data->map);
	key_constructor(data->key);
}
