/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 11:53:35 by cgoldens          #+#    #+#             */
/*   Updated: 2025/07/28 11:54:00 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

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
