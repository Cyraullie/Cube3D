/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:46:40 by ktintim-          #+#    #+#             */
/*   Updated: 2025/07/01 11:17:39 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FUNCTIONS_H
# define FUNCTIONS_H


int			check_map_walls(char **map);

//parsing.c
void		parsing(int fd, t_data *data);
//checking_utils.c
int			is_valid_map_char(char c);
//parsing_utils.c
void		strip_newline(char *str);
void		get_map_dimensions(char **lines, t_map *map);
void		copy_map(char **raw_lines, t_map *map);
//check_parsing.c
int			check_texture(t_texture *txtr);
int			check_map(t_map *map);
//free.c
void		free_array(char **tab);
void		free_visited_partial(char **visited, int limit);
//map.c
void		open_door(t_data *data);
int			integrity_check(t_map *map);
int			is_player(char c);
int			is_accessible(char c);
int			is_valid_cell(t_map *map, int x, int y);
char		**dup_map(t_map *map);
int			flood_fill_from(t_map *map, int x, int y, char **visited);
int			check_neighbors(t_map *map, int x, int y);

//struct_constructor
	//game_constructor.c
void		window_constructor(t_window *window);
void		data_constructor(t_data *data, char *argv);
void		key_constructor(t_key *key);
	//graphic_constructor.c
void		texture_constructor(t_texture *texture);
void		map_constructor(t_map *map);
void		image_constructor(t_img *img, void *mlx, int height, int width);
void		xpm_img_constructor(t_img *img, char *path, void *mlx);

//raycasting
	//mlx_action.c
void		mlx_action(t_data *data);
int			close_window(void *param);
long long	get_time(void);
	//key_handler.c
int			key_press(int key, void *param);
int			key_unpress(int key, void *param);
int			mouse_move(int x, int y, void *param);
void		key_pressed(t_data *data);
double		new_x(double angle, t_data *data);
double		new_y(double angle, t_data *data);
	//control.c
int			check_w(t_data *data);
int			check_s(t_data *data);
int			check_a(t_data *data);
int			check_d(t_data *data);
int			check_door(t_data *data);
	//minimap.c
void		put_minimap(t_data *data, t_img *scn_img);
	//draw_panel.c
void		draw_square(t_img *img, int square_size, int color);
void		draw_map(t_data *data, char *map[8]);
void		draw_line(t_img *img, int color);
void		draw_floor(t_img *scn_img, int color);
void		draw_ceiling(t_img *scn_img, int color);
	//rotate_image.c
void		rotate_image(t_img *src, t_img *dest, double angle_degre);
void		put_pixel(t_img *img, int x, int y, int color);
int			get_pixel(t_img *img, int x, int y);
double		return_radian(double angle_degre);
	//fusion_image.c
void		fusion_image(t_img *screen_img, t_img *img, int x, int y);
int			ft_abs(int a);
double		ft_fabs(double a);
	//DDA.c
void		dda(t_data *data, t_img *scn_img);
// void	intersection_point(t_dda *vars, t_data *data, double angle);
	//raycasting.c
void		raycasting(t_data *data, t_img *scn_img);
int			rgb_to_hex(int color[3]);
	//grid_search.c
void		intersection_point(t_data *data, t_grid *grid, double angle);

//debug
void		visio_map(char **map, int rows, int cols);
#endif