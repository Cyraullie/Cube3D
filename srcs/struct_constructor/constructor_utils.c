/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:04:21 by ktintim-          #+#    #+#             */
/*   Updated: 2025/07/28 16:03:52 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	malloc_data(t_data *data)
{
	data->texture = malloc(sizeof(t_texture));
	if (!data->texture)
		return (0);
	data->map = malloc(sizeof(t_map));
	if (!data->map)
		return (0);
	data->window = malloc(sizeof(t_window));
	if (!data->window)
		return (0);
	data->character = malloc(sizeof(t_character));
	if (!data->character)
		return (0);
	data->key = malloc(sizeof(t_key));
	if (!data->key)
		return (0);
	return (1);
}

int	malloc_texture(t_texture *texture)
{
	texture->north = malloc(sizeof(t_img));
	if (!texture->north)
		return (0);
	texture->south = malloc(sizeof(t_img));
	if (!texture->south)
		return (0);
	texture->west = malloc(sizeof(t_img));
	if (!texture->west)
		return (0);
	texture->east = malloc(sizeof(t_img));
	if (!texture->east)
		return (0);
	texture->c_door = malloc(sizeof(t_img));
	if (!texture->c_door)
		return (0);
	texture->id = malloc(sizeof(t_identifiers));
	if (!texture->id)
		return (0);
	return (1);
}
