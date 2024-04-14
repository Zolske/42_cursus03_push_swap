/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 10:44:12 by zkepes            #+#    #+#             */
/*   Updated: 2024/04/14 19:08:32 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_all_img(t_data *d)
{
	free_txt(d);
	free_img_static(d);
	free_img_coin(d);
	free_img_exit(d);
	free_img_player_idle(d);
	free_img_player_walk_down(d);
	free_img_player_walk_up(d);
	free_img_player_walk_right(d);
	free_img_player_walk_left(d);
	free_img_dragon_idle(d);
	free_img_talk(d);
	free_img_num(d);
}

void	free_txt(t_data *d)
{
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.text.arrow_key.img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.text.won.img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.text.lost.img_ptr);
}

void	free_img_static(t_data *d)
{
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.i_sta.wallh.img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.i_sta.wall.img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.i_sta.sand.img_ptr);
}

void	free_img_coin(t_data *d)
{
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.coin[0].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.coin[1].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.coin[2].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.coin[3].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.coin[4].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.coin[5].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.coin[6].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.coin[7].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.coin[8].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.coin[9].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.coin[10].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.coin[11].img_ptr);
}

void	free_img_exit(t_data *d)
{
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.exit[0].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.exit[1].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.exit[2].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.exit[3].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.exit[4].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.exit[5].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.exit[6].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.exit[7].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.exit[8].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.exit[9].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.exit[10].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.exit[11].img_ptr);
}
