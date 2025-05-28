/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colision.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 10:47:50 by ktintim-          #+#    #+#             */
/*   Updated: 2025/05/27 14:56:41 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/**
 * @brief check if the moove dont go in a wall
 * 
 * @param data 
 * @return int 1 if go in a wall 0 if not
 */
int	check_w(t_data *data)
{
	double	pose_x;
	double	pose_y;
	int		x;
	int		y;

	pose_x = data->character->x_pose + new_x(data->character->angle_view) + 32;
	pose_y = data->character->y_pose + new_y(data->character->angle_view) + 32;
	x = (int)pose_x / 64;
	y = (int)pose_y / 64;
	if (data->map->map[y][x] == '1')
		return (1);
	else
		return (0);
}

/**
 * @brief check if the moove dont go in a wall
 * 
 * @param data 
 * @return int 1 if go in a wall 0 if not
 */
int	check_s(t_data *data)
{
	double	pose_x;
	double	pose_y;
	int		x;
	int		y;

	pose_x = data->character->x_pose - new_x(data->character->angle_view) + 32;
	pose_y = data->character->y_pose - new_y(data->character->angle_view) + 32;
	x = (int)pose_x / 64;
	y = (int)pose_y / 64;
	if (data->map->map[y][x] == '1')
		return (1);
	else
		return (0);
}

/**
 * @brief check if the moove dont go in a wall
 * 
 * @param data 
 * @return int 1 if go in a wall 0 if not
 */
int	check_a(t_data *data)
{
	double	pose_x;
	double	pose_y;
	int		x;
	int		y;

	pose_x = data->character->x_pose + new_x(data->character->angle_view - 90) + 32;
	pose_y = data->character->y_pose + new_y(data->character->angle_view - 90) + 32;
	x = (int)pose_x / 64;
	y = (int)pose_y / 64;
	if (data->map->map[y][x] == '1')
		return (1);
	else
		return (0);
}

/**
 * @brief check if the moove dont go in a wall
 * 
 * @param data 
 * @return int 1 if go in a wall 0 if not
 */
int	check_d(t_data *data)
{
	double	pose_x;
	double	pose_y;
	int		x;
	int		y;

	pose_x = data->character->x_pose + new_x(data->character->angle_view + 90) + 32;
	pose_y = data->character->y_pose + new_y(data->character->angle_view + 90) + 32;
	x = (int)pose_x / 64;
	y = (int)pose_y / 64;
	if (data->map->map[y][x] == '1')
		return (1);
	else
		return (0);
}
