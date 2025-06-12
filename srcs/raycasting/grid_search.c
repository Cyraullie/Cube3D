/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_search.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 11:24:44 by kilian            #+#    #+#             */
/*   Updated: 2025/06/12 15:24:59 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	init_grid(t_grid *vars, t_data *data, double angle)
{
	vars->ray_x = data->character->x_pose + \
					(data->character->square->width / 2);
	vars->ray_y = data->character->y_pose + \
					(data->character->square->height / 2);
	vars->ray_angle = return_radian(angle);
	vars->dir_x = cos(vars->ray_angle);
	vars->dir_y = sin(vars->ray_angle);
	printf("dir_x : %f, dir_y : %f\n", vars->dir_x, vars->dir_y);

	vars->map_x = (int)(vars->ray_x / PIXEL);
	vars->map_y = (int)(vars->ray_y / PIXEL);

	vars->delta_dist_x = fabs(1.0 / vars->dir_x);
	vars->delta_dist_y = fabs(1.0 / vars->dir_y);
}

static void	direction(t_grid *vars)
{
	if (vars->dir_x < 0)
	{
		vars->step_x = -1;
		vars->side_dist_x = \
			(vars->ray_x / PIXEL - vars->map_x) * vars->delta_dist_x;
	}
	else
	{
		vars->step_x = 1;
		vars->side_dist_x = \
			((vars->map_x + 1) - vars->ray_x / PIXEL) * vars->delta_dist_x;
	}
	if (vars->dir_y < 0)
	{
		vars->step_y = -1;
		vars->side_dist_y = \
			(vars->ray_y / PIXEL - vars->map_y) * vars->delta_dist_y;
	}
	else
	{
		vars->step_y = 1;
		vars->side_dist_y = \
			((vars->map_y + 1) - vars->ray_y / PIXEL) * vars->delta_dist_y;
	}
}

static void	dda_loop(t_grid *vars, t_data *data)
{
	int	hit;

	hit = 0;
	vars->side = 0;
	while (!hit)
	{
		if (vars->side_dist_x < vars->side_dist_y)
		{
			vars->side_dist_x += vars->delta_dist_x;
			vars->map_x += vars->step_x;
			vars->side = 0;
		}
		else
		{
			vars->side_dist_y += vars->delta_dist_y;
			vars->map_y += vars->step_y;
			vars->side = 1;
		}
		if (data->map->map[vars->map_y][vars->map_x] == '1')
			hit = 1;
	}
}

void	intersection_point(t_data *data, t_grid *grid, double angle)
{
	if (angle >= 360)
		angle -= 360;
	else if (angle < 0)
		angle += 360;
	init_grid(grid, data, angle);
	direction(grid);
	dda_loop(grid, data);
	if (grid->side == 0)
	{
		grid->dst = grid->side_dist_x - grid->delta_dist_x;
	}
	else
	{
		grid->dst = grid->side_dist_y - grid->delta_dist_y;
	}
}
