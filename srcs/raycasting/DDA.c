/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDA.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilian <kilian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 13:12:53 by ktintim-          #+#    #+#             */
/*   Updated: 2025/05/29 19:23:56 by kilian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	intersection_point(t_dda *vars, t_data *data, double angle)
{
	double	ray_x;
	double	ray_y;
	double	ray_angle;

	ray_x = data->character->x_pose;
	ray_y = data->character->y_pose;
	if (angle > 360)
		angle -= 360;
	else if (angle < 0)
		angle += 360;
	ray_angle = return_radian(angle);
	while (data->map->map[(int)(ray_y / PIXEL)][(int)(ray_x / PIXEL)] != '1')
	{
		ray_x += cos(ray_angle) * vars->step_size;
		// printf("ray_x : %f\n", ray_x);
		ray_y += sin(ray_angle) * vars->step_size;
		// printf("ray_y : %f\n", ray_y);
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
	if (a < b)
		return (a);
	else
		return (b);
}

static void	dda_algo(t_dda vars, t_data *data, t_img *scn_img)
{
	double	dx;
	double	dy;
	double	xinc;
	double	yinc;
	double	x;
	double	y;
	int		steps;
	int		i;

	dx = vars.x - data->character->x_pose;
	dy = vars.y - data->character->y_pose;
	steps = return_abs_max((int)dx, (int)dy);
	xinc = dx / (float)steps;
	yinc = dy / (float)steps;
	x = data->character->x_pose;
	y = data->character->y_pose;
	i = 0;
	while (i < steps)
	{
		put_pixel(scn_img, x, y, 16755456);
		x += xinc;
		y += yinc;
		i++;
	}
}

void	dda(t_data *data, t_img *scn_img)
{
	t_dda	vars;
	int		i;

	vars.angle = data->character->angle_view - (FOV / 2);
	vars.step_size = 0.1;
	i = 0;
	while (i < FOV)
	{
		intersection_point(&vars, data, (vars.angle + i));
		dda_algo(vars, data, scn_img);
		i++;
	}
}
