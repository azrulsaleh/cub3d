/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azrulsaleh <azrulsaleh@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:11:07 by azrulsaleh        #+#    #+#             */
/*   Updated: 2025/09/01 03:24:34 by azrulsaleh       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

//floor/ceiling rgb
typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

//player position
typedef struct s_player
{
	int		x;
	int		y;
	char	dir;
}	t_player;

//map dimensions
typedef struct s_map
{
	char	**point;
	int		w;
	int		h;
	bool	is_valid;
}	t_map;

//program struct
typedef struct s_cub
{
	char		*no_tex;
	char		*so_tex;
	char		*we_tex;
	char		*ea_tex;
	t_rgb		floor;
	t_rgb		ceiling;
	t_player	player;
	t_map		map;
}	t_cub;

//parse
bool	parsing(t_cub *cub, char **av);

//texture
bool	is_line_texture(char *line);
bool	handle_texture_line(t_cub *cub, char *line);

//color
bool	is_line_color(char *line);
bool	handle_color_line(t_cub *cub, char *line);

//map
int		append_map_line(t_cub *cub, char *line);

//validate
int		validate_map(t_cub *cub);

//player
void	set_player_values(t_cub *cub);

//floodfill
bool validate_closed_map(t_cub *cub, int x, int y);

#endif
