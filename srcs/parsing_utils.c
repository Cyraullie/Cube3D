/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:59:14 by cgoldens          #+#    #+#             */
/*   Updated: 2025/05/19 15:59:42 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	strip_newline(char *str)
{
	int	len;

	if (!str)
		return ;
	len = 0;
	while (str[len])
		len++;
	if (len > 0 && str[len - 1] == '\n')
		str[len - 1] = '\0';
}
