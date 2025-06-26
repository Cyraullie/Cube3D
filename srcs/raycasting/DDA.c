/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDA.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 13:12:53 by ktintim-          #+#    #+#             */
/*   Updated: 2025/06/26 11:13:22 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	put_line(double dst, t_img *scn_img, t_data *data, double angle)
{
	double	ray_x;
	double	ray_y;
	int		i;

	ray_x = data->character->x_pose + PIXEL / 2;
	ray_y = data->character->y_pose + PIXEL / 2;
	i = 0;
	while (i < (int)dst)
	{
		put_pixel(scn_img, ray_x, ray_y, 0xFFA500);
		ray_x += cos(angle);
		ray_y += sin(angle);
		i++;
	}
}

void	dda(t_data *data, t_img *scn_img)
{
	t_grid	grid;
	double	angle;
	int		i;

	i = 0;
	while (i <= FOV)
	{
		angle = data->character->angle_view - (FOV / 2) + i;
		intersection_point(data, &grid, angle);
		put_line(grid.dst * PIXEL, scn_img, data, return_radian(angle));
		i++;
	}
}
