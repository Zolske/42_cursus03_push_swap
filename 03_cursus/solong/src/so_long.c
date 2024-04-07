/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:27:59 by zkepes            #+#    #+#             */
/*   Updated: 2024/04/07 17:47:28 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int main(int argc, char *argv[])
{
	t_data data;

	if (argc == 2)
	{
		init(&data, argv);
		file_into_struct(argv[1], &data);
		// validate_map(&data);
		start_game(&data);
		free_all(&data);
	}
}

void init(t_data *d, char *argv[])
{
	d->map.file = argv[1];
	d->map.height = 0;
	d->map.width = 0;
	d->map.map = NULL;
	d->map.tmp_map = NULL;
	d->map.valid_path = false;
	d->map.perspective = VIEW_BOTTOM;
}

void start_game(t_data *d)
{
	d->mlx.win_w = 1920;
	d->mlx.win_h = 1080;
	d->mlx.mlx_ptr = mlx_init();
	d->mlx.win_ptr = mlx_new_window(d->mlx.mlx_ptr, d->mlx.win_w, d->mlx.win_h, WIN_TITLE);
	create_canvas(d, d->mlx.win_w, d->mlx.win_h);
	init_static_img(d);
	init_anim_img(d);

	t_img_data wall_light;
	t_img_data wall_dark;
	t_img_data acid;
	t_img_data lava;
	t_img_data lava_dark;
	t_img_data sand;
	t_img_data stone;

	// const int CEN_X_OFF = 1920/2 -50;
	// const int CEN_Y_OFF = 1080/2 -25;

	wall_light = new_file_img(d, "img/stonebrickbluefull.xpm");
	wall_dark = new_file_img(d, "img/stonebrickdarkfull.xpm");
	acid = new_file_img(d, "img/acidfull.xpm");
	lava = new_file_img(d, "img/lavafull.xpm");
	lava_dark = new_file_img(d, "img/lavadarkfull.xpm");
	sand = new_file_img(d, "img/sandfull.xpm");

	// stone = new_file_img(d, "img/stonebluefull.xpm");
	// put_img_to_img(d->img.canvas, wall_dark , CEN_X_OFF -50, CEN_Y_OFF -25);	// left
	// put_img_to_img(d->img.canvas, sand , CEN_X_OFF +50, CEN_Y_OFF -25);		// top
	// put_img_to_img(d->img.canvas, wall_dark , CEN_X_OFF, CEN_Y_OFF + -50);	// next Level
	// put_img_to_img(d->img.canvas, acid , CEN_X_OFF +50, CEN_Y_OFF +25);		// right
	// put_img_to_img(d->img.canvas, lava , CEN_X_OFF -50, CEN_Y_OFF +25);		// bottom

	init_map_4d(d);
	cpy_map_4d(d);
	update_maps(d);
	// update_coordinates(d, VIEW_BOTTOM);
	// update_table_perspective(d);
	// print_map_4d_char(d, VIEW_BOTTOM);
	print_map_4d_char(d, VIEW_RIGHT);
	// print_map_4d_char(d, VIEW_TOP);
	// print_map_4d_char(d, VIEW_LEFT);
	// print_map_4d_coordinates(d, VIEW_BOTTOM);
	paint_map(d, VIEW_BOTTOM, 0);
	paint_map(d, VIEW_BOTTOM, 1);
	// put_img_to_img(d->img.canvas, lava, CEN_X_OFF, CEN_Y_OFF);			// center


	mlx_put_image_to_window(d->mlx.mlx_ptr, d->mlx.win_ptr, d->img.canvas.img_ptr, 0, 0);
	mlx_key_hook(d->mlx.win_ptr, key_hook, d);
	mlx_hook(d->mlx.win_ptr, 17, 1L << 0, close_window, d);
	mlx_loop_hook(d->mlx.mlx_ptr, render_next_frame, d);
	mlx_loop(d->mlx.mlx_ptr);
}

void	process_move(int keysym, t_data *d)
{
	keysym = translate_keysym(keysym, d);
	printf("keysym: %d\n", keysym);
}

int	translate_keysym(int keysym, t_data *d)
{
	if (d->map.perspective == VIEW_RIGHT)
	{
		if (keysym == XK_Right)
			return (XK_Down);
		else if (keysym == XK_Down)
			return (XK_Left);
		else if (keysym == XK_Left)
			return (XK_Up);
		else if (keysym == XK_Up)
			return (XK_Right);
	}
	else if (d->map.perspective == VIEW_TOP)
	{
		if (keysym == XK_Right)
			return (XK_Left);
		else if (keysym == XK_Down)
			return (XK_Up);
		else if (keysym == XK_Left)
			return (XK_Right);
		else if (keysym == XK_Up)
			return (XK_Down);
	}
	else if (d->map.perspective == VIEW_LEFT)
	{
		if (keysym == XK_Right)
			return (XK_Up);
		else if (keysym == XK_Down)
			return (XK_Right);
		else if (keysym == XK_Left)
			return (XK_Up);
		else if (keysym == XK_Up)
			return (XK_Left);
	}
	return (keysym);
}

int render_next_frame(t_data *d)
{
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.canvas.img_ptr);
	create_canvas(d, d->mlx.win_w, d->mlx.win_h);
	update_maps(d);
	paint_map(d, d->map.perspective, 0);
	paint_map(d, d->map.perspective, 1);
	mlx_put_image_to_window(d->mlx.mlx_ptr, d->mlx.win_ptr, d->img.canvas.img_ptr, 0, 0);
	// printf("next frame, perspective: %d\n", d->map.perspective);
}

int	key_hook(int keysym, t_data *d)
{
	if (keysym == XK_Up)
		printf("Up\n");
	else if (keysym == XK_Right)
		printf("Right\n");
	else if (keysym == XK_Down)
		printf("Down\n");
	else if (keysym == XK_Left)
		printf("Left\n");
	else if (keysym == XK_Tab)
	{
		printf("tab\n");
		if (VIEW_LEFT == d->map.perspective)
			d->map.perspective = VIEW_BOTTOM;
		else
			d->map.perspective++;
	}
	else if (keysym == XK_Escape)
		close_window(d);
	return (0);
}


int close_window(t_data *d)
{
	mlx_destroy_window(d->mlx.mlx_ptr, d->mlx.win_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.canvas.img_ptr);
	mlx_destroy_display(d->mlx.mlx_ptr);
	free(d->mlx.mlx_ptr);
	free_all(d);
	exit(0);
}

void init_map_4d(t_data *d)
{
	int i_per;
	int i_cxy;
	int i_tab;

	i_per = 0;
	d->map.map_4d = (int ****)malloc(sizeof(int ***) * 5);
	d->map.map_4d[4] = NULL;
	while (i_per < 4)
	{
		d->map.map_4d[i_per] = (int ***)malloc(sizeof(int **) * 4);
		d->map.map_4d[i_per][3] = NULL;
		i_cxy = 0;
		while (i_cxy < 3)
		{
			if (i_per == 0 || i_per == 2)
			{
				d->map.map_4d[i_per][i_cxy] =
					(int **)malloc(sizeof(int *) * d->map.height + 1);
				d->map.map_4d[i_per][i_cxy][d->map.height] = NULL;
				i_tab = 0;
				while (i_tab < d->map.height)
				{
					d->map.map_4d[i_per][i_cxy][i_tab] = (int *)malloc(sizeof(int) * d->map.width + 1);
					d->map.map_4d[i_per][i_cxy][i_tab][d->map.width] = INT_MAX;
					i_tab++;
				}
			}
			if (i_per == 1 || i_per == 3)
			{
				d->map.map_4d[i_per][i_cxy] =
					(int **)malloc(sizeof(int *) * d->map.width + 1);
				d->map.map_4d[i_per][i_cxy][d->map.width] = NULL;
				i_tab = 0;
				while (i_tab < d->map.width)
				{
					d->map.map_4d[i_per][i_cxy][i_tab] = (int *)malloc(sizeof(int) * d->map.height + 1);
					d->map.map_4d[i_per][i_cxy][i_tab][d->map.height] = INT_MAX;
					i_tab++;
				}
			}
			i_cxy++;
		}
		i_per++;
	}
}

void cpy_map_4d(t_data *d)
{
	int idx_row;
	int idx_col;

	idx_row = 0;
	while (idx_row < d->map.height)
	{
		idx_col = 0;
		while (idx_col < d->map.width)
		{
			d->map.map_4d[0][0][idx_row][idx_col] = d->map.map[idx_row][idx_col];
			idx_col++;
		}
		idx_row++;
	}
}

void	update_table_perspective(t_data *d)
{
	int idx_row;
	int idx_col;
	int idx_row_last;
	int idx_col_last;
	char cpy;

	idx_row_last = d->map.height;
	idx_row = 0;
	while (d->map.map_4d[VIEW_BOTTOM][TAB_C][idx_row] != NULL)
	{
		idx_row_last--;
		idx_col = 0;
		idx_col_last = d->map.width;
		while (d->map.map_4d[VIEW_BOTTOM][TAB_C][idx_row][idx_col] != INT_MAX)
		{
			idx_col_last--;
			cpy = d->map.map_4d[VIEW_BOTTOM][TAB_C][idx_row][idx_col];
			d->map.map_4d[VIEW_RIGHT][TAB_C][idx_col][idx_row_last] = cpy;
			d->map.map_4d[VIEW_TOP][TAB_C][idx_row_last][idx_col_last] = cpy;
			d->map.map_4d[VIEW_LEFT][TAB_C][idx_col_last][idx_row] = cpy;
			idx_col++;
		}
		idx_row++;
	}
}

void	update_maps(t_data *d)
{
	update_table_perspective(d);
	update_coordinates(d, VIEW_BOTTOM);
	update_coordinates(d, VIEW_RIGHT);
	update_coordinates(d, VIEW_TOP);
	update_coordinates(d, VIEW_LEFT);
}

/*coor. must coordinate[2], [0] is for x axis, [1] for y axis*/
void player_coordinate(t_data *d, int *coor_x, int *coor_y, int per)
{
	int idx_y;
	int idx_x;

	idx_y = 0;
	// while (idx_y < d->map.height)
	while (d->map.map_4d[per][TAB_C][idx_y] != NULL)
	{
		idx_x = 0;
		// while (idx_x < d->map.width)
		while (d->map.map_4d[per][TAB_C][idx_y][idx_x] != INT_MAX)
		{
			if (PLAYER == (char)d->map.map_4d[per][TAB_C][idx_y][idx_x])
			{
				*coor_x = idx_x;
				*coor_y = idx_y;
				return;
			}
			idx_x++;
		}
		idx_y++;
	}
}

