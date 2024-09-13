/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andi <andi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:49:58 by andi              #+#    #+#             */
/*   Updated: 2024/09/13 16:28:12 by andi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void player_move(t_game *game, int move)
{
	int x;
	int y;
	
	x = game->pos.Px;
	y = game->pos.Py;
	game->map[y][x] = '0';
	if (move == W && game->map[y - 1][x] != '1')
		y--;
	else if (move == A && game->map[y][x - 1] != '1')
		x--;
	else if (move == S && game->map[y + 1][x] != '1')
		y++;
	else if (move == D && game->map[y][x + 1] != '1')
		x++;
	if (game->map[y][x] == 'C')
		game->count.C2--;
	// if (game->map[y][x] == 'M')
	// 	you_died(game);
	if (game->map[y][x] == 'E' && game->count.C2 == 0)
	{
		close_display(game);
		write(1, "keep it a secret...", 19);
	}
	game->map[y][x] = 'P'
}