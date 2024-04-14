/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:28:17 by zkepes            #+#    #+#             */
/*   Updated: 2024/04/14 21:13:34 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
// map characters
# define SPACE '0'
# define WALL '1'
# define COLLEC 'C'
# define EXIT 'E'
# define PLAYER 'P'
# define MAPCHAR "01CEP"		// allowed map characters
# define MAPCHAR_BONUS "01CEPD"	// allowed map characters in bonus
# define CHECKED 'X'
# define DRAGON 'D'
// window and tile sizes
// # define WIN_TITLE "solong"
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define CEN_X 960				// norminette does not allow WIN_WIDTH/2
# define CEN_Y 540
# define CEN_X_OFF 910
# define CEN_Y_OFF 515
# define TILE_WIDTH 100
# define TILE_HEIGHT 50
# define FLOOR 0
# define GROUND 1
# define LAYER -50				// negative values move tiles up
# define GAME_SPEED 4000		// higher value means slower game
# define DRAGON_SPEED 20		// how fast the dragon moves
// player states
# define WALK_DOWN 0
# define WALK_RIGHT 1
# define WALK_UP 2
# define WALK_LEFT 3
# define IDLE 4
// player talking
# define TALK_NO 0
# define TALK_MONEY 1
# define TALK_WALL 2
# define TALK_TIME 20			// how long to show talk
// elements surrounding the player in 4D array
# define N_TOP 3				// next element on tob
# define N_RIG 4				// next element on right
# define N_BOT 5				// next element on bottom
# define N_LEF 6				// next element on left

// 4d array
# define VIEW_BOTTOM 0			// perspective in 4d array
# define VIEW_RIGHT 1			// perspective in 4d array
# define VIEW_TOP 2				// perspective in 4d array
# define VIEW_LEFT 3			// perspective in 4d array
# define TAB_C 0				// character
# define TAB_X 1				// x coordinate
# define TAB_Y 2				// y coordinate

# include "../libft/libft.h"
# include "../libmlx/mlx.h"		// minilibx
# include "struct.h"

# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>
# include <X11/keysym.h>

// map
void			init(t_data *d, char *argv[]);
void			file_into_struct(char *map_file, t_data *d);
void			write_map_size(char *map_file, t_data *d);
void			write_map(char *map_file, t_data *d);
// validate
void			validate_map(t_data *d);
bool			not_valid_file_extension(t_data *d);
bool			not_surrounded_wall(t_data *d);
bool			not_rectangular_map(int width, t_data *d);
bool			not_valid_character(t_data *d);
bool			not_valid_path(t_data *d);
bool			not_valid_path_exit(t_data *data);
bool			not_valid_path_collac(t_data *data);
// validate helper
bool			not_eq_line_char(char *str, char c);
bool			not_eq_first_last_char(char *str, char c);
bool			not_valid_map_char(t_data *d);
bool			not_sufficient_items_map(t_data *d);
int				count_arg1_in_map(char arg1, t_data *d);
// flood fill
void			search_path(t_data *data, char item, int y, int x);
bool			outside_map(t_data *data);
void			cpy_map_tmp(t_data *d);
void			find_position(t_data *data, char c);
void			replace_arg1_arg2_map(char arg1, char arg2, t_data *tmp_d);
// game
void			start_game(t_data *d);
void			destroy_image(t_img img);
void			create_canvas(t_data *d, int w, int h);
bool			validate_move(t_data *d, int move);
void			process_move(int key, t_data *d);
int				render_next_frame(t_data *d);
int				key_hook(int keycode, t_data *d);
void			put_img_to_img(t_img_data dst, t_img_data src, int x, int y);
void			put_pixel_img(t_img_data img, int x, int y, int color);
t_img_data		new_file_img(t_data *d, char *path);
unsigned int	get_pixel_img(t_img_data img, int x, int y);
// map data
void			init_map_4d(t_data *d);
void			cpy_map_4d(t_data *d);
void			player_coordinate(t_data *d, int *coor_x, int *coor_y, int per);
void			dragon_coordinate(t_data *d, int *coor_x, int *coor_y, int per);
void			update_coordinates(t_data *d, int per);
void			update_table_perspective(t_data *d);
void			update_maps(t_data *d);
void			update_surrounding(t_data *d, int per);
void			cpy_exit_from_ori(t_data *d);
void			count_move(t_data *d);
// init images
void			init_images(t_data *d);
void			init_static(t_data *d);
void			init_img_player(t_data *d);
void			init_img_player_idle(t_data *d);
void			init_img_player_walk_down(t_data *d);
void			init_img_player_walk_up(t_data *d);
void			init_img_player_walk_right(t_data *d);
void			init_img_player_walk_left(t_data *d);
void			init_img_coin(t_data *d);
void			init_img_exit(t_data *d);
void			init_img_dragon_idle(t_data *d);
void			init_img_num(t_data *d);
void			init_img_talk(t_data *d);
// render
void			paint_map(t_data *d, int per, int layer);
void			paint_tile(t_data *d);
void			increment_img_frame(t_data *d);
void			render_player(t_data *d);
void			move_player_down(t_data *d);
void			move_player_up(t_data *d);
void			move_player_right(t_data *d);
void			move_player_left(t_data *d);
void			render_talk(t_data *d);
void			render_gui(t_data *d);
// 4d array
void			create_tabc_tabx_taby(t_data *d, int i_per, int i_cxy);
void			create_ntop_nrig_nbot_nlef(t_data *d, int i_per, int i_cxy);
// error
void			e_fd(t_data *d, int fd, char *msg);
void			e_tab(t_data *d, char **tab, int fd, char *msg);
void			e_str(t_data *d, char *str, int fd, char *msg);
void			e_data(t_data *d, char *msg);
// free
void			free_all(t_data *d);
void			free_map(char **map);
void			free_str(char *str);
void			free_tab(char **tab);
void			free_map_4d(t_data *d);
void			free_all_img(t_data *d);
void			free_txt(t_data *d);
void			free_img_static(t_data *d);
void			free_img_coin(t_data *d);
void			free_img_exit(t_data *d);
void			free_img_player_idle(t_data *d);
void			free_img_player_walk_down(t_data *d);
void			free_img_player_walk_up(t_data *d);
void			free_img_player_walk_right(t_data *d);
void			free_img_player_walk_left(t_data *d);
void			free_img_dragon_idle(t_data *d);
void			free_img_talk(t_data *d);
void			free_img_num(t_data *d);
int				close_window(t_data *d);

// print for debugging and checking correct data
void	print_map(t_data *d);
void	print_map_4d_char(t_data *d, int per);
void	print_map_4d_coordinates(t_data *d, int per);

void	dragon_move(t_data *d);
void	dragon_move_clockwise(t_data *d, bool clockwise);
bool	can_dragon_move_down(t_data *d);
bool	can_dragon_move_up(t_data *d);
bool	can_dragon_move_left(t_data *d);
bool	can_dragon_move_right(t_data *d);
#endif
