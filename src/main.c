/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvacca <anvacca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:35:33 by andi              #+#    #+#             */
/*   Updated: 2024/09/17 13:52:35 by anvacca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void init_struct(t_game *game)
{
	game->count.C = 0;
	game->count.C2 = 0;
	game->count.E = 0;
	game->count.P = 0;
	game->pos.Px = 0;
	game->pos.Py = 0;
	game->map = 0;
	game->map_copy = 0;
	game->map_width = 0;
	game->map_height = 0;
}

int main(int ac, char **av)
{
	t_game *game;
	
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		exit_function(3);
	init_struct(game);
	init_map(av, game);
	does_exist(ac, av);
	is_rectangle(game);
	is_closed(game);
	is_char(game);
	floodfill_algo(game);
	init_display(game);
	init_sprite(game);
	if (game->count.C > 0 || game->count.E > 0)
		exit_function(4);
	display_game(game);
	mlx_hook(game->mlx.mlx_window, 2, (1L<<0), key_binds, game);
	mlx_hook(game->mlx.mlx_window, 17, 0L, close_display, game);
	mlx_loop(game->mlx.mlx_con);
}
