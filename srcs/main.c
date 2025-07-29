/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:46:48 by cgoldens          #+#    #+#             */
/*   Updated: 2025/07/29 16:11:58 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

//TODO map missing
//TODO pas le droit de passer en diago (les coins de map interdit)
//TODO texture nord et sud la meme ????
//TODO compilation par rapport au header aussi (dans makefile)
//TODO autoriser uniquement les .xpm
//TODO input infini


static int	find_last_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i - 1);
}

static int	check_file_name(char *path)
{
	const char	*ext = ".cub";
	size_t		len_filename;
	size_t		len_ext;
	char		**tab;
	int			id;

	tab = ft_split(path, '/');
	id = find_last_tab(tab);
	len_filename = ft_strlen(tab[id]);
	len_ext = ft_strlen(ext);
	if (!ft_strncmp(tab[id], ".cub", 5))
		return (free_array(tab), 1);
	if ((!ft_strcmp(tab[id] + (len_filename - len_ext), ext)) == 0)
		return (free_array(tab), 1);
	return (free_array(tab), 0);
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
	if (argc < 2 || check_file_name(argv[1]))
	{
		printf("Error\n.cub file needed\n");
		exit(EXIT_FAILURE);
	}
	data_constructor(&data, argv[1]);
	mlx_action(&data);
}
