/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andi <andi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:54:25 by andi              #+#    #+#             */
/*   Updated: 2024/09/06 13:53:37 by andi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void exit_function(int num)
{
	if (num == 1)
		write(1, "not enough or too many args", 27);
	if (num == 2)
		write(1, "map does not exist", 18);
	if (num == 3)
		write(1, "allocation failed", 17);
	exit(1);
}