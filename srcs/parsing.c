/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:46:51 by cgoldens          #+#    #+#             */
/*   Updated: 2025/07/04 16:12:57 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"



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
		if (!tab[i] || tab[i][0] == '\n' || check_rgb(tab[i]))
		{
			printf("Error\nRGB format (255,255,255) is not respected\n");
			free_array(tab);
			exit(EXIT_FAILURE);
		}
		color[i] = ft_atoi(tab[i]);
		i++;
	}
	free_array(tab);
}

/**
 * @brief function to check when an identifier are update
 * 
 * @param tab 
 * @param txtr 
 */
void	count_identifier(char *tab, t_texture *txtr)
{
	if (!ft_strncmp(tab, "NO", 3))
		txtr->id->no = 1;
	else if (!ft_strncmp(tab, "SO", 3))
		txtr->id->so = 1;
	else if (!ft_strncmp(tab, "WE", 3))
		txtr->id->we = 1;
	else if (!ft_strncmp(tab, "EA", 3))
		txtr->id->ea = 1;
	else if (!ft_strncmp(tab, "F", 2))
		txtr->id->f = 1;
	else if (!ft_strncmp(tab, "C", 2))
		txtr->id->c = 1;
}


/**
 * @brief add data with identifier in struct
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
	if (!tab || !tab[0] || !tab[1])
		return (free_array(tab), 0);
	count_identifier(tab[0], txtr);
	if (!ft_strncmp(tab[0], "NO", 3))
		txtr->n_path = ft_strdup(tab[1]);
	else if (!ft_strncmp(tab[0], "SO", 3))
		txtr->s_path = ft_strdup(tab[1]);
	else if (!ft_strncmp(tab[0], "WE", 3))
		txtr->w_path = ft_strdup(tab[1]);
	else if (!ft_strncmp(tab[0], "EA", 3))
		txtr->e_path = ft_strdup(tab[1]);
	else if (!ft_strncmp(tab[0], "F", 2))
		get_color(txtr->f_color, tab[1]);
	else if (!ft_strncmp(tab[0], "C", 2))
		get_color(txtr->c_color, tab[1]);
	else
		return (free_array(tab), 0);
	return (free_array(tab), 1);
}

/**
 * @brief add map in data struct
 * 
 * @param fd 
 * @param data 
 * @param old_buf 
 */
void	parse_map(int fd, t_data *data, char *old_buf)
{
	char	**raw_lines;
	int		line_idx;
	char	*buf;

	line_idx = 0;
	raw_lines = malloc(sizeof(char *) * 1024);
	buf = old_buf;
	while (buf != NULL)
	{
		strip_newline(buf);
		raw_lines[line_idx++] = ft_strdup(buf);
		free(buf);
		buf = get_next_line(fd);
	}
	raw_lines[line_idx] = NULL;
	if (check_init_map(raw_lines))
	{
		free_tab_and_close(fd, buf, raw_lines);
		print_error("Error\nCutted map", EXIT_FAILURE, data);
	}
	map_data(raw_lines, data);
	free_buff_array(raw_lines, buf);
}

/**
 * @brief main function to parse .cub
 * 
 * @param file 
 * @param data 
 */
void	parsing(int fd, t_data *data)
{
	char	*buf;

	buf = get_next_line(fd);
	while (buf != NULL)
	{
		if (!(!ft_strcmp(buf, "\n") || is_empty_or_whitespace(buf)))
		{
			if (!has_all_identifiers(data->texture->id))
				add_struct(data->texture, buf);
			else if (is_map_line(buf))
			{
				parse_map(fd, data, buf);
				break ;
			}
			else
			{
				free_and_close(fd, buf);
				print_error("Error\nInvalid line", EXIT_FAILURE, data);
			}
		}
		free(buf);
		buf = get_next_line(fd);
	}
	close(fd);
	check_parsing(data);
}
