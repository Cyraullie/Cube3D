/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:06:39 by ktintim-          #+#    #+#             */
/*   Updated: 2025/05/20 16:11:39 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

//TODO free_all
int	close_window(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	(void)data;
	exit(0);
}

void	put_character(t_data *data)
{
	draw_rotated_square(data->character->square, data->character->fov);
	mlx_put_image_to_window(data->window->mlx, data->window->win, data->character->square->ptr, 100, 100);
}

static int	mlx_big_loop(t_data *data)
{
	// mlx_clear_window(data->window->mlx, data->window->win);
	char *map[] = {
		"111111111111111",
		"100000000000001",
		"101111111110101",
		"101000000010101",
		"101000000010101",
		"101000000010101",
		"100000000000001",
		"111111111111111"
	};
	draw_map(data, map);
	put_character(data);
	return (0);
}

void	mlx_action(t_data *data, char *map[8])
{
	(void)map;
	mlx_key_hook(data->window->win, key_handler, data);
	mlx_hook(data->window->win, 17, 0, close_window, &data);
	mlx_loop_hook(data->window->mlx, mlx_big_loop, data);
	mlx_loop(data->window->mlx);
}
