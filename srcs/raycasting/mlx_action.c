/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:06:39 by ktintim-          #+#    #+#             */
/*   Updated: 2025/06/03 15:46:38 by cgoldens         ###   ########.fr       */
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

static void	put_character(t_data *data, t_img *screen_img)
{
	t_img	new_img;

	image_constructor(&new_img, data->window->mlx, \
			data->character->square->height, data->character->square->width);
	rotate_image(data->character->square, &new_img, \
				data->character->angle_view);
	fusion_image(screen_img, &new_img, \
				data->character->x_pose, data->character->y_pose);
	mlx_destroy_image(data->window->mlx, new_img.ptr);
}

static void	put_map(t_data *data, t_img *screen_img)
{
	int		i;
	int		j;
	t_img	white_square;
	t_img	door;

	image_constructor(&white_square, data->window->mlx, 63, 63);
	draw_square(&white_square, 63, 16777215);

	image_constructor(&door, data->window->mlx, 63, 63);
	draw_square(&door, 63, 5979153);
	i = 0;
	while (i < data->map->rows)
	{
		j = 0;
		while (j < data->map->cols)
		{
			if (data->map->map[i][j] == '1')
				fusion_image(screen_img, &white_square, (j * 64) - 1, \
					(i * 64) - 1);
			if (data->map->map[i][j] == '2')
				fusion_image(screen_img, &door, (j * 64) - 1, \
					(i * 64) - 1);
			j++;
		}
		i++;
	}
	mlx_destroy_image(data->window->mlx, white_square.ptr);
	mlx_destroy_image(data->window->mlx, door.ptr);
}

static int	game_loop(void	*param)
{
	t_data	*data;
	t_img	screen_image;

	data = (t_data *)param;
	//visio_map(data->map->map, data->map->rows, data->map->cols);
	image_constructor(&screen_image, data->window->mlx, data->map->rows * 64, data->map->cols * 64);
	key_pressed(data);
	put_map(data, &screen_image);
	put_character(data, &screen_image);
	dda(data, &screen_image);
	mlx_put_image_to_window(data->window->mlx, \
		data->window->win, screen_image.ptr, 0, 0);
	// mlx_clear_window(data->window->mlx, data->window->win);
	mlx_destroy_image(data->window->mlx, screen_image.ptr);
	return (0);
}

void	mlx_action(t_data *data)
{
	mlx_hook(data->window->win, 17, 0, close_window, data);
	mlx_hook(data->window->win, 2, 1L << 0, key_press, data);
	mlx_hook(data->window->win, 3, 1L << 1, key_unpress, data);
	mlx_loop_hook(data->window->mlx, game_loop, data);
	mlx_loop(data->window->mlx);
}
