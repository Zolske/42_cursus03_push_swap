/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 06:42:03 by zkepes            #+#    #+#             */
/*   Updated: 2024/04/15 12:32:49 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	key_hook(int key, t_data *d)
{
	if (!d->map.keys_locked)
	{
		if (XK_Up == key || XK_Right == key || XK_Down == key || XK_Left == key)
			process_move(key, d);
		else if (XK_Tab == key)
		{
			if (VIEW_LEFT == d->map.per)
				d->map.per = VIEW_BOTTOM;
			else
				d->map.per++;
		}
	}
	if (XK_Escape == key)
		close_window(d);
	return (0);
}

int	close_window(t_data *d)
{
	free_all_img(d);
	mlx_destroy_window(d->mlx.mlx_ptr, d->mlx.win_ptr);
	mlx_destroy_image(d->mlx.mlx_ptr, d->img.canvas.img_ptr);
	mlx_destroy_display(d->mlx.mlx_ptr);
	free(d->mlx.mlx_ptr);
	free_map_4d(d);
	free_all(d);
	exit(0);
}
