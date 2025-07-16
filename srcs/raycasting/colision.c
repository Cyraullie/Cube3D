/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colision.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:11:09 by cgoldens          #+#    #+#             */
/*   Updated: 2025/07/16 13:11:12 by cgoldens         ###   ########.fr       */
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

	pose_x = data->character->x_pose + \
new_x(data->character->angle_view, data) + 32;
	pose_y = data->character->y_pose + \
new_y(data->character->angle_view, data) + 32;
	x = (int)pose_x / PIXEL;
	y = (int)pose_y / PIXEL;
	if (data->map->map[y][x] == '1' || data->map->map[y][x] == '2' \
|| data->map->map[y][x] == ' ' || !data->map->map[y][x])
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

	pose_x = data->character->x_pose - \
new_x(data->character->angle_view, data) + 32;
	pose_y = data->character->y_pose - \
new_y(data->character->angle_view, data) + 32;
	x = (int)pose_x / PIXEL;
	y = (int)pose_y / PIXEL;
	if (data->map->map[y][x] == '1' || data->map->map[y][x] == '2' \
|| data->map->map[y][x] == ' ' || !data->map->map[y][x])
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

	pose_x = data->character->x_pose + \
new_x(data->character->angle_view - 90, data) + 32;
	pose_y = data->character->y_pose + \
new_y(data->character->angle_view - 90, data) + 32;
	x = (int)pose_x / PIXEL;
	y = (int)pose_y / PIXEL;
	if (data->map->map[y][x] == '1' || data->map->map[y][x] == '2' \
|| data->map->map[y][x] == ' ' || !data->map->map[y][x])
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

	pose_x = data->character->x_pose + \
new_x(data->character->angle_view + 90, data) + 32;
	pose_y = data->character->y_pose + \
new_y(data->character->angle_view + 90, data) + 32;
	x = (int)pose_x / PIXEL;
	y = (int)pose_y / PIXEL;
	if (data->map->map[y][x] == '1' || data->map->map[y][x] == '2' \
|| data->map->map[y][x] == ' ' || !data->map->map[y][x])
		return (1);
	else
		return (0);
}

/**
 * @brief check if a door is front of player
 * 
 * @param data 
 * @return int 1 if go in a door 0 if not
 */
int	check_door(t_data *data)
{
	double	pose_x;
	double	pose_y;
	int		x;
	int		y;

	pose_x = (data->character->x_pose + 32) / PIXEL + \
(cos(data->character->angle_view * 6.28 / 360));
	pose_y = (data->character->y_pose + 32) / PIXEL + \
(sin(data->character->angle_view * 6.28 / 360));
	x = floor(pose_x);
	y = floor(pose_y);
	if (data->map->map[y][x] == '2' || data->map->map[y][x] == '3')
		return (1);
	else
		return (0);
}
