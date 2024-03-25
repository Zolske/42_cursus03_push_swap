/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:46:33 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/25 15:03:19 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(t_map *map)
{
	int	idx_hight;

	if (map->map)
	{
		idx_hight = 0;
		printf("width: %d height %d\n\n", map->width, map->height);
		while (map->map[idx_hight])
		{
			printf("|%s|\n", map->map[idx_hight]);
			idx_hight++;
		}
		printf("\n");
	}
}
