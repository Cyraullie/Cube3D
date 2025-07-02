/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:59:14 by cgoldens          #+#    #+#             */
/*   Updated: 2025/07/02 14:23:53 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

/**
 * @brief Get the maximum width of any line in the raw map.
 * 
 * @param raw_lines Array of raw map lines.
 * @return int Length of the longest line.
 */
int	get_max_line_length(char **raw_lines)
{
	int	i;
	int	max;
	int	len;

	i = 0;
	max = 0;
	while (raw_lines[i])
	{
		len = ft_strlen(raw_lines[i]);
		if (len > max)
			max = len;
		i++;
	}
	return (max);
}

/**
 * @brief Allocate memory for each line of the map and initialize it to zero.
 * 
 * @param map The map structure to fill.
 * @param line_count Number of lines to allocate.
 * @param max_len Maximum length of each line (number of columns).
 */
static void	allocate_map_lines(t_map *map, int line_count, int max_len)
{
	int	i;

	map->map = malloc(sizeof(char *) * (line_count + 1));
	if (!map->map)
		return ;
	i = 0;
	while (i < line_count)
	{
		map->map[i] = ft_calloc(max_len + 2, sizeof(char));
		if (!map->map[i])
		{
			while (--i >= 0)
				free(map->map[i]);
			free(map->map);
			map->map = NULL;
			return ;
		}
		i++;
	}
	map->map[line_count] = NULL;
}

/**
 * @brief Fill each line of the map with characters from raw_lines,
 *        and pad shorter lines with spaces.
 * 
 * @param raw_lines Raw map lines.
 * @param map Map structure to fill.
 * @param max_len Length to pad each line to.
 */
static void	fill_map_lines(char **raw_lines, t_map *map, int max_len)
{
	int	i;
	int	j;
	int	end;

	i = 0;
	while (raw_lines[i])
	{
		j = 0;
		end = 0;
		while (j < max_len)
		{
			if (raw_lines[i][j] == '\0')
			{
				end++;
				break ;
			}
			map->map[i][j] = ' ';
			if (end == 0)
				map->map[i][j] = raw_lines[i][j];
			j++;
		}
		map->map[i][j] = '\0';
		i++;
	}
}

/**
 * @brief Copy the raw map into a properly sized rectangular array in the map,
 *        padding shorter lines with spaces.
 * 
 * @param raw_lines Array of raw map lines.
 * @param map Map structure to fill.
 */
void	copy_map(char **raw_lines, t_map *map)
{
	int	line_count;
	int	max_len;

	line_count = 0;
	while (raw_lines[line_count])
		line_count++;
	max_len = get_max_line_length(raw_lines);
	map->rows = line_count;
	map->cols = max_len;
	allocate_map_lines(map, line_count, max_len);
	if (!map->map)
		return ;
	fill_map_lines(raw_lines, map, max_len);
	line_count = 0;
}
