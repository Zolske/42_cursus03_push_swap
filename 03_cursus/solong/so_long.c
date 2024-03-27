/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:27:59 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/27 18:22:33 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_data	data;
	
	if (argc == 2)
	{
		init(&data, argv);
		file_into_struct(argv[1], &data);
		validate_map(&data);
		start_game(&data);
		free_all(&data);
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

void	start_game(t_data *d)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
	printf("ḧello\n");
}