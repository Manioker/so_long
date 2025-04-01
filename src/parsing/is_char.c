/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvacca <anvacca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 09:36:46 by anvacca           #+#    #+#             */
/*   Updated: 2024/10/11 11:59:47 by anvacca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	map_char(t_game *game, int *i, int j)
{
	if (game->map[j][*i] == 'C')
		game->count.c++;
	if (game->map[j][*i] == 'E')
		game->count.e++;
	if (game->map[j][*i] == 'P')
	{
		game->count.p++;
		game->pos.px = *i;
		game->pos.py = j;
	}
	if (game->map[j][*i] != 'P' && game->map[j][*i] != 'E'
		&& game->map[j][*i] != 'C' && game->map[j][*i] != '1'
		&& game->map[j][*i] != '0' && game->map[j][*i] != '\n'
		&& game->map[j][*i] != '\r')
		exit_function(4);
	*i += 1;
}

void	is_char(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[j])
	{
		while (game->map[j][i])
			map_char(game, &i, j);
		j++;
		i = 0;
	}
	if (game->count.c < 1 || game->count.e != 1 || game->count.p != 1)
	{
		free_map(game);
		exit_function(4);
	}
	game->count.c2 = game->count.c;
}
