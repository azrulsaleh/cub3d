/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azrulsaleh <azrulsaleh@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 01:04:10 by azsaleh           #+#    #+#             */
/*   Updated: 2025/09/01 00:24:52 by azrulsaleh       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//ensures that all characters in map is valid
static int	validate_map_chars(char **map)
{
	int		x;
	int		y;
	int		pos;
	char	c;

	pos = 0;
	x = 0;
	while (map && map[x])
	{
		y = 0;
		c = map[x][y];
		while (c)
		{
			if (c != 'N' && c != 'S' && c != 'E' && c != 'W'
				&& c != '0' && c != '1' && c != ' ')
				return (print_error("Invalid character in map"));
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
				pos++;
			c = map[x][y++];
		}
		x++;
	}
	if (pos != 1)
		return (print_error("Invalid player position in map"));
	return (0);
}

//gets number of valid characters in read line
static int	get_line_width(char **map, int x)
{
	int	idx;
	int	y;

	idx = 0;
	y = 0;
	while (map[x][y])
	{
		if (map[x][y] != ' ')
			idx = y;
		y++;
	}
	return (idx + 1);
}

//stores map's width and height and returns minimum index to valid map point
static int	get_map_dimensions(t_cub *cub)
{
	int	idx;
	int	start;
	int	y;

	idx = 0;
	start = INT_MAX;
	while (cub->map.point[cub->map.h])
	{
		idx = get_line_width(cub->map.point, cub->map.h);
		if (idx > cub->map.w)
			cub->map.w = idx;
		y = 0;
		while (cub->map.point[cub->map.h][y] == ' '
			|| cub->map.point[cub->map.h][y] == '\t')
			y++;
		if (y < start)
			start = y;
		cub->map.h++;
	}
	cub->map.w -= start;
	return (start);
}

//fills in map lines with spaces when line is less than map's width
static int	make_map_rectangular(t_cub *cub, int start)
{
	char	*line;
	int		x;
	int		len;

	x = 0;
	while (x < cub->map.h)
	{
		line = malloc(cub->map.w + 1);
		if (!line)
			return (print_error("Malloc failed in make_map_rectangular"));
		len = get_line_width(cub->map.point, x);
		ft_memset(line, ' ', cub->map.w);
		line[cub->map.w] = '\0';
		ft_memcpy_rng(line, cub->map.point[x], start, len - start);
		free(cub->map.point[x]);
		cub->map.point[x] = line;
		x++;
	}
	return (0);
}

//ensure that map is optimal through validation and adjusting its content
int	validate_map(t_cub *cub)
{
	int	start;

	if (validate_map_chars(cub->map.point))
		return (1);
	start = get_map_dimensions(cub);
	if (make_map_rectangular(cub, start))
		return (1);
	return (0);
}
