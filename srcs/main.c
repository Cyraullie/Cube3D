/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:46:48 by cgoldens          #+#    #+#             */
/*   Updated: 2025/05/26 14:52:44 by ktintim-         ###   ########.fr       */
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
	data_constructor(&data);
	parsing(argv[1], &data);
	if (integrity_check(data.map))
		printf("map not ok\n");
	else
		printf("map ok\n");
	printf("direction look : %c", data.map->direction);
	t_data	data;
	char *map[] = {
		"111111111111111",
		"100000000000001",
		"101111111110101",
		"101000000010101",
		"101000000010101",
		"101000000010101",
		"100000000000001",
		"111111111111111"
	};

	data_constructor(&data);
	(void)argc;
	(void)argv;
	mlx_action(&data, map);
}
