/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvacca <anvacca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:54:25 by andi              #+#    #+#             */
/*   Updated: 2024/09/10 10:06:55 by anvacca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void exit_function(int num)
{
	if (num == 1)
		write(1, "not enough or too many args", 27);
	if (num == 2)
		write(1, "map does not exist", 18);
	if (num == 3)
		write(1, "allocation failed", 17);
	if (num == 3)
		write(1, "incorrect map", 13);
	exit(1);
}
