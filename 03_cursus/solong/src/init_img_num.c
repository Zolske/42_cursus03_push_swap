/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:46:32 by zkepes            #+#    #+#             */
/*   Updated: 2024/04/15 18:17:15 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_img_num(t_data *d)
{
	d->img.text.moves = new_file_img(d, "textures/text/moves.xpm");
	d->img.text.num[0] = new_file_img(d, "textures/text/0.xpm");
	d->img.text.num[1] = new_file_img(d, "textures/text/1.xpm");
	d->img.text.num[2] = new_file_img(d, "textures/text/2.xpm");
	d->img.text.num[3] = new_file_img(d, "textures/text/3.xpm");
	d->img.text.num[4] = new_file_img(d, "textures/text/4.xpm");
	d->img.text.num[5] = new_file_img(d, "textures/text/5.xpm");
	d->img.text.num[6] = new_file_img(d, "textures/text/6.xpm");
	d->img.text.num[7] = new_file_img(d, "textures/text/7.xpm");
	d->img.text.num[8] = new_file_img(d, "textures/text/8.xpm");
	d->img.text.num[9] = new_file_img(d, "textures/text/9.xpm");
}
