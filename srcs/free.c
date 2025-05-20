/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:22:42 by cgoldens          #+#    #+#             */
/*   Updated: 2025/05/20 15:34:11 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

/**
 * @brief function to free an array
 * 
 * @param tab 
 */
void	free_array(char **tab)
{
	int	j;

	j = 0;
	if (!tab)
		return ;
	while (tab[j])
		free(tab[j++]);
	free(tab);
}
