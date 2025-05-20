/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:41:29 by ktintim-          #+#    #+#             */
/*   Updated: 2025/05/20 15:10:12 by ktintim-         ###   ########.fr       */
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

typedef struct s_img {
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_character
{
	double	x_pose;
	double	y_pose;
	double	fov;
	t_img	*square;
}	t_character;

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
	t_character	*character;
	int			seg_count;
}	t_data;

#endif