/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azsaleh <azsaleh@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:11:07 by azrulsaleh        #+#    #+#             */
/*   Updated: 2025/09/02 13:42:35 by azsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

typedef struct s_tex
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}	t_tex;

//floor/ceiling color
typedef struct s_bg
{
	int	floor[3];
	int	ceiling[3];
}	t_bg;

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
	bool	is_invalid;
}	t_map;

//program struct
typedef struct s_cub
{
	t_tex		tex;
	t_bg		bg;
	t_player	player;
	t_map		map;
	bool		debug_mode;
}	t_cub;

//parse
bool	parsing(t_cub *cub, char **av);
bool	check_extension(const char *file, const char *ext);

//texture
bool	is_line_texture(char *line);
bool	handle_texture_line(t_cub *cub, char *line);

//bg
bool	is_line_bg(char *line);
bool	handle_bg_line(t_cub *cub, char *line);
bool	validate_bg(t_bg bg);

//map
int		append_map_line(t_cub *cub, char *line);

//validate
int		validate_map(t_cub *cub);

//player
void	set_player_values(t_cub *cub);

//floodfill
bool	validate_closed_map(t_cub *cub, int y, int x);

#endif
