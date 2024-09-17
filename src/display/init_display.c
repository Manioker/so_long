/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvacca <anvacca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:05:03 by anvacca           #+#    #+#             */
/*   Updated: 2024/09/17 13:13:39 by anvacca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	init_display(t_game *game)
{
	game->mlx.mlx_con = mlx_init();
	game->mlx.mlx_window = mlx_new_window(game->mlx.mlx_con,
		game->map_width * BLOCK, game->map_height * BLOCK, "anvacca's so_long");
	if (!game->mlx.mlx_window)
		exit_function(5);
}
