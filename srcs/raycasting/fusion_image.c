/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fusion_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:43:21 by ktintim-          #+#    #+#             */
/*   Updated: 2025/05/26 13:59:00 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	fusion_image(t_img *screen_img, t_img *img, int x, int y)
{
	int	i;
	int	j;
	int	color;

	j = 0;
	while (j < img->height)
	{
		i = 0;
		while (i < img->width)
		{
			color = get_pixel(img, i, j);
			if (color != 0x000000)
				put_pixel(screen_img, x + i, y + j, color);
			i++;
		}
		j++;
	}
}
