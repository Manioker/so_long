/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvacca <anvacca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 09:36:46 by anvacca           #+#    #+#             */
/*   Updated: 2024/09/11 12:01:10 by anvacca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void map_char(t_game *game, int *i, int j)
{
	if (game->map[j][*i] == 'C')
		game->C++;
	if (game->map[j][*i] == 'E')
		game->E++;
	if (game->map[j][*i] == 'P')
	{
		game->P++;
		game->Px = *i;
		game->Py = j;
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
	if (game->C < 1 || game->E < 1 || game->P < 1)
	{
		free_map(game);
		exit_function(4);
	}
}
