/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:46:48 by cgoldens          #+#    #+#             */
/*   Updated: 2025/07/02 15:59:52 by cgoldens         ###   ########.fr       */
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

	if (argc > 2)
		print_error("Error\nToo many arguments", EXIT_FAILURE);
	if (argc < 2)
		print_error("Error\n.cub file needed", EXIT_FAILURE);
	data_constructor(&data, argv[1]);
	mlx_action(&data);
}
