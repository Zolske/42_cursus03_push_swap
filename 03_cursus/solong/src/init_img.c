/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 10:44:12 by zkepes            #+#    #+#             */
/*   Updated: 2024/04/14 19:07:17 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_images(t_data *d)
{
	init_img_player(d);
	init_img_coin(d);
	init_img_exit(d);
	init_static(d);
	init_img_dragon_idle(d);
	init_img_num(d);
	init_img_talk(d);
}

void	init_static(t_data *d)
{
	d->img.text.arrow_key = new_file_img(d, "img/text/keys2.xpm");
	d->img.text.won = new_file_img(d, "img/text/won.xpm");
	d->img.text.lost = new_file_img(d, "img/text/lost.xpm");
	d->img.i_sta.wall = new_file_img(d, "img/stonebrickbluefull.xpm");
	d->img.i_sta.sand = new_file_img(d, "img/sandfull.xpm");
	d->img.i_sta.wallh = new_file_img(d, "img/stonebrickblue.xpm");
}

void	init_img_player(t_data *d)
{
	d->img.player.fr = 0;
	d->img.player.last_fr = 11;
	init_img_player_idle(d);
	init_img_player_walk_down(d);
	init_img_player_walk_up(d);
	init_img_player_walk_right(d);
	init_img_player_walk_left(d);
}

void	init_img_coin(t_data *d)
{
	d->img.coin[0] = new_file_img(d, "img/coin/coin_00.xpm");
	d->img.coin[1] = new_file_img(d, "img/coin/coin_00.xpm");
	d->img.coin[2] = new_file_img(d, "img/coin/coin_01.xpm");
	d->img.coin[3] = new_file_img(d, "img/coin/coin_02.xpm");
	d->img.coin[4] = new_file_img(d, "img/coin/coin_03.xpm");
	d->img.coin[5] = new_file_img(d, "img/coin/coin_04.xpm");
	d->img.coin[6] = new_file_img(d, "img/coin/coin_04.xpm");
	d->img.coin[7] = new_file_img(d, "img/coin/coin_05.xpm");
	d->img.coin[8] = new_file_img(d, "img/coin/coin_06.xpm");
	d->img.coin[9] = new_file_img(d, "img/coin/coin_07.xpm");
	d->img.coin[10] = new_file_img(d, "img/coin/coin_08.xpm");
	d->img.coin[11] = new_file_img(d, "img/coin/coin_09.xpm");
}

void	init_img_exit(t_data *d)
{
	d->img.exit[0] = new_file_img(d, "img/exit/exit_00.xpm");
	d->img.exit[1] = new_file_img(d, "img/exit/exit_01.xpm");
	d->img.exit[2] = new_file_img(d, "img/exit/exit_02.xpm");
	d->img.exit[3] = new_file_img(d, "img/exit/exit_03.xpm");
	d->img.exit[4] = new_file_img(d, "img/exit/exit_04.xpm");
	d->img.exit[5] = new_file_img(d, "img/exit/exit_05.xpm");
	d->img.exit[6] = new_file_img(d, "img/exit/exit_00.xpm");
	d->img.exit[7] = new_file_img(d, "img/exit/exit_01.xpm");
	d->img.exit[8] = new_file_img(d, "img/exit/exit_02.xpm");
	d->img.exit[9] = new_file_img(d, "img/exit/exit_03.xpm");
	d->img.exit[10] = new_file_img(d, "img/exit/exit_04.xpm");
	d->img.exit[11] = new_file_img(d, "img/exit/exit_05.xpm");
}
