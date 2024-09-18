/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_closed.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvacca <anvacca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 14:00:33 by andi              #+#    #+#             */
/*   Updated: 2024/09/18 10:42:45 by anvacca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	is_closed(t_game *game)
{
	int	i;
	int	j;
	int	last;

	i = 0;
	j = 0;
	last = ft_strlen(game->map[j]) - 2;
	while (game->map[j + 1])
	{
		if (game->map[j][i] != '1' || game->map[j][last] != '1')
		{
			free_map(game);
			exit_function(4);
		}
		j++;
	}
	while (game->map[j][i] == '1' && game->map[0][i] == '1')
		i++;
	if (game->map[j][i] != '\n' || game->map[0][i] != '\n')
	{
		free_map(game);
		exit_function(4);
	}
}
