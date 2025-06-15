/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilian <kilian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 11:27:46 by kilian            #+#    #+#             */
/*   Updated: 2025/06/15 11:41:45 by kilian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

// static void	put_character(t_data *data, t_img *screen_img)
// {
// 	t_img	new_img;

// 	image_constructor(&new_img, data->window->mlx, 
// 			data->character->square->height, data->character->square->width);
// 	rotate_image(data->character->square, &new_img, 
// 				data->character->angle_view);
// 	fusion_image(screen_img, &new_img, 
// 				data->character->x_pose, data->character->y_pose);
// 	mlx_destroy_image(data->window->mlx, new_img.ptr);
// }

// static void	put_map(t_data *data, t_img *screen_img)
// {
// 	int		i;
// 	int		j;
// 	t_img	white_square;
// 	t_img	door;

// 	image_constructor(&white_square, data->window->mlx, 63, 63);
// 	draw_square(&white_square, 63, 16777215);

// 	image_constructor(&door, data->window->mlx, 63, 63);
// 	draw_square(&door, 63, 5979153);
// 	i = 0;
// 	while (i < data->map->rows)
// 	{
// 		j = 0;
// 		while (j < data->map->cols)
// 		{
// 			if (data->map->map[i][j] == '1')
// 				fusion_image(screen_img, &white_square, (j * 64) - 1, 
// 					(i * 64) - 1);
// 			if (data->map->map[i][j] == '2')
// 				fusion_image(screen_img, &door, (j * 64) - 1, 
// 					(i * 64) - 1);
// 			j++;
// 		}
// 		i++;
// 	}
// 	mlx_destroy_image(data->window->mlx, white_square.ptr);
// 	mlx_destroy_image(data->window->mlx, door.ptr);
// }

void	put_minimap(t_data *data, t_img *scn_img)
{

	// put_map(data, &screen_image);
	// put_character(data, &screen_image);
	// dda(data, &screen_image);
}

// 1. savoir ou placer la map
// 2. cree mon image a la bonne taille et rescale
// 3. placer les bonnes informations dessu

// idee : pour ne pas avoir a faire un rescale de map on fais une map 
//		  qui affiche la map autour du personnae