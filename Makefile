# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slombard <slombard@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/15 11:03:37 by slombard          #+#    #+#              #
#    Updated: 2023/07/15 12:59:53 by slombard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc 
CFLAGS = -Wall -Wextra -Werror
# MLX42FLAGS = -lglfw -framework Cocoa -framework OpenGL -framework IOKit # for mac
# MLX42FLAGS = -lglfw -framework Cocoa -framework OpenGL -framework IOKit  -L/opt/homebrew/lib # for mac M1
MLX42FLAGS = $(shell pkg-config --libs glfw3) -framework Cocoa -framework OpenGL -framework IOKit
# MLX42FLAGS = -ldl -lglfw -pthread -lm  
LIBFT = ./libft/libft.a
LIBMLX42 = ./MLX42/build/libmlx42.a
INCLUDES = -I./include -I./MLX42/include/MLX42 -I./libft
GREEN   = \033[32;1m
RESET	= \033[0m
MLX42_DIR = ./MLX42
SRC_DIR = src/
OBJ_DIR = objs/

SRCS	:= $(shell find ./src -iname "*.c")

SRC	= $(addprefix $(SRC_DIR), $(SRCS))
OBJ = $(addprefix $(OBJ_DIR), $(notdir $(SRC:.c=.o)))

all:	check_MLX42_dir	$(NAME) 

$(NAME): $(LIBFT) libmlx $(LIBMLX42) $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(LIBMLX42) $(MLX42FLAGS)
	@echo "$(GREEN) Compiled with $(CFLAGS)$(RESET)"

$(LIBFT):
	@$(MAKE) -C ./libft
	@echo "$(GREEN) Libft compiled $(RESET)"

libmlx:
	@cd $(MLX42_DIR) && cmake -B build && cmake --build build -j4
	@echo "$(GREEN) MLX42 built $(RESET)"

check_MLX42_dir:
	@if ! [ -d "$(MLX42_DIR)" ]; then \
	git clone https://github.com/codam-coding-college/MLX42.git $(MLX42_DIR); \
	fi

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $^

clean: 
	@$(MAKE) clean -C ./libft
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN) Cleaned $(RESET)"

fclean: clean
	@$(MAKE) fclean -C ./libft
	@rm -f $(NAME)
	@echo "$(GREEN) Full cleaned $(RESET)"

re:	fclean all

.PHONY: all clean fclean re
