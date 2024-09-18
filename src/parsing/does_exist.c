/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   does_exist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvacca <anvacca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:02:06 by andi              #+#    #+#             */
/*   Updated: 2024/09/18 10:41:53 by anvacca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	does_exist(int ac, char **av)
{
	if (ac != 2)
		exit_function(1);
	if (ft_strcmp(av[1] + ft_strlen(av[1] - 4), ".ber") != 0)
		exit_function(2);
}
