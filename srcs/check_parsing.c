/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:56:59 by cgoldens          #+#    #+#             */
/*   Updated: 2025/07/01 14:03:39 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

/**
 * @brief check is the color tab respect the range
 * 
 * @param color 
 * @return int 
 */
int	check_color(int color[3])
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (!(color[i] >= 0 && color[i] <= 255))
			return (printf("Erreur\nThe color channel nb %d is not valid.\n"\
				, i + 1), 1);
		i++;
	}
	return (0);
}

/**
 * @brief check if texture path exist
 * 
 * @param path 
 * @return int 
 */
int	check_path(char *path)
{
	int		fd;
	char	*tmp_path;

	tmp_path = path;
	fd = open(tmp_path, O_RDONLY);
	if (fd == -1)
	{
		printf("Erreur\nThe path '%s' is incorrect\n", path);
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}

/**
 * @brief check if all texture data are correct
 * 
 * @param txtr 
 * @return int 
 */
int	check_texture(t_texture *txtr)
{
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
		return (1);
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
