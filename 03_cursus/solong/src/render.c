/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 06:21:19 by zkepes            #+#    #+#             */
/*   Updated: 2024/04/14 19:15:54 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	paint_map(t_data *d, int per, int level)
{
	int	idx_row;
	int	idx_col;

	d->tmp.per = per;
	d->tmp.layer = level;
	if (!d->map.game_lost && !d->map.game_won)
	{
		idx_row = 0;
		while (d->map.map_4d[per][TAB_C][idx_row] != NULL)
		{
			idx_col = 0;
			while (d->map.map_4d[per][TAB_X][idx_row][idx_col] != INT_MAX)
			{
				d->tmp.x = CEN_X_OFF
					+ d->map.map_4d[per][TAB_X][idx_row][idx_col];
				d->tmp.y = CEN_Y_OFF + d->map.map_4d
				[per][TAB_Y][idx_row][idx_col] + (LAYER * level);
				d->tmp.tile = d->map.map_4d[per][TAB_C][idx_row][idx_col];
				paint_tile(d);
				idx_col++;
			}
			idx_row++;
		}
	}
	render_gui(d);
}

void	paint_tile(t_data *d)
{
	if (FLOOR == d->tmp.layer)
		put_img_to_img(d->img.canvas, d->img.i_sta.sand,
			d->tmp.x + d->map.move_x, d->tmp.y + d->map.move_y);
	else if (WALL == d->tmp.tile)
		put_img_to_img(d->img.canvas, d->img.i_sta.wallh,
			d->tmp.x + d->map.move_x, d->tmp.y + d->map.move_y);
	else if (PLAYER == d->tmp.tile)
		render_player(d);
	else if (COLLEC == d->tmp.tile)
		put_img_to_img(d->img.canvas, d->img.coin[d->img.player.fr],
			d->tmp.x + d->map.move_x, d->tmp.y + d->map.move_y);
	else if (EXIT == d->tmp.tile && d->map.show_exit)
		put_img_to_img(d->img.canvas, d->img.exit[d->img.player.fr],
			d->tmp.x + d->map.move_x, d->tmp.y + d->map.move_y -30);
	else if (DRAGON == d->tmp.tile)
		put_img_to_img(d->img.canvas, d->img.dragon.idle[d->img.player.fr],
			d->tmp.x + d->map.move_x, d->tmp.y + d->map.move_y);
}

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

void	render_gui(t_data *d)
{
	int	idx;

	if (!d->map.game_lost && !d->map.game_won)
	{
		render_talk(d);
		put_img_to_img(d->img.canvas, d->img.text.arrow_key, 0, 0);
		put_img_to_img(d->img.canvas, d->img.text.moves, 0, 462);
		if (d->map.count_moves > 99)
		{
			idx = d->map.count_moves / 100;
			put_img_to_img(d->img.canvas, d->img.text.num[idx], 110, 462);
		}
		if (d->map.count_moves > 9)
		{
			idx = (d->map.count_moves / 10) % 10;
			put_img_to_img(d->img.canvas, d->img.text.num[idx], 130, 462);
		}
		idx = d->map.count_moves % 10;
		put_img_to_img(d->img.canvas, d->img.text.num[idx], 150, 462);
	}
	else if (d->map.game_won)
		put_img_to_img(d->img.canvas, d->img.text.won, 0, 0);
	else if (d->map.game_lost)
		put_img_to_img(d->img.canvas, d->img.text.lost, 0, 0);
}

void	render_talk(t_data *d)
{
	t_img_data	img;
	int			idx;

	if (d->img.player.state_talk)
	{
		if (d->img.player.talk_idx > 5)
			d->img.player.talk_idx = 0;
		idx = d->img.player.talk_idx;
		if (TALK_MONEY == d->img.player.state_talk)
			img = d->img.talk.money[idx];
		if (TALK_WALL == d->img.player.state_talk)
			img = d->img.talk.wall[idx];
		put_img_to_img(d->img.canvas, img, CEN_X_OFF, CEN_Y_OFF -130);
	}
}
