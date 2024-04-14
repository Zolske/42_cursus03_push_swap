/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 06:21:19 by zkepes            #+#    #+#             */
/*   Updated: 2024/04/14 10:20:35 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	paint_map(t_data *d, int per, int level)
{
	int	idx_row;
	int	idx_col;

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
			paint_tile(d);
			idx_col++;
		}
		idx_row++;
	}
	put_img_to_img(d->img.canvas, d->img.text.arrow_key, 0, 0);
	if (d->map.game_won && !d->map.keys_locked)
		put_img_to_img(d->img.canvas, d->img.text.won, 0, 0);
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

void	cpy_exit_from_ori(t_data *d)
{
	int	idx_y;
	int	idx_x;

	idx_y = 0;
	if (d->map.copy_exit)
	{
		while (idx_y < d->map.height)
		{
			idx_x = 0;
			while (idx_x < d->map.width)
			{
				if (EXIT == (char) d->map.map[idx_y][idx_x])
				{
					d->map.map_4d[VIEW_BOTTOM][TAB_C][idx_y][idx_x] = EXIT;
					d->map.copy_exit = false;
					return ;
				}
				idx_x++;
			}
			idx_y++;
		}
	}
}
