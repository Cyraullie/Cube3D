/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:06:39 by ktintim-          #+#    #+#             */
/*   Updated: 2025/05/26 10:55:08 by ktintim-         ###   ########.fr       */
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
	t_img	new_img;

	image_constructor(&new_img, data->window->mlx, \
			data->character->square->height, data->character->square->width);
	rotate_image(data->character->square, &new_img, \
				data->character->angle_view);
	mlx_put_image_to_window(data->window->mlx, \
			data->window->win, new_img.ptr, \
			data->character->x_pose, data->character->y_pose);
	mlx_destroy_image(data->window->mlx, new_img.ptr);
}

// char *map[] = {
// 	"111111111111111",
// 	"100000000000001",
// 	"101111111110101",
// 	"101000000010101",
// 	"101000000010101",
// 	"101000000010101",
// 	"100000000000001",
// 	"111111111111111"
// };
// draw_map(data, map);
static int	game_loop(void	*param)
{
	t_data	*data;

	data = (t_data *)param;
	key_pressed(data);
	put_character(data);
	return (0);
}

void	mlx_action(t_data *data, char *map[8])
{
	(void)map;
	mlx_hook(data->window->win, 17, 0, close_window, data);
	mlx_hook(data->window->win, 2, 1L << 0, key_press, data);
	mlx_hook(data->window->win, 3, 1L << 1, key_unpress, data);
	mlx_loop_hook(data->window->mlx, game_loop, data);
	mlx_loop(data->window->mlx);
}
