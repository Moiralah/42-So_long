# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/20 01:30:16 by huidris           #+#    #+#              #
#    Updated: 2024/11/01 02:01:26 by huidris          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

FLAGS	= -Wall -Wextra -Werror -fsanitize=address -g3 -ggdb

SRC_DIR = src
SRC		= $(wildcard $(SRC_DIR)/*.c)

LIB_DIR	= libft
LIBFT_A	= libft/libft.a

OBJ_DIR	= obj
OBJ		= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

LINKS	= -lft -L libft $(MLX_FLAGS)

# Default target
all: $(NAME)

# Rule to build the executable
$(NAME): $(OBJ) $(LIBFT_A)
	gcc $(FLAGS) $(OBJ) $(LINKS) -o $@

# Rule to build object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	gcc $(FLAGS) -c $< -o $@

$(LIBFT_A):
	make -C $(LIB_DIR)

# Clean rule
clean:
	rm -f $(OBJ)
	rm -rf $(OBJ_DIR)
	make -C $(LIB_DIR) clean
	clear

# Clean rule with target executable
fclean: clean
	rm -f $(NAME)
	make -C $(LIB_DIR) fclean
	clear

# Rebuild rule
re: fclean all

norm:
	norminette
	clear

.PHONY: all, clean, fclean, re, norm
