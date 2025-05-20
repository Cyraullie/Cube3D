/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:59:14 by cgoldens          #+#    #+#             */
/*   Updated: 2025/05/20 15:32:22 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

/**
 * @brief delete '\n' char
 * 
 * @param str 
 */
void	strip_newline(char *str)
{
	int	len;

	if (!str)
		return ;
	len = 0;
	while (str[len])
		len++;
	if (len > 0 && str[len - 1] == '\n')
		str[len - 1] = '\0';
}

/**
 * @brief Get the map dimensions object
 * 
 * @param lines 
 * @param map 
 */
void	get_map_dimensions(char **lines, t_map *map)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	map->rows = 0;
	map->cols = 0;
	while (lines[i])
	{
		len = ft_strlen(lines[i]);
		if (len > map->cols)
			map->cols = len;
		map->rows++;
		i++;
	}
}

void	copy_map(char **lines, t_map *map)
{
	int	i;

	i = 0;
	map->map = malloc(sizeof(char *) * (map->rows + 1));
	if (!map->map)
	{
		perror("malloc map");
		exit(EXIT_FAILURE);
	}
	while (i < map->rows)
	{
		map->map[i] = ft_strdup(lines[i]);
		if (!map->map[i])
		{
			perror("malloc line");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	map->map[i] = NULL;
}
