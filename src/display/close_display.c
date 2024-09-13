/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andi <andi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 09:05:50 by andi              #+#    #+#             */
/*   Updated: 2024/09/13 09:37:52 by andi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int close_display(t_game *game)
{
	mlx_destroy_window(game->mlx.mlx_con, game->mlx.mlx_window);
	free(game->mlx.mlx_con);
	free_map(game->map);
	free_map(game->map_copy);
	free(game);
	exit(0);
}