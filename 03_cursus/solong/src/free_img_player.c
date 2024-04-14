/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_img_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 10:39:44 by zkepes            #+#    #+#             */
/*   Updated: 2024/04/13 16:54:54 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_img_player_idle(t_data *d)
{
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.player.idle[0].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.player.idle[1].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.player.idle[2].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.player.idle[3].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.player.idle[4].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.player.idle[5].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.player.idle[6].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.player.idle[7].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.player.idle[8].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.player.idle[9].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.player.idle[10].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.player.idle[11].img_ptr);
}

void	free_img_player_walk_down(t_data *d)
{
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.player.down[0].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.player.down[1].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.player.down[2].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.player.down[3].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.player.down[4].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.player.down[5].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.player.down[6].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.player.down[7].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.player.down[8].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.player.down[9].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.player.down[10].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.player.down[11].img_ptr);
}

void	free_img_player_walk_up(t_data *d)
{
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.player.up[0].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.player.up[1].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.player.up[2].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.player.up[3].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.player.up[4].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.player.up[5].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.player.up[6].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.player.up[7].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.player.up[8].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.player.up[9].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.player.up[10].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.player.up[11].img_ptr);
}

void	free_img_player_walk_right(t_data *d)
{
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.player.right[0].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.player.right[1].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.player.right[2].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.player.right[3].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.player.right[4].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.player.right[5].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.player.right[6].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.player.right[7].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.player.right[8].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.player.right[9].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.player.right[10].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.player.right[11].img_ptr);
}

void	free_img_player_walk_left(t_data *d)
{
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.player.left[0].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.player.left[1].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.player.left[2].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.player.left[3].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.player.left[4].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.player.left[5].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.player.left[6].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.player.left[7].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.player.left[8].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.player.left[9].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.player.left[10].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.player.left[11].img_ptr);
}
