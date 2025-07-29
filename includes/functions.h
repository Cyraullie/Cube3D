/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:46:40 by ktintim-          #+#    #+#             */
/*   Updated: 2025/07/29 15:44:06 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

//parsing.c
void		parsing(int fd, t_data *data);
void		parse_map(int fd, t_data *data, char *old_buf);
int			add_struct(t_texture *txtr, char *str);
//checking_utils.c
int			is_valid_map_char(char c);
int			has_all_identifiers(t_identifiers *id);
int			check_path(char *path);
int			handle_texture_error(t_texture *txtr);
//check_utils.c
int			check_double(t_texture *txtr, char *str);
int			check_file(char *path);
int			get_data(t_data *data, char *buf, int fd);
//parsing_utils.c
void		strip_newline(char *str);
void		get_map_dimensions(char **lines, t_map *map);
int			check_rgb(char *str);
int			is_map_line(const char *line);
void		map_data(char **raw_lines, t_data *data);
//copy_map.c
int			copy_map(char **raw_lines, t_map *map);
int			check_init_map(char **map);
//check_parsing.c
void		check_parsing(t_data *data);
int			check_texture(t_texture *txtr);
int			check_map(t_map *map);
int			is_empty_or_whitespace(const char *str);
int			check_color(int color[3]);
//free.c
void		free_array(char **tab);
void		free_visited_partial(char **visited, int limit);
int			close_window(void *param);
void		free_text(t_texture *text, void *mlx);
void		print_error(char *msg, int status, t_data *data);
//free_utils.c
void		free_buff_array(char **tab, char *buf);
void		free_tab_and_close(int fd, char *str, char **tab);
void		free_and_close(int fd, char *str);
//map.c
void		open_door(t_data *data);
int			integrity_check(t_map *map);
int			check_neighbors(t_map *map, int x, int y);
//map_utils.c
int			flood_fill_from(t_map *map, int x, int y, char **visited);
int			is_accessible(char c);
int			is_valid_cell(t_map *map, int x, int y);
char		**dup_map(t_map *map);
int			is_player(char c);

//struct_constructor
	//game_constructor.c
void		window_constructor(t_window *window);
void		data_constructor(t_data *data, char *argv);
void		key_constructor(t_key *key);
	//graphic_constructor.c
void		texture_constructor(t_texture *texture, t_data *data);
void		map_constructor(t_map *map);
void		image_constructor(t_img *img, void *mlx, int height, int width);
void		xpm_img_constructor(t_img *img, char *path, void *mlx, t_data *data);
	//constructor_utils.c
int			malloc_data(t_data *data);
int			malloc_texture(t_texture *texture);
	//free_protection.c
void		correct_free(t_data *data, int malloc_index);

//raycasting
	//mlx_action.c
void		mlx_action(t_data *data);
long long	get_time(void);
	//key_press.c
int			key_press(int key, void *param);
	//key_handler.c
int			key_unpress(int key, void *param);
int			mouse_move(int x, int y, void *param);
void		key_pressed(t_data *data);
double		new_x(double angle, t_data *data);
double		new_y(double angle, t_data *data);
	//colision.c
int			check_w(t_data *data);
int			check_s(t_data *data);
int			check_a(t_data *data);
int			check_d(t_data *data);
int			check_door(t_data *data);
	//minimap.c
void		put_minimap(t_data *data, t_img *scn_img);
	//draw_panel.c
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
	//raycasting.c
void		raycasting(t_data *data, t_img *scn_img);
int			rgb_to_hex(int color[3]);
	//grid_search.c
void		intersection_point(t_data *data, t_grid *grid, double angle);

#endif