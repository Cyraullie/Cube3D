/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:46:23 by cgoldens          #+#    #+#             */
/*   Updated: 2025/05/20 15:30:40 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

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
