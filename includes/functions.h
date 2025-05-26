/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:46:40 by ktintim-          #+#    #+#             */
/*   Updated: 2025/05/26 14:48:21 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FUNCTIONS_H
# define FUNCTIONS_H
//constructor.c
void	window_constructor(t_window *window);
void	texture_constructor(t_texture *texture);
void	data_constructor(t_data *data);
//parsing.c
void	parsing(char *file, t_data *data);
//checking_utils.c
int		is_valid_map_char(char c);
//parsing_utils.c
void	strip_newline(char *str);
void	get_map_dimensions(char **lines, t_map *map);
void	copy_map(char **lines, t_map *map);
//check_parsing.c
int		check_texture(t_texture *txtr);
int		check_map(t_map *map);
//free.c
void	free_array(char **tab);
void	free_visited_partial(char **visited, int limit);
//map.c
int		integrity_check(t_map *map);
int		is_player(char c);
int		is_accessible(char c);
int		is_valid_cell(t_map *map, int x, int y);
char	**dup_map(t_map *map);
int		flood_fill_from(t_map *map, int x, int y, char **visited);
int		check_neighbors(t_map *map, int x, int y);

//struct_constructor
	//constructor1.c
void	window_constructor(t_window *window);
void	texture_constructor(t_texture *texture);
void	data_constructor(t_data *data);
void	image_constructor(t_img *img, void *mlx, int height, int width);
	//constructor2.c
void	key_constructor(t_key *key);

//raycasting
	//mlx_action.c
void	mlx_action(t_data *data, char *map[8]);
int		close_window(void *param);
	//key_handler.c
int		key_handler(int key, void *param);
int		key_press(int key, void *param);
int		key_unpress(int key, void *param);
void	key_pressed(t_data *data);
	//draw_panel.c
void	draw_square(t_img *img, int square_size, int color);
void	draw_map(t_data *data, char *map[8]);
void	draw_rotated_square(t_img *img, double angle_rad);
void	draw_line(t_img *img, int color);
	//rotate_image.c
void	rotate_image(t_img *src, t_img *dest, double angle_degre);
void	put_pixel(t_img *img, int x, int y, int color);
int		get_pixel(t_img *img, int x, int y);
	//fusion_image.c
void	fusion_image(t_img *screen_img, t_img *img, int x, int y);


#endif