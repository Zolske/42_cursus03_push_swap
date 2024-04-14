/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dragon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 12:16:30 by zkepes            #+#    #+#             */
/*   Updated: 2024/04/14 20:59:56 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	dragon_coordinate(t_data *d, int *coor_x, int *coor_y, int per)
{
	int	idx_y;
	int	idx_x;

	idx_y = 0;
	while (d->map.map_4d[per][TAB_C][idx_y] != NULL)
	{
		idx_x = 0;
		while (d->map.map_4d[per][TAB_C][idx_y][idx_x] != INT_MAX)
		{
			if (DRAGON == (char)d->map.map_4d[per][TAB_C][idx_y][idx_x])
			{
				*coor_x = idx_x;
				*coor_y = idx_y;
				return ;
			}
			idx_x++;
		}
		idx_y++;
	}
}

void	dragon_move(t_data *d)
{
	d->map.dragon_speed++;
	if (DRAGON_SPEED == d->map.dragon_speed)
		d->map.dragon_speed = 0;
	if (0 == d->map.dragon_speed && !d->map.game_won
		&& !d->map.game_lost && !d->map.keys_locked)
	{
		if (d->map.coins % 2 == 0)
			dragon_move_clockwise(d, true);
		else
			dragon_move_clockwise(d, false);
	}
}

void	dragon_move_clockwise(t_data *d, bool clockwise)
{
	dragon_coordinate(d, &(d->tmp.x), &(d->tmp.y), VIEW_BOTTOM);
	if (clockwise)
	{
		if (can_dragon_move_right(d))
			d->map.map_4d[VIEW_BOTTOM][TAB_C][d->tmp.y][d->tmp.x] = SPACE;
		else if (can_dragon_move_down(d))
			d->map.map_4d[VIEW_BOTTOM][TAB_C][d->tmp.y][d->tmp.x] = SPACE;
		else if (can_dragon_move_left(d))
			d->map.map_4d[VIEW_BOTTOM][TAB_C][d->tmp.y][d->tmp.x] = SPACE;
		else if (can_dragon_move_up(d))
			d->map.map_4d[VIEW_BOTTOM][TAB_C][d->tmp.y][d->tmp.x] = SPACE;
	}
	else
	{
		if (can_dragon_move_down(d))
			d->map.map_4d[VIEW_BOTTOM][TAB_C][d->tmp.y][d->tmp.x] = SPACE;
		else if (can_dragon_move_right(d))
			d->map.map_4d[VIEW_BOTTOM][TAB_C][d->tmp.y][d->tmp.x] = SPACE;
		else if (can_dragon_move_left(d))
			d->map.map_4d[VIEW_BOTTOM][TAB_C][d->tmp.y][d->tmp.x] = SPACE;
		else if (can_dragon_move_up(d))
			d->map.map_4d[VIEW_BOTTOM][TAB_C][d->tmp.y][d->tmp.x] = SPACE;
	}
}
