/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill_help.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 07:51:46 by zkepes            #+#    #+#             */
/*   Updated: 2024/04/14 07:54:39 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*replace the checked fields in the map with space*/
void	replace_arg1_arg2_map(char arg1, char arg2, t_data *d)
{
	int	idx_y;
	int	idx_x;

	idx_y = 0;
	while (d->map.tmp_map[idx_y])
	{
		idx_x = 0;
		while (d->map.tmp_map[idx_y][idx_x])
		{
			if (arg1 == d->map.tmp_map[idx_y][idx_x])
			{
				d->map.tmp_map[idx_y][idx_x] = arg2;
			}
			idx_x++;
		}
		idx_y++;
	}
}

/*find position of character 'c' in map, if not found values are negative*/
void	find_position(t_data *d, char c)
{
	int	idx_y;
	int	idx_x;

	idx_y = 0;
	d->map.x = -1;
	d->map.y = -1;
	while (d->map.tmp_map[idx_y])
	{
		idx_x = 0;
		while (d->map.tmp_map[idx_y][idx_x])
		{
			if (c == d->map.tmp_map[idx_y][idx_x])
			{
				d->map.y = idx_y;
				d->map.x = idx_x;
			}
			idx_x++;
		}
		idx_y++;
	}
}

/*copy original map to tmp_map*/
void	cpy_map_tmp(t_data *d)
{
	int	idx_height;

	idx_height = 0;
	d->map.tmp_map = (char **) ft_calloc(d->map.height + 1, sizeof(char *));
	while (idx_height < d->map.height)
	{
		d->map.tmp_map[idx_height] = ft_strdup(d->map.map[idx_height]);
		idx_height++;
	}
	d->map.tmp_map[idx_height] = NULL;
}
