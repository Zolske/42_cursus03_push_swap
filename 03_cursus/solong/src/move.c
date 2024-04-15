/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 06:30:01 by zkepes            #+#    #+#             */
/*   Updated: 2024/04/15 11:38:51 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	process_move(int key, t_data *d)
{
	d->map.keys_locked = true;
	if (XK_Up == key && validate_move(d, N_LEF) && !d->map.game_lost)
	{
		d->img.player.state = WALK_UP;
		count_move(d);
	}
	else if (XK_Right == key && validate_move(d, N_TOP) && !d->map.game_lost)
	{
		d->img.player.state = WALK_RIGHT;
		count_move(d);
	}
	else if (XK_Down == key && validate_move(d, N_RIG) && !d->map.game_lost)
	{
		d->img.player.state = WALK_DOWN;
		count_move(d);
	}
	else if (XK_Left == key && validate_move(d, N_BOT) && !d->map.game_lost)
	{
		d->img.player.state = WALK_LEFT;
		count_move(d);
	}
}

bool	validate_move(t_data *d, int move)
{
	if (WALL == d->map.map_4d[d->map.per][move][0][TAB_C])
	{
		d->img.player.state_talk = TALK_WALL;
		d->map.keys_locked = false;
		return (false);
	}
	else if (COLLEC == d->map.map_4d[d->map.per][move][0][TAB_C])
	{
		d->map.coins--;
		d->img.player.state_talk = TALK_MONEY;
	}
	else if (EXIT == d->map.map_4d[d->map.per][move][0][TAB_C]
		&& d->map.show_exit)
		d->map.game_won = true;
	else if (DRAGON == d->map.map_4d[d->map.per][move][0][TAB_C])
	{
		d->map.game_lost = true;
		return (false);
	}
	return (true);
}

void	count_move(t_data *d)
{
	char	*str_move;

	d->map.count_moves++;
	if (!d->map.bonus)
	{
		str_move = ft_itoa(d->map.count_moves);
		write(1, "moves: ", 7);
		write(1, str_move, ft_strlen(str_move));
		write(1, "\n", 1);
		free(str_move);
	}
}
