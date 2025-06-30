/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:14:59 by ktintim-          #+#    #+#             */
/*   Updated: 2025/06/30 16:39:20 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	mouse_move(int x, int y, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	(void)y;
	if (x > (SCR_WIDTH / 2))
	{
		data->character->angle_view += VIEW_SPEED / 1.5;
	}
	else if (x < (SCR_WIDTH / 2))
	{
		data->character->angle_view -= VIEW_SPEED / 1.5;
	}
	mlx_mouse_move(data->window->mlx, data->window->win, \
					SCR_WIDTH / 2, SCR_HEIGHT / 2);
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

static void	key_press_2(t_data *data)
{
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
	key_press_2(data);
}
