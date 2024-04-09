/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:27:59 by zkepes            #+#    #+#             */
/*   Updated: 2024/04/09 19:13:24 by zkepes           ###   ########.fr       */
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
	d->map.keys_locked = false;
	d->map.move_x = 0;
	d->map.move_y = 0;
	d->img.idx_fr = 0;
	// d->img.player.state = IDLE;
	d->img.player.state = IDLE;
}

void start_game(t_data *d)
{
	d->mlx.win_w = 1920;
	d->mlx.win_h = 1080;
	d->mlx.mlx_ptr = mlx_init();
	d->mlx.win_ptr = mlx_new_window(d->mlx.mlx_ptr, d->mlx.win_w, d->mlx.win_h, WIN_TITLE);
	create_canvas(d, d->mlx.win_w, d->mlx.win_h);
	init_static_img(d);
	init_images(d);
	// init_anim_img(d);

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
	// print_map_4d_char(d, VIEW_RIGHT);
	// print_map_4d_char(d, VIEW_TOP);
	// print_map_4d_char(d, VIEW_LEFT);
	print_map_4d_coordinates(d, VIEW_BOTTOM);
	paint_map(d, VIEW_BOTTOM, 0);
	paint_map(d, VIEW_BOTTOM, 1);
	// put_img_to_img(d->img.canvas, lava, CEN_X_OFF, CEN_Y_OFF);			// center


	mlx_put_image_to_window(d->mlx.mlx_ptr, d->mlx.win_ptr, d->img.canvas.img_ptr, 0, 0);
	if (!d->map.keys_locked)
		mlx_key_hook(d->mlx.win_ptr, key_hook, d);
	mlx_hook(d->mlx.win_ptr, 17, 1L << 0, close_window, d);
	mlx_loop_hook(d->mlx.mlx_ptr, render_next_frame, d);
	mlx_loop(d->mlx.mlx_ptr);
}

void	process_move(int key, t_data *d)
{
	d->map.keys_locked = true;
	// key = translate_key(key, d);
	if (XK_Up == key)
	{
		printf("UP\n");
		d->img.player.state = WALK_UP;
		// d->map.move_x = 50;
		// d->map.move_y = 25;
	}
	else if (XK_Right == key)
	{
		printf("Right\n");
		d->img.player.state = WALK_RIGHT;
	}
	else if (XK_Down == key)
	{
		printf("Down\n");
		d->img.player.state = WALK_DOWN;
	}
	else if (XK_Left == key)
	{
		printf("Left\n");
		d->img.player.state = WALK_LEFT;
	}
	printf("key: %d\n", key);
}

int	translate_key(int key, t_data *d)
{
	if (d->map.perspective == VIEW_RIGHT)
	{
		if (key == XK_Right)
			return (XK_Down);
		else if (key == XK_Down)
			return (XK_Left);
		else if (key == XK_Left)
			return (XK_Up);
		else if (key == XK_Up)
			return (XK_Right);
	}
	else if (d->map.perspective == VIEW_TOP)
	{
		if (key == XK_Right)
			return (XK_Left);
		else if (key == XK_Down)
			return (XK_Up);
		else if (key == XK_Left)
			return (XK_Right);
		else if (key == XK_Up)
			return (XK_Down);
	}
	else if (d->map.perspective == VIEW_LEFT)
	{
		if (key == XK_Right)
			return (XK_Up);
		else if (key == XK_Down)
			return (XK_Right);
		else if (key == XK_Left)
			return (XK_Up);
		else if (key == XK_Up)
			return (XK_Left);
	}
	return (key);
}

int render_next_frame(t_data *d)
{
	if (0 == d->img.idx_fr)
	{
		mlx_destroy_image(d->mlx.mlx_ptr, d->img.canvas.img_ptr);
		create_canvas(d, d->mlx.win_w, d->mlx.win_h);
		increment_img_frame(d);
		update_maps(d);
		paint_map(d, d->map.perspective, FLOOR);
		paint_map(d, d->map.perspective, GROUND);
		mlx_put_image_to_window(d->mlx.mlx_ptr, d->mlx.win_ptr, d->img.canvas.img_ptr, 0, 0);
	}
	d->img.idx_fr++;
	if (d->img.idx_fr > 10000)
		d->img.idx_fr = 0;
	// printf("next frame, perspective: %d\n", d->map.perspective);
}

int		key_hook(int key, t_data *d)
{
	d->map.keys_locked = true;
	if (XK_Up == key || XK_Right == key || XK_Down == key || XK_Left == key)
		process_move(key, d);
	else if (XK_Tab == key)
	{
		printf("tab\n");
		if (VIEW_LEFT == d->map.perspective)
			d->map.perspective = VIEW_BOTTOM;
		else
			d->map.perspective++;
	}
	else if (XK_Escape == key)
		close_window(d);
	return (0);
}

