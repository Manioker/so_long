/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvacca <anvacca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 08:11:47 by anvacca           #+#    #+#             */
/*   Updated: 2024/09/17 13:51:59 by anvacca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	floodfill(t_game *game);

void	free_map_copy(t_game *game)
{
	int	i;

	i = 0;
	while (game->map_copy[i])
	{
		free(game->map_copy[i]);
		i++;
	}
	free(game->map_copy);
}

static void	mapcopy_alloc(t_game *game, int size)
{
	int	i;

	i = 0;
	game->map_copy = (char **)malloc(sizeof(char *) * (size + 1));
	if (!game->map_copy)
		exit_function(3);
	while (i < size)
	{
		game->map_copy[i] = ft_strdup(game->map[i]);
		if (!game->map_copy[i])
			exit_function(4);
		i++;
	}
	game->map_copy[i] = NULL;
}

static void	used_char(t_game *game, int j, int i)
{
	if (game->map[j][i] == 'C')
		game->count.C--;
	if (game->map[j][i] == 'E')
		game->count.E--;
	game->map_copy[game->pos.Py][game->pos.Px] = '1';
	floodfill(game);
}

static void	floodfill(t_game *game)
{
	if (game->map_copy[game->pos.Py][game->pos.Px + 1] != '1')
	{
		used_char(game, game->pos.Py, game->pos.Px++);
		game->pos.Px--;
	}
	else if (game->map_copy[game->pos.Py + 1][game->pos.Px] != '1')
	{
		used_char(game, game->pos.Py++, game->pos.Px);
		game->pos.Py--;
	}
	else if (game->map_copy[game->pos.Py][game->pos.Px - 1] != '1')
	{
		used_char(game, game->pos.Py, game->pos.Px--);
		game->pos.Px++;
	}
	else if (game->map_copy[game->pos.Py - 1][game->pos.Px] != '1')
	{
		used_char(game, game->pos.Py--, game->pos.Px);
		game->pos.Py++;
	}
	else
		return ;
	floodfill(game);
}

void	floodfill_algo(t_game *game)
{
	mapcopy_alloc(game, game->map_height);
	floodfill(game);
	free_map_copy(game);
}
