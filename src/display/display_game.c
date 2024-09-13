/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andi <andi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:29:25 by andi              #+#    #+#             */
/*   Updated: 2024/09/13 16:35:04 by andi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void display(t_game *game, int *i, int j)
{
	if (game->map[j][*i] == '1')
		display_wall(game);
	if (game->map[j][*i] == 'C')
		display_collectible(game);
	if (game->map[j][*i] == 'P')
		display_character(game);
	*i += 1;
}

void display_game(t_game *game)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (game->map[j])
	{
		while(game->map[j][i])
			display(game, &i, j);
		j++;
		i = 0;
	}
}