/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andi <andi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 13:17:12 by andi              #+#    #+#             */
/*   Updated: 2024/09/13 11:16:14 by andi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

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

int map_size(int fd)
{
	char buffer;
	int lines;
	int end;
	
	lines = 0;
	buffer = 0;
	end = 1;
	while (end > 0)
	{
		end = read(fd, &buffer, 1);
		if (buffer == '\n')
			lines++;
	}
	if (buffer == '\n' && end == 0)
		lines--;
	close(fd);
	return (lines);
}

void init_map(char **av, t_game *game)
{
	int fd;
	char *line;
	int i;

	i = 0;
	fd = open(av[1], O_RDONLY);
	game->map_height = map_game->map_height(fd);
	game->map = malloc(sizeofof(char*) * (game->map_height + 1));
	if (!game->map)
		exit_function(3);
	fd = open(av[1], O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		game->map[i++] = line;
		line = get_next_line(fd);
	}
	game->map[i] = NULL;
	mapcopy_alloc(game, game->map_height);
	close(fd);
}
