/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:46:33 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/31 18:01:22 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_map(t_data *d)
{
	int	idx_hight;

	if (d->map)
	{
		idx_hight = 0;
		printf("width: %d height %d\n\n", d->width, d->height);
		while (d->map[idx_hight])
		{
			printf("|%s|\n", d->map[idx_hight]);
			idx_hight++;
		}
		printf("\n");
	}
}
