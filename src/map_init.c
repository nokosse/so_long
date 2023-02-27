/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:06:37 by kvisouth          #+#    #+#             */
/*   Updated: 2023/02/27 19:31:38 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// This function count the number of coins in the map
// and store it in game->coins.
int	count_coins(t_game *game)
{
	int	i;
	int	j;
	int	coins;

	i = 0;
	coins = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				coins++;
			j++;
		}
		i++;
	}
	return (coins);
}

// Initialize game->goblin->x and game->goblin->y
// and coin, and move.
void	goblin_init(t_game *game)
{
	game->goblin = malloc(sizeof(t_goblin));
	if (!game->goblin)
		return ;
	game->goblin->x = 0;
	game->goblin->y = 0;
	game->goblin->moves = 0;
	game->goblin->coins = 0;
}

// map_dim[0] = height
// map_dim[1] = width
void	map_init(t_game *game)
{
	int	height;
	int	width;
	int	coins;

	goblin_init(&*game);
	coins = 0;
	coins = count_coins(&*game);
	height = game->map_dim[0];
	width = game->map_dim[1];
	game->coins = coins;
	game->win = mlx_new_window(game->mlx, width * 64, height * 64, "so_long");
	put_walls(&*game);
	put_ground(&*game);
	put_player(&*game);
	put_coins(&*game);
	put_exit_closed(&*game);
	free(game->map_dim);
	get_player_coords(&*game);
}
