/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 06:15:08 by zkepes            #+#    #+#             */
/*   Updated: 2024/04/14 07:33:15 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	update_maps(t_data *d)
{
	update_table_perspective(d);
	update_coordinates(d, VIEW_BOTTOM);
	update_coordinates(d, VIEW_RIGHT);
	update_coordinates(d, VIEW_TOP);
	update_coordinates(d, VIEW_LEFT);
}

void	update_table_perspective(t_data *d)
{
	int		idx_row;
	int		idx_col;
	int		idx_row_last;
	int		idx_col_last;
	char	cpy;

	idx_row_last = d->map.height;
	idx_row = 0;
	while (d->map.map_4d[VIEW_BOTTOM][TAB_C][idx_row] != NULL)
	{
		idx_row_last--;
		idx_col = 0;
		idx_col_last = d->map.width;
		while (d->map.map_4d[VIEW_BOTTOM][TAB_C][idx_row][idx_col] != INT_MAX)
		{
			idx_col_last--;
			cpy = d->map.map_4d[VIEW_BOTTOM][TAB_C][idx_row][idx_col];
			d->map.map_4d[VIEW_RIGHT][TAB_C][idx_col][idx_row_last] = cpy;
			d->map.map_4d[VIEW_TOP][TAB_C][idx_row_last][idx_col_last] = cpy;
			d->map.map_4d[VIEW_LEFT][TAB_C][idx_col_last][idx_row] = cpy;
			idx_col++;
		}
		idx_row++;
	}
}

void	update_coordinates(t_data *d, int per)
{
	int	idx_y;
	int	idx_x;

	player_coordinate(d, &(d->tmp.x), &(d->tmp.y), per);
	idx_y = 0;
	while (d->map.map_4d[per][TAB_X][idx_y] != NULL)
	{
		idx_x = 0;
		while (d->map.map_4d[per][TAB_X][idx_y][idx_x] != INT_MAX)
		{
			d->map.map_4d[per][TAB_X][idx_y][idx_x] = ((idx_x - d->tmp.x)
					- (idx_y - d->tmp.y)) * (TILE_WIDTH / 2);
			d->map.map_4d[per][TAB_Y][idx_y][idx_x] = (((idx_x - d->tmp.x)
						+ (idx_y - d->tmp.y))) * (TILE_HEIGHT / 2);
			idx_x++;
		}
		idx_y++;
	}
	update_surrounding(d, per);
}

void	update_surrounding(t_data *d, int per)
{
	d->map.map_4d[per][N_TOP][TAB_C][0] = d->map.map_4d
	[per][TAB_C][d->tmp.y - 1][d->tmp.x];
	d->map.map_4d[per][N_TOP][TAB_X][0] = d->map.map_4d
	[per][TAB_X][d->tmp.y - 1][d->tmp.x];
	d->map.map_4d[per][N_TOP][TAB_Y][0] = d->map.map_4d
	[per][TAB_Y][d->tmp.y - 1][d->tmp.x];
	d->map.map_4d[per][N_RIG][TAB_C][0] = d->map.map_4d
	[per][TAB_C][d->tmp.y][d->tmp.x + 1];
	d->map.map_4d[per][N_RIG][TAB_X][0] = d->map.map_4d
	[per][TAB_X][d->tmp.y][d->tmp.x + 1];
	d->map.map_4d[per][N_RIG][TAB_Y][0] = d->map.map_4d
	[per][TAB_Y][d->tmp.y][d->tmp.x + 1];
	d->map.map_4d[per][N_BOT][TAB_C][0] = d->map.map_4d
	[per][TAB_C][d->tmp.y + 1][d->tmp.x];
	d->map.map_4d[per][N_BOT][TAB_X][0] = d->map.map_4d
	[per][TAB_X][d->tmp.y + 1][d->tmp.x];
	d->map.map_4d[per][N_BOT][TAB_Y][0] = d->map.map_4d
	[per][TAB_Y][d->tmp.y + 1][d->tmp.x];
	d->map.map_4d[per][N_LEF][TAB_C][0] = d->map.map_4d
	[per][TAB_C][d->tmp.y][d->tmp.x - 1];
	d->map.map_4d[per][N_LEF][TAB_X][0] = d->map.map_4d
	[per][TAB_X][d->tmp.y][d->tmp.x - 1];
	d->map.map_4d[per][N_LEF][TAB_Y][0] = d->map.map_4d
	[per][TAB_Y][d->tmp.y][d->tmp.x - 1];
}

/*coor. must coordinate[2], [0] is for x axis, [1] for y axis*/
void	player_coordinate(t_data *d, int *coor_x, int *coor_y, int per)
{
	int	idx_y;
	int	idx_x;

	idx_y = 0;
	while (d->map.map_4d[per][TAB_C][idx_y] != NULL)
	{
		idx_x = 0;
		while (d->map.map_4d[per][TAB_C][idx_y][idx_x] != INT_MAX)
		{
			if (PLAYER == (char)d->map.map_4d[per][TAB_C][idx_y][idx_x])
			{
				*coor_x = idx_x;
				*coor_y = idx_y;
				return ;
			}
			idx_x++;
		}
		idx_y++;
	}
}
