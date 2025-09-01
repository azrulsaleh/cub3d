/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azrulsaleh <azrulsaleh@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:37:10 by azsaleh           #+#    #+#             */
/*   Updated: 2025/08/31 23:13:32 by azrulsaleh       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//returns 1 if read line is floor or ceiling color
bool	is_line_color(char *line)
{
	if (line[0] == 'F' || line[0] == 'C')
		return (1);
	return (0);
}

//parses and stores color info into r, g and b components
static int	parse_rgb(char *rgb, t_rgb *color)
{
	char	**split;
	int		i;

	split = ft_split(rgb, ',');
	i = 0;
	while (split && split[i])
		i++;
	if (i != 3)
		return (ft_freearray(split), 1);
	color->r = ft_atoi(split[0]);
	color->g = ft_atoi(split[1]);
	color->b = ft_atoi(split[2]);
	if (color->r < 0 || color->r > 255 || color->g < 0 || color->g > 255
		|| color->b < 0 || color->b > 255)
		return (ft_freearray(split), 1);
	return (0);
}

//handler to get color to ceiling and floor information
bool	handle_color_line(t_cub *cub, char *line)
{
	char	*rgb;
	int		status;

	rgb = ft_strtrim(line + 1, " \t\n");
	if (!rgb)
		return (print_error("Failed ft_strtrim in handle_color_line"));
	if (line[0] == 'F')
		status = parse_rgb(rgb, &cub->floor);
	else
		status = parse_rgb(rgb, &cub->ceiling);
	if (status)
		print_error("Failed color validation");
	free(rgb);
	return (status);
}
