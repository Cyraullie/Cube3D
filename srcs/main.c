/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:46:48 by cgoldens          #+#    #+#             */
/*   Updated: 2025/05/26 15:08:57 by ktintim-         ###   ########.fr       */
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
	printf("direction look : %c", data.map->direction);
	mlx_action(&data);
}
