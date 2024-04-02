/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:27:59 by zkepes            #+#    #+#             */
/*   Updated: 2024/04/02 19:22:03 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char *argv[])
{
	t_data	data;
	
	if (argc == 2)
	{
		init(&data, argv);
		file_into_struct(argv[1], &data);
		validate_map(&data);
		start_game(&data);
		free_all(&data);
	}
}

void	init(t_data *d, char *argv[])
{
	d->file = argv[1];
	d->height = 0;
	d->width = 0;
	d->map = NULL;
	d->found = false;
}

void	start_game(t_data *d)
{
	t_win	window;
	t_img	base_img;
	t_xpm xpm;

	window = new_window(1920, 1080, "Hello world!");
	base_img = new_img(1000, 650, window);
	init_xpm(&xpm, d, &base_img, window);


	int idx_y = 0;
	int idx_x;
	while (d->map[idx_y])
	{
		idx_x = 0;
		while (d->map[idx_y][idx_x])
		{
			if (WALL == d->map[idx_y][idx_x])
			{
				if (d->height -1 > idx_y && WALL == d->map[idx_y + 1][idx_x])
					put_img_to_img(base_img, xpm.ba.wall_top, (TILE * idx_x) + OFFSET_L, TILE * idx_y);
				else
					put_img_to_img(base_img, xpm.ba.wall, (TILE * idx_x) + OFFSET_L, TILE * idx_y);
			}
			if ((SPACE == d->map[idx_y][idx_x])
				|| (PLAYER == d->map[idx_y][idx_x])
				|| (EXIT == d->map[idx_y][idx_x]))
					put_img_to_img(base_img, xpm.ba.floor , (TILE * idx_x) + OFFSET_L, TILE * idx_y);
			if (COLLEC == d->map[idx_y][idx_x])
					put_img_to_img(base_img, xpm.fr_0.collect, (TILE * idx_x) + OFFSET_L, TILE * idx_y);
			idx_x++;
		}
		idx_y++;
	}
	idx_y = 0;
	while (idx_y < d->height)
	{
		put_img_to_img(base_img, xpm.ba.la_ro_lm, 0, idx_y * TILE);
		put_img_to_img(base_img, xpm.ba.la_ro_rm, (d->width * TILE) + OFFSET_L, idx_y * TILE);
		idx_y++;
	}

	put_img_to_img(base_img, xpm.fr_0.la_ro_l, 0, d->height * TILE);
	put_img_to_img(base_img, xpm.fr_0.la_ro_r, (d->width * TILE) + OFFSET_L , d->height * TILE);
	idx_x = 0;
	while (idx_x < d->width)
	{
		put_img_to_img(base_img, xpm.fr_0.la_ro_m, (idx_x * TILE) + OFFSET_L, d->height * TILE);
		idx_x++;
	}
	


	mlx_put_image_to_window (base_img.win.mlx_ptr, base_img.win.win_ptr, base_img.img_ptr, 0, 0);
	mlx_loop_hook(window.mlx_ptr, update_frame, &xpm);
	mlx_loop(window.mlx_ptr);
	mlx_destroy_window(window.mlx_ptr, window.win_ptr);
}

int	update_frame(t_xpm *xpm)
{
	int	idx_x;

	if (4000 == xpm->fr_idx)
	{
		idx_x = 0;
		while (idx_x < xpm->w)
		{
			put_img_to_img(*(xpm->base_img), xpm->fr_0.la_ro_m, (idx_x * TILE) + OFFSET_L, xpm->h * TILE);
			idx_x++;
		}
		// printf("frame: 0\n");
	}
	else if (8000 == xpm->fr_idx)
	{
		idx_x = 0;
		while (idx_x < xpm->w)
		{
			put_img_to_img(*(xpm->base_img), xpm->fr_1.la_ro_m, (idx_x * TILE) + OFFSET_L, xpm->h * TILE);
			idx_x++;
		}
		// printf("frame: 1\n");
		xpm->fr_idx = 0;
	}
	xpm->fr_idx++;
	if (12000 == xpm->fr_idx)
		xpm->fr_idx = 0;
	
	mlx_put_image_to_window ((*(xpm->base_img)).win.mlx_ptr, (*(xpm->base_img)).win.win_ptr, (*(xpm->base_img)).img_ptr, 0, 0);
	return (0);
}

void	init_xpm(t_xpm *xpm, t_data *d, t_img *base_img, t_win window)
{
	xpm->base_img = base_img;
	init_map(xpm);
	init_base(xpm, window);
	init_frame_0(xpm, window);
	init_frame_1(xpm, window);
}

void	init_map(t_xpm *xpm)
{
	xpm->h = 5;
	xpm->w = 13;
	// xpm->map = d->map;
	xpm->fr_idx = 0;
}

void	init_base(t_xpm *xpm, t_win window)
{
	(*xpm).ba.floor = new_file_img("img/ba/floor.xpm", window);
	(*xpm).ba.wall = new_file_img("img/ba/wall.xpm", window);
	(*xpm).ba.wall_top = new_file_img("img/ba/wall_top.xpm", window);
	(*xpm).ba.la_ro_lm = new_file_img("img/ba/lava_rock_lm.xpm", window);
	(*xpm).ba.la_ro_rm = new_file_img("img/ba/lava_rock_rm.xpm", window);
}

void	init_frame_0(t_xpm *xpm, t_win window)
{
	(*xpm).fr_0.collect = new_file_img("img/fr_0/collect_0.xpm", window);
	(*xpm).fr_0.la_ro_l = new_file_img("img/fr_0/lava_rock_l_0.xpm", window);
	(*xpm).fr_0.la_ro_m = new_file_img("img/fr_0/lava_rock_m_0.xpm", window);
	(*xpm).fr_0.la_ro_r = new_file_img("img/fr_0/lava_rock_r_0.xpm", window);
}

void	init_frame_1(t_xpm *xpm, t_win window)
{
	(*xpm).fr_1.collect = new_file_img("img/fr_1/collect_1.xpm", window);
	(*xpm).fr_1.la_ro_l = new_file_img("img/fr_1/lava_rock_l_1.xpm", window);
	(*xpm).fr_1.la_ro_m = new_file_img("img/fr_1/lava_rock_m_1.xpm", window);
	(*xpm).fr_1.la_ro_r = new_file_img("img/fr_1/lava_rock_r_1.xpm", window);
}
