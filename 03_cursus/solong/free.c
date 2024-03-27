/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:42:24 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/27 13:24:15 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_all(t_data *d)
{
	free_map(d->map);
}

/*free table of strings and set it's pointers to NULL*/
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

/*free string and set it's pointer to NULL*/
void	free_str(char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
}