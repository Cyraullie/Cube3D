/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_clip.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim <ktintim-@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:23:48 by ktintim           #+#    #+#             */
/*   Updated: 2025/08/21 13:54:05 by ktintim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	no_clip(t_data *data, int new_x, int new_y)
{
	int	pose_x;
	int	pose_y;

	pose_x = data->character->x_pose / PIXEL;
	pose_y = data->character->y_pose / PIXEL;
	if (floor(pose_x) == floor(new_x) || \
floor(pose_y) == floor(new_y))
		return (0);
	if (data->map->map[new_y][pose_x] != '0' && \
data->map->map[pose_y][new_x] != '0')
		return (1);
	return (0);
}
