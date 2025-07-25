/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilian <kilian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:46:23 by cgoldens          #+#    #+#             */
/*   Updated: 2025/07/25 07:03:21 by kilian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/**
 * @brief check the char to know if it's a valid char in the map
 * 
 * @param c 
 * @return int 
 */
int	is_valid_map_char(char c)
{
	return (c == '0' || c == '1' || c == '2' || c == '3'
		|| c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == ' ' || c == '\n' || c == '\0');
}

/**
 * @brief check is the color tab respect the range
 * 
 * @param color 
 * @return int 
 */
int	check_color(int color[3])
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (!(color[i] >= 0 && color[i] <= 255))
			return (printf("Error\nThe color channel nb %d is not valid.\n", \
i + 1), 1);
		i++;
	}
	return (0);
}

/**
 * @brief check if texture path exist
 * 
 * @param path 
 * @return int 
 */
int	check_path(char *path)
{
	int		fd;
	char	*tmp_path;

	tmp_path = path;
	fd = open(tmp_path, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nThe path '%s' is incorrect\n", path);
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}

/**
 * @brief handle error from identifier
 * 
 * @param txtr 
 * @return int 
 */
int	handle_texture_error(t_texture *txtr)
{
	if (!txtr->n_path)
		return (printf("Error\nNo NO identifier find"), 1);
	if (!txtr->e_path)
		return (printf("Error\nNo EA identifier find"), 1);
	if (!txtr->s_path)
		return (printf("Error\nNo SO identifier find"), 1);
	if (!txtr->w_path)
		return (printf("Error\nNo WE identifier find"), 1);
	if (txtr->c_color[0] == -1 && txtr->c_color[1] == -1
		&& txtr->c_color[2] == -1)
		return (printf("Error\nNo C identifier find"), 1);
	if (txtr->f_color[0] == -1 && txtr->f_color[1] == -1
		&& txtr->f_color[2] == -1)
		return (printf("Error\nNo F identifier find"), 1);
	return (0);
}

/**
 * @brief check state of identifier in .cub file
 * 
 * @param id 
 * @return int 
 */
int	has_all_identifiers(t_identifiers *id)
{
	return (id->no && id->so && id->we && id->ea && id->f && id->c);
}
