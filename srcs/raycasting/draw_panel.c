/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_panel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim <ktintim-@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 09:47:05 by ktintim-          #+#    #+#             */
/*   Updated: 2025/08/25 14:07:03 by ktintim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/**
 * @brief draw floor
 * 
 * @param scn_img 
 * @param color 
 */
void	draw_ceiling(t_img *scn_img, int color)
{
	int	x;
	int	y;

	x = 0;
	while (x <= SCR_WIDTH)
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

/**
 * @brief draw ceiling
 * 
 * @param scn_img 
 * @param color 
 */
void	draw_floor(t_img *scn_img, int color)
{
	int	x;
	int	y;

	x = 0;
	while (x <= SCR_WIDTH)
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
