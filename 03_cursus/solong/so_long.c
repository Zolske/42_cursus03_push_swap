/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:27:59 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/27 12:58:12 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_data	d;
	
	if (argc == 2)
	{
		init(&d, argv);
		file_into_struct(argv[1], &d);
		validate_map(&d);
		free_all(&d);
	}
}

void	init(t_data *d, char *argv[])
{
	d->file = argv[1];
	d->height = 0;
	d->width = 0;
	d->map = NULL;
	d->found = false;
}