int		close_window(t_data *d)
{
	mlx_destroy_window(d->mlx.mlx_ptr, d->mlx.win_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.canvas.img_ptr);
	mlx_destroy_display(d->mlx.mlx_ptr);
	free(d->mlx.mlx_ptr);
	free_map_4d(d);
	free_all(d);
	//TODO: need to free images
	exit(0);
}

void	init_map_4d(t_data *d)
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

void	cpy_map_4d(t_data *d)
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
void	player_coordinate(t_data *d, int *coor_x, int *coor_y, int per)
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

void	update_coordinates(t_data *d, int per)
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

void	paint_map(t_data *d, int per, int level)
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
			// d->tmp.x = CEN_X_OFF + d->map.map_4d[per][TAB_X][idx_row][idx_col];
			// d->tmp.y = CEN_Y_OFF + d->map.map_4d[per][TAB_Y][idx_row][idx_col] + (LAYER * level);
			d->tmp.tile = d->map.map_4d[per][TAB_C][idx_row][idx_col];
			paint_tile(d);
			idx_col++;
		}
		idx_row++;
	}
}

void	paint_tile(t_data *d)
{
	if (FLOOR == d->tmp.layer)
		put_img_to_img(d->img.canvas, d->img.i_sta.sand,
			d->tmp.x + d->map.move_x, d->tmp.y + d->map.move_y);
	else if (WALL == d->tmp.tile)
		put_img_to_img(d->img.canvas, d->img.i_sta.wall,
			d->tmp.x + d->map.move_x, d->tmp.y + d->map.move_y);
	else if (PLAYER == d->tmp.tile)
		render_player(d);
}

void	init_static_img(t_data *d)
{
	d->img.i_sta.wall =  new_file_img(d, "img/stonebrickbluefull.xpm");
	d->img.i_sta.sand =  new_file_img(d, "img/sandfull.xpm");
}

// void	init_anim_img(t_data *d)
// {
// 	d->img.i_ani.idle =  new_file_img(d, "img/crusader_idle_00000.xpm");
// }

void	render_player(t_data *d)
{
	if (IDLE == d->img.player.state)
		put_img_to_img(d->img.canvas, d->img.player.idle[d->img.player.fr],
			d->tmp.x, d->tmp.y);
	else if (WALK_DOWN == d->img.player.state)
		put_img_to_img(d->img.canvas, d->img.player.down[d->img.player.fr],
			d->tmp.x, d->tmp.y);
	else if (WALK_RIGHT == d->img.player.state)
		put_img_to_img(d->img.canvas, d->img.player.right[d->img.player.fr],
			d->tmp.x, d->tmp.y);
	else if (WALK_UP == d->img.player.state)
		put_img_to_img(d->img.canvas, d->img.player.up[d->img.player.fr],
			d->tmp.x, d->tmp.y);
	else if (WALK_LEFT == d->img.player.state)
		put_img_to_img(d->img.canvas, d->img.player.left[d->img.player.fr],
			d->tmp.x, d->tmp.y);
}

void	increment_img_frame(t_data *d)
{
	d->img.player.fr++;
	if (d->img.player.fr > d->img.player.last_fr )
		d->img.player.fr = 0;
	if (WALK_DOWN == d->img.player.state)
		move_player_down(d);
	if (WALK_UP == d->img.player.state)
		move_player_up(d);
	if (WALK_RIGHT == d->img.player.state)
		move_player_right(d);
	if (WALK_LEFT == d->img.player.state)
		move_player_left(d);
}

void	move_player_down(t_data *d)
{
		d->map.move_x -= 4;
		d->map.move_y -= 2;
		if (d->map.move_x <= -50)
		{
			d->map.move_x = 0;
			d->map.move_y = 0;
			d->img.player.state = IDLE;
			player_coordinate(d, &(d->tmp.x), &(d->tmp.y), VIEW_BOTTOM);
			d->map.map_4d[VIEW_BOTTOM][TAB_C][d->tmp.y][d->tmp.x] = SPACE;
			if (VIEW_BOTTOM == d->map.perspective)
				d->tmp.x++;
			else if (VIEW_TOP == d->map.perspective)
				d->tmp.x--;
			else if (VIEW_LEFT == d->map.perspective)
				d->tmp.y++;
			else if (VIEW_RIGHT == d->map.perspective)
				d->tmp.y--;
			d->map.map_4d[VIEW_BOTTOM][TAB_C][d->tmp.y][d->tmp.x] = PLAYER;
			d->map.keys_locked = false;
		}
}

