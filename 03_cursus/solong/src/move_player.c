/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 10:36:28 by zkepes            #+#    #+#             */
/*   Updated: 2024/04/14 18:09:48 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
		if (VIEW_BOTTOM == d->map.per)
			d->tmp.x++;
		else if (VIEW_TOP == d->map.per)
			d->tmp.x--;
		else if (VIEW_LEFT == d->map.per)
			d->tmp.y++;
		else if (VIEW_RIGHT == d->map.per)
			d->tmp.y--;
		d->map.map_4d[VIEW_BOTTOM][TAB_C][d->tmp.y][d->tmp.x] = PLAYER;
		d->map.keys_locked = false;
		if (0 == d->map.coins)
		{
			d->map.show_exit = true;
			cpy_exit_from_ori(d);
		}
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
		if (VIEW_BOTTOM == d->map.per)
			d->tmp.x--;
		else if (VIEW_TOP == d->map.per)
			d->tmp.x++;
		else if (VIEW_LEFT == d->map.per)
			d->tmp.y--;
		else if (VIEW_RIGHT == d->map.per)
			d->tmp.y++;
		d->map.map_4d[VIEW_BOTTOM][TAB_C][d->tmp.y][d->tmp.x] = PLAYER;
		d->map.keys_locked = false;
		if (0 == d->map.coins)
		{
			d->map.show_exit = true;
			cpy_exit_from_ori(d);
		}
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
		if (VIEW_BOTTOM == d->map.per)
			d->tmp.y--;
		else if (VIEW_TOP == d->map.per)
			d->tmp.y++;
		else if (VIEW_LEFT == d->map.per)
			d->tmp.x++;
		else if (VIEW_RIGHT == d->map.per)
			d->tmp.x--;
		d->map.map_4d[VIEW_BOTTOM][TAB_C][d->tmp.y][d->tmp.x] = PLAYER;
		d->map.keys_locked = false;
		if (0 == d->map.coins)
		{
			d->map.show_exit = true;
			cpy_exit_from_ori(d);
		}
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
		if (VIEW_BOTTOM == d->map.per)
			d->tmp.y++;
		else if (VIEW_TOP == d->map.per)
			d->tmp.y--;
		else if (VIEW_LEFT == d->map.per)
			d->tmp.x--;
		else if (VIEW_RIGHT == d->map.per)
			d->tmp.x++;
		d->map.map_4d[VIEW_BOTTOM][TAB_C][d->tmp.y][d->tmp.x] = PLAYER;
		d->map.keys_locked = false;
		if (0 == d->map.coins)
		{
			d->map.show_exit = true;
			cpy_exit_from_ori(d);
		}
	}
}
