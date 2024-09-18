/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvacca <anvacca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:49:58 by andi              #+#    #+#             */
/*   Updated: 2024/09/18 10:47:34 by anvacca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	player_move(int x, int y, t_game *game)
{
	static int	moves;

	ft_putnbr(moves);
	write(1, "\n", 1);
	moves++;
	if (game->map[y][x] == '0' || game->map[y][x] == 'C')
	{
		if (game->map[y][x] == 'C')
			game->count.c2--;
		game->map[game->pos.py][game->pos.px] = '0';
		game->map[y][x] = 'P';
		game->pos.px = x;
		game->pos.py = y;
	}
	if (game->map[y][x] == 'E' && game->count.c2 == 0)
	{
		write(1, "keep it a secret...", 19);
		close_display(game);
	}
}
