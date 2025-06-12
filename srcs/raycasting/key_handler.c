/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:14:59 by ktintim-          #+#    #+#             */
/*   Updated: 2025/06/12 14:10:32 by ktintim-         ###   ########.fr       */
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
	if (key == KEY_E)
		data->key->e = true;
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
	if (key == KEY_E)
	{
		data->key->e = false;
		data->key->e_lock = false;
	}
	return (0);
}

double	new_x(double angle)
{
	return (MOOVE_SPPED * cos(return_radian(angle)));
}

double	new_y(double angle)
{
	return (MOOVE_SPPED * sin(return_radian(angle)));
}

void	key_pressed(t_data *data)
{
	if (data->key->w == true && check_w(data) == 0)
	{
		data->character->x_pose += new_x(data->character->angle_view);
		data->character->y_pose += new_y(data->character->angle_view);
	}
	if (data->key->s == true && check_s(data) == 0)
	{
		data->character->x_pose -= new_x(data->character->angle_view);
		data->character->y_pose -= new_y(data->character->angle_view);
	}
	if (data->key->a == true && check_a(data) == 0)
	{
		data->character->x_pose += new_x(data->character->angle_view - 90);
		data->character->y_pose += new_y(data->character->angle_view - 90);
	}
	if (data->key->d == true && check_d(data) == 0)
	{
		data->character->x_pose += new_x(data->character->angle_view + 90);
		data->character->y_pose += new_y(data->character->angle_view + 90);
	}
	if (data->key->left == true)
		data->character->angle_view -= VIEW_SPEED;
	if (data->key->right == true)
		data->character->angle_view += VIEW_SPEED;
	if (data->character->angle_view >= 360)
		data->character->angle_view -= 360;
	else if (data->character->angle_view < 0)
		data->character->angle_view += 360;
	if (data->key->e == true && data->key->e_lock == false)
	{
		if (check_door(data) == 1)
			open_door(data);
		data->key->e_lock = true;
	}
}
