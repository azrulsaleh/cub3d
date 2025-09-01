/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azrulsaleh <azrulsaleh@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:11:07 by azrulsaleh        #+#    #+#             */
/*   Updated: 2025/08/31 22:07:58 by azrulsaleh       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include "parse.h"
# include "execute.h"
# include "debug.h"
# include "libft.h"

//defines
# define RED	"\033[0;31m"
# define GREEN	"\033[0;32m"
# define YELLOW	"\033[0;33m"
# define BLUE	"\033[0;34m"
# define PINK	"\033[0;35m"
# define CYAN	"\033[0;36m"
# define GREY	"\033[0;37m"
# define RESET	"\033[0m"
# define CLEAR	"\033[2J\033[1;1H"

bool	print_error(char *msg);

#endif
