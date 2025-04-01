/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvacca <anvacca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 08:11:47 by anvacca           #+#    #+#             */
/*   Updated: 2024/10/11 11:19:53 by anvacca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static	void	floodfill(t_game *game, int x, int y);

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

static	void	floodfill(t_game *game, int x, int y)
{
	if (game->map_copy[y][x] == 'C')
		game->count.c--;
	if (game->map_copy[y][x] == 'E')
		game->count.e--;
	if (game->map_copy[y][x] == '1' || game->map_copy[y][x] == 'E')
	{
		game->map_copy[y][x] = '1';
		return ;
	}
	game->map_copy[y][x] = '1';
	floodfill(game, x + 1, y);
	floodfill(game, x - 1, y);
	floodfill(game, x, y + 1);
	floodfill(game, x, y - 1);
}

void	floodfill_algo(t_game *game)
{
	int	x;
	int	y;

	x = game->pos.px;
	y = game->pos.py;
	mapcopy_alloc(game, game->map_height);
	floodfill(game, x, y);
	if (game->count.e != 0 || game->count.c != 0)
		exit_function(4);
	free_map_copy(game);
}
