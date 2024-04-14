/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 10:39:44 by zkepes            #+#    #+#             */
/*   Updated: 2024/04/14 07:36:34 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_img_player_idle(t_data *d)
{
	d->img.player.idle[0] = new_file_img(d, "img/player/idle/idle_00.xpm");
	d->img.player.idle[1] = new_file_img(d, "img/player/idle/idle_01.xpm");
	d->img.player.idle[2] = new_file_img(d, "img/player/idle/idle_02.xpm");
	d->img.player.idle[3] = new_file_img(d, "img/player/idle/idle_03.xpm");
	d->img.player.idle[4] = new_file_img(d, "img/player/idle/idle_04.xpm");
	d->img.player.idle[5] = new_file_img(d, "img/player/idle/idle_05.xpm");
	d->img.player.idle[6] = new_file_img(d, "img/player/idle/idle_06.xpm");
	d->img.player.idle[7] = new_file_img(d, "img/player/idle/idle_07.xpm");
	d->img.player.idle[8] = new_file_img(d, "img/player/idle/idle_08.xpm");
	d->img.player.idle[9] = new_file_img(d, "img/player/idle/idle_09.xpm");
	d->img.player.idle[10] = new_file_img(d, "img/player/idle/idle_10.xpm");
	d->img.player.idle[11] = new_file_img(d, "img/player/idle/idle_11.xpm");
}

void	init_img_player_walk_down(t_data *d)
{
	d->img.player.down[0] = new_file_img(d, "img/player/down/down_01.xpm");
	d->img.player.down[1] = new_file_img(d, "img/player/down/down_02.xpm");
	d->img.player.down[2] = new_file_img(d, "img/player/down/down_03.xpm");
	d->img.player.down[3] = new_file_img(d, "img/player/down/down_04.xpm");
	d->img.player.down[4] = new_file_img(d, "img/player/down/down_05.xpm");
	d->img.player.down[5] = new_file_img(d, "img/player/down/down_06.xpm");
	d->img.player.down[6] = new_file_img(d, "img/player/down/down_07.xpm");
	d->img.player.down[7] = new_file_img(d, "img/player/down/down_08.xpm");
	d->img.player.down[8] = new_file_img(d, "img/player/down/down_09.xpm");
	d->img.player.down[9] = new_file_img(d, "img/player/down/down_10.xpm");
	d->img.player.down[10] = new_file_img(d, "img/player/down/down_11.xpm");
	d->img.player.down[11] = new_file_img(d, "img/player/down/down_12.xpm");
}

void	init_img_player_walk_up(t_data *d)
{
	d->img.player.up[0] = new_file_img(d, "img/player/up/up_00_tu.xpm");
	d->img.player.up[1] = new_file_img(d, "img/player/up/up_01_tu.xpm");
	d->img.player.up[2] = new_file_img(d, "img/player/up/up_02.xpm");
	d->img.player.up[3] = new_file_img(d, "img/player/up/up_03.xpm");
	d->img.player.up[4] = new_file_img(d, "img/player/up/up_04.xpm");
	d->img.player.up[5] = new_file_img(d, "img/player/up/up_05.xpm");
	d->img.player.up[6] = new_file_img(d, "img/player/up/up_06.xpm");
	d->img.player.up[7] = new_file_img(d, "img/player/up/up_07.xpm");
	d->img.player.up[8] = new_file_img(d, "img/player/up/up_08.xpm");
	d->img.player.up[9] = new_file_img(d, "img/player/up/up_09.xpm");
	d->img.player.up[10] = new_file_img(d, "img/player/up/up_01_tu.xpm");
	d->img.player.up[11] = new_file_img(d, "img/player/up/up_00_tu.xpm");
}

void	init_img_player_walk_right(t_data *d)
{
	d->img.player.right[0] = new_file_img(d, "img/player/right/ri_00_tu.xpm");
	d->img.player.right[1] = new_file_img(d, "img/player/right/ri_01_tu.xpm");
	d->img.player.right[2] = new_file_img(d, "img/player/right/ri_02.xpm");
	d->img.player.right[3] = new_file_img(d, "img/player/right/ri_03.xpm");
	d->img.player.right[4] = new_file_img(d, "img/player/right/ri_04.xpm");
	d->img.player.right[5] = new_file_img(d, "img/player/right/ri_05.xpm");
	d->img.player.right[6] = new_file_img(d, "img/player/right/ri_06.xpm");
	d->img.player.right[7] = new_file_img(d, "img/player/right/ri_07.xpm");
	d->img.player.right[8] = new_file_img(d, "img/player/right/ri_08.xpm");
	d->img.player.right[9] = new_file_img(d, "img/player/right/ri_09.xpm");
	d->img.player.right[10] = new_file_img(d, "img/player/right/ri_01_tu.xpm");
	d->img.player.right[11] = new_file_img(d, "img/player/right/ri_00_tu.xpm");
}

void	init_img_player_walk_left(t_data *d)
{
	d->img.player.left[0] = new_file_img(d, "img/player/left/le_00.xpm");
	d->img.player.left[1] = new_file_img(d, "img/player/left/le_01.xpm");
	d->img.player.left[2] = new_file_img(d, "img/player/left/le_02.xpm");
	d->img.player.left[3] = new_file_img(d, "img/player/left/le_03.xpm");
	d->img.player.left[4] = new_file_img(d, "img/player/left/le_04.xpm");
	d->img.player.left[5] = new_file_img(d, "img/player/left/le_05.xpm");
	d->img.player.left[6] = new_file_img(d, "img/player/left/le_06.xpm");
	d->img.player.left[7] = new_file_img(d, "img/player/left/le_07.xpm");
	d->img.player.left[8] = new_file_img(d, "img/player/left/le_08.xpm");
	d->img.player.left[9] = new_file_img(d, "img/player/left/le_09.xpm");
	d->img.player.left[10] = new_file_img(d, "img/player/left/le_10.xpm");
	d->img.player.left[11] = new_file_img(d, "img/player/left/le_11.xpm");
}
