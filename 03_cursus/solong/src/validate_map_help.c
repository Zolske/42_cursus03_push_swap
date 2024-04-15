/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_help.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:42:00 by zkepes            #+#    #+#             */
/*   Updated: 2024/04/15 12:33:16 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*compares every character of a string with the argument 'c'*/
bool	not_eq_line_char(char *str, char c)
{
	while (*str)
	{
		if (*str != c)
			return (true);
		str++;
	}
	return (false);
}

/*compares the first and the last character of a string with the argument 'c'*/
bool	not_eq_first_last_char(char *str, char c)
{
	if (*str != c)
		return (true);
	if (str[ft_strlen(str) - 1] != c)
		return (true);
	return (false);
}

/*check if there is a character in the map which is not in 'MAPCHAR'*/
bool	not_valid_map_char(t_data *d)
{
	int		idx_row;
	int		idx_col;
	char	*tmp;

	idx_row = 0;
	while (d->map.map[idx_row])
	{
		idx_col = 0;
		while (d->map.map[idx_row][idx_col])
		{
			tmp = ft_strchr(MAPCHAR, d->map.map[idx_row][idx_col]);
			if (d->map.bonus)
				tmp = ft_strchr(MAPCHAR_BONUS, d->map.map[idx_row][idx_col]);
			if (NULL == tmp)
			{
				write(2, "Error\nInvalid character in map!\n", 32);
				return (true);
			}
			idx_col++;
		}
		idx_row++;
	}
	return (false);
}

/*check if there is enough items in map, value comes from macro*/
bool	not_sufficient_items_map(t_data *data)
{
	int	exit;
	int	player;
	int	collect;

	exit = count_arg1_in_map(EXIT, data);
	player = count_arg1_in_map(PLAYER, data);
	collect = count_arg1_in_map(COLLEC, data);
	if (1 < exit)
		return (write(2, "Error\nMore then one 'EXIT' in map!\n", 35));
	else if (0 == exit)
		return (write(2, "Error\nNO 'EXIT' in map!\n", 24));
	else if (1 < player)
		return (write(2, "Error\nMore then one 'Player' in map!\n", 37));
	else if (0 == player)
		return (write(2, "Error\nNO 'Player' in map!\n", 26));
	else if (0 == collect)
		return (write(2, "Error\nNO 'Collectables' in map!\n", 32));
	return (false);
}

/*count appearance of character in map*/
int	count_arg1_in_map(char arg1, t_data *d)
{
	int	idx_row;
	int	idx_col;
	int	counter;

	idx_row = 0;
	counter = 0;
	while (d->map.map[idx_row])
	{
		idx_col = 0;
		while (d->map.map[idx_row][idx_col])
		{
			if (arg1 == d->map.map[idx_row][idx_col])
				counter++;
			idx_col++;
		}
		idx_row++;
	}
	return (counter);
}
