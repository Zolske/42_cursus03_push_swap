/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:27:59 by zkepes            #+#    #+#             */
/*   Updated: 2024/04/16 12:03:38 by zkepes           ###   ########.fr       */
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
	}
	return (0);
}

// set "d->map.bonus = false" if you want to play without bonus
void	init(t_data *d, char *argv[])
{
	d->map.bonus = true;
	d->map.found_dragon = false;
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
	d->img.player.state_talk = TALK_NO;
	d->img.talk.time = 0;
	d->img.player.talk_idx = 0;
	d->map.show_exit = false;
	d->map.game_won = false;
	d->map.game_lost = false;
	d->map.count_moves = 0;
	d->img.canvas.img_ptr = NULL;
	d->map.copy_exit = true;
	d->map.dragon_speed = 0;
}

void	start_game(t_data *d)
{
	d->mlx.mlx_ptr = mlx_init();
	if (!d->map.bonus)
		d->mlx.win_ptr = mlx_new_window(
				d->mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "so_long");
	else
		d->mlx.win_ptr = mlx_new_window(
				d->mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "so_long BONUS");
	init_images(d);
	init_map_4d(d);
	cpy_map_4d(d);
	update_maps(d);
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
		if (d->map.found_dragon)
			dragon_move(d);
		update_maps(d);
		paint_map(d, d->map.per, FLOOR);
		paint_map(d, d->map.per, GROUND);
		mlx_put_image_to_window(
			d->mlx.mlx_ptr, d->mlx.win_ptr, d->img.canvas.img_ptr, 0, 0);
	}
	d->img.idx_fr++;
	if (d->img.idx_fr > GAME_SPEED)
		d->img.idx_fr = 0;
	return (0);
}

void	increment_img_frame(t_data *d)
{
	d->img.player.fr++;
	if (d->img.player.fr > d->img.player.last_fr)
		d->img.player.fr = 0;
	if (d->img.player.state_talk)
		d->img.talk.time++;
	if (d->img.talk.time > TALK_TIME)
	{
		d->img.talk.time = 0;
		d->img.player.talk_idx++;
		d->img.player.state_talk = TALK_NO;
	}
	if (WALK_DOWN == d->img.player.state)
		move_player_down(d);
	if (WALK_UP == d->img.player.state)
		move_player_up(d);
	if (WALK_RIGHT == d->img.player.state)
		move_player_right(d);
	if (WALK_LEFT == d->img.player.state)
		move_player_left(d);
}
