/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   innit_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andi <andi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:05:03 by anvacca           #+#    #+#             */
/*   Updated: 2024/09/13 10:17:56 by andi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	innit_display(t_game *game)
{
	Display	*d;

	// Open a connection to the X server
	d = XOpenDisplay(NULL);
	// Get screen size
	game->screen_width = DisplayWidth(d, 0);
	game->screen_height = DisplayHeight(d, 0);
	game->mlx.mlx_con = mlx_init();
	game->mlx.mlx_window = mlx_new_window(game->mlx.mlx_con, screen_width,
			screen_height, "anvacca's so_long");
	if (!game->mlx.mlx_window)
		exit_function(5);
}
