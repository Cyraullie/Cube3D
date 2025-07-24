/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:46:48 by cgoldens          #+#    #+#             */
/*   Updated: 2025/07/24 17:05:35 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

/*
Attention au parsing,
double identifier/path.
Espace dans le path texture.
Experience utilisateur pas fluide.
ET LA NORMINETTE.
check du nom du file.
Pas de message d'erreur si Identifier apres la map. 
*/

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
	printf("%s\n", argv[1]);
	//TODO check name of file need to contain .cub but .cub only didnt work
	data_constructor(&data, argv[1]);
	mlx_action(&data);
}
