/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvacca <anvacca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:54:25 by andi              #+#    #+#             */
/*   Updated: 2024/10/09 14:17:03 by anvacca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	exit_function(int num)
{
	if (num == 1)
		write(1, "not enough or too many args\n", 28);
	if (num == 2)
		write(1, "map does not exist\n", 19);
	if (num == 3)
		write(1, "allocation failed\n", 18);
	if (num == 4)
		write(1, "incorrect map\n", 14);
	if (num == 5)
		write(1, "failed window\n", 14);
	if (num == 6)
		write(1, "tsk tsk tsk...\n", 15);
	exit(1);
}
