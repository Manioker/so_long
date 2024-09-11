/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvacca <anvacca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 08:11:47 by anvacca           #+#    #+#             */
/*   Updated: 2024/09/11 13:29:33 by anvacca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	used_char(t_game *game, int j, int i)
{
	if (game->map[j][i] == 'C')
		game->C--;
	if (game->map[j][i] == 'E')
		game->E--;
	game->map_copy[game->Py][game->Px] = '1';
	floodfill_algo(game);
}

void	floodfill_algo(t_game *game)
{
	if (game->map_copy[game->Py][game->Px + 1] != '1')
	{
		used_char(game, game->Py, game->Px++);
		game->Px--;
	}
	else if (game->map_copy[game->Py + 1][game->Px] != '1')
	{
		used_char(game, game->Py++, game->Px);
		game->Py--;
	}
	else if (game->map_copy[game->Py][game->Px - 1] != '1')
	{
		used_char(game, game->Py, game->Px--);
		game->Px++;
	}
	else if (game->map_copy[game->Py - 1][game->Px] != '1')
	{
		used_char(game, game->Py--, game->Px);
		game->Py++;
	}
	else
		return ;
	floodfill_algo(game);
}
