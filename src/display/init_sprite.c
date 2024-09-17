/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvacca <anvacca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 09:21:05 by anvacca           #+#    #+#             */
/*   Updated: 2024/09/17 13:48:22 by anvacca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	init_sprite(t_game *game)
{
	int size;

	size = BLOCK;
	game->mlx.wall = mlx_xpm_file_to_image(game->mlx.mlx_con, WALL,
			&size, &size);
	game->mlx.floor = mlx_xpm_file_to_image(game->mlx.mlx_con, FLOOR,
			&size, &size);
	game->mlx.collectible = mlx_xpm_file_to_image(game->mlx.mlx_con, COLLECTIBLE,
			&size, &size);
	game->mlx.player = mlx_xpm_file_to_image(game->mlx.mlx_con, PLAYER,
			&size, &size);
	game->mlx.exit = mlx_xpm_file_to_image(game->mlx.mlx_con, EXIT,
			&size, &size);
}
