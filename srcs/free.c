/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:22:42 by cgoldens          #+#    #+#             */
/*   Updated: 2025/05/21 15:39:11 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

//TODO do brief
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

/**
 * @brief 
 * 
 * @param visited 
 * @param limit 
 */
void	free_visited_partial(char **visited, int limit)
{
	int	i;

	i = 0;
	while (i < limit)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}
