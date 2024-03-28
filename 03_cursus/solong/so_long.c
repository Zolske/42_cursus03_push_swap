/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:27:59 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/28 14:28:17 by zkepes           ###   ########.fr       */
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
	void		*mlx;
	void		*mlx_win;
	t_i_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	
	// Load a texture image
	int width = 64;
	int height = 64;
    void *img_t = mlx_xpm_file_to_image(mlx, "test/open.xpm", &width, &height);

    // Display the texture on the window
    // mlx_put_image_to_window(mlx, mlx_win, img_t, 100, 100);
	// mlx_put_image_to_window(mlx, mlx_win, img_t, 500, 400);
	// mlx_hook(mlx_win, 2, 1L << 0, key_press, NULL);
    // mlx_hook(mlx_win, 6, 1L << 6, mouse_move, NULL);

	    // The animation loop
	void *img_p;
	int idx = 0;
	int widthp = 32;
	int heightp = 32;
    mlx_string_put(mlx, mlx_win, 100, 100, 0xFFFF00, "Magical Text");
    while (1) {
        // Load the current frame of your sprite animation
        // char frame_filename[20]; // Assuming frame filenames are like "frame1.xpm", "frame2.xpm", etc.
        // sprintf(frame_filename, "frame%d.xpm", frame);
		if (4 == idx)
			idx = 0;;
		if (0 == idx)
        	img_p = mlx_xpm_file_to_image(mlx, "test/player/player1.xpm", &widthp, &heightp);
		if (1 == idx)
        	img_p = mlx_xpm_file_to_image(mlx, "test/player/player2.xpm", &widthp, &heightp);
		if (2 == idx)
        	img_p = mlx_xpm_file_to_image(mlx, "test/player/player3.xpm", &widthp, &heightp);
		idx++;

        // Display the sprite on the window
        mlx_put_image_to_window(mlx, mlx_win, img_p, 100, 100);

        // Update the frame for the next iteration
        // frame = (frame % NUM_FRAMES) + 1; // Change frame from 1 to NUM_FRAMES and loop back

        // Adjust the frame rate for your desired animation speed
        usleep(100000); // Sleep for 0.1 seconds (adjust as needed)
    }
	// Add text to the window

	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

void	my_mlx_pixel_put(t_i_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int key_press(int keycode, void *param)
{
    printf("Key %d is pressed!\n", keycode);
    return 0;
}

int mouse_move(int x, int y, void *param)
{
    printf("Mouse is at position (%d, %d)\n", x, y);
    return 0;
}