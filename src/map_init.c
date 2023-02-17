/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:06:37 by kvisouth          #+#    #+#             */
/*   Updated: 2023/02/17 17:05:07 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// map_dim[0] = height
// map_dim[1] = width
void	map_init(t_game game)
{
	int	height;
	int	width;

	height = game.map_dim[0];
	width = game.map_dim[1];
	game.mlx_win = mlx_new_window(game.mlx, width * 64, height * 64, "so_long");
	put_walls(game);
	put_ground(game);
	put_player(game);
	put_coins(game);
	put_exit(game);
}
