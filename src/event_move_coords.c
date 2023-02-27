/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_move_coords.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:51:53 by marvin            #+#    #+#             */
/*   Updated: 2023/02/20 09:51:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// This function will get the coordinates of the player on the map.
// The coordinates of the player are located at game.goblin.x or y.
// The coordinates of the player is P on maps.
// The coordinates 0, 0 are map[0][0] on the array.
// The coordinates at the right of 0, 0 are map[0][1]
int	get_player_x(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map[y])
	{
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
				return (x);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int	get_player_y(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map[y])
	{
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
				return (y);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

void	get_player_coords(t_game *game)
{
	int	x;
	int	y;

	x = get_player_x(game);
	y = get_player_y(game);
	game->goblin->x = x;
	game->goblin->y = y;
}