void	move_player_up(t_data *d)
{
		d->map.move_x += 4;
		d->map.move_y += 2;
		if (d->map.move_x >= 50)
		{
			d->map.move_x = 0;
			d->map.move_y = 0;
			d->img.player.state = IDLE;
			player_coordinate(d, &(d->tmp.x), &(d->tmp.y), VIEW_BOTTOM);
			d->map.map_4d[VIEW_BOTTOM][TAB_C][d->tmp.y][d->tmp.x] = SPACE;
			if (VIEW_BOTTOM == d->map.perspective)
				d->tmp.x--;
			else if (VIEW_TOP == d->map.perspective)
				d->tmp.x++;
			else if (VIEW_LEFT == d->map.perspective)
				d->tmp.y--;
			else if (VIEW_RIGHT == d->map.perspective)
				d->tmp.y++;
			d->map.map_4d[VIEW_BOTTOM][TAB_C][d->tmp.y][d->tmp.x] = PLAYER;
			d->map.keys_locked = false;
		}
}

void	move_player_right(t_data *d)
{
		d->map.move_x -= 4;
		d->map.move_y += 2;
		if (d->map.move_x <= -50)
		{
			d->map.move_x = 0;
			d->map.move_y = 0;
			d->img.player.state = IDLE;
			player_coordinate(d, &(d->tmp.x), &(d->tmp.y), VIEW_BOTTOM);
			d->map.map_4d[VIEW_BOTTOM][TAB_C][d->tmp.y][d->tmp.x] = SPACE;
			if (VIEW_BOTTOM == d->map.perspective)
				d->tmp.y--;
			else if (VIEW_TOP == d->map.perspective)
				d->tmp.y++;
			else if (VIEW_LEFT == d->map.perspective)
				d->tmp.x++;
			else if (VIEW_RIGHT == d->map.perspective)
				d->tmp.x--;
			d->map.map_4d[VIEW_BOTTOM][TAB_C][d->tmp.y][d->tmp.x] = PLAYER;
			d->map.keys_locked = false;
		}
}

void	move_player_left(t_data *d)
{
		d->map.move_x += 4;
		d->map.move_y -= 2;
		if (d->map.move_x >= 50)
		{
			d->map.move_x = 0;
			d->map.move_y = 0;
			d->img.player.state = IDLE;
			player_coordinate(d, &(d->tmp.x), &(d->tmp.y), VIEW_BOTTOM);
			d->map.map_4d[VIEW_BOTTOM][TAB_C][d->tmp.y][d->tmp.x] = SPACE;
			if (VIEW_BOTTOM == d->map.perspective)
				d->map.map_4d[VIEW_BOTTOM][TAB_C][d->tmp.y + 1][d->tmp.x] = PLAYER;
			if (VIEW_BOTTOM == d->map.perspective)
				d->tmp.y++;
			else if (VIEW_TOP == d->map.perspective)
				d->tmp.y--;
			else if (VIEW_LEFT == d->map.perspective)
				d->tmp.x--;
			else if (VIEW_RIGHT == d->map.perspective)
				d->tmp.x++;
			d->map.map_4d[VIEW_BOTTOM][TAB_C][d->tmp.y][d->tmp.x] = PLAYER;
			d->map.keys_locked = false;
		}
}


void	init_images(t_data *d)
{
	init_img_player(d);
}

void	init_img_player(t_data *d)
{
	d->img.player.fr = 0;
	d->img.player.last_fr = 11;
	init_img_player_idle(d);
	init_img_player_walk_down(d);
	init_img_player_walk_up(d);
	init_img_player_walk_right(d);
	init_img_player_walk_left(d);
}

void	init_img_player_idle(t_data *d)
{
	d->img.player.idle[0] = new_file_img(d,"img/player/idle/idle_00.xpm");
	d->img.player.idle[1] = new_file_img(d,"img/player/idle/idle_01.xpm");
	d->img.player.idle[2] = new_file_img(d,"img/player/idle/idle_02.xpm");
	d->img.player.idle[3] = new_file_img(d,"img/player/idle/idle_03.xpm");
	d->img.player.idle[4] = new_file_img(d,"img/player/idle/idle_04.xpm");
	d->img.player.idle[5] = new_file_img(d,"img/player/idle/idle_05.xpm");
	d->img.player.idle[6] = new_file_img(d,"img/player/idle/idle_06.xpm");
	d->img.player.idle[7] = new_file_img(d,"img/player/idle/idle_07.xpm");
	d->img.player.idle[8] = new_file_img(d,"img/player/idle/idle_08.xpm");
	d->img.player.idle[9] = new_file_img(d,"img/player/idle/idle_09.xpm");
	d->img.player.idle[10] = new_file_img(d,"img/player/idle/idle_10.xpm");
	d->img.player.idle[11] = new_file_img(d,"img/player/idle/idle_11.xpm");
	d->img.player.idle[12] = new_file_img(d,"img/player/idle/idle_12.xpm");
	d->img.player.idle[13] = new_file_img(d,"img/player/idle/idle_13.xpm");
	d->img.player.idle[14] = new_file_img(d,"img/player/idle/idle_14.xpm");
	d->img.player.idle[15] = new_file_img(d,"img/player/idle/idle_15.xpm");	
}

