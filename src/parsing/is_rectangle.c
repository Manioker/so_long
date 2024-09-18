/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rectangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvacca <anvacca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 09:32:11 by anvacca           #+#    #+#             */
/*   Updated: 2024/09/18 10:42:05 by anvacca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	is_rectangle(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i + 1])
	{
		if (ft_strlen(game->map[i]) != ft_strlen(game->map[i + 1]))
		{
			free_map(game);
			exit_function(4);
		}
		i++;
	}
}
