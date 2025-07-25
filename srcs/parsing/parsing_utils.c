/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilian <kilian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:59:14 by cgoldens          #+#    #+#             */
/*   Updated: 2025/07/25 07:03:21 by kilian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

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

/**
 * @brief check if rgb channel are correct
 * 
 * @param str 
 * @return int 
 */
int	check_rgb(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	is_map_line(const char *line)
{
	int	i;
	int	has_valid_char;

	if (!line)
		return (0);
	i = 0;
	has_valid_char = 0;
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != ' '
			&& line[i] != 'N' && line[i] != 'S' && line[i] != 'E'
			&& line[i] != 'W' && line[i] != '2' && line[i] != '3'
			&& line[i] != '\n')
			return (0);
		if (line[i] != ' ' && line[i] != '\n')
			has_valid_char = 1;
		i++;
	}
	return (has_valid_char);
}

/**
 * @brief function to get all map data
 * 
 * @param raw_lines 
 * @param data 
 */
void	map_data(char **raw_lines, t_data *data)
{
	get_map_dimensions(raw_lines, data->map);
	copy_map(raw_lines, data->map);
}
