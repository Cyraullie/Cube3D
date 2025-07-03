/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:46:48 by cgoldens          #+#    #+#             */
/*   Updated: 2025/07/03 10:58:35 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

//TODO faire attention au directiory qui ont le .cub
//TODO faire des messages d-erreur pour si y a pas NO/SU/WE/EA/C/F
//TODO 

/**
 * @brief main function
 * 
 */
int	main(int argc, char **argv)
{
	t_data	data;

	if (argc > 2)
	{
		printf("Error\nToo many arguments\n");
		exit(EXIT_FAILURE);
	}
	if (argc < 2)
	{
		printf("Error\n.cub file needed\n");
		exit(EXIT_FAILURE);
	}
	data_constructor(&data, argv[1]);
	mlx_action(&data);
}
