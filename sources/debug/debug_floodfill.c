/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_floodfill.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azrulsaleh <azrulsaleh@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:37:10 by azsaleh           #+#    #+#             */
/*   Updated: 2025/09/01 03:38:54 by azrulsaleh       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//print boundaries and map content
void	debug_floodfill(char **map, bool is_valid)
{
	int	x;
	int	y;

	if (map && map[0])
	{
		x = 0;
		while (map[x])
		{
			y = 0;
			while (map[x][y])
			{
				if (map[x][y] == '1')
					printf(GREEN "%c" RESET, map[x][y]);
				else if (map[x][y] == '0')
					printf(BLUE "%c" RESET, map[x][y]);
				else if (map[x][y] == ' ')
					printf(BLUE "." RESET);
				else if (is_valid)
					printf(YELLOW "%c" RESET, map[x][y]);
				else
					printf(RED "%c" RESET, map[x][y]);
				y++;
			}
			printf("\n");
			x++;
		}
	}
}
