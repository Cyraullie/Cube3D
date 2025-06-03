/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:59:14 by cgoldens          #+#    #+#             */
/*   Updated: 2025/06/03 16:07:45 by cgoldens         ###   ########.fr       */
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
