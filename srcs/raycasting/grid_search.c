/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_search.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 11:24:44 by kilian            #+#    #+#             */
/*   Updated: 2025/07/16 13:13:10 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	init_grid(t_grid *vars, t_data *data, double angle)
{
	vars->ray_x = data->character->x_pose + \
(PIXEL / 2);
	vars->ray_y = data->character->y_pose + \
(PIXEL / 2);
	vars->ray_angle = return_radian(angle);
	vars->dir_x = cos(vars->ray_angle);
	vars->dir_y = sin(vars->ray_angle);
	vars->map_x = floor(vars->ray_x / PIXEL);
	vars->map_y = floor(vars->ray_y / PIXEL);
	if (ft_fabs(vars->dir_x) < 1e-6)
		vars->delta_dist_x = 1e6;
	else
		vars->delta_dist_x = ft_fabs(1.0 / vars->dir_x);
	if (ft_fabs(vars->dir_y) < 1e-6)
		vars->delta_dist_y = 1e6;
	else
		vars->delta_dist_y = ft_fabs(1.0 / vars->dir_y);
	vars->door_side = 0;
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

static int	return_side(double angle, int index)
{
	if (index == 1)
	{
		if (angle <= 90 || angle >= 270)
			return (W);
		else
			return (E);
	}
	else
	{
		if (angle <= 180 || angle >= 0)
			return (S);
		else
			return (N);
	}
}

static void	dda_loop(t_grid *vars, t_data *data, double angle)
{
	vars->hit_wall = 0;
	vars->side = 0;
	while (!vars->hit_wall)
	{
		if (vars->side_dist_x < vars->side_dist_y)
		{
			vars->side_dist_x += vars->delta_dist_x;
			vars->map_x += vars->step_x;
			vars->side = return_side(angle, 1);
		}
		else
		{
			vars->side_dist_y += vars->delta_dist_y;
			vars->map_y += vars->step_y;
			vars->side = return_side(angle, 0);
		}
		if (data->map->map[vars->map_y][vars->map_x] == '1' || \
data->map->map[vars->map_y][vars->map_x] == '2' || \
!data->map->map[vars->map_y][vars->map_x])
		{
			vars->hit_wall = 1;
			if (data->map->map[vars->map_y][vars->map_x] == '2')
				vars->door_side = 1;
		}
	}
}

void	intersection_point(t_data *data, t_grid *grid, double angle)
{
	double	hit_x;
	double	hit_y;

	if (angle >= 360)
		angle -= 360;
	else if (angle < 0)
		angle += 360;
	init_grid(grid, data, angle);
	direction(grid);
	dda_loop(grid, data, angle);
	if (grid->side == W || grid->side == E)
	{
		grid->dst = grid->side_dist_x - grid->delta_dist_x;
		hit_y = ((data->character->y_pose + PIXEL / 2) / PIXEL) + \
grid->dir_y * (grid->dst);
		grid->percent = hit_y - floor(hit_y);
	}
	else
	{
		grid->dst = grid->side_dist_y - grid->delta_dist_y;
		hit_x = ((data->character->x_pose + PIXEL / 2) / PIXEL) + \
grid->dir_x * (grid->dst);
		grid->percent = hit_x - floor(hit_x);
	}
}
