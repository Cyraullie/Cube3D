/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_panel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 09:47:05 by ktintim-          #+#    #+#             */
/*   Updated: 2025/06/16 13:09:26 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/**
 * @brief fonction qui permet de dessiner une image d'une couleur simple
 * 
 * @param img_data 	le img_data que nous a return mlx_get_data_adress
 * @param size_line le meme que on a du envoyer dans mlx_get_data_adress
 * @param color 	la conversion decimal de l'hexa de la couleur quon veux
 */
void	draw_square(t_img *img, int square_size, int color)
{
	int	y_x[2];
	int	xstart_ystart[2];
	int	pixel;
	int	draw_x;
	int	draw_y;

	xstart_ystart[0] = (img->width - square_size) / 2;
	xstart_ystart[1] = (img->height - square_size) / 2;
	y_x[0] = 0;
	while (y_x[0] < square_size)
	{
		y_x[1] = 0;
		while (y_x[1] < square_size)
		{
			draw_x = xstart_ystart[0] + y_x[1];
			draw_y = xstart_ystart[1] + y_x[0];
			pixel = draw_y * img->line_length + draw_x * 4;
			img->addr[pixel + 0] = (color & 0xFF);
			img->addr[pixel + 1] = (color >> 8) & 0xFF;
			img->addr[pixel + 2] = (color >> 16) & 0xFF;
			y_x[1]++;
		}
		y_x[0]++;
	}
}

void	draw_map(t_data *data, char *map[8])
{
	int	i;
	int	j;

	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 15)
		{
			if (map[i][j] == '1')
				mlx_put_image_to_window(data->window->mlx, data->window->win, \
					data->texture->white_img, (j * PIXEL), (i * PIXEL));
			else if (map[i][j] == '2')
				mlx_put_image_to_window(data->window->mlx, data->window->win, \
					data->texture->door_img, (j * PIXEL), (i * PIXEL));
			else if (map[i][j] == '0' || map[i][j] == '3')
				mlx_put_image_to_window(data->window->mlx, data->window->win, \
					data->texture->black_img, (j * PIXEL), (i * PIXEL));
			j++;
		}
		i++;
	}
}

void	draw_line(t_img *img, int color)
{
	int	line_size;
	int	cx;
	int	cy;
	int	i;

	line_size = 100;
	cx = img->height / 2;
	cy = img->height / 2;
	i = 0;
	while (i < line_size && (cx + i) < img->width)
	{
		put_pixel(img, cx + i, cy, color);
		i++;
	}
}

void	draw_floor(t_img *scn_img, int color)
{
	int	x;
	int	y;

	x = 0;
	while (x <= SCR_WEIGHT)
	{
		y = 0;
		while (y < (SCR_HEIGHT / 2))
		{
			if (get_pixel(scn_img, x, y) == 0x000000)
				put_pixel(scn_img, x, y, color);
			y++;
		}
		x++;
	}
}

void	draw_ceiling(t_img *scn_img, int color)
{
	int	x;
	int	y;

	x = 0;
	while (x <= SCR_WEIGHT)
	{
		y = SCR_HEIGHT / 2;
		while (y <= SCR_HEIGHT)
		{
			if (get_pixel(scn_img, x, y) == 0x000000)
				put_pixel(scn_img, x, y, color);
			y++;
		}
		x++;
	}
}
