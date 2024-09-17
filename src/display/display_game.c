/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvacca <anvacca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:29:25 by andi              #+#    #+#             */
/*   Updated: 2024/09/17 13:28:17 by anvacca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	display(t_game *game, int j, int *i)
{
	if (game->map[j][*i] == '1')
		mlx_put_image_to_window(game->mlx.mlx_con, game->mlx.mlx_window,
			game->mlx.wall, *i * BLOCK, j * BLOCK);
	if (game->map[j][*i] == '0')
		mlx_put_image_to_window(game->mlx.mlx_con, game->mlx.mlx_window,
			game->mlx.floor, *i * BLOCK, j * BLOCK);
	if (game->map[j][*i] == 'C') 
		mlx_put_image_to_window(game->mlx.mlx_con, game->mlx.mlx_window,
			game->mlx.collectible, *i * BLOCK, j * BLOCK);
	if (game->map[j][*i] == 'P')
		mlx_put_image_to_window(game->mlx.mlx_con, game->mlx.mlx_window,
			game->mlx.player, *i * BLOCK, j * BLOCK);
	if (game->map[j][*i] == 'E')
		mlx_put_image_to_window(game->mlx.mlx_con, game->mlx.mlx_window,
			game->mlx.exit, *i * BLOCK, j * BLOCK);
	*i += 1;
}

void	display_game(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[j])
	{
		while (game->map[j][i])
			display(game, j, &i);
		j++;
		i = 0;
	}
}
