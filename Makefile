# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azrulsaleh <azrulsaleh@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/10 15:54:12 by azsaleh           #+#    #+#              #
#    Updated: 2025/08/31 17:41:47 by azrulsaleh       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = cc
FLAG = -g
# FLAG = -Wall -Wextra -Werror -g
INC_DIR = includes
SRC_DIR = sources
SRCS = $(wildcard $(SRC_DIR)/*.c $(SRC_DIR)/*/*.c)
OBJ_DIR = objects
# OBJS = $(addprefix $(OBJ_DIR)/, $(OBJ_FILE))
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
RM = rm -f -r
LIB = -Llibft -lft -Lminilibx-macos -lmlx -framework OpenGL -framework AppKit
# LIB = -Llibft -lft -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

#default rule
all: $(NAME)

#compile .o files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(FLAG) -I$(INC_DIR) -Ilibft/includes -Iminilibx-macos -c $< -o $@
# 	$(CC) $(FLAG) -I$(INC_DIR) -Ilibft/includes -Iminilibx-linux -c $< -o $@

#create binary
$(NAME): $(OBJS)
	@make -C libft
	@make -C minilibx-macos
	$(CC) $(FLAG) $(OBJS) $(LIB) -o $(NAME)
# 	@make -C minilibx-linux

#utility targets
libft:
	make -C libft
minilibx:
	make -C minilibx
clean:
	make clean -C libft
	make clean -C minilibx-macos
	$(RM) $(OBJ_DIR)
# 	make clean -C minilibx-linux
fclean: clean
	make fclean -C libft
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re