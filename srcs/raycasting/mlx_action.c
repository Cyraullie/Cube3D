/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilian <kilian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:06:39 by ktintim-          #+#    #+#             */
/*   Updated: 2025/06/15 11:31:05 by kilian           ###   ########.fr       */
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

long long	get_time(void)
{
	struct timeval	time;
	long long		result;

	gettimeofday(&time, NULL);
	result = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (result);
}

static void	update_time(t_data *data)
{
	data->last_frame = data->actual_frame;
	data->actual_frame = get_time();
}

static int	game_loop(void	*param)
{
	t_data	*data;
	t_img	screen_image;

	data = (t_data *)param;
	image_constructor(&screen_image, data->window->mlx, SCR_HEIGHT, SCR_WEIGHT);
	key_pressed(data);
	raycasting(data, &screen_image);
	draw_floor(&screen_image, rgb_to_hex(data->texture->f_color));
	draw_ceiling(&screen_image, rgb_to_hex(data->texture->c_color));
	mlx_put_image_to_window(data->window->mlx, \
		data->window->win, screen_image.ptr, 0, 0);
	mlx_destroy_image(data->window->mlx, screen_image.ptr);
	return (0);
}

void	mlx_action(t_data *data)
{
	update_time(data);
	mlx_mouse_hide(data->window->mlx, data->window->win);
	mlx_hook(data->window->win, 6, 1L << 6, mouse_move, data);
	mlx_hook(data->window->win, 17, 0, close_window, data);
	mlx_hook(data->window->win, 2, 1L << 0, key_press, data);
	mlx_hook(data->window->win, 3, 1L << 1, key_unpress, data);
	mlx_loop_hook(data->window->mlx, game_loop, data);
	mlx_loop(data->window->mlx);
}
