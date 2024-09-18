/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_binds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvacca <anvacca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:00:02 by anvacca           #+#    #+#             */
/*   Updated: 2024/09/18 10:46:58 by anvacca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	key_binds(int key_code, t_game *game)
{
	int	x;
	int	y;

	x = game->pos.px;
	y = game->pos.py;
	if (key_code == ESC)
		close_display(game);
	else if ((key_code == W) || (key_code == ARROW_UP))
		player_move(x, y - 1, game);
	else if ((key_code == A) || (key_code == ARROW_LEFT))
		player_move(x - 1, y, game);
	else if ((key_code == S) || (key_code == ARROW_DOWN))
		player_move(x, y + 1, game);
	else if ((key_code == D) || (key_code == ARROW_RIGHT))
		player_move(x + 1, y, game);
	display_game(game);
	return (0);
}
