/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_help.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 19:14:06 by zkepes            #+#    #+#             */
/*   Updated: 2024/04/14 19:14:43 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	cpy_exit_from_ori(t_data *d)
{
	int	idx_y;
	int	idx_x;

	idx_y = 0;
	if (d->map.copy_exit)
	{
		while (idx_y < d->map.height)
		{
			idx_x = 0;
			while (idx_x < d->map.width)
			{
				if (EXIT == (char) d->map.map[idx_y][idx_x])
				{
					d->map.map_4d[VIEW_BOTTOM][TAB_C][idx_y][idx_x] = EXIT;
					d->map.copy_exit = false;
					return ;
				}
				idx_x++;
			}
			idx_y++;
		}
	}
}
