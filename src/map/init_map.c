/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvacca <anvacca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 13:17:12 by andi              #+#    #+#             */
/*   Updated: 2024/09/17 10:36:45 by anvacca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	map_size(int fd)
{
	char	buffer;
	int		lines;
	int		end;

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

void	init_map(char **av, t_game *game)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(av[1], O_RDONLY);
	game->map_height = map_size(fd);
	game->map = malloc(sizeof(char *) * (game->map_height + 1));
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
	game->map_width = ft_strlen(game->map[1]);
	close(fd);
}
