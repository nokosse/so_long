# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 12:36:43 by kvisouth          #+#    #+#              #
#    Updated: 2023/02/07 18:51:12 by kvisouth         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# See how I compiled libft ?
# I used the same method to compile mlx.
# I do 'make' in the mlx_linux folder and it creates a libmlx.a file.
# I then link libmlx.a to my program.
# And I compile my programe with a few more flags : -lXext -lX11 -lm

NAME = so_long
SRCS = 

OBJS = $(SRCS:src/%.c=obj/%.o) obj/main.o
HEADERS = inc/so_long.h
LIBFT = libft/libft.a
CFLAGS = -Wall -Wextra -Werror
CC = gcc
MLX_FLAGS = -lXext -lX11 -lm
MLX_FILE = mlx_linux/libmlx.a

all:
	@echo -n "\033[31m\nCompiling...\033[0m"
	@$(MAKE) $(NAME) > /dev/null && echo -en "\r\033[32mCompiled succesfully !!\033[0m\n"

$(NAME): $(OBJS) $(HEADERS) $(LIBFT) $(MLX_FILE)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX_FILE) $(MLX_FLAGS)

obj/%.o: src/%.c $(HEADERS)
	mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@

obj/main.o: main.c $(HEADERS)
	mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C libft

$(MLX_FILE):
	make -C mlx_linux > /dev/null 2>&1

clean:
	@rm -rf obj 2> /dev/null || true
	@make -C libft clean > /dev/null 2>&1 || true
	@make -C mlx_linux clean > /dev/null 2>&1 || true

fclean: clean
	@echo "\033[32m\nDeleting files\n\033[0m"
	@rm -f $(NAME) 2> /dev/null
	@make -C libft fclean > /dev/null 2>&1

re: fclean all