/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img_dragon_talk.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 10:57:02 by zkepes            #+#    #+#             */
/*   Updated: 2024/04/14 18:48:27 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_img_dragon_idle(t_data *d)
{
	d->img.dragon.idle[0] = new_file_img(d, "img/dragon/idle/idle_00.xpm");
	d->img.dragon.idle[1] = new_file_img(d, "img/dragon/idle/idle_01.xpm");
	d->img.dragon.idle[2] = new_file_img(d, "img/dragon/idle/idle_02.xpm");
	d->img.dragon.idle[3] = new_file_img(d, "img/dragon/idle/idle_03.xpm");
	d->img.dragon.idle[4] = new_file_img(d, "img/dragon/idle/idle_04.xpm");
	d->img.dragon.idle[5] = new_file_img(d, "img/dragon/idle/idle_05.xpm");
	d->img.dragon.idle[6] = new_file_img(d, "img/dragon/idle/idle_06.xpm");
	d->img.dragon.idle[7] = new_file_img(d, "img/dragon/idle/idle_07.xpm");
	d->img.dragon.idle[8] = new_file_img(d, "img/dragon/idle/idle_08.xpm");
	d->img.dragon.idle[9] = new_file_img(d, "img/dragon/idle/idle_09.xpm");
	d->img.dragon.idle[10] = new_file_img(d, "img/dragon/idle/idle_10.xpm");
	d->img.dragon.idle[11] = new_file_img(d, "img/dragon/idle/idle_11.xpm");
}

void	init_img_talk(t_data *d)
{
	d->img.talk.money[0] = new_file_img(d, "img/text/talk/talk_rich0.xpm");
	d->img.talk.money[1] = new_file_img(d, "img/text/talk/talk_rich1.xpm");
	d->img.talk.money[2] = new_file_img(d, "img/text/talk/talk_rich2.xpm");
	d->img.talk.money[3] = new_file_img(d, "img/text/talk/talk_rich3.xpm");
	d->img.talk.money[4] = new_file_img(d, "img/text/talk/talk_rich4.xpm");
	d->img.talk.money[5] = new_file_img(d, "img/text/talk/talk_rich5.xpm");
	d->img.talk.wall[0] = new_file_img(d, "img/text/talk/talk_wall0.xpm");
	d->img.talk.wall[1] = new_file_img(d, "img/text/talk/talk_wall1.xpm");
	d->img.talk.wall[2] = new_file_img(d, "img/text/talk/talk_wall2.xpm");
	d->img.talk.wall[3] = new_file_img(d, "img/text/talk/talk_wall3.xpm");
	d->img.talk.wall[4] = new_file_img(d, "img/text/talk/talk_wall4.xpm");
	d->img.talk.wall[5] = new_file_img(d, "img/text/talk/talk_wall5.xpm");
}
