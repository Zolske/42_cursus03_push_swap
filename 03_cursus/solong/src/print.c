/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:46:33 by zkepes            #+#    #+#             */
/*   Updated: 2024/04/07 12:57:06 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_map(t_data *d)
{
	int	idx_hight;

	if (d->map.map)
	{
		idx_hight = 0;
		printf("width: %d height %d\n\n", d->map.width, d->map.height);
		while (d->map.map[idx_hight])
		{
			printf("|%s|\n", d->map.map[idx_hight]);
			idx_hight++;
		}
		printf("\n");
	}
}

void	print_map_4d_char(t_data *d, int per)
{
	int	idx_row;
	int	idx_col;
	int	play_x;
	int	play_y;


	idx_row = 0;
	player_coordinate(d, &play_x, &play_y, per);
	printf("\nCHARACTER TABLE:\n");
	printf("Player coordinate: x=%d, y=%d\n\n", play_x, play_y);
	while (d->map.map_4d[per][TAB_C][idx_row] != NULL)
	{
		idx_col = 0;
		while (d->map.map_4d[per][TAB_C][idx_row][idx_col] != INT_MAX)
		{
			printf("%c|", (char) d->map.map_4d[per][TAB_C][idx_row][idx_col]);
			idx_col++;
		}
		printf("\n");
		while (idx_col--)
			printf("--");
		printf("\n");
		idx_row++;
	}
}

void	print_map_4d_coordinates(t_data *d, int per)
{
	int	idx_row;
	int	idx_col;
	int	play_x;
	int	play_y;


	idx_row = 0;
	player_coordinate(d, &play_x, &play_y, per);
	printf("\nALL TABLE C X Y: ");
	printf("Player coordinate: x=%d, y=%d\n", play_x, play_y);
	// while (idx_row < d->map.height)
	while (d->map.map_4d[per][TAB_C][idx_row] != NULL)
	{
		idx_col = 0;
		while (d->map.map_4d[per][TAB_C][idx_row][idx_col] != INT_MAX)
		{
			printf("\033[0;36m%c\033[0m", d->map.map_4d[per][TAB_C][idx_row][idx_col]);
			printf("\033[0;31m%4d\033[0m", d->map.map_4d[per][TAB_X][idx_row][idx_col]);
			printf("\033[0;32m%4d\033[0m|", d->map.map_4d[per][TAB_Y][idx_row][idx_col]);
			idx_col++;
		}
		printf("\n");
		while (idx_col--)
			printf("----------");
		printf("\n");
		idx_row++;
	}
}
