/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:14:59 by ktintim-          #+#    #+#             */
/*   Updated: 2025/05/26 11:07:06 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

//TODO

int	key_press(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (key == KEY_ESC)
		close_window(data);
	if (key == KEY_W)
		data->key->w = true;
	if (key == KEY_S)
		data->key->s = true;
	if (key == KEY_A)
		data->key->a = true;
	if (key == KEY_D)
		data->key->d = true;
	if (key == KEY_LEFT)
		data->key->left = true;
	if (key == KEY_RIGHT)
		data->key->right = true;
	return (0);
}

int	key_unpress(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (key == KEY_W)
		data->key->w = false;
	if (key == KEY_S)
		data->key->s = false;
	if (key == KEY_A)
		data->key->a = false;
	if (key == KEY_D)
		data->key->d = false;
	if (key == KEY_LEFT)
		data->key->left = false;
	if (key == KEY_RIGHT)
		data->key->right = false;
	return (0);
}

void	key_pressed(t_data *data)
{
	if (data->key->w == true)
		data->character->y_pose -= MOOVE_SPPED;
	if (data->key->s == true)
		data->character->y_pose += MOOVE_SPPED;
	if (data->key->a == true)
		data->character->x_pose -= MOOVE_SPPED;
	if (data->key->d == true)
		data->character->x_pose += MOOVE_SPPED;
	if (data->key->left == true)
		data->character->angle_view -= VIEW_SPEED;
	if (data->key->right == true)
		data->character->angle_view += VIEW_SPEED;
}
