/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 11:53:35 by cgoldens          #+#    #+#             */
/*   Updated: 2025/07/29 16:21:34 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/**
 * @brief 
 * 
 * @param txtr 
 * @param str 
 * @return int 
 */
int	check_double(t_texture *txtr, char *str)
{
	if (!ft_strncmp(str, "NO", 3) && txtr->id->no == 1)
		return (txtr->id->duplicate = 1, 1);
	else if (!ft_strncmp(str, "SO", 3) && txtr->id->so == 1)
		return (txtr->id->duplicate = 1, 1);
	else if (!ft_strncmp(str, "WE", 3) && txtr->id->we == 1)
		return (txtr->id->duplicate = 1, 1);
	else if (!ft_strncmp(str, "EA", 3) && txtr->id->ea == 1)
		return (txtr->id->duplicate = 1, 1);
	else if (!ft_strncmp(str, "F", 2) && txtr->id->f == 1)
		return (txtr->id->duplicate = 1, 1);
	else if (!ft_strncmp(str, "C", 2) && txtr->id->c == 1)
		return (txtr->id->duplicate = 1, 1);
	return (0);
}


int	check_xpm(char *str)
{
	char	**tab;

	strip_newline(str);
	tab = ft_split(str, ' ');
	if (!tab || !tab[0] || !tab[1])
		return (free_array(tab), 0);
	free_array(tab);
	return (0);
}

/**
 * @brief Get the data object from .cub
 * 
 * @param data 
 * @param buf 
 * @param fd 
 * @return int 
 */
int	get_data(t_data *data, char *buf, int fd)
{
	if (!has_all_identifiers(data->texture->id) && is_map_line(buf))
		return (1);
	if (!has_all_identifiers(data->texture->id))
	{
		if (check_xpm(buf) == 0)
			add_struct(data->texture, buf);
		else
			print_error("Error\nPath in %s didn't .xmp", EXIT_FAILURE, data);
	}
	else if (is_map_line(buf))
		return (parse_map(fd, data, buf), 2);
	else
	{
		free_and_close(fd, buf);
		print_error("Error\nInvalid line", EXIT_FAILURE, data);
	}
	return (0);
}

/**
 * @brief 
 * 
 * @param path 
 * @return int 
 */
int	check_file(char *path)
{
	int		fd;

	if (open(path, __O_DIRECTORY) != -1)
	{
		printf("Error\nAn identifier path is a folder not a file\n");
		exit(EXIT_FAILURE);
	}
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nThis path didnt exist\n");
		exit(EXIT_FAILURE);
	}
	return (fd);
}
