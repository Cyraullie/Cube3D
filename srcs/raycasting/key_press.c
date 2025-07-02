/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:37:35 by ktintim-          #+#    #+#             */
/*   Updated: 2025/07/01 11:34:05 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

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
