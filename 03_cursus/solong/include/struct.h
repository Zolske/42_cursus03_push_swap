/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 10:06:35 by zkepes            #+#    #+#             */
/*   Updated: 2024/04/07 16:37:45 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdbool.h>

typedef struct s_map
{
	char	*file;		// name of program input map file "*.ber"
	int		width;		// map size in characters
	int		height;		// map size in characters
	char	**map;		// MALLOC! map as characters from input filename
	char	**tmp_map;	// MALLOC! temporay map
	int		****map_4d;	// to hold perspective, char as int, x and y coordinates
	int		x;			// coordinate horizontal axis, left to right
	int		y;			// coordinate vertical axis, top to bottom
	int		perspective;
	bool	valid_path;
}	t_map;

typedef struct s_mlx
{
	void	*mlx_ptr;	// MALLOC! to struct for connection to x service
	void	*win_ptr;	// MALLOC! to window
	int		win_h;
	int		win_w;
}	t_mlx;

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

typedef struct s_img_stat
{
	t_img_data	wall;
	t_img_data	sand;
}	t_img_stat;

typedef struct s_img_anim
{
	t_img_data	idle;
}	t_img_anim;

typedef struct s_images
{
	int			idx_fr;		// store current frame index
	t_img_data	canvas;		// all images are put on the canvas
	t_img_stat	i_sta;			// base images (no animation)
	t_img_anim	i_ani;
	// t_frame		fr[7];		// array of frames
}	t_img;

typedef struct s_tmp_tile
{
	int	x;
	int	y;
	int	per;
	int	tile;
	int	layer;
}	t_tmp_tile;

typedef struct s_data
{
	t_map		map;
	t_mlx		mlx;
	t_img_data	img_d;
	t_img		img;
	t_tmp_tile	tmp;
} t_data;

enum
{
	VIEW_BOTTOM = 0,
	VIEW_RIGHT = 1,
	VIEW_TOP = 2,
	VIEW_LEFT = 3,
	LAYER = -50,	// negative values move tiles up, center is in the middle
	TAB_C = 0,
	TAB_X = 1,
	TAB_Y = 2
};

// typedef struct	s_img_data { // my structure
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_img_d;

// typedef struct s_base
// {
// 	t_img	wall;
// 	t_img	wall_top;
// 	t_img	floor;
// 	t_img	la_ro_lm;
// 	t_img	la_ro_rm;
// }	t_base;

// typedef struct s_frame
// {
// 	t_img	collect;
// 	t_img	la_ro_l;
// 	t_img	la_ro_m;
// 	t_img	la_ro_r;
// }		t_frame;

// typedef struct s_xpm
// {
// 	char		**map;
// 	int			h;
// 	int			w;
// 	int			fr_idx;
// 	t_img		*base_img;
// 	t_base		ba;
// 	t_frame		fr_0;
// 	t_frame		fr_1;
// 	t_frame		fr_2;
// 	t_frame		fr_3;
// 	t_frame		fr_4;
// 	t_frame		fr_5;
// 	t_frame		fr_6;
// }	t_xpm;

#endif



// static images with no animation
// typedef struct s_base
// {
// 	t_img_data	wall;		// wall with front view
// 	t_img_data	wall_top;	// wall top view
// 	t_img_data	floor;		// ground (replaces 0 == SPACE from map)
// 	t_img_data	la_ro_lm;	// lava rock left middle 
// 	t_img_data	la_ro_rm;	// lava rock right middle
// }	t_base;

// typedef struct s_frame
// {
// 	t_img_data	collect;		// collectables
// 	t_img_data	la_ro_l;		// lava rock left (bottom)
// 	t_img_data	la_ro_m;		// lava rock middle (bottom)
// 	t_img_data	la_ro_r;		// lava rock right (bottom)
// }	t_frame;
