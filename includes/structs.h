/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:41:29 by ktintim-          #+#    #+#             */
/*   Updated: 2025/07/08 16:25:21 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdbool.h>

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
	double	view_speed;
	double	move_speed;
}	t_character;

typedef struct s_identifiers
{
	int		no;
	int		so;
	int		we;
	int		ea;
	int		f;
	int		c;
	int		complete;
}	t_identifiers;


typedef struct s_texture
{
	t_identifiers	*id;
	t_img			*north;
	char			*n_path;
	t_img			*south;
	char			*s_path;
	t_img			*west;
	char			*w_path;
	t_img			*east;
	char			*e_path;
	int				f_color[3];
	int				c_color[3];
	t_img			*c_door;
}	t_texture;

typedef struct s_key
{
	bool	w;
	bool	a;
	bool	s;
	bool	d;
	bool	left;
	bool	right;
	bool	eshap;
}	t_key;


typedef struct s_data
{
	t_key		*key;
	t_window	*window;
	t_texture	*texture;
	t_map		*map;
	t_character	*character;
	long long	last_frame;
	long long	actual_frame;
	int			close;
}	t_data;

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
	int		door_side;
	int		hit_wall;
	double	dst;
	double	line_h;
}	t_grid;

#endif