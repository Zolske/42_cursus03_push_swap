/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:23:31 by zkepes            #+#    #+#             */
/*   Updated: 2024/04/03 11:37:19 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

// typedef struct s_win
// {
// 	void	*mlx_ptr;
// 	void	*win_ptr;
// 	int		height;
// 	int		width;
// }		t_win;

// typedef struct s_img
// {
// 	t_win	win;
// 	void	*img_ptr;
// 	char	*addr;
// 	int		h;
// 	int		w;
// 	int		bpp;
// 	int		endian;
// 	int		line_len;
// }		t_img;

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


// t_win	new_window(int w, int h, char *str);
// t_img	new_img(int w, int h, t_win window);
// t_img	new_file_img(char * path, t_win window);
// void	destroy_image(t_img img);
// void	put_pixel_img(t_img img, int x, int y, int color);
// unsigned int	get_pixel_img(t_img img, int x, int y);
// void	put_img_to_img(t_img dst, t_img src, int x, int y);
// int	update_frame(t_xpm *xpm);
// void	init_map(t_xpm *xpm);
#endif
