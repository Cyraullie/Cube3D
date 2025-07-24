/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:46:48 by cgoldens          #+#    #+#             */
/*   Updated: 2025/07/24 17:33:36 by cgoldens         ###   ########.fr       */
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

int	check_file_name(char *path)
{
	const char	*ext = ".cub";
	size_t		len_filename;
	size_t		len_ext;

	len_filename = ft_strlen(path);
	len_ext = ft_strlen(ext);
	if (!ft_strcmp(path, ".cub"))
		return (1);
	return (!ft_strcmp(path + (len_filename - len_ext), ext) == 0);
}

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
	if (argc < 2  || check_file_name(argv[1]))
	{
		printf("Error\n.cub file needed\n");
		exit(EXIT_FAILURE);
	}
	//TODO check name of file need to contain .cub but .cub only didnt work
	data_constructor(&data, argv[1]);
	mlx_action(&data);
}
