/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_panel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 09:47:05 by ktintim-          #+#    #+#             */
/*   Updated: 2025/05/20 15:33:27 by ktintim-         ###   ########.fr       */
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
void	draw_panel(char *img_data, int size_line, int color)
{
	int	y;
	int	x;
	int	pixel;

	y = 0;
	while (y < 64)
	{
		x = 0;
		while (x < 64)
		{
			pixel = y * size_line + x * 4;
			img_data[pixel + 0] = (color & 0xFF);
			img_data[pixel + 1] = (color >> 8) & 0xFF;
			img_data[pixel + 2] = (color >> 16) & 0xFF;
			x++;
		}
		y++;
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
			{
				mlx_put_image_to_window(data->window->mlx, data->window->win, \
					data->texture->white_img, (j * 64), (i * 64));
			}
			else if (map[i][j] == '0')
			{
				mlx_put_image_to_window(data->window->mlx, data->window->win, \
					data->texture->black_img, (j * 64), (i * 64));
			}
			j++;
		}
		i++;
	}
}

void	draw_rotated_square(t_img *img, double angle_rad)
{
	int		x, y;
	int		half = 5; // carré centré, taille totale 11
	double	cx = img->width / 2.0;
	double	cy = img->height / 2.0;

	for (y = -half; y <= half; y++)
	{
		for (x = -half; x <= half; x++)
		{
			// Rotation autour du centre
			double rx = cos(angle_rad) * x - sin(angle_rad) * y;
			double ry = sin(angle_rad) * x + cos(angle_rad) * y;

			int px = (int)(cx + rx);
			int py = (int)(cy + ry);

			// Vérifie que le pixel est bien dans l’image
			if (px >= 0 && py >= 0 && px < img->width && py < img->height)
			{
				char *dst = img->addr + (py * img->line_length + px * (img->bpp / 8));
				*(int *)dst = 0x00FF0000;
			}
		}
	}
}
