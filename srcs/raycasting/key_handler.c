/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:14:59 by ktintim-          #+#    #+#             */
/*   Updated: 2025/07/16 13:11:51 by cgoldens         ###   ########.fr       */
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
		data->character->angle_view += data->character->view_speed / 1.5;
	}
	else if (x < (SCR_WIDTH / 2))
	{
		data->character->angle_view -= data->character->view_speed / 1.5;
	}
	mlx_mouse_move(data->window->mlx, data->window->win, \
SCR_WIDTH / 2, SCR_HEIGHT / 2);
	return (0);
}

double	new_x(double angle, t_data *data)
{
	return (data->character->move_speed * cos(return_radian(angle)));
}

double	new_y(double angle, t_data *data)
{
	return (data->character->move_speed * sin(return_radian(angle)));
}

static void	key_press_2(t_data *data)
{
	if (data->key->d == true && check_d(data) == 0)
	{
		data->character->x_pose += new_x(data->character->angle_view + 90, \
data);
		data->character->y_pose += new_y(data->character->angle_view + 90, \
data);
	}
	if (data->key->left == true)
		data->character->angle_view -= data->character->view_speed;
	if (data->key->right == true)
		data->character->angle_view += data->character->view_speed;
	if (data->character->angle_view >= 360)
		data->character->angle_view -= 360;
	else if (data->character->angle_view < 0)
		data->character->angle_view += 360;
}

void	key_pressed(t_data *data)
{
	if (data->key->w == true && check_w(data) == 0)
	{
		data->character->x_pose += new_x(data->character->angle_view, data);
		data->character->y_pose += new_y(data->character->angle_view, data);
	}
	if (data->key->s == true && check_s(data) == 0)
	{
		data->character->x_pose -= new_x(data->character->angle_view, data);
		data->character->y_pose -= new_y(data->character->angle_view, data);
	}
	if (data->key->a == true && check_a(data) == 0)
	{
		data->character->x_pose += new_x(data->character->angle_view - 90, \
data);
		data->character->y_pose += new_y(data->character->angle_view - 90, \
data);
	}
	key_press_2(data);
}
