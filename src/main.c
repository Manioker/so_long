/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvacca <anvacca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:35:33 by andi              #+#    #+#             */
/*   Updated: 2024/09/11 13:29:54 by anvacca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	printus(char **map)
{
	int	j;

	j = 0;
	while (map[j])
	{
		printf("%s", map[j]);
		j++;
	}
}

int main(int ac, char **av)
{
	t_game *game;
	
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		exit_function(3);
	game->C = 0;
	game->E = 0;
	game->P = 0;
	game->Px = 0;
	game->Py = 0;
	init_map(av, game);
	does_exist(ac, av);
	is_rectangle(game);
	is_closed(game);
	is_char(game);
	floodfill_algo(game);
	if (game->C > 0 || game->E > 0)
		exit_function(4);
	printus(game->map_copy);
}
