/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:22:53 by zkepes            #+#    #+#             */
/*   Updated: 2024/04/03 12:25:06 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*check if there is a valid path from the player to the exit*/
bool	not_valid_path_exit(t_data *d)
{
	cpy_map_tmp(d);
	find_position(d, PLAYER);
	d->map.valid_path = false;
	search_path(d, EXIT, d->map.y, d->map.x);
	free_map(d->map.tmp_map);
	return (!d->map.valid_path);
}

/*check if all the collectables have a valid path to the player*/
bool	not_valid_path_collac(t_data *d)
{
	int	num_collec;

	cpy_map_tmp(d);
	find_position(d, PLAYER);
	num_collec = count_arg1_in_map(COLLEC, d);
	while (num_collec--)
	{
		d->map.valid_path = false;
		search_path(d, COLLEC, d->map.y, d->map.x);
		if (!d->map.valid_path)
			break;
		replace_arg1_with_arg2_in_map(CHECKED, SPACE, d);
	}
	free_map(d->map.tmp_map);
	return (!d->map.valid_path);
}

/*search the map in tmp_d if there is a valid path*/
void	search_path(t_data *d, char item, int y, int x)
{
	if (d->map.valid_path)
		return;
	if (outside_map(d))
		return;
	if (WALL == d->map.tmp_map[y][x])
		return;
	if (CHECKED == d->map.tmp_map[y][x])
		return;
	if (item == d->map.tmp_map[y][x])
	{
		d->map.valid_path = true;
		d->map.tmp_map[y][x] = SPACE;
		return;
	}
	d->map.tmp_map[y][x] = CHECKED;
	search_path(d, item, y +1, x);
	search_path(d, item, y -1, x);
	search_path(d, item, y, x +1);
	search_path(d, item, y, x -1);
	return;
}

/*check if coordinates are outside of map*/
bool	outside_map(t_data *d)
{
	if (0 > d->map.y)
		return (true);
	else if (d->map.height <= d->map.y)
		return (true);
	else if (0 > d->map.x)
		return (true);
	else if (d->map.width <= d->map.x)
		return (true);
	return (false);
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

/*replace the checked fields in the map with space*/
void	replace_arg1_with_arg2_in_map(char arg1, char arg2, t_data *d)
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
