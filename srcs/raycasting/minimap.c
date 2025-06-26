/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 11:27:46 by kilian            #+#    #+#             */
/*   Updated: 2025/06/26 11:31:56 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

// void	put_character(t_img *minimap, int h, int color, double angle)
// {
// 	int	x;
// 	int	y;

// 	x = MINIMAP_RADIUS;
// 	y = MINIMAP_RADIUS;
// }

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

char	get_tile(t_data *data, int x, int y)
{
	int	world_x;
	int	world_y;
	int	map_x;
	int	map_y;

	world_x = ((data->character->x_pose + PIXEL) \
					/ PIXEL) * TILE_SIZE - MINIMAP_RADIUS + x;
	world_y = ((data->character->y_pose + PIXEL) \
					/ PIXEL) * TILE_SIZE - MINIMAP_RADIUS + y;
	world_x -= TILE_SIZE / 2;
	world_y -= TILE_SIZE / 2;
	map_x = world_x / TILE_SIZE;
	map_y = world_y / TILE_SIZE;
	if (map_x < 0 || map_y < 0 || \
		map_x >= data->map->cols || map_y >= data->map->rows)
		return ('\0');

	return (data->map->map[map_y][map_x]);
}

void	put_tile(t_img *minimap, char tile, int x, int y)
{
	float	dist_x;
	float	dist_y;

	dist_x = abs(x - MINIMAP_RADIUS);
	dist_y = abs(y - MINIMAP_RADIUS);
	if (sqrt(dist_x * dist_x + dist_y * dist_y) < MINIMAP_RADIUS)
	{
		if (tile == '1')
			put_pixel(minimap, x, y, 0x888888);
		if (tile == '0' || tile == 'W' || tile == 'S' || \
			tile == 'N' || tile == 'E' || tile == '3')
			put_pixel(minimap, x, y, 0x222222);
		if (tile == ' ' || tile == '\0')
			put_pixel(minimap, x, y, 0x010101);
		if (tile == '2')
			put_pixel(minimap, x, y, 0x5B3C11);
	}
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
			put_tile(minimap, tile, x, y);
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
	fusion_image(scn_img, &minimap, SCR_WIDTH - (MINIMAP_SIZE + 20), 20);
	mlx_destroy_image(data->window->mlx, minimap.ptr);
}
