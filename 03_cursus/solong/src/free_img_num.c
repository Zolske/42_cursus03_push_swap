/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_img_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:59:08 by zkepes            #+#    #+#             */
/*   Updated: 2024/04/14 19:06:31 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_img_num(t_data *d)
{
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.text.moves.img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.text.num[0].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.text.num[1].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.text.num[2].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.text.num[3].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.text.num[4].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.text.num[5].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.text.num[6].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.text.num[7].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.text.num[8].img_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.text.num[9].img_ptr);
}
