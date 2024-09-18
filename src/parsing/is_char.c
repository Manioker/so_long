/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvacca <anvacca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 09:36:46 by anvacca           #+#    #+#             */
/*   Updated: 2024/09/18 10:51:26 by anvacca          ###   ########.fr       */
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
	if (game->count.c < 1 || game->count.e < 1 || game->count.p < 1)
	{
		free_map(game);
		exit_function(4);
	}
	game->count.c2 = game->count.c;
}
