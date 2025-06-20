/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:41:29 by ktintim-          #+#    #+#             */
/*   Updated: 2025/06/20 11:23:48 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdbool.h>

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

typedef struct s_map {
	char	**map;
	int		rows;
	int		cols;
	float	direction;
	float	c_x;
	float	c_y;
}				t_map;

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
	double	angle_view;
	t_img	*square;
}	t_character;

typedef struct s_texture
{
	t_img	*north;
	char	*n_path;
	t_img	*south;
	char	*s_path;
	t_img	*west;
	char	*w_path;
	t_img	*east;
	char	*e_path;
	int		f_color[3];
	int		c_color[3];
}	t_texture;

typedef struct s_key
{
	bool	w;
	bool	a;
	bool	s;
	bool	d;
	bool	e;
	bool	e_lock;
	bool	left;
	bool	right;
}	t_key;


typedef struct s_data
{
	t_key		*key;
	t_window	*window;
	t_texture	*texture;
	t_map		*map;
	t_segment	*segment;
	t_character	*character;
	long long	last_frame;
	long long	actual_frame;
}	t_data;

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_vars
{
	double	angle;
	double	dx;
	double	dy;
	int		src_x;
	int		src_y;
	int		cx;
	int		cy;
	int		dest_cx;
	int		dest_cy;
	int		x;
	int		y;
}	t_vars;

typedef struct s_dda
{
	double	step_size;
	double	x;
	double	y;
	int		angle;
	int		side;
}	t_dda;

typedef struct s_grid
{
	int		x;
	double	percent;
	double	ray_x;
	double	ray_y;
	double	ray_angle;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	double	side_dist_x;
	double	side_dist_y;
	int		side;
	double	dst;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	plane_x;
	double	plane_y;
	double	fov_scale;
	double	line_h;
}	t_grid;

#endif