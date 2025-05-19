/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:41:29 by ktintim-          #+#    #+#             */
/*   Updated: 2025/05/19 10:27:07 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_segment
{
	float	x1;
	float	y1;
	float	x2;
	float	y2;
}	t_segment;

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
	int		f_color[3];
	int		c_color[3];
}	t_texture;

typedef struct s_data
{
	t_window	*window;
	t_texture	*texture;
	t_segment	*segment;
	int			seg_count;
}	t_data;

#endif