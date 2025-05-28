/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:46:48 by cgoldens          #+#    #+#             */
/*   Updated: 2025/05/28 12:58:32 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

/**
 * @brief main function
 * 
 */
int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		printf("Error\n.cub file needed");
		exit(EXIT_FAILURE);
	}
	data_constructor(&data, argv[1]);
	if (integrity_check(data.map))
		printf("map not ok\n");
	else
		printf("map ok\n");
	printf("direction look : %0.1f\n", data.map->direction);
	visio_map(data.map->map, data.map->rows, data.map->cols);
	printf("player position : x:%0.1f y:%0.1f\n", (data.map->c_x- 0.5) / 64, (data.map->c_y - 0.5) / 64);
	mlx_action(&data);
}
