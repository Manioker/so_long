/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvacca <anvacca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 09:36:46 by anvacca           #+#    #+#             */
/*   Updated: 2024/09/17 13:52:10 by anvacca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void map_char(t_game *game, int *i, int j)
{
	if (game->map[j][*i] == 'C')
		game->count.C++;
	if (game->map[j][*i] == 'E')
		game->count.E++;
	if (game->map[j][*i] == 'P')
	{
		game->count.P++;
		game->pos.Px = *i;
		game->pos.Py = j;
	}
	*i += 1;
}

void is_char(t_game *game)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (game->map[j])
	{
		while(game->map[j][i])
			map_char(game, &i, j);
		j++;
		i = 0;
	}
	if (game->count.C < 1 || game->count.E < 1 || game->count.P < 1)
	{
		free_map(game);
		exit_function(4);
	}
	game->count.C2 = game->count.C;
}
