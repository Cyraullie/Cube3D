/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:37:04 by cgoldens          #+#    #+#             */
/*   Updated: 2025/06/30 17:21:13 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

/**
 * @brief Checks if all 4 neighboring cells around (x, y) are valid.
 *
 * Ensures that adjacent positions are within the map bounds and do not contain
 * spaces or null characters, which would indicate a map leak.
 *
 * @param map Pointer to the map structure.
 * @param x X coordinate (row) of the current position.
 * @param y Y coordinate (column) of the current position.
 * @return 1 if all neighbors are valid, 0 otherwise.
 */
int	check_neighbors(t_map *map, int x, int y)
{
	const int	dx[4] = {-1, 1, 0, 0};
	const int	dy[4] = {0, 0, -1, 1};
	int			i;
	int			nx;
	int			ny;

	i = 0;
	while (i < 4)
	{
		nx = x + dx[i];
		ny = y + dy[i];
		if (!is_valid_cell(map, x, y) || y >= (int)ft_strlen(map->map[x]))
			return (0);
		if (map->map[nx][ny] == ' ' || map->map[nx][ny] == '\0')
			return (0);
		i++;
	}
	return (1);
}

/**
 * @brief Allocates and initializes the visited matrix.
 *
 * The visited matrix tracks which cells have been visited during the flood fill.
 * It is allocated based on the map's dimensions and initialized to zero.
 *
 * @param map Pointer to the map structure.
 * @return A pointer to the allocated visited matrix, or NULL on failure.
 */
static char	**init_visited(t_map *map)
{
	char	**visited;
	int		i;

	visited = malloc(sizeof(char *) * map->rows);
	if (!visited)
		return (NULL);
	i = 0;
	while (i < map->rows)
	{
		visited[i] = calloc(map->cols, sizeof(char));
		if (!visited[i])
		{
			free_visited_partial(visited, i);
			return (NULL);
		}
		i++;
	}
	return (visited);
}

/**
 * @brief Performs flood fill to check if accessible zones are closed.
 *
 * Iterates over each cell in the map and applies the flood fill algorithm
 * to accessible areas. If an invalid path is found, the function returns 0.
 *
 * @param map Pointer to the map structure.
 * @return 1 if the map is valid (closed), 0 otherwise.
 */
int	flood_fill_zone_check(t_map *map)
{
	char	**visited;
	int		x;
	int		y;

	visited = init_visited(map);
	if (!visited)
		return (0);
	x = 0;
	while (x < map->rows)
	{
		y = 0;
		while (y < map->cols)
		{
			if (!visited[x][y] && is_accessible(map->map[x][y]))
			{
				if (!flood_fill_from(map, x, y, visited))
					return (free_visited_partial(visited, map->rows), 0);
			}
			y++;
		}
		x++;
	}
	return (free_visited_partial(visited, map->rows), 1);
}

/**
 * @brief Checks the integrity of the map.
 *
 * Runs a complete validation to ensure that the map does not contain leaks.
 * Delegates the logic to flood_fill_zone_check.
 *
 * @param map Pointer to the map structure.
 * @return 0 if the map is valid, 1 if the map is invalid.
 */
int	integrity_check(t_map *map)
{
	if (!flood_fill_zone_check(map))
		return (1);
	return (0);
}

void	open_door(t_data *data)
{
	double	pose_x;
	double	pose_y;
	int		x;
	int		y;

	pose_x = data->character->x_pose + \
								new_x(data->character->angle_view, data) + 32;
	pose_y = data->character->y_pose + \
								new_y(data->character->angle_view, data) + 32;
	x = (int)pose_x / PIXEL;
	y = (int)pose_y / PIXEL;
	if (data->map->map[y][x] == '2')
		data->map->map[y][x] = '3';
	else if (data->map->map[y][x] == '3')
		data->map->map[y][x] = '2';
	else
		return ;
}
