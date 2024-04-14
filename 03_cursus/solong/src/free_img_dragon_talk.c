/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_img_dragon_talk.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 14:18:07 by zkepes            #+#    #+#             */
/*   Updated: 2024/04/14 18:46:20 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_img_dragon_idle(t_data *d)
{
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.dragon.idle[0].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.dragon.idle[1].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.dragon.idle[2].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.dragon.idle[3].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.dragon.idle[4].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.dragon.idle[5].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.dragon.idle[6].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.dragon.idle[7].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.dragon.idle[8].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.dragon.idle[9].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.dragon.idle[10].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.dragon.idle[11].img_ptr);
}

void	free_img_talk(t_data *d)
{
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.talk.money[0].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.talk.money[1].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.talk.money[2].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.talk.money[3].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.talk.money[4].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.talk.money[5].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.talk.wall[0].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.talk.wall[1].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.talk.wall[2].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.talk.wall[3].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.talk.wall[4].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.talk.wall[5].img_ptr);
}
