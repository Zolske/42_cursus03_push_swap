/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_4d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 10:53:02 by zkepes            #+#    #+#             */
/*   Updated: 2024/04/14 07:47:05 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_map_4d(t_data *d)
{
	int	i_per;
	int	i_cxy;
	int	i_tab;

	i_per = 0;
	d->map.map_4d = (int ****)malloc(sizeof(int ***) * 5);
	d->map.map_4d[4] = NULL;
	while (i_per < 4)
	{
		d->map.map_4d[i_per] = (int ***)malloc(sizeof(int **) * 8);
		d->map.map_4d[i_per][7] = NULL;
		i_cxy = 0;
		while (i_cxy < 3)
		{
			create_tabc_tabx_taby(d, i_per, i_cxy);
			i_cxy++;
		}
		while (i_cxy >= 3 && i_cxy < 7)
		{
			create_ntop_nrig_nbot_nlef(d, i_per, i_cxy);
			i_cxy++;
		}
		i_per++;
	}
}

void	create_tabc_tabx_taby(t_data *d, int i_per, int i_cxy)
{
	int	i_tab;
	int	i_row;
	int	i_col;

	i_row = d->map.height;
	i_col = d->map.width;
	if (i_per == 1 || i_per == 3)
	{
		i_row = d->map.width;
		i_col = d->map.height;
	}
	d->map.map_4d[i_per][i_cxy] = (int **) malloc(sizeof(int *) * i_row + 1);
	d->map.map_4d[i_per][i_cxy][i_row] = NULL;
	i_tab = 0;
	while (i_tab < i_row)
	{
		d->map.map_4d[i_per][i_cxy][i_tab] = (int *) malloc(sizeof(int)
				* i_col + 1);
		d->map.map_4d[i_per][i_cxy][i_tab][i_col] = INT_MAX;
		i_tab++;
	}
}

void	create_ntop_nrig_nbot_nlef(t_data *d, int i_per, int i_cxy)
{
	int	i_tab;

	d->map.map_4d[i_per][i_cxy] = (int **) malloc(sizeof(int *) * 4);
	d->map.map_4d[i_per][i_cxy][3] = NULL;
	i_tab = 0;
	while (i_tab < 3)
	{
		d->map.map_4d[i_per][i_cxy][i_tab] = (int *) malloc(sizeof(int));
		i_tab++;
	}
}

void	cpy_map_4d(t_data *d)
{
	int	idx_row;
	int	idx_col;

	idx_row = 0;
	while (idx_row < d->map.height)
	{
		idx_col = 0;
		while (idx_col < d->map.width)
		{
			d->map.map_4d[0][0][idx_row][idx_col] = d->map.map
			[idx_row][idx_col];
			idx_col++;
		}
		idx_row++;
	}
}
