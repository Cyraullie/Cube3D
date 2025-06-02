/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDA.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 13:12:53 by ktintim-          #+#    #+#             */
/*   Updated: 2025/06/02 11:01:32 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	intersection_point(t_dda *vars, t_data *data, double angle)
{
	double	ray_x;
	double	ray_y;
	double	ray_angle;

	ray_x = data->character->x_pose + (data->character->square->width / 2);
	ray_y = data->character->y_pose + (data->character->square->height / 2);
	while (angle > 360)
		angle -= 360;
	while (angle < 0)
		angle += 360;
	ray_angle = return_radian(angle);
	while (data->map->map[(int)(ray_y / PIXEL)][(int)(ray_x / PIXEL)] != '1')
	{
		ray_x += cos(ray_angle) * vars->step_size;
		ray_y += sin(ray_angle) * vars->step_size;
	}
	vars->x = ray_x;
	vars->y = ray_y;
}

static int	return_abs_max(int a, int b)
{
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	if (a > b)
		return (a);
	else
		return (b);
}

static void	dda_algo(t_dda vars, t_data *data, t_img *scn_img)
{
	double	dx_dy[2];
	double	xinc_yinc[2];
	double	x_y[2];
	int		steps;
	int		i;

	dx_dy[0] = vars.x - (data->character->x_pose + \
						(data->character->square->width / 2));
	dx_dy[1] = vars.y - (data->character->y_pose + \
						(data->character->square->height / 2));
	steps = return_abs_max((int)dx_dy[0], (int)dx_dy[1]);
	xinc_yinc[0] = dx_dy[0] / (float)steps;
	xinc_yinc[1] = dx_dy[1] / (float)steps;
	x_y[0] = data->character->x_pose + (data->character->square->width / 2);
	x_y[1] = data->character->y_pose + (data->character->square->height / 2);
	i = 0;
	while (i < steps)
	{
		put_pixel(scn_img, x_y[0], x_y[1], 16755456);
		x_y[0] += xinc_yinc[0];
		x_y[1] += xinc_yinc[1];
		i++;
	}
}

void	dda(t_data *data, t_img *scn_img)
{
	t_dda	vars;
	int		i;

	vars.angle = data->character->angle_view - (FOV / 2);
	vars.step_size = 0.5;
	i = 0;
	while (i < FOV)
	{
		// intersection_point(&vars, data, (vars.angle + i));
		intersection_point(&vars, data, (vars.angle + i));
		put_pixel(scn_img, vars.x, vars.y, 3342080);
		dda_algo(vars, data, scn_img);
		i++;
	}
}
