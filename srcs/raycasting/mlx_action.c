/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:06:39 by ktintim-          #+#    #+#             */
/*   Updated: 2025/05/19 15:41:24 by ktintim-         ###   ########.fr       */
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

void	mlx_action(t_data *data)
{
	mlx_key_hook(data->window->win, key_handler, data);
	mlx_hook(data->window->win, 17, 0, close_window, &data);
	mlx_loop(data->window->mlx);
}
