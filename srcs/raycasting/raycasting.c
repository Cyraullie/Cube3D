/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:12:24 by ktintim-          #+#    #+#             */
/*   Updated: 2025/06/20 10:44:20 by ktintim-         ###   ########.fr       */
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

static void	draw_vertical_line(t_img *img, int x, int line_height, int color)
{
	int	start;
	int	end;
	int	y;

	start = (SCR_HEIGHT / 2) - (line_height / 2);
	if (start < 0)
		start = 0;
	end = (SCR_HEIGHT / 2) + (line_height / 2);
	if (end > SCR_HEIGHT)
		end = SCR_HEIGHT;

	y = start;
	while (y < end)
	{
		put_pixel(img, x, y, color);
		y++;
	}
}

// static void	draw_line(t_img *scn_img, t_grid grid, double line_h, t_data *data)
// {
// 	int	text_x;
// 	int	text_y;
// 	int	start;
// 	int	end;

// 	start = (SCR_HEIGHT / 2) - (line_h / 2);
// 	if (start < 0)
// 		start = 0;
// 	end = (SCR_HEIGHT / 2) + (line_h / 2);
// 	if (end > SCR_HEIGHT)
// 		end = SCR_HEIGHT;
	
// }

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
		printf("percent : %f\n", grid.percent);
		grid.dst *= cos(return_radian(angle_offset));
		grid.dst *= PIXEL;
		if (grid.dst == 0)
			grid.dst = 0.1;
		line_h = (PIXEL * SCR_HEIGHT) / grid.dst;
		if (line_h > SCR_HEIGHT)
			line_h = SCR_HEIGHT;
		if (grid.side == W || grid.side == E)
			draw_vertical_line(scn_img, grid.x, line_h, 0x880000);
		else
			draw_vertical_line(scn_img, grid.x, line_h, 0x008800);
		grid.x++;
	}
}
