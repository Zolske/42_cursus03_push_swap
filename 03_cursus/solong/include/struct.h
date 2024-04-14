/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 10:06:35 by zkepes            #+#    #+#             */
/*   Updated: 2024/04/14 21:22:53 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdbool.h>

// map data
typedef struct s_map
{
	bool	bonus;		// set to true in solong.c init function for bonus
	bool	found_dragon; // if there is a dragon then render it
	char	*file;		// name of program input map file "*.ber"
	int		width;		// map size in characters
	int		height;		// map size in characters
	char	**map;		// MALLOC! map as characters from input filename
	char	**tmp_map;	// MALLOC! temporay map
	int		****map_4d;	// MALLOC! perspective, char as int, x and y coordinates
	int		x;			// coordinate horizontal axis, left to right
	int		y;			// coordinate vertical axis, top to bottom
	int		per;		// perspective, map
	int		coins;		// number of coins to be collected
	bool	keys_locked;// lock keys while animation is running
	bool	show_exit;	// show exit after all coins collected
	bool	game_won;	// show game won message
	bool	game_lost;	// show game lost message
	int		move_x;		// move towards the x direction
	int		move_y;		// move towards the y direction
	bool	valid_path;	// path to exit, collectables
	int		count_moves;// number of moves
	bool	copy_exit;	// copy exit back into 4d map, only once
	int		dragon_speed;
}	t_map;

// needed by mlx library
typedef struct s_mlx
{
	void	*mlx_ptr;	// MALLOC! to struct for connection to x service
	void	*win_ptr;	// MALLOC! to window
}	t_mlx;

// needed by mlx library for images
typedef struct s_img_data
{
	void	*img_ptr;
	char	*addr;
	int		h;
	int		w;
	int		bpp;			// bits per pixel
	int		endian;
	int		line_len;
}	t_img_data;

// static images
typedef struct s_img_stat
{
	t_img_data	wall;
	t_img_data	sand;
	t_img_data	wallh;
}	t_img_stat;

// player images
typedef struct s_player
{
	int			state;		// player state, idle, walk, ...
	int			fr;			// current player frame
	int			last_fr;	// last frame
	int			state_talk;	// what text to display for talk
	int			talk_idx;
	t_img_data	idle[12];	// sprites for idle player
	t_img_data	down[12];	// sprites for walking down
	t_img_data	up[12];		// sprites for walking up
	t_img_data	left[12];	// sprites for walking left
	t_img_data	right[12];	// sprites for walking right
}	t_player;

// player images
typedef struct s_dragon
{
	int			state;		// player state, idle, walk, ...
	int			fr;			// current player frame
	int			last_fr;	// last frame
	t_img_data	idle[12];	// sprites for idle player
	t_img_data	down[12];	// sprites for walking down
	t_img_data	up[12];		// sprites for walking up
	t_img_data	left[12];	// sprites for walking left
	t_img_data	right[12];	// sprites for walking right
}	t_dragon;

// player images
typedef struct s_talk
{
	int			time;		// counting up to controll how long to show talk
	t_img_data	money[6];	// talk when see coin
	t_img_data	wall[6];	// talk when see wall
}	t_talk;

// GUI
typedef struct s_text
{
	t_img_data	arrow_key;	// legend for keys
	t_img_data	won;		// win message
	t_img_data	lost;		// lost message
	t_img_data	num[10];	// digits to show moves
	t_img_data	moves;		// word moves to show before num
}	t_text;

// containing all images
typedef struct s_images
{
	int			idx_fr;		// store current frame index
	t_img_data	canvas;		// all images are put on the canvas
	t_img_stat	i_sta;		// static images
	t_player	player;		// struct for player images
	t_dragon	dragon;
	t_img_data	coin[12];	// collectable sprite
	t_img_data	exit[12];	// exit portal sprite
	t_text		text;		// structure for gui
	t_talk		talk;
}	t_img;

// temp data overwritten after each tile render
typedef struct s_tmp_tile
{
	int	x;					// coordinate of tile placement in the map
	int	y;
	int	per;				// perspective
	int	tile;				// tile to be rendered
	int	layer;				// layer (FLOOR, GROUND)
}	t_tmp_tile;

// containing all other structures / data
typedef struct s_data
{
	t_map		map;		// struct containing map data
	t_mlx		mlx;		// struct for mlx lib
	t_img_data	img_d;		// struct for mlx lib used for images
	t_img		img;		// struct for images
	t_tmp_tile	tmp;		// temporay data, image tiles
}	t_data;

#endif
