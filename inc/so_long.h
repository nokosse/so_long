/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:14:39 by kvisouth          #+#    #+#             */
/*   Updated: 2023/02/27 13:51:28 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <string.h>
# include <stdint.h>
# include <fcntl.h>
# include <limits.h>
# include "../libft/inc/libft.h"
# include "../libft/inc/get_next_line.h"
# include "../libft/inc/ft_printf.h"
# include "../mlx_linux/mlx.h"
# include "X11/X.h"
# include <X11/keysym.h>

typedef struct s_texture
{
	void	*img;
	char	*path;
	int		img_width;
	int		img_height;
}			t_texture;

typedef struct s_goblin
{
	int	x;
	int	y;
	int	coins;
	int	moves;
}			t_goblin;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	int			*map_dim;
	t_goblin	*goblin;
}			t_game;

int		check_map(int ac, char **av);
int		get_map_width(char **path);
int		get_map_height(char **path);
int		*get_dims(int height, int width);
int		check_map_surrounded(char **map);
int		check_map_elements(char **map);
int		check_possible_path(char **map, int *dimensions);
int		check_empty(char **path);
void	err(void);
char	**get_map(char **path);
void	print_map(char **map);
void	free_map(char **map);
void	*window_init(void *mlx, int width, int height);
void	map_init(t_game *game);
void	put_walls(t_game *game);
void	put_ground(t_game *game);
void	put_coins(t_game *game);
void	put_exit(t_game *game);
void	put_player(t_game *game);
int		render_next_frame(t_game *data);
int		handle_keypress(int keysym, t_game *data);
int		handle_keyrelease(int keysym, t_game *data);
void	move_player(int keysym, t_game *game);
int		exit_game(t_game *data);
int		print_moves(t_game *game);

void	get_player_coords(t_game *game);

#endif