void update_coordinates(t_data *d, int per)
{
	int play_x;
	int play_y;
	int idx_y;
	int idx_x;

	player_coordinate(d, &play_x, &play_y, per);
	idx_y = 0;
	while (d->map.map_4d[per][TAB_X][idx_y] != NULL)
	{
		idx_x = 0;
		while (d->map.map_4d[per][TAB_X][idx_y][idx_x] != INT_MAX)
		{
			d->map.map_4d[per][TAB_X][idx_y][idx_x] =
			((idx_x - play_x) - (idx_y - play_y)) * (TILE_WIDTH / 2);
			d->map.map_4d[per][TAB_Y][idx_y][idx_x] =
			(((idx_x- play_x) + (idx_y - play_y))) * (TILE_HEIGHT / 2);
			idx_x++;
		}
		idx_y++;
	}
}

void paint_map(t_data *d, int per, int level)
{
	int idx_row;
	int idx_col;
	
	d->tmp.per = per;
	d->tmp.layer = level;
	idx_row = 0;
	while (d->map.map_4d[per][TAB_C][idx_row] != NULL)
	{
		idx_col = 0;
		while (d->map.map_4d[per][TAB_X][idx_row][idx_col] != INT_MAX)
		{
			d->tmp.x = CEN_X_OFF + d->map.map_4d[per][TAB_X][idx_row][idx_col];
			d->tmp.y = CEN_Y_OFF + d->map.map_4d[per][TAB_Y][idx_row][idx_col]
				+ (LAYER * level);
			d->tmp.tile = d->map.map_4d[per][TAB_C][idx_row][idx_col];
			d->tmp.layer = level;
			paint_tile(d);
			idx_col++;
		}
		idx_row++;
	}
}

void	paint_tile(t_data *d)
{
	t_img_data tile_img;
	bool		paint_tile;

	paint_tile = false;
	if (0 == d->tmp.layer)
	{
		tile_img = d->img.i_sta.sand;
		paint_tile = true;
	}
	else if ('1' == d->tmp.tile)
	{
		tile_img = d->img.i_sta.wall;
		paint_tile = true;
	}
	else if ('P' == d->tmp.tile)
	{
		tile_img = d->img.i_ani.idle;
		put_img_to_img(d->img.canvas, tile_img, d->tmp.x , d->tmp.y);
		paint_tile = false;
	}

	if (paint_tile)
		put_img_to_img(d->img.canvas, tile_img, d->tmp.x, d->tmp.y);
}

void	init_static_img(t_data *d)
{
	d->img.i_sta.wall =  new_file_img(d, "img/stonebrickbluefull.xpm");
	d->img.i_sta.sand =  new_file_img(d, "img/sandfull.xpm");
}

void	init_anim_img(t_data *d)
{
	d->img.i_ani.idle =  new_file_img(d, "img/crusader_idle_00000.xpm");
}
