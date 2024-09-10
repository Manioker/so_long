/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvacca <anvacca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 09:36:46 by anvacca           #+#    #+#             */
/*   Updated: 2024/09/10 10:06:34 by anvacca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void is_char(t_game *game)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (game->map[j])
	{
		while(game->map[j][i])
		{
			if (game->map[j][i] == 'C')
				game->C++;
			if (game->map[j][i] == 'E')
				game->E++;
			if (game->map[j][i] == 'P')
				game->P++;
			i++;
		}
		j++;
	}
}
