/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvacca <anvacca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:49:58 by andi              #+#    #+#             */
/*   Updated: 2024/09/17 13:54:30 by anvacca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	printus(char **map)
{
	int	j;

	j = 0;
	while (map[j])
	{
		printf("%s", map[j]);
		j++;
	}
	puts("\n");
}

void	player_move(int x, int y, t_game *game)
{
	if (game->map[y][x] == '0' || game->map[y][x] == 'C')
	{
		if (game->map[y][x] == 'C')
			game->count.C2--;
		game->map[game->pos.Py][game->pos.Px] = '0';
		game->map[y][x] = 'P';
		game->pos.Px = x;
		game->pos.Py = y;
	}
	if (game->map[y][x] == 'E' && game->count.C2 == 0)
	{
		write(1, "keep it a secret...", 19);
		close_display(game);
	}
	printus(game->map);
}
