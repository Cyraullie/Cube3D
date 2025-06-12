/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDA.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 13:12:53 by ktintim-          #+#    #+#             */
/*   Updated: 2025/06/12 15:25:18 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

// void	intersection_point(t_dda *vars, t_data *data, double angle)
// {
// 	double	ray_x;
// 	double	ray_y;
// 	double	ray_angle;

// 	ray_x = data->character->x_pose + (data->character->square->width / 2);
// 	ray_y = data->character->y_pose + (data->character->square->height / 2);
// 	while (angle > 360)
// 		angle -= 360;
// 	while (angle < 0)
// 		angle += 360;
// 	ray_angle = return_radian(angle);
// 	while (data->map->map[(int)(ray_y / PIXEL)][(int)(ray_x / PIXEL)] != '1')
// 	{
// 		ray_x += cos(ray_angle) * vars->step_size;
// 		ray_y += sin(ray_angle) * vars->step_size;
// 	}
// 	vars->x = ray_x;
// 	vars->y = ray_y;
// }

void	put_line(double dst, t_img *scn_img, t_data *data, double angle)
{
	double	ray_x;
	double	ray_y;
	int		i;

	ray_x = data->character->x_pose + data->character->square->width / 2;
	ray_y = data->character->y_pose + data->character->square->height / 2;
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
