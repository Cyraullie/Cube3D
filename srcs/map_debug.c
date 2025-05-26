/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_debug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:22:20 by cgoldens          #+#    #+#             */
/*   Updated: 2025/05/26 15:26:55 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	visio_map(char **map, int rows, int cols)
{
	for (int x = 0; x < rows; x++)
	{
		for (int y = 0; y < cols && map[x][y] != '\0'; y++)
			printf("%c", map[x][y]);
		printf("\n");
	}
}

int	flood_fill_from_debug(t_map *map, int x, int y, char **visited, char **debug_map)
{
	if (!is_valid_cell(map, x, y))
	{
		printf("❌ Case (%d,%d) est en dehors des limites\n", x, y);
		return (0);
	}

	if (visited[x][y] || map->map[x][y] == '1')
		return (1);

	char c = map->map[x][y];

	if (c == ' ' || c == '\0')
	{
		printf("❌ Zone ouverte détectée à (%d,%d)\n", x, y);
		return (0);
	}

	if (!is_accessible(c))
		return (1);

	visited[x][y] = 1;

	if (c == '0' || c == '2')
		debug_map[x][y] = '.';
	else if (is_player(c))
		debug_map[x][y] = c;

	const int dx[4] = {-1, 1, 0, 0};
	const int dy[4] = {0, 0, -1, 1};

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (!is_valid_cell(map, nx, ny))
		{
			printf("❌ Case accessible (%d,%d) touche l’extérieur via (%d,%d)\n", x, y, nx, ny);
			return (0);
		}

		char adj = map->map[nx][ny];
		if (adj == ' ' || adj == '\0')
		{
			printf("❌ Case accessible (%d,%d) touche une case vide (%d,%d)\n", x, y, nx, ny);
			return (0);
		}
	}

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (!flood_fill_from_debug(map, nx, ny, visited, debug_map))
			return (0);
	}

	return (1);
}

int	flood_fill_zone_check_debug(t_map *map)
{
	char **visited = malloc(sizeof(char *) * map->rows);
	char **debug_map = dup_map(map);
	if (!visited || !debug_map)
		return (0);

	for (int i = 0; i < map->rows; i++)
	{
		visited[i] = calloc(map->cols, sizeof(char));
		if (!visited[i])
			return (0);
	}

	for (int x = 0; x < map->rows; x++)
	{
		for (int y = 0; y < map->cols; y++)
		{
			if (!visited[x][y] && is_accessible(map->map[x][y]))
			{
				if (!flood_fill_from_debug(map, x, y, visited, debug_map))
				{
					printf("\n🧯 Map après inondation (debug):\n");
					visio_map(debug_map, map->rows, map->cols);

					for (int i = 0; i < map->rows; i++)
					{
						free(visited[i]);
						free(debug_map[i]);
					}
					free(visited);
					free(debug_map);
					return (0);
				}
			}
		}
	}

	printf("\n🧯 Map après inondation (debug):\n");
	visio_map(debug_map, map->rows, map->cols);

	for (int i = 0; i < map->rows; i++)
	{
		free(visited[i]);
		free(debug_map[i]);
	}
	free(visited);
	free(debug_map);
	return (1);
}

int	integrity_check_debug(t_map *map)
{
	if (!flood_fill_zone_check_debug(map))
	{
		printf("❌ Map a des zones accessibles non fermées\n");
		return (1);
	}

	printf("\n✅ Mur extérieur fermé\n");
	return (0);
}
