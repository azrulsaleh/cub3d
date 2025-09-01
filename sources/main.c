/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azrulsaleh <azrulsaleh@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:37:10 by azsaleh           #+#    #+#             */
/*   Updated: 2025/09/01 03:24:48 by azrulsaleh       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//initialize cub struct
static void	init_cub(t_cub *cub)
{
	cub->no_tex = NULL;
	cub->so_tex = NULL;
	cub->we_tex = NULL;
	cub->ea_tex = NULL;
	cub->floor.r = 0;
	cub->floor.g = 0;
	cub->floor.b = 0;
	cub->ceiling.r = 0;
	cub->ceiling.g = 0;
	cub->ceiling.b = 0;
	cub->player.x = 0;
	cub->player.y = 0;
	cub->player.dir = '\0';
	cub->map.point = NULL;
	cub->map.w = 0;
	cub->map.h = 0;
	cub->map.is_valid = 1;
}

static void	free_cub(t_cub *cub)
{
	if (cub->no_tex)
		free(cub->no_tex);
	if (cub->so_tex)
		free(cub->so_tex);
	if (cub->we_tex)
		free(cub->we_tex);
	if (cub->ea_tex)
		free(cub->ea_tex);
	ft_freearray(cub->map.point);
}

//prints colored error message and returns status 1
bool	print_error(char *msg)
{
	printf(RED "Error\n%s\n" RESET, msg);
	return (1);
}

//remove show_parsed_map_content() before eval
int	main(int ac, char **av)
{
	t_cub	cub;

	if (ac != 2)
		return (print_error("Usage ./cub3d map/*.cub"));
	init_cub(&cub);
	if (parsing(&cub, av))
		return (1);
	while (1)
		if (executing(&cub))
			break ;
	free_cub(&cub);
	return (0);
}
