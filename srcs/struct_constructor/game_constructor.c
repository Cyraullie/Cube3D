/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_constructor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:42:35 by ktintim-          #+#    #+#             */
/*   Updated: 2025/07/28 11:44:30 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

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
	character->move_speed = MOVE_SPEED;
	character->view_speed = VIEW_SPEED;
}

void	load_image(t_data *data)
{
	xpm_img_constructor(data->texture->north, data->texture->n_path, \
data->window->mlx);
	xpm_img_constructor(data->texture->south, data->texture->s_path, \
data->window->mlx);
	xpm_img_constructor(data->texture->east, data->texture->e_path, \
data->window->mlx);
	xpm_img_constructor(data->texture->west, data->texture->w_path, \
data->window->mlx);
	xpm_img_constructor(data->texture->c_door, CLOSE_DOOR_TXTR, \
data->window->mlx);
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

	if (open(argv, __O_DIRECTORY) != -1)
	{
		printf("Error\nThis path is a folder not a file\n");
		exit(EXIT_FAILURE);
	}
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
	window_constructor(data->window);
	load_image(data);
	character_constructor(data->character, data->window->mlx, data->map);
	key_constructor(data->key);
	data->close = 0;
}
