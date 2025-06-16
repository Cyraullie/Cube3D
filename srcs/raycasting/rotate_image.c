/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 10:49:54 by ktintim-          #+#    #+#             */
/*   Updated: 2025/06/16 13:58:37 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

double	return_radian(double angle_degre)
{
	return (angle_degre * M_PI / 180.0);
}

/**
 * @brief Get the color of the pixel at x;y on the image
 * 
 * @param img pointer to the image
 * @param x 
 * @param y 
 * @return int 
 */
int	get_pixel(t_img *img, int x, int y)
{
	char	*pixel;

	if (x < 0 || y < 0 || x >= img->width || y >= img->height)
		return (0);

	pixel = img->addr + (y * img->line_length + x * (img->bpp / 8));
	return (*(int *)pixel);
}

/**
 * @brief put a pixel at x;y coordonee of a certain color
 * 
 * @param img pointer to the image
 * @param x x coordonee
 * @param y y coordonee
 * @param color the color of the pixel 
 */
void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= img->width || y >= img->height)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = (unsigned int)color;
}

static void	create_image(t_img *src, t_img *dest, t_vars vars)
{
	int	color;

	if (vars.src_x >= 0 && vars.src_x < src->width \
		&& vars.src_y >= 0 && vars.src_y < src->height)
	{
		color = get_pixel(src, vars.src_x, vars.src_y);
		put_pixel(dest, vars.x, vars.y, color);
	}
	else
	{
		put_pixel(dest, vars.x, vars.y, 0x000000);
	}
}

/**
 * @brief take an image and rotate it of angle_degre degre and create a new 
 * 		image rotated in dest
 * 
 * @param src 	base image
 * @param dest 	pointer to rotated image
 * @param angle_degre the degre the image will face (on trigonom circle)
 */
void	rotate_image(t_img *src, t_img *dest, double angle_degre)
{
	t_vars	vars;

	vars.angle = return_radian(angle_degre);
	vars.cx = src->width / 2;
	vars.cy = src->height / 2;
	vars.dest_cx = dest->width / 2;
	vars.dest_cy = dest->height / 2;
	vars.y = 0;
	while (vars.y < dest->height)
	{
		vars.x = 0;
		while (vars.x < dest->width)
		{
			vars.dx = vars.x - vars.dest_cx;
			vars.dy = vars.y - vars.dest_cy;
			vars.src_x = (int)(cos(vars.angle) * vars.dx + \
						sin(vars.angle) * vars.dy + vars.cx);
			vars.src_y = (int)(-sin(vars.angle) * vars.dx + \
						cos(vars.angle) * vars.dy + vars.cy);
			create_image(src, dest, vars);
			vars.x++;
		}
		vars.y++;
	}
}
