/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andi <andi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:16:57 by anvacca           #+#    #+#             */
/*   Updated: 2024/09/13 17:50:28 by andi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "mlx_linux/mlx.h" // MiniLibX
// # include <X11/Xlib.h>      // Display
# include <fcntl.h>         // open
# include <math.h>          // Math Functions
# include <stdarg.h>        // Variadic Functions
# include <stdio.h>         // printf
# include <stdlib.h>        // malloc, free, exit
# include <unistd.h>        // write, close, read

// void printus(char **map)
// {
// 	int j;

// 	j = 0;
// 	while (map[j])
// 	{
// 		printf("%s", map[j]);
// 		j++;
// 	}
// }

int	main(void)
{
	void	*mlx;
	void	*mlx_window;
	void	*img;
	char	*relative_path = "./test.xpm";
	int		img_width = 40;
	int		img_height = 40;

	// Get screen size
	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, 1920,
			1080, "anvacca's so_long");
	if (!mlx_window)
		exit(1);
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_window,  img, 600, 450);
	mlx_loop(mlx);
}