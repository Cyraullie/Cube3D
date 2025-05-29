/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDA.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 13:12:53 by ktintim-          #+#    #+#             */
/*   Updated: 2025/05/29 12:07:35 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	intersection_point(t_dda *vars, t_data *data, double angle)
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
	while (data->map->map[(int)(ray_y / PIXEL)][(int)(ray_x / PIXEL)])
	{
		ray_x += cos(ray_angle) * vars->step_size;
		ray_y += sin(ray_angle) * vars->step_size;
	}
	vars->x = ray_x;
	vars->y = ray_y;
}

void	dda_algo(t_dda vars, t_data *data)
{
	
}

void	dda(t_data *data, t_img *scn_img)
{
	t_dda	vars;
	int		i;

	vars.angle = data->character->angle_view - 30;
	vars.step_size = 0.1;
	i = 0;
	while (i < 60)
	{
		intersection_point(&vars, data, (vars.angle + i));
		// print la ligne jusquau point dintersection
		i++;
	}
}
