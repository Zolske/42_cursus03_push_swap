/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:28:17 by zkepes            #+#    #+#             */
/*   Updated: 2024/04/07 17:16:26 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define SPACE '0'
# define WALL '1'
# define COLLEC 'C'
# define EXIT 'E'
# define PLAYER 'P'
# define MAPCHAR "01CEP"
# define CHECKED 'X'
# define TILE 48				//TODO: redundant?
# define OFFSET_L 31			//TODO: redundant?
# define WIN_TITLE "solong"
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define CEN_X 1920/2
# define CEN_Y 1080/2
# define CEN_X_OFF 1920/2 -50
# define CEN_Y_OFF 1080/2 -25
# define TILE_WIDTH 100
# define TILE_HEIGHT 50
# define FLOOR 0
# define GROUND 1

// dont change values, just to make it more readable
// # define VIEW_BOTTOM 0
// # define VIEW_RIGHT 1
// # define VIEW_TOP 2
// # define VIEW_LEFT 3

# include "../libft/libft.h"
// minilibx
# include "../libmlx/mlx.h"
// header for rendering images to the window
# include "render.h"
# include "struct.h"

# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>
#include <X11/keysym.h>



// typedef struct s_data
// {
// 	char	*file;		// name of the file
// 	int		width;
// 	int		height;
// 	char	**map;
// 	// char	**map_cpy;	// cpy of the original map
// 	int		x;			// horizontal, left to right, row
// 	int		y;			// vertical, top to bottom, colum
// 	bool	found;		// has found item
// } t_data;

// typedef struct	s_img_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_img_d;

// typedef struct s_position
// {
// 	int	y;
// 	int	x;
// } t_pos;

// to process the xpm files meta data
// typedef struct s_meta_xpm_list
// {
// 	// t_meta_xpm_list	*next;
// 	char			c;
// 	int				color;
// } t_meta_xpm_list;

// typedef struct	s_meta_xpm
// {
// 	int			size_x;
// 	int			size_y;
// 	int			n_colors;
// } t_meta_xpm;


// map
void	init(t_data *d, char *argv[]);
void	file_into_struct(char *map_file, t_data *d);
void	write_map_size(char *map_file, t_data *d);
void	write_map(char *map_file, t_data *d);
// validate
void	validate_map(t_data *d);
bool	not_surrounded_wall(t_data *d);
bool	not_rectangular_map(int width, t_data *d);
bool	not_valid_character(t_data *d);
bool	not_valid_path(t_data *d);
bool	not_valid_path_exit(t_data *data);
bool	not_valid_path_collac(t_data *data);
// validate helper
bool	not_eq_line_char(char *str, char c);
bool	not_eq_first_last_char(char *str, char c);
bool	not_valid_map_char(t_data *d);
bool	not_sufficient_items_map(t_data *d);
int		count_arg1_in_map(char arg1, t_data *d);

// flood fill
void	search_path(t_data *data, char item, int y, int x);
bool	outside_map(t_data *data);
// void	cpy_struct_data(t_data *dest, t_data *src);
void	cpy_map_tmp(t_data *d);
void	find_position(t_data *data, char c);
void	replace_arg1_with_arg2_in_map(char arg1, char arg2, t_data *tmp_d);

// print
void	print_map(t_data *d);
void	print_map_4d_char(t_data *d, int per);
void	print_map_4d_coordinates(t_data *d, int per);

// error
void	e_fd(t_data *d, int fd, char *msg);
void	e_tab(t_data *d, char **tab, int fd, char *msg);
void	e_str(t_data *d, char *str, int fd, char *msg);
void	e_data(t_data *d, char *msg);

// free
void	free_all(t_data *d);
void	free_map(char **map);
void	free_str(char *str);
void	free_tab(char **tab);

// minilibx
void	start_game(t_data *d);
// void	my_mlx_pixel_put(t_i_data *data, int x, int y, int color);
// int		key_press(int keycode, void *param);
// int		mouse_move(int x, int y, void *param);

// process xpm files
// void	init_xpm(t_xpm *xpm, t_data *d, t_img *base_img, t_win window);
// void	init_base(t_xpm *xpm, t_win window);
// void	init_frame_0(t_xpm *xpm, t_win window);
// void	init_frame_1(t_xpm *xpm, t_win window);

// render functions
// t_win	new_window(int w, int h, char *str);
// t_img	new_img(int w, int h, t_win window);
// t_img	new_file_img(char * path, t_win window);
void	destroy_image(t_img img);
// void	put_pixel_img(t_img img, int x, int y, int color);
// unsigned int	get_pixel_img(t_img img, int x, int y);
// void	put_img_to_img(t_img dst, t_img src, int x, int y);
// int	update_frame(t_xpm *xpm);
// void	init_map(t_xpm *xpm);


// refactor
void	create_canvas(t_data *d, int w, int h);
void	put_img_to_img(t_img_data dst, t_img_data src, int x, int y);
t_img_data	new_file_img(t_data *d, char *path);
void	put_pixel_img(t_img_data img, int x, int y, int color);
// void	init_images(t_data *d);
// void	init_base(t_data *d);
// void	init_frame(t_data *d);
unsigned int	get_pixel_img(t_img_data img, int x, int y);

//TESTING

// typedef struct s_img
// {
// 	// t_win	win;
// 	void	*img_ptr;
// 	char	*addr;
// 	int		h;
// 	int		w;
// 	int		bpp;
// 	int		endian;
// 	int		line_len;
// }		t_img_test;

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
}		t_win_test;

// void	test_create_canvas(t_data d, t_img_data canvas, int w, int h);
t_win_test new_window(int w, int h, char *str);
// t_img_test	new_img(int w, int h, t_win_test window);
// t_img_data	new_img(int w, int h, t_data *d, t_img_data *base_image);

void	init_map_4d(t_data *d);
void	cpy_map_4d(t_data *d);
void	player_coordinate(t_data *d, int *coor_x, int *coor_y, int perspective);
void	update_coordinates(t_data *d, int per);
void	paint_map(t_data *d, int per, int layer);
void	init_static_img(t_data *d);
void	paint_tile(t_data *d);
void	update_table_perspective(t_data *d);
void	update_maps(t_data *d);
void	init_anim_img(t_data *d);
int render_next_frame(t_data *d);
void	process_move(int keysym, t_data *d);
int		translate_keysym(int keysym, t_data *d);

// close window
int	close_window(t_data *d);

int	key_hook(int keycode, t_data *d);
#endif
