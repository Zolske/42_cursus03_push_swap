/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:26:24 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/25 14:09:23 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// bool	not_valid_map()
// {
// 	if (not_surrounded_by_wall())
// }

/*check if width of map changes while subtracting '\n'*/
bool	not_rectangular_map(int width, char *map_row)
{
	int	len;

	if (NULL != map_row)
	{
		len = ft_strlen(map_row);
		if ('\n' == map_row[ft_strlen(map_row) - 1])
			len = ft_strlen(map_row) -1;
		if (width != len)
			return (true);
	}
	return (false);
}

