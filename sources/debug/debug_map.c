/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azsaleh <azsaleh@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:37:10 by azsaleh           #+#    #+#             */
/*   Updated: 2025/09/01 17:54:42 by azsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map_values(t_map map)
{
	printf("map width: ");
	printf(GREEN "%d\n" RESET, map.w);
	printf("map height: ");
	printf(GREEN "%d\n\n" RESET, map.h);
}

//print boundaries and map content
void	debug_map_optimized(t_map map)
{
	int	y;
	int	x;

	if (!map.point || !map.point[0])
		return ;
	printf("\nmap (optimized)\n");
	y = 0;
	while (map.point[y])
	{
		x = 0;
		while (map.point[y][x])
		{
			if (map.point[y][x] == '1')
				printf(GREEN "%c" RESET, map.point[y][x]);
			else if (map.point[y][x] == '0')
				printf(BLUE "%c" RESET, map.point[y][x]);
			else if (map.point[y][x] == ' ')
				printf(BLUE "." RESET);
			else
				printf(YELLOW "%c" RESET, map.point[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}

//print boundaries and map content
void	debug_map_floodfill(bool debug_mode, char **map, bool is_invalid)
{
	int	y;
	int	x;

	if (!map || !map[0] || !debug_mode)
		return ;
	printf("\nmap (floodfill)\n");
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				printf(GREEN "%c" RESET, map[y][x]);
			else if (map[y][x] == '0')
				printf(BLUE "%c" RESET, map[y][x]);
			else if (is_invalid)
				printf(RED "%c" RESET, map[y][x]);
			else if (map[y][x] == '.' || map[y][x] == ' ')
				printf(YELLOW "%c" RESET, map[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}

//print boundaries and map content
void	debug_map_final(t_cub *cub)
{
	int	y;
	int	x;

	if (!cub->map.point || !cub->map.point[0] || !cub->debug_mode)
		return ;
	printf("\nmap (final)\n");
	y = 0;
	while (cub->map.point[y])
	{
		x = 0;
		while (cub->map.point[y][x])
		{
			if (cub->map.point[y][x] == '1')
				printf(GREEN "%c" RESET, cub->map.point[y][x]);
			else if (cub->map.point[y][x] == '0')
				printf(BLUE "%c" RESET, cub->map.point[y][x]);
			else
				printf("%c", cub->map.point[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}