void	init_img_player_walk_down(t_data *d)
{
	d->img.player.down[0]= new_file_img(d,"img/player/down/down_01.xpm");
	d->img.player.down[1]= new_file_img(d,"img/player/down/down_02.xpm");
	d->img.player.down[2]= new_file_img(d,"img/player/down/down_03.xpm");
	d->img.player.down[3]= new_file_img(d,"img/player/down/down_04.xpm");
	d->img.player.down[4]= new_file_img(d,"img/player/down/down_05.xpm");
	d->img.player.down[5]= new_file_img(d,"img/player/down/down_06.xpm");
	d->img.player.down[6]= new_file_img(d,"img/player/down/down_07.xpm");
	d->img.player.down[7]= new_file_img(d,"img/player/down/down_08.xpm");
	d->img.player.down[8]= new_file_img(d,"img/player/down/down_09.xpm");
	d->img.player.down[9]= new_file_img(d,"img/player/down/down_10.xpm");
	d->img.player.down[10]= new_file_img(d,"img/player/down/down_11.xpm");
	d->img.player.down[11]= new_file_img(d,"img/player/down/down_12.xpm");	
}

void	init_img_player_walk_up(t_data *d)
{
	d->img.player.up[0] = new_file_img(d,"img/player/up/up_00_tu.xpm");
	d->img.player.up[1] = new_file_img(d,"img/player/up/up_01_tu.xpm");
	d->img.player.up[2] = new_file_img(d,"img/player/up/up_02.xpm");
	d->img.player.up[3] = new_file_img(d,"img/player/up/up_03.xpm");
	d->img.player.up[4] = new_file_img(d,"img/player/up/up_04.xpm");
	d->img.player.up[5] = new_file_img(d,"img/player/up/up_05.xpm");
	d->img.player.up[6] = new_file_img(d,"img/player/up/up_06.xpm");
	d->img.player.up[7] = new_file_img(d,"img/player/up/up_07.xpm");
	d->img.player.up[8] = new_file_img(d,"img/player/up/up_08.xpm");
	d->img.player.up[9] = new_file_img(d,"img/player/up/up_09.xpm");
	d->img.player.up[10] = new_file_img(d,"img/player/up/up_01_tu.xpm");
	d->img.player.up[11] = new_file_img(d,"img/player/up/up_00_tu.xpm");
}

void	init_img_player_walk_right(t_data *d)
{
	d->img.player.right[0] = new_file_img(d,"img/player/right/ri_00_tu.xpm");
	d->img.player.right[1] = new_file_img(d,"img/player/right/ri_01_tu.xpm");
	d->img.player.right[2] = new_file_img(d,"img/player/right/ri_02.xpm");
	d->img.player.right[3] = new_file_img(d,"img/player/right/ri_03.xpm");
	d->img.player.right[4] = new_file_img(d,"img/player/right/ri_04.xpm");
	d->img.player.right[5] = new_file_img(d,"img/player/right/ri_05.xpm");
	d->img.player.right[6] = new_file_img(d,"img/player/right/ri_06.xpm");
	d->img.player.right[7] = new_file_img(d,"img/player/right/ri_07.xpm");
	d->img.player.right[8] = new_file_img(d,"img/player/right/ri_08.xpm");
	d->img.player.right[9] = new_file_img(d,"img/player/right/ri_09.xpm");
	d->img.player.right[10] = new_file_img(d,"img/player/right/ri_01_tu.xpm");
	d->img.player.right[11] = new_file_img(d,"img/player/right/ri_00_tu.xpm");
}

void	init_img_player_walk_left(t_data *d)
{
	d->img.player.left[0] = new_file_img(d,"img/player/left/le_00.xpm");
	d->img.player.left[1] = new_file_img(d,"img/player/left/le_01.xpm");
	d->img.player.left[2] = new_file_img(d,"img/player/left/le_02.xpm");
	d->img.player.left[3] = new_file_img(d,"img/player/left/le_03.xpm");
	d->img.player.left[4] = new_file_img(d,"img/player/left/le_04.xpm");
	d->img.player.left[5] = new_file_img(d,"img/player/left/le_05.xpm");
	d->img.player.left[6] = new_file_img(d,"img/player/left/le_06.xpm");
	d->img.player.left[7] = new_file_img(d,"img/player/left/le_07.xpm");
	d->img.player.left[8] = new_file_img(d,"img/player/left/le_08.xpm");
	d->img.player.left[9] = new_file_img(d,"img/player/left/le_09.xpm");
	d->img.player.left[10] = new_file_img(d,"img/player/left/le_10.xpm");
	d->img.player.left[11] = new_file_img(d,"img/player/left/le_11.xpm");
}
