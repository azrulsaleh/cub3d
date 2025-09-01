/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azsaleh <azsaleh@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:11:07 by azrulsaleh        #+#    #+#             */
/*   Updated: 2025/09/01 17:53:51 by azsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

//debug
void	debug_struct(t_cub *cub);

//debug_map
void	print_map_values(t_map map);
void	debug_map_optimized(t_map map);
void	debug_map_floodfill(bool debug_mode, char **map, bool is_invalid);
void	debug_map_final(t_cub *cub);

#endif
