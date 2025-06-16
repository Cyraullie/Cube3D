/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 11:27:46 by kilian            #+#    #+#             */
/*   Updated: 2025/06/16 14:10:44 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void draw_square_image(t_img *img, int x, int y, int size, int color)
{
	int i, j;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			put_pixel(img, x + j, y + i, color);
		}
	}
}

void draw_circle(t_img *img, int xc, int yc, int r, int color)
{
	int x = 0;
	int y = r;
	int d = 3 - 2 * r;

	while (y >= x)
	{
		put_pixel(img, xc + x, yc + y, color);
		put_pixel(img, xc - x, yc + y, color);
		put_pixel(img, xc + x, yc - y, color);
		put_pixel(img, xc - x, yc - y, color);
		put_pixel(img, xc + y, yc + x, color);
		put_pixel(img, xc - y, yc + x, color);
		put_pixel(img, xc + y, yc - x, color);
		put_pixel(img, xc - y, yc - x, color);
		x++;
		if (d > 0)
		{
			y--;
			d = d + 4 * (x - y) + 10;
		}
		else
			d = d + 4 * x + 6;
	}
}

void draw_line_image(t_img *img, int x0, int y0, int x1, int y1, int color)
{
	int dx = abs(x1 - x0);
	int dy = abs(y1 - y0);
	int sx = (x0 < x1) ? 1 : -1;
	int sy = (y0 < y1) ? 1 : -1;
	int err = dx - dy;

	while (1)
	{
		put_pixel(img, x0, y0, color);
		if (x0 == x1 && y0 == y1)
			break;
		int e2 = 2 * err;
		if (e2 > -dy) { err -= dy; x0 += sx; }
		if (e2 < dx) { err += dx; y0 += sy; }
	}
}

void draw_minimap_rotating(t_img *minimap, t_data *data)
{
	int px = data->character->x_pose;
	int py = data->character->y_pose;
	double angle = data->character->angle_view;
	int center_x = MINIMAP_SIZE / 2;
	int center_y = MINIMAP_SIZE / 2;

	int half = VISIBLE_TILES / 2;

	for (int my = -half; my <= half; my++)
	{
		for (int mx = -half; mx <= half; mx++)
		{
			int map_x = px / TILE_SIZE + mx;
			int map_y = py / TILE_SIZE + my;

			if (map_x < 0 || map_y < 0 || map_y >= data->map->rows || map_x >= data->map->cols)
				continue;

			// position relative (en pixels) par rapport au joueur
			double rel_x = mx * TILE_SIZE - (px % TILE_SIZE);
			double rel_y = my * TILE_SIZE - (py % TILE_SIZE);

			// rotation
			double rot_x = rel_x * cos(-angle) - rel_y * sin(-angle);
			double rot_y = rel_x * sin(-angle) + rel_y * cos(-angle);

			// position sur la minimap
			int draw_x = center_x + (int)rot_x;
			int draw_y = center_y + (int)rot_y;

			// masque circulaire
			// int dx = draw_x - center_x;
			// int dy = draw_y - center_y;
			// if (dx * dx + dy * dy < MINIMAP_RADIUS * MINIMAP_RADIUS)
			// {
				int color = (data->map->map[map_y][map_x] == '1') ? 0x888888 : 0x222222;
				if (data->map->map[map_y][map_x] != '.')
				{
					int zoom = TILE_SIZE / 4;
					draw_square_image(minimap, draw_x - zoom / 2, draw_y - zoom / 2, zoom, color);
				}
			// }
		}
	}

	// Dessiner le joueur au centre
	draw_circle(minimap, center_x, center_y, 3, 0x00FF00);

	// Dessiner la direction
	int dir_len = 10;
	int dir_x = center_x + cos(angle) * dir_len;
	int dir_y = center_y + -sin(angle) * dir_len;
	draw_line_image(minimap, center_x, center_y, dir_x, dir_y, 0xFF0000);
}

void	put_minimap(t_data *data, t_img *scn_img)
{
	t_img	minimap;

	(void)scn_img;
	image_constructor(&minimap, data->window->mlx, MINIMAP_SIZE, MINIMAP_SIZE);
	draw_minimap_rotating(&minimap, data);
	mlx_put_image_to_window(data->window->mlx, data->window->win, minimap.ptr, 0, 0);
	// fusion_image(scn_img, &minimap, SCR_WEIGHT - (MINIMAP_SIZE + 20), 20);
	mlx_destroy_image(data->window->mlx, minimap.ptr);
}

// 1. savoir ou placer la map
// 2. cree mon image a la bonne taille et rescale
// 3. placer les bonnes informations dessu

// idee : pour ne pas avoir a faire un rescale de map on fais une map 
//		  qui affiche la map autour du personnae