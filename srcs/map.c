/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:37:04 by cgoldens          #+#    #+#             */
/*   Updated: 2025/05/21 15:39:08 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"
//TODO do brief
/**
 * @brief 
 * 
 * @param map 
 * @param x 
 * @param y 
 * @return int 
 */
static int	check_neighbors(t_map *map, int x, int y)
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
		if (!is_valid_cell(map, nx, ny))
			return (0);
		if (map->map[nx][ny] == ' ' || map->map[nx][ny] == '\0')
			return (0);
		i++;
	}
	return (1);
}

/**
 * @brief 
 * 
 * @param map 
 * @return char** 
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
 * @brief 
 * 
 * @param map 
 * @return int 
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
 * @brief 
 * 
 * @param map 
 * @return int 
 */
int	integrity_check(t_map *map)
{
	if (!flood_fill_zone_check(map))
		return (1);
	return (0);
}
