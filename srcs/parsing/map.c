/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:37:04 by cgoldens          #+#    #+#             */
/*   Updated: 2025/07/28 14:54:43 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

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
		if (nx < 0 || nx >= map->rows || ny < 0)
			return (0);
		if (ny >= (int)ft_strlen(map->map[nx]))
			return (0);
		if (!is_valid_cell(map, nx, ny))
			return (0);
		if (!is_valid_cell(map, x, y) || y >= (int)ft_strlen(map->map[x]))
			return (0);
		if (map->map[nx][ny] == ' ' || map->map[nx][ny] == '\0')
			return (0);
		i++;
	}
	return (1);
}

/**
 * @brief function to find the player position
 * 
 * @param map 
 * @param px 
 * @param py 
 * @return int 
 */
int	find_player(t_map *map, int *px, int *py)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->rows)
	{
		y = 0;
		while (y < (int)ft_strlen(map->map[x]))
		{
			if (is_player(map->map[x][y]))
			{
				*px = x;
				*py = y;
				return (1);
			}
			y++;
		}
		x++;
	}
	return (0);
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
	int		player_x;
	int		player_y;

	if (!find_player(map, &player_x, &player_y))
	{
		fprintf(stderr, "No player start found.\n");
		return (0);
	}
	visited = dup_map(map);
	if (!visited)
		return (0);
	if (!flood_fill_from(map, player_x, player_y, visited))
	{
		free_visited_partial(visited, map->rows);
		return (0);
	}
	free_visited_partial(visited, map->rows);
	return (1);
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
		return (printf("Error\nMap integrity compromise\n"), 1);
	return (0);
}

/**
 * @brief function to open/close target door
 * 
 * @param data 
 */
void	open_door(t_data *data)
{
	double	pose_x;
	double	pose_y;
	int		x;
	int		y;

	pose_x = (data->character->x_pose + 32) / PIXEL;
	pose_y = (data->character->y_pose + 32) / PIXEL;
	x = floor(pose_x + (cos(data->character->angle_view * 6.28 / 360)));
	y = floor(pose_y + (sin(data->character->angle_view * 6.28 / 360)));
	if (data->map->map[y][x] == '2')
	{
		data->map->map[y][x] = '3';
	}
	else if (data->map->map[y][x] == '3'
			&& data->map->map[(int)pose_y][(int)pose_x] != '3')
	{
		data->map->map[y][x] = '2';
	}
	else
		return ;
}
