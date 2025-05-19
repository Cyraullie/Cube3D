/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seg_convertor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 09:44:41 by ktintim-          #+#    #+#             */
/*   Updated: 2025/05/19 11:08:20 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

t_segment	*seg_realloc(t_segment *segment, int count)
{
	t_segment	*new_segment;
	int			i;

	if (count == 0)
	{
		segment = malloc(sizeof(t_segment));
		return (segment);
	}
	new_segment = malloc(sizeof(t_segment) * (count + 1));
	i = 0;
	while (i < count)
	{
		new_segment[i] = segment[i];
		i++;
	}
	free(segment);
	return (new_segment);
}

void	add_segment(t_data *data, float tp_br_x[2], float tp_br_y[2])
{
	(*data).segment = seg_realloc(data->segment, data->seg_count);

	(*data).seg_count++;
}

// tl pour top_left et br pour bottom_right
/**
 * @brief convertit les infos de la map pour cree les segments
 * 
 * @param x 
 * @param y 
 * @param map 
 * @param data 
 */
void	fill_segment(int x, int y, char **map, t_data *data)
{
	float	tl_br_x[2];
	float	tl_br_y[2];

	tl_br_x[0] = x * 32;
	tl_br_y[0] = y * 32;
	tl_br_x[1] = (x + 1) * 32;
	tl_br_y[1] = (y + 1) * 32;
	if (y == 0 || map[y - 1][x] == '0')
	{
		add_segment(data, tl_br_x, tl_br_y);
	}
	if (y == rows - 1 || map[y + 1][x] == '0')
	{
		add_segment(data, tl_br_x, tl_br_y);
	}
	if (x == 0 || map[y][x - 1] == '0')
	{
		add_segment(data, tl_br_x, tl_br_y);
	}
	if (x == cols - 1 || map[y][x + 1] == '0')
	{
		add_segment(data, tl_br_x, tl_br_y);
	}
}

void	segment_convertor(t_data *data, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
			{
				fill_segment(i, j, map, data);
			}
		}
		i++;
	}
}
