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
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
				return (j);
			j++;
		}
		i++;
	}
	return (-1);
}

int	get_player_y(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
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
