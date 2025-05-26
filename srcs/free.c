/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:22:42 by cgoldens          #+#    #+#             */
/*   Updated: 2025/05/22 11:35:57 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

/**
 * @brief Frees a NULL-terminated array of strings.
 *
 * Iterates through the array and frees each string, then frees the array itself.
 * Does nothing if the array pointer is NULL.
 *
 * @param tab The array of strings to free.
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
 * @brief Frees a partially allocated 2D array up to a given limit.
 *
 * Used to safely clean up memory when full allocation of a matrix fails.
 *
 * @param visited The array to be freed.
 * @param limit The number of rows to free.
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
