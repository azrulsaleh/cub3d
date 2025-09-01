/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azrulsaleh <azrulsaleh@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:37:10 by azsaleh           #+#    #+#             */
/*   Updated: 2025/09/01 01:46:45 by azrulsaleh       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//print north, south, west and east texture paths
static void	print_textures(t_cub *cub)
{
	if (cub->no_tex != NULL)
		printf("no_tex: %s\n", cub->no_tex);
	else
		printf("no_tex: NULL\n");
	if (cub->so_tex)
		printf("so_tex: %s\n", cub->so_tex);
	else
		printf("so_tex: NULL\n");
	if (cub->we_tex)
		printf("we_tex: %s\n", cub->we_tex);
	else
		printf("we_tex: NULL\n");
	if (cub->ea_tex)
		printf("ea_tex: %s\n\n", cub->ea_tex);
	else
		printf("ea_tex: NULL\n\n");
}

//print floor and ceiling color values
static void	print_planes(t_cub *cub)
{
	printf("floor: %d,%d,%d\n", cub->floor.r, cub->floor.g, cub->floor.b);
	printf("ceiling: %d,%d,%d\n\n",
		cub->ceiling.r, cub->ceiling.g, cub->ceiling.b);
}

//print boundaries and map content
static void	print_map(t_map map)
{
	int	x;
	int	y;

	if (map.point && map.point[0])
	{
		x = 0;
		while (map.point[x])
		{
			y = 0;
			while (map.point[x][y])
			{
				if (map.point[x][y] == '1')
					printf(GREEN "%c" RESET, map.point[x][y]);
				else if (map.point[x][y] == '0')
					printf(BLUE "%c" RESET, map.point[x][y]);
				else if (map.point[x][y] == ' ')
					printf(BLUE "." RESET);
				else
					printf(YELLOW "%c" RESET, map.point[x][y]);
				y++;
			}
			printf("\n");
			x++;
		}
	}
}

static void	print_player(t_player player)
{
	printf("player position: %d,%d\n", player.x, player.y);
	printf("player direction: %c\n", player.dir);
}

//handler to show content to the main struct
void	debug_struct(t_cub *cub)
{
	printf(GREEN "\n");
	print_textures(cub);
	print_planes(cub);
	printf("" RESET);
	print_map(cub->map);
	printf(GREEN "\nmap width: %d\n", cub->map.w);
	printf("map height: %d\n\n", cub->map.h);
	print_player(cub->player);
	printf(RESET);
}
