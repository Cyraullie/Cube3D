/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 15:34:09 by cgoldens          #+#    #+#             */
/*   Updated: 2025/07/04 16:08:52 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

/**
 * @brief free a string and an array
 * 
 * @param tab 
 */
void	free_buff_array(char **tab, char *buf)
{
	free(buf);
	free_array(tab);
}

/**
 * @brief free a string and close file descriptor
 * 
 * @param fd 
 * @param str 
 */
void	free_and_close(int fd, char *str)
{
	close(fd);
	free(str);
}

/**
 * @brief free an array, a string and close file descriptor
 * 
 * @param fd 
 * @param str 
 * @param tab 
 */
void	free_tab_and_close(int fd, char *str, char **tab)
{
	close(fd);
	free_buff_array(tab, str);
}
