/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andi <andi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 13:17:12 by andi              #+#    #+#             */
/*   Updated: 2024/09/06 13:57:55 by andi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int map_size(int fd)
{
	char buffer;
	int lines;
	
	bite_size = 0;
	lines = 1;
	while (buffer != 0)
	{
		read(fd, &buffer, 1);
		if (buffer == \n)
			lines++;
	}
	close(fd);
	return (lines);
}

void init_map(char **av)
{
	int fd;
	char **map;
	char *line;
	int i;

	i = 0;
	fd = open(av[1], O_RDONLY);
	map = malloc(sizeof(*char) * map_size(fd) + 1);
	if (!map)
		exit_function(3);
	fd = open(av[1], O_RDONLY);
	line = get_next_line;
	while (line)
	{
		map[i++] = line;
		line = get_next_line;
	}
	map[i] = NULL;
	close(fd);
}