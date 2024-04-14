/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:27:59 by zkepes            #+#    #+#             */
/*   Updated: 2024/04/14 10:46:09 by zkepes           ###   ########.fr       */
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
		// validate_map(&data); //TODO: uncomment for final version
		start_game(&data);
	}
}

void	init(t_data *d, char *argv[])
{
	d->map.file = argv[1];
	d->map.height = 0;
	d->map.width = 0;
	d->map.map = NULL;
	d->map.tmp_map = NULL;
	d->map.valid_path = false;
	d->map.per = VIEW_BOTTOM;
	d->map.keys_locked = false;
	d->map.move_x = 0;
	d->map.move_y = 0;
	d->img.idx_fr = 0;
	d->img.player.state = IDLE;
	d->map.show_exit = false;
	d->map.game_won = false;
	d->map.count_moves = 0;
	d->img.canvas.img_ptr = NULL;
	d->map.copy_exit = true;
}

void	start_game(t_data *d)
{
	d->mlx.mlx_ptr = mlx_init();
	d->mlx.win_ptr = mlx_new_window(
			d->mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	init_images(d);
	init_map_4d(d);
	cpy_map_4d(d);
	update_maps(d);
	if (!d->map.keys_locked)
		mlx_key_hook(d->mlx.win_ptr, key_hook, d);
	mlx_hook(d->mlx.win_ptr, 17, 1L << 0, close_window, d);
	mlx_loop_hook(d->mlx.mlx_ptr, render_next_frame, d);
	mlx_loop(d->mlx.mlx_ptr);
}

int	render_next_frame(t_data *d)
{
	if (0 == d->img.idx_fr)
	{
		if (d->img.canvas.img_ptr)
			mlx_destroy_image(d->mlx.mlx_ptr, d->img.canvas.img_ptr);
		create_canvas(d, WIN_WIDTH, WIN_HEIGHT);
		increment_img_frame(d);
		update_maps(d);
		paint_map(d, d->map.per, FLOOR);
		paint_map(d, d->map.per, GROUND);
		mlx_put_image_to_window(
			d->mlx.mlx_ptr, d->mlx.win_ptr, d->img.canvas.img_ptr, 0, 0);
	}
	d->img.idx_fr++;
	if (d->img.idx_fr > GAME_SPEED)
		d->img.idx_fr = 0;
}

void	increment_img_frame(t_data *d)
{
	d->img.player.fr++;
	if (d->img.player.fr > d->img.player.last_fr)
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
