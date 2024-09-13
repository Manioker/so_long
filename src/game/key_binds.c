/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_binds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andi <andi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:00:02 by anvacca           #+#    #+#             */
/*   Updated: 2024/09/13 16:23:42 by andi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	key_binds(int key_code, t_game *game)
{
	if (key_code == ESC)
		close_display(game);
	else if (key_code == W || ARROW_UP)
		player_move(W, game);
	else if (key_code == A || ARROW_LEFT)
		player_move(A, game);
	else if (key_code == S || ARROW_DOWN)
		player_move(S, game);
	else if (key_code == D || ARROW_RIGHT)
		player_move(D, game);
	else
		return (0);
}
