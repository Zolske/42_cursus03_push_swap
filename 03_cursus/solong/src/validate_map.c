/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:26:24 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/31 18:01:22 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	validate_map(t_data *d)
{
	if (not_valid_character(d))
		e_data(d, "Map has invalid or missing characters!");
	if (not_rectangular_map(d->width, d))
		e_data(d, "Map is not rectangular!");
	if (not_surrounded_wall(d))
		e_data(d, "Map is not surrounded by a wall!");
	if (not_valid_path(d))
		e_data(d, "Map has no valid path!");
}

/*check if map is rectangular while subtracting '\n' from EOL*/
bool	not_rectangular_map(int width, t_data *d)
{
	int	len;
	int	idx_row;

	idx_row = 0;
	while (d->map[idx_row])
	{
		len = ft_strlen(d->map[idx_row]);
		if ('\n' == d->map[idx_row][len - 1])
			len--;
		if (width != len)
			return (true);
		idx_row++;
	}
	return (false);
}

/*check if map is surrounded by a "wall"*/
bool	not_surrounded_wall(t_data *d)
{
	int			idx_row;

	idx_row = 0;
	if (not_eq_line_char(d->map[idx_row], WALL))
		return (true);
	while (++idx_row < d->height - 1)
		if (not_eq_first_last_char((d->map[idx_row]), WALL))
			return (true);
	if (not_eq_line_char(d->map[idx_row], WALL))
		return (true);
	return (false);
}

/*check map for valid characters*/
bool	not_valid_character(t_data *d)
{
	if (not_valid_map_char(d))
		return (true);
	if (not_sufficient_items_map(d))
		return (true);
	return (false);
}

/*check if there is a path to items*/
bool	not_valid_path(t_data *d)
{
	if (not_valid_path_exit(d))
		return (true);
	if (not_valid_path_collac(d))
		return (true);
	return (false);
}
