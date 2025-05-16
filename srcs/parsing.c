/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:46:51 by cgoldens          #+#    #+#             */
/*   Updated: 2025/05/16 15:46:51 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	test(char *file)
{
	int		fd;
	char	*buf;

	buf = malloc(BUFFER_SIZE * sizeof(char *));

	fd = open(file, O_RDONLY);
	read(fd, buf, BUFFER_SIZE);
	printf("%s\n", ft_split(buf, ' ')[0]);
}

