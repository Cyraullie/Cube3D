/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilian <kilian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 11:27:46 by kilian            #+#    #+#             */
/*   Updated: 2025/06/17 14:40:54 by kilian           ###   ########.fr       */
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

char get_tile(t_data *data, int x, int y)
{
	int	world_x = data->character->x_pose - MINIMAP_RADIUS + x;
	int	world_y = data->character->y_pose - MINIMAP_RADIUS + y;

	int	map_x = world_x / TILE_SIZE;
	int	map_y = world_y / TILE_SIZE;

	if (map_x < 0 || map_y < 0 || \
		map_x >= data->map->cols || map_y >= data->map->rows)
		return ('\0');

	return (data->map->map[map_y][map_x]);
}

void	draw_minimap(t_img *minimap, t_data *data)
{
	char	tile;
	int		x;
	int		y;

	y = 0;
	while (y <= MINIMAP_SIZE)
	{
		x = 0;
		while (x <= MINIMAP_SIZE)
		{
			tile = get_tile(data, x, y);
			if (tile == '1')
				put_pixel(minimap, x, y, 0x888888);
			if (tile == '0')
				put_pixel(minimap, x, y, 0x222222);
			if (tile == '.' || tile == '\0')
				put_pixel(minimap, x, y, 0x010101);
			x++;
		}
		y++;
	}
	draw_circle(minimap, MINIMAP_RADIUS, MINIMAP_RADIUS, 3, 0x00FF00);
}

void	put_minimap(t_data *data, t_img *scn_img)
{
	t_img	minimap;

	(void)scn_img;
	image_constructor(&minimap, data->window->mlx, MINIMAP_SIZE, MINIMAP_SIZE);
	draw_minimap(&minimap, data);
	mlx_put_image_to_window(data->window->mlx, data->window->win, minimap.ptr, 50, 50);
	// fusion_image(scn_img, &minimap, SCR_WEIGHT - (MINIMAP_SIZE + 20), 20);
	mlx_destroy_image(data->window->mlx, minimap.ptr);
}

// 1. savoir ou placer la map
// 2. cree mon image a la bonne taille et rescale
// 3. placer les bonnes informations dessu

// idee : pour ne pas avoir a faire un rescale de map on fais une map 
//		  qui affiche la map autour du personnae