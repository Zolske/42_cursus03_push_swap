/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 06:30:01 by zkepes            #+#    #+#             */
/*   Updated: 2024/04/14 09:35:33 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	process_move(int key, t_data *d)
{
	d->map.keys_locked = true;
	if (XK_Up == key && validate_move(d, N_LEF))
	{
		d->img.player.state = WALK_UP;
		count_move(d);
	}
	else if (XK_Right == key && validate_move(d, N_TOP))
	{
		d->img.player.state = WALK_RIGHT;
		count_move(d);
	}
	else if (XK_Down == key && validate_move(d, N_RIG))
	{
		d->img.player.state = WALK_DOWN;
		count_move(d);
	}
	else if (XK_Left == key && validate_move(d, N_BOT))
	{
		d->img.player.state = WALK_LEFT;
		count_move(d);
	}
}

bool	validate_move(t_data *d, int move)
{
	if (WALL == d->map.map_4d[d->map.per][move][0][TAB_C])
	{
		return (false);
	}
	else if (COLLEC == d->map.map_4d[d->map.per][move][0][TAB_C])
		d->map.coins--;
	else if (EXIT == d->map.map_4d[d->map.per][move][0][TAB_C]
		&& d->map.show_exit)
		d->map.game_won = true;
	return (true);
}

void	count_move(t_data *d)
{
	char	*str_move;

	d->map.count_moves++;
	str_move = ft_itoa(d->map.count_moves);
	write(1, "moves: ", 7);
	write(1, str_move, ft_strlen(str_move));
	write(1, "\n", 1);
	free(str_move);
}
