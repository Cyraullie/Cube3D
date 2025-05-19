/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:46:51 by cgoldens          #+#    #+#             */
/*   Updated: 2025/05/19 16:23:26 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"
//TODO check data missing or incorrect

/**
 * @brief Get the color object
 * 
 * @param color 
 * @param str 
 */
void	get_color(int color[3], char *str)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_split(str, ',');
	while (i < 3)
	{
		if (!tab[i] || tab[i][0] == '\n')
		{
			printf("Erreur\nRGB format (255,255,255) is not respected\n");
			free_array(tab);
			exit(EXIT_FAILURE);
		}
		color[i] = ft_atoi(tab[i]);
		i++;
	}
	free_array(tab);
}

/**
 * @brief caca
 * 
 * @param txtr 
 * @param str 
 * @return int 
 */
int	add_struct(t_texture *txtr, char *str)
{
	char	**tab;

	strip_newline(str);
	tab = ft_split(str, ' ');

	if (!ft_strncmp(tab[0], "NO", 3))
		txtr->n_path = tab[1];
	else if (!ft_strncmp(tab[0], "SO", 3))
		txtr->s_path = tab[1];
	else if (!ft_strncmp(tab[0], "WE", 3))
		txtr->w_path = tab[1];
	else if (!ft_strncmp(tab[0], "EA", 3))
		txtr->e_path = tab[1];
	else if (!ft_strncmp(tab[0], "F", 2))
		get_color(txtr->f_color, tab[1]);
	else if (!ft_strncmp(tab[0], "C", 2))
		get_color(txtr->c_color, tab[1]);
	else
		return (0);
	return (1);
}

void	add_map(t_map *map, char *str)
{
	strip_newline(str);
	map->map[map->cols] = str;
	map->rows = ft_strlen(str);
	map->cols++;
}

/**
 * @brief 
 * 
 * @param file 
 * @param txtr 
 */
void	test(char *file, t_data *data)
{
	int		fd;
	char	*buf;
	int		count;

	count = 0;
	buf = malloc(BUFFER_SIZE * sizeof(char *));

	fd = open(file, O_RDONLY);
	//read(fd, buf, BUFFER_SIZE);
	//printf("%s\n", buf);
	buf = get_next_line(fd);
	while (buf != NULL)
	{
		//printf("%s", buf);
		if (!(!ft_strcmp(buf, "\n")))
		{
			if (count != MAX_DATA)
			{
				count += add_struct(data->texture, buf);
				printf("%d_%s\n", count, buf);
			}
			else
			{
				add_map(data->map, buf);
			}
		}
		free(buf);
		buf = get_next_line(fd);
	}
	//TODO if incorrect free + exit
	check_texture(data->texture);
	check_map(data->map);
	close(fd);
}

