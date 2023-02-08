# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 12:36:43 by kvisouth          #+#    #+#              #
#    Updated: 2023/02/08 10:44:52 by kvisouth         ###   ########.fr        #
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
	@$(MAKE) $(NAME)

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
	make -C mlx_linux

clean:
	@rm -rf obj 
	@make -C libft clean
	@make -C mlx_linux clean
fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all