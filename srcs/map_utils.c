/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:15:26 by cgoldens          #+#    #+#             */
/*   Updated: 2025/05/21 15:39:13 by cgoldens         ###   ########.fr       */
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
int	is_valid_cell(t_map *map, int x, int y)
{
	return (x >= 0 && y >= 0 && x < map->rows && y < map->cols);
}

/**
 * @brief 
 * 
 * @param c 
 * @return int 
 */
int	is_accessible(char c)
{
	return (c == '0' || is_player(c) || c == '2');
}

/**
 * @brief 
 * 
 * @param c 
 * @return int 
 */
int	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

/**
 * @brief 
 * 
 * @param map 
 * @return char** 
 */
char	**dup_map(t_map *map)
{
	char	**copy;
	int		x;

	copy = malloc(sizeof(char *) * (map->rows + 1));
	if (!copy)
		return (NULL);
	x = 0;
	while (x < map->rows)
	{
		copy[x] = ft_strdup(map->map[x]);
		if (!copy[x])
		{
			x--;
			while (x >= 0)
			{
				free(copy[x]);
				x--;
			}
			free(copy);
			return (NULL);
		}
		x++;
	}
	copy[x] = NULL;
	return (copy);
}

/**
 * @brief 
 * 
 * @param map 
 * @param x 
 * @param y 
 * @param visited 
 * @return int 
 */
int	flood_fill_from(t_map *map, int x, int y, char **visited)
{
	char	c;

	if (!is_valid_cell(map, x, y))
		return (0);
	if (visited[x][y] || map->map[x][y] == '1')
		return (1);
	c = map->map[x][y];
	if (c == ' ' || c == '\0')
		return (0);
	if (!is_accessible(c))
		return (1);
	if (!check_neighbors(map, x, y))
		return (0);
	visited[x][y] = 1;
	if (!flood_fill_from(map, x - 1, y, visited))
		return (0);
	if (!flood_fill_from(map, x + 1, y, visited))
		return (0);
	if (!flood_fill_from(map, x, y - 1, visited))
		return (0);
	if (!flood_fill_from(map, x, y + 1, visited))
		return (0);
	return (1);
}
