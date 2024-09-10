/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvacca <anvacca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 13:17:12 by andi              #+#    #+#             */
/*   Updated: 2024/09/10 11:48:56 by anvacca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int map_size(int fd)
{
	char buffer;
	int lines;
	
	lines = 1;
	buffer = 'a';
	while (buffer != 0)
	{
		read(fd, &buffer, 1);
		if (buffer == '\n')
			lines++;
	}
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
	game->map = malloc(sizeof(char*) * map_size(fd) + 1);
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
	close(fd);
}
