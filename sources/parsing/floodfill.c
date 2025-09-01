/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azrulsaleh <azrulsaleh@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:37:10 by azsaleh           #+#    #+#             */
/*   Updated: 2025/09/01 03:38:09 by azrulsaleh       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//recursive flood fill algorithm to test for map validity
static bool	flood_fill(t_map *map, char **copy, int x, int y)
{
	if (!((*map).is_valid))
		return (1);
	if (y < 0 || y >= (*map).h || x < 0 || x >= (*map).w || copy[y][x] == ' ')
	{
		(*map).is_valid = 0;
		return (print_error("Map failed floodfill test"));
	}
	if (copy[y][x] == '1' || copy[y][x] == 'V')
		return (0);
	copy[y][x] = 'V';
	flood_fill(map, copy, x + 1, y);
	flood_fill(map, copy, x - 1, y);
	flood_fill(map, copy, x, y + 1);
	flood_fill(map, copy, x, y - 1);
	return (0);
}

//make a deep copy of map
static bool	copy_map_for_floodfill(t_map map, char ***copy)
{
	int	i;
	int	j;

	*copy = malloc(sizeof(char *) * map.h);
	if (!(*copy))
		return (print_error("Malloc failed in copy_map_for_floodfill"));
	i = 0;
	while (i < map.h)
	{
		(*copy)[i] = ft_strdup(map.point[i]);
		if (!(*copy)[i++])
		{
			ft_freearray(*copy);
			return (print_error("Failed ft_strdup in copy_map_for_floodfill"));
		}
	}
	return (0);
}

bool	validate_closed_map(t_cub *cub, int x, int y)
{
	char	**copy;

	if (copy_map_for_floodfill(cub->map, &copy))
		return (1);
	flood_fill(&cub->map, copy, x, y);
	debug_floodfill(copy, cub->map.is_valid);
	return (ft_freearray(copy), cub->map.is_valid);
}
