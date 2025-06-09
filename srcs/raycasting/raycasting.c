/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:12:24 by ktintim-          #+#    #+#             */
/*   Updated: 2025/06/09 18:04:48 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	rgb_to_hex(int color[3])
{
	return (color[0] << 16) | (color[1] << 8) | color[2];
}

static bool	is_whole_number(double n)
{
	return (n == floor(n));
}

double	pythagor(double x1, double x2, double y1, double y2)
{
	double	x_seg;
	double	y_seg;

	x_seg = x2 - x1;
	y_seg = y2 - y1;

	return (sqrt((x_seg * x_seg) + (y_seg * y_seg)));
}

void	draw_vertical_line(t_img *img, int x, int line_height, int color)
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

void	raycasting(t_data *data, t_img *scn_img)
{
	t_dda	vars;
	double	line_h;
	double	dst;
	double	ray_angle;
	double	angle_offset;
	int		i;

	vars.step_size = 0.1;
	i = 0;
	while (i < SCR_WEIGHT)
	{
		// Angle entre -FOV/2 et +FOV/2, selon la colonne
		angle_offset = ((double)i / SCR_WEIGHT - 0.5) * FOV;

		// Angle absolu dans le monde
		ray_angle = data->character->angle_view + angle_offset;

		// Trouve l’intersection
		intersection_point(&vars, data, ray_angle);

		// Distance entre joueur et mur
		dst = pythagor(
			data->character->x_pose + data->character->square->width / 2,
			vars.x,
			data->character->y_pose + data->character->square->height / 2,
			vars.y
		);

		// Correction du fish-eye
		dst *= cos(return_radian(angle_offset));

		// Hauteur de ligne à dessiner
		if (dst == 0)
			dst = 0.1;
		line_h = (PIXEL * SCR_HEIGHT) / dst;
		if (line_h > SCR_HEIGHT)
			line_h = SCR_HEIGHT;

		// Dessine ligne verticale à la colonne i
		if (is_whole_number(vars.x))
			draw_vertical_line(scn_img, i, line_h, 0x880000);
		else
			draw_vertical_line(scn_img, i, line_h, 0x008800);
		i++;
	}
}
