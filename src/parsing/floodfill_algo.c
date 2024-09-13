/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andi <andi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 08:11:47 by anvacca           #+#    #+#             */
/*   Updated: 2024/09/13 16:12:57 by andi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	used_char(t_game *game, int j, int i)
{
	game->count.C2 = game->count.C;
	game->count.E2 = game->count.E;

	if (game->map[j][i] == 'C')
		game->count.C--;
	if (game->map[j][i] == 'E')
		game->count.E--;
	game->map_copy[game->pos.Py][game->pos.Px] = '1';
	floodfill_algo(game);
}

void	floodfill_algo(t_game *game)
{
	if (game->map_copy[game->pos.Py][game->pos.Px + 1] != '1')
	{
		used_char(game, game->pos.Py, game->pos.Px++);
		game->pos.Px--;
	}
	else if (game->map_copy[game->pos.Py + 1][game->pos.Px] != '1')
	{
		used_char(game, game->pos.Py++, game->pos.Px);
		game->pos.Py--;
	}
	else if (game->map_copy[game->pos.Py][game->pos.Px - 1] != '1')
	{
		used_char(game, game->pos.Py, game->pos.Px--);
		game->pos.Px++;
	}
	else if (game->map_copy[game->pos.Py - 1][game->pos.Px] != '1')
	{
		used_char(game, game->pos.Py--, game->pos.Px);
		game->pos.Py++;
	}
	else
		return ;
	floodfill_algo(game);
}
