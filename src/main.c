/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvacca <anvacca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:35:33 by andi              #+#    #+#             */
/*   Updated: 2024/09/10 11:10:35 by anvacca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main(int ac, char **av)
{
	t_game *game;
	
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		exit_function(3);
	game->C = 0;
	game->E = 0;
	game->P = 0;
	init_map(av, game);
	does_exist(ac, av);
	is_rectangle(game);
	is_closed(game);
	is_char(game);
}
