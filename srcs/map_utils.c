/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:15:26 by cgoldens          #+#    #+#             */
/*   Updated: 2025/05/22 11:35:05 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

/**
 * @brief Checks if a cell is within the bounds of the map.
 *
 * Verifies that the given coordinates (x, y) are inside the map's dimensions.
 *
 * @param map Pointer to the map structure.
 * @param x Row index.
 * @param y Column index.
 * @return 1 if the cell is valid, 0 otherwise.
 */
int	is_valid_cell(t_map *map, int x, int y)
{
	return (x >= 0 && y >= 0 && x < map->rows && y < map->cols);
}

/**
 * @brief Determines if a character represents an accessible cell.
 *
 * Checks if the given character is a walkable or interactive element
 * like an empty space, player start, or a sprite ('2').
 *
 * @param c The character to check.
 * @return 1 if accessible, 0 otherwise.
 */
int	is_accessible(char c)
{
	return (c == '0' || is_player(c) || c == '2');
}

/**
 * @brief Checks if a character represents a player start position.
 *
 * Validates if the character corresponds to one of the four cardinal directions
 * indicating a player spawn: 'N', 'S', 'E', or 'W'.
 *
 * @param c The character to check.
 * @return 1 if it's a player start, 0 otherwise.
 */
int	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

/**
 * @brief Duplicates the map into a new matrix.
 *
 * Allocates memory and copies the content of the original map into a new
 * matrix. Frees and returns NULL if any allocation fails.
 *
 * @param map Pointer to the map structure.
 * @return A new copy of the map, or NULL on failure.
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
 * @brief Recursive flood fill algorithm for map validation.
 *
 * Starting from a given cell, recursively explores accessible neighbors.
 * Fails if it reaches out-of-bounds or invalid characters, ensuring the map is 
 * closed.
 *
 * @param map Pointer to the map structure.
 * @param x Current row index.
 * @param y Current column index.
 * @param visited Matrix to track visited cells.
 * @return 1 if the flood fill is valid (closed), 0 otherwise.
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
