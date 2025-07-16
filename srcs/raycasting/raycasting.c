/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:12:24 by ktintim-          #+#    #+#             */
/*   Updated: 2025/07/16 13:12:26 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	rgb_to_hex(int color[3])
{
	return ((color[0] << 16) | (color[1] << 8) | color[2]);
}

static int	return_text_pixel(t_img *texture, double percent, \
double line_h, int y)
{
	int	text_x;
	int	text_y;

	text_x = texture->width * percent;
	text_x = texture->width - text_x - 1;
	text_y = y * texture->height / line_h;
	return (get_pixel(texture, text_x, text_y));
}

static int	get_texture_pixel(t_data *data, double line_h,
							t_grid *grid, int y)
{
	if (grid->door_side != 0)
		return (return_text_pixel(data->texture->c_door, \
grid->percent, line_h, y));
	else
	{
		if (grid->side == N)
			return (return_text_pixel(data->texture->north, \
grid->percent, line_h, y));
		else if (grid->side == S)
			return (return_text_pixel(data->texture->south, \
grid->percent, line_h, y));
		else if (grid->side == E)
			return (return_text_pixel(data->texture->east, \
grid->percent, line_h, y));
		else if (grid->side == W)
			return (return_text_pixel(data->texture->west, \
grid->percent, line_h, y));
	}
	return (0);
}

static void	draw_vertical_line(t_img *scn_img, t_grid *grid,
								double line_h, t_data *data)
{
	int	start;
	int	end;
	int	y;
	int	color;

	start = (SCR_HEIGHT / 2) - (line_h / 2);
	end = (SCR_HEIGHT / 2) + (line_h / 2);
	if (start < 0)
		y = 0;
	else
		y = start;
	while (y < end)
	{
		color = get_texture_pixel(data, line_h, grid, y - start);
		put_pixel(scn_img, grid->x, y, color);
		y++;
	}
}

void	raycasting(t_data *data, t_img *scn_img)
{
	t_grid	grid;
	double	line_h;
	double	ray_angle;
	double	angle_offset;

	grid.x = 0;
	while (grid.x < SCR_WIDTH)
	{
		angle_offset = ((double)grid.x / SCR_WIDTH - 0.5) * FOV;
		ray_angle = data->character->angle_view + angle_offset;
		intersection_point(data, &grid, ray_angle);
		grid.dst *= cos(return_radian(angle_offset));
		if (grid.dst == 0)
			grid.dst = 0.1;
		line_h = SCR_HEIGHT / grid.dst;
		draw_vertical_line(scn_img, &grid, line_h, data);
		grid.x++;
	}
}
