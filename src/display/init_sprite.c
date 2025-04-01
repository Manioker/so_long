/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvacca <anvacca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 09:21:05 by anvacca           #+#    #+#             */
/*   Updated: 2024/10/09 09:39:11 by anvacca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	init_sprite(t_game *game)
{
	int	size;

	size = BLOCK;
	game->mlx.wall = mlx_xpm_file_to_image(game->mlx.mlx_con, WALL, &size,
			&size);
	if (!game->mlx.wall)
		exit_function(6);
	game->mlx.floor = mlx_xpm_file_to_image(game->mlx.mlx_con, FLOOR, &size,
			&size);
	if (!game->mlx.floor)
		exit_function(6);
	game->mlx.collectible = mlx_xpm_file_to_image(game->mlx.mlx_con,
			COLLECTIBLE, &size, &size);
	if (!game->mlx.collectible)
		exit_function(6);
	game->mlx.player = mlx_xpm_file_to_image(game->mlx.mlx_con, PLAYER, &size,
			&size);
	if (!game->mlx.player)
		exit_function(6);
	game->mlx.exit = mlx_xpm_file_to_image(game->mlx.mlx_con, EXIT, &size,
			&size);
	if (!game->mlx.exit)
		exit_function(6);
}
