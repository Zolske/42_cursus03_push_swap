/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dragon_can_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 19:17:31 by zkepes            #+#    #+#             */
/*   Updated: 2024/04/14 19:18:07 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

bool	can_dragon_move_right(t_data *d)
{
	if (SPACE == d->map.map_4d[VIEW_BOTTOM][TAB_C][d->tmp.y][d->tmp.x + 1])
	{
		d->map.map_4d[VIEW_BOTTOM][TAB_C][d->tmp.y][d->tmp.x + 1] = DRAGON;
		return (true);
	}
	return (false);
}

bool	can_dragon_move_left(t_data *d)
{
	if (SPACE == d->map.map_4d[VIEW_BOTTOM][TAB_C][d->tmp.y][d->tmp.x - 1])
	{
		d->map.map_4d[VIEW_BOTTOM][TAB_C][d->tmp.y][d->tmp.x - 1] = DRAGON;
		return (true);
	}
	return (false);
}

bool	can_dragon_move_up(t_data *d)
{
	if (SPACE == d->map.map_4d[VIEW_BOTTOM][TAB_C][d->tmp.y + 1][d->tmp.x])
	{
		d->map.map_4d[VIEW_BOTTOM][TAB_C][d->tmp.y + 1][d->tmp.x] = DRAGON;
		return (true);
	}
	return (false);
}

bool	can_dragon_move_down(t_data *d)
{
	if (SPACE == d->map.map_4d[VIEW_BOTTOM][TAB_C][d->tmp.y - 1][d->tmp.x])
	{
		d->map.map_4d[VIEW_BOTTOM][TAB_C][d->tmp.y - 1][d->tmp.x] = DRAGON;
		return (true);
	}
	return (false);
}
