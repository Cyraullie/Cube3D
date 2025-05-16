/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:42:35 by ktintim-          #+#    #+#             */
/*   Updated: 2025/05/16 17:09:50 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

t_window	*window_constructor(void)
{
	t_window	window;

	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, 960, 540, "Cub3D");
	return (&window);
}

t_texture	*texture_constructor(void)
{
	t_texture	texture;

	texture.north = NULL;
	texture.south = NULL;
	texture.west = NULL;
	texture.east = NULL;
	texture.n_path = NULL;
	texture.s_path = NULL;
	texture.w_path = NULL;
	texture.e_path = NULL;
	return (&texture);
}

t_data	*data_constructor(void)
{
	t_data	data;

	data.window = window_constructor();
	data.texture = texture_constructor();
	return (&data);
}
