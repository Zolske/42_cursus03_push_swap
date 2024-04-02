/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:22:53 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/31 18:01:22 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*check if there is a valid path from the player to the exit*/
bool	not_valid_path_exit(t_data *data)
{
	t_data	tmp_data;
	t_pos	position;
	bool	valid_path;

	cpy_struct_data(&tmp_data, data);
	find_position(&tmp_data, PLAYER, &position);
	search_path(&tmp_data, EXIT, position);
	valid_path = tmp_data.found;
	free_all(&tmp_data);
	if (valid_path)
		return (false);
	else
		return (true);
}

/*check if all the collectables have a valid path to the player*/
bool	not_valid_path_collac(t_data *data)
{
	t_data	tmp_data;
	t_pos	position;
	int		num_collec;
	int		count;
	bool	valid_path;

	cpy_struct_data(&tmp_data, data);
	find_position(&tmp_data, PLAYER, &position);
	num_collec = count_arg1_in_map(COLLEC, &tmp_data);
	count = 1;
	while (count++ <= num_collec)
	{
		tmp_data.found = false;
		search_path(&tmp_data, COLLEC, position);
		replace_arg1_with_arg2_in_map(CHECKED, SPACE, &tmp_data);
	}
	valid_path = tmp_data.found;
	free_all(&tmp_data);
	if (tmp_data.found)
	{
		return (false);
	}
		return (true);
}

/*search the map in tmp_d if there is a valid path*/
void	search_path(t_data *tmp_d, char item, t_pos pos)
{
	if (tmp_d->found)
		return;
	if (outside_map(tmp_d, &pos))
		return;
	if (WALL == tmp_d->map[pos.y][pos.x])
		return;
	if (CHECKED == tmp_d->map[pos.y][pos.x])
		return;
	if (item == tmp_d->map[pos.y][pos.x])
	{
		tmp_d->found = true;
		tmp_d->map[pos.y][pos.x] = SPACE;
		return;
	}
	tmp_d->map[pos.y][pos.x] = CHECKED;
	search_path(tmp_d, item, (t_pos){pos.y +1, pos.x});
	search_path(tmp_d, item, (t_pos){pos.y -1, pos.x});
	search_path(tmp_d, item, (t_pos){pos.y, pos.x +1});
	search_path(tmp_d, item, (t_pos){pos.y, pos.x -1});
	return;
}

/*check if coordinates are outside of map*/
bool	outside_map(t_data *tmp_d, t_pos *pos)
{
	if (0 > pos->y)
		return (true);
	else if (tmp_d->height <= pos->y)
		return (true);
	else if (0 > pos->x)
		return (true);
	else if (tmp_d->width <= pos->x)
		return (true);
	return (false);
}

/*initialize structure with values from src struct and some base values*/
void	cpy_struct_data(t_data *dst, t_data *src)
{
	int	idx_hight;
	
	idx_hight = 0;
	dst->found = false;
	dst->height = src->height;
	dst->width = src->width;
	dst->map = (char **) ft_calloc(dst->height + 1, sizeof(char *));
	while (idx_hight < dst->height)
	{
		dst->map[idx_hight] = ft_strdup(src->map[idx_hight]);
		idx_hight++;
	}
	dst->map[idx_hight] = NULL;
}

/*check position of character 'c' in map, if not values are negative*/
void	find_position(t_data *tmp_d, char c, t_pos *pos)
{
	int	idx_y;
	int	idx_x;

	idx_y = 0;
	pos->y = -1;
	pos->x = -1;
	while (tmp_d->map[idx_y])
	{
		idx_x = 0;
		while (tmp_d->map[idx_y][idx_x])
		{
			if (c == tmp_d->map[idx_y][idx_x])
			{
				pos->y = idx_y;
				pos->x = idx_x;
			}
			idx_x++;
		}
		idx_y++;
	}
}

/*replace the checked fields in the map with space*/
void	replace_arg1_with_arg2_in_map(char arg1, char arg2, t_data *tmp_d)
{
	int	idx_y;
	int	idx_x;

	idx_y = 0;
	while (tmp_d->map[idx_y])
	{
		idx_x = 0;
		while (tmp_d->map[idx_y][idx_x])
		{
			if (arg1 == tmp_d->map[idx_y][idx_x])
			{
				tmp_d->map[idx_y][idx_x] = arg2;
			}
			idx_x++;
		}
		idx_y++;
	}
}
