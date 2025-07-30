/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:56:59 by cgoldens          #+#    #+#             */
/*   Updated: 2025/07/30 14:30:53 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/**
 * @brief check if all texture data are correct
 * 
 * @param txtr 
 * @return int 
 */
int	check_texture(t_texture *txtr)
{
	if (handle_texture_error(txtr))
		return (1);
	if (check_color(txtr->c_color) || check_color(txtr->f_color))
		return (1);
	if (check_path(txtr->n_path) || check_path(txtr->s_path)
		|| check_path(txtr->e_path) || check_path(txtr->w_path))
		return (1);
	return (0);
}

/**
 * @brief check spawnpoint and add it in struct
 * 
 * @param c 
 * @param i 
 * @param map 
 * @return int 
 */
int	check_spawn(char c, t_map *map, int cols, int rows)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (map->c_x != 0.0 && map->c_y != 0.0)
		{
			printf("Error\nToo many spawn points\n");
			exit(EXIT_FAILURE);
		}
		else
		{
			if (c == 'E')
				map->direction = EAST;
			else if (c == 'S')
				map->direction = SOUTH;
			else if (c == 'W')
				map->direction = WEST;
			else if (c == 'N')
				map->direction = NORTH;
			map->c_x = cols * PIXEL + 0.5;
			map->c_y = rows * PIXEL + 0.5;
			return (1);
		}
	}
	return (0);
}

/**
 * @brief check the map if it's right
 * 
 * @param map 
 * @return int 
 */
int	check_map(t_map *map)
{
	int		cols;
	int		rows;
	char	c;
	int		spawn_cnt;

	spawn_cnt = 0;
	if (map->rows == 0 || map->cols == 0)
		return (printf("Error\nMap missing in .cub file\n"), 1);
	rows = -1;
	while (++rows < map->rows)
	{
		cols = -1;
		while (++cols < map->cols)
		{
			c = map->map[rows][cols];
			if (!is_valid_map_char(c))
				return (printf("Error\nForbidden character: '%c'\n", c), 1);
			spawn_cnt += check_spawn(c, map, cols, rows);
		}
	}
	if (spawn_cnt == 0)
		return (printf("Error\nNo spawn point\n"), 1);
	return (0);
}

/**
 * @brief check if all data in file are correct
 * 
 * @param data 
 */
void	check_parsing(t_data *data)
{
	if (!has_all_identifiers(data->texture->id))
		print_error("Error\nOne or more identifier missing", \
EXIT_FAILURE, data);
	if (check_texture(data->texture) || check_map(data->map)
		|| integrity_check(data->map))
	{
		free(data->character);
		free(data->texture->north);
		free(data->texture->n_path);
		free(data->texture->south);
		free(data->texture->s_path);
		free(data->texture->east);
		free(data->texture->e_path);
		free(data->texture->west);
		free(data->texture->w_path);
		free(data->texture->c_door);
		free(data->texture->id);
		free(data->texture);
		free_array(data->map->map);
		free(data->key);
		free(data->map);
		free(data->window);
		exit(EXIT_FAILURE);
	}
}

/**
 * @brief check if a string is fill with space
 * 
 * @param str 
 * @return int 
 */
int	is_empty_or_whitespace(const char *str)
{
	int	i;

	if (!str)
		return (1);
	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t'
			&& str[i] != '\n' && str[i] != '\v'
			&& str[i] != '\f' && str[i] != '\r')
			return (0);
		i++;
	}
	return (1);
}
