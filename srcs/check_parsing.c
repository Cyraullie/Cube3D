/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:56:59 by cgoldens          #+#    #+#             */
/*   Updated: 2025/05/20 11:05:42 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	check_color(int color[3])
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (!(color[i] >= 0 && color[i] <= 255))
			return (1);
		i++;
	}
	return (0);
}

int	check_path(char *path)
{
	int		fd;
	char	*tmp_path;

//TODO check if I can keep that
	tmp_path = ft_strjoin(path, ".png");
	fd = open(tmp_path, O_RDONLY);
	free(tmp_path);
	if (fd == -1)
	{
		printf("Erreur\nThe path '%s' is incorrect\n", path);
		close(fd);
		return (1);
		//exit(EXIT_FAILURE); // ou return si tu veux juste ignorer
	}
	close(fd);
	return (0);
}

int	check_texture(t_texture *txtr)
{
	//TODO free and exit if caca
	if (check_color(txtr->c_color) || check_color(txtr->f_color))
		printf("caca\n");
	if (check_path(txtr->n_path) || check_path(txtr->s_path)
		|| check_path(txtr->e_path) || check_path(txtr->w_path))
		printf("cacaV2\n");
	return (0);
}

int	check_map(t_map *map)
{
	int	cols;
	int	rows;

	printf("rows=%d\ncols=%d\n%s", map->rows, map->cols, map->map[0]);

	rows = 0;
	while (rows < map->rows)
	{
		cols = 0;
		while (cols < map->cols)
		{
			printf("%c", map->map[rows][cols]);
			cols++;
		}
		rows++;
	}
	return (0);
}
