/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:42:24 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/25 16:50:52 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_all(t_map *map)
{
	free_map(map->map);
}

/*frees a table of characters ("the map") and sets its pointers to NULL*/
void	free_map(char **map)
{
	int	idx_height;

	idx_height = 0;
	if (map)
	{
		while (map[idx_height])
		{
			free(map[idx_height]);
			map[idx_height] = NULL;
			idx_height++;
		}
		free(map);
		map = NULL;
	}
}