/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:41:29 by ktintim-          #+#    #+#             */
/*   Updated: 2025/05/16 15:51:27 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_window
{
	void	*mlx;
	void	*win;
}	t_window;

typedef struct s_texture
{
	void	*north;
	void	*south;
	void	*west;
	void	*east;
	char	*n_path;
	char	*s_path;
	char	*w_path;
	char	*e_path;
}	t_texture;

#endif