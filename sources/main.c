/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azsaleh <azsaleh@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:37:10 by azsaleh           #+#    #+#             */
/*   Updated: 2025/09/01 15:35:39 by azsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//initialize cub struct
static void	init_cub(t_cub *cub)
{
	cub->tex.no = NULL;
	cub->tex.so = NULL;
	cub->tex.we = NULL;
	cub->tex.ea = NULL;
	cub->bg.floor[0] = 0;
	cub->bg.floor[1] = 0;
	cub->bg.floor[2] = 0;
	cub->bg.ceiling[0] = 0;
	cub->bg.ceiling[1] = 0;
	cub->bg.ceiling[2] = 0;
	cub->player.x = 0;
	cub->player.y = 0;
	cub->player.dir = '\0';
	cub->map.point = NULL;
	cub->map.w = 0;
	cub->map.h = 0;
	cub->map.is_invalid = 0;
}

static void	free_cub(t_cub *cub)
{
	if (cub->tex.no)
		free(cub->tex.no);
	if (cub->tex.so)
		free(cub->tex.so);
	if (cub->tex.we)
		free(cub->tex.we);
	if (cub->tex.ea)
		free(cub->tex.ea);
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
