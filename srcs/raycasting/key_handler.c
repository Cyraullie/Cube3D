/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilian <kilian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:14:59 by ktintim-          #+#    #+#             */
/*   Updated: 2025/05/21 21:01:04 by kilian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

//TODO
int	key_handler(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (key == 65307)
		close_window(data);
	if (key == 97)
	{
		data->character->fov += 45;
		if (data->character->fov >= 360)
			data->character->fov -= 360;
		mlx_clear_window(data->window->mlx, data->window->win);
	}
	if (key == 100)
	{
		data->character->fov -= 45;
		if (data->character->fov < 0)
			data->character->fov += 360;
		mlx_clear_window(data->window->mlx, data->window->win);
	}
	return (0);
}
