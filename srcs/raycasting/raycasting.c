/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:12:24 by ktintim-          #+#    #+#             */
/*   Updated: 2025/06/26 13:42:50 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	rgb_to_hex(int color[3])
{
	return ((color[0] << 16) | (color[1] << 8) | color[2]);
}

// double	pythagor(double x1, double x2, double y1, double y2)
// {
// 	double	x_seg;
// 	double	y_seg;

// 	x_seg = x2 - x1;
// 	y_seg = y2 - y1;

// 	return (sqrt((x_seg * x_seg) + (y_seg * y_seg)));
// }

static int	get_texture_pixel(t_data *data, double line_h, \
								t_grid *grid, int y)
{
	int	text_x;
	int	text_y;

	if (grid->side == N)
	{
		text_x = (int)(data->texture->north->width * grid->percent);
		text_x = data->texture->north->width - text_x - 1;
		text_y = y * data->texture->north->height / line_h;
		return (get_pixel(data->texture->north, text_x, text_y));
	}
	else if (grid->side == S)
	{
		text_x = (int)(data->texture->south->width * grid->percent);
		text_x = data->texture->south->width - text_x - 1;
		text_y = y * data->texture->south->height / line_h;
		return (get_pixel(data->texture->south, text_x, text_y));
	}
	else if (grid->side == E)
	{
		text_x = data->texture->east->width * grid->percent;
		text_x = data->texture->east->width - text_x - 1;
		text_y = y * data->texture->east->height / line_h;
		return (get_pixel(data->texture->east, text_x, text_y));
	}
	else
	{
		text_x = (int)(data->texture->west->width * grid->percent);
		text_x = data->texture->west->width - text_x - 1;
		text_y = y * data->texture->west->height / line_h;
		return (get_pixel(data->texture->west, text_x, text_y));
	}
}

static void	draw_vertical_line(t_img *scn_img, t_grid *grid, \
								double line_h, t_data *data)
{
	int	start;
	int	end;
	int	y;
	int	color;

	start = (SCR_HEIGHT / 2) - (line_h / 2);
	// if (start < 0)
	// 	start = 0;
	end = (SCR_HEIGHT / 2) + (line_h / 2);
	// if (end > SCR_HEIGHT)
	// 	end = SCR_HEIGHT;
	y = start;
	while (y < end)
	{
		if (y > 0)
		{
			color = get_texture_pixel(data, line_h, grid, y - start);
			put_pixel(scn_img, grid->x, y, color);
		}
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
		grid.dst *= PIXEL;
		if (grid.dst == 0)
			grid.dst = 0.1;
		line_h = (PIXEL * SCR_HEIGHT) / grid.dst;
		// if (line_h > SCR_HEIGHT)
		// 	line_h = SCR_HEIGHT;
		draw_vertical_line(scn_img, &grid, line_h, data);
		grid.x++;
	}
}
