/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:41:29 by ktintim-          #+#    #+#             */
/*   Updated: 2025/05/20 10:18:19 by ktintim-         ###   ########.fr       */
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

	void	*black_img;
	int		black_img_line_size;
	char	*black_img_data;
	void	*white_img;
	int		white_img_line_size;
	char	*white_img_data;
}	t_texture;

typedef struct s_data
{
	t_window	*window;
	t_texture	*texture;
	t_segment	*segment;
	int			seg_count;
}	t_data;

#endif