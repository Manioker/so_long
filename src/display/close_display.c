/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvacca <anvacca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 09:05:50 by andi              #+#    #+#             */
/*   Updated: 2024/09/17 13:47:26 by anvacca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int close_display(t_game *game)
{
	mlx_destroy_image(game->mlx.mlx_con, game->mlx.wall);
	mlx_destroy_image(game->mlx.mlx_con, game->mlx.floor);
	mlx_destroy_image(game->mlx.mlx_con, game->mlx.player);
	mlx_destroy_image(game->mlx.mlx_con, game->mlx.collectible);
	mlx_destroy_image(game->mlx.mlx_con, game->mlx.exit);
	mlx_destroy_window(game->mlx.mlx_con, game->mlx.mlx_window);
	free(game->mlx.mlx_con);
	free_map(game);
	free(game);
	exit(0);
}
