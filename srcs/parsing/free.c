/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:22:42 by cgoldens          #+#    #+#             */
/*   Updated: 2025/07/28 14:54:32 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

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

/**
 * @brief free all texture data
 * 
 * @param text 
 * @param mlx 
 */
void	free_text(t_texture *text, void *mlx)
{
	mlx_destroy_image(mlx, text->north->ptr);
	mlx_destroy_image(mlx, text->south->ptr);
	mlx_destroy_image(mlx, text->east->ptr);
	mlx_destroy_image(mlx, text->west->ptr);
	mlx_destroy_image(mlx, text->c_door->ptr);
	free(text->north);
	free(text->n_path);
	free(text->south);
	free(text->s_path);
	free(text->east);
	free(text->e_path);
	free(text->west);
	free(text->w_path);
	free(text->c_door);
}

/**
 * @brief free all data before close program
 * 
 * @param param 
 * @return int 
 */
int	close_window(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	free(data->character);
	free_text(data->texture, data->window->mlx);
	free(data->texture->id);
	free(data->texture);
	free(data->key);
	free_array(data->map->map);
	free(data->map);
	mlx_destroy_window(data->window->mlx, data->window->win);
	mlx_destroy_display(data->window->mlx);
	free(data->window->mlx);
	free(data->window);
	exit(0);
}

/**
 * @brief print error message and free all data and close program
 * 
 * @param msg 
 * @param status 
 */
void	print_error(char *msg, int status, t_data *data)
{
	printf("%s\n", msg);
	free(data->character);
	if (data->texture->n_path != NULL)
		free(data->texture->n_path);
	if (data->texture->s_path != NULL)
		free(data->texture->s_path);
	if (data->texture->e_path != NULL)
		free(data->texture->e_path);
	if (data->texture->w_path != NULL)
		free(data->texture->w_path);
	if (data->texture->c_door != NULL)
		free(data->texture->c_door);
	if (data->map->map != NULL)
		free_array(data->map->map);
	free(data->texture->north);
	free(data->texture->south);
	free(data->texture->east);
	free(data->texture->west);
	free(data->texture->id);
	free(data->texture);
	free(data->key);
	free(data->map);
	free(data->window);
	exit(status);
}
