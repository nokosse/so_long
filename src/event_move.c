/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:14:21 by kvisouth          #+#    #+#             */
/*   Updated: 2023/02/18 19:10:34 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// What the functions below will basically do is :
// 1. Check if the player is able to move in the direction.
//    He can only be blocked by a wall ('1'). If he is blocked, the player
//    will not move.
// 2. If the player is not blocked, he will move in the direction.
//
// The coordinates of the player are located at game.goblin.x or y.
// The move of the player will be done by changing the position of the player
// on game.map the character 'P' will be replaced by a '0' and the new position
// will be replaced by a 'P'.
// Then we will need to redraw the map according to the changes made to the map.
// Using map_init() will do the trick.

void	move_up(t_game *game)
{
	printf("fonction pour bouger en haut\n");
	(void)game;
}

void	move_left(t_game *game)
{
	printf("fonction pour bouger à gauche\n");
	(void)game;
}

void	move_down(t_game *game)
{
	printf("fonction pour bouger en bas\n");
	(void)game;
}

void	move_right(t_game *game)
{
	printf("fonction pour bouger à droite\n");
	(void)game;
}

// This function is called when the keys W, A, S or D are pressed.
// Or when the arrow keys are pressed.
void	move_player(int keysym, t_game *game)
{
	if (keysym == XK_w || keysym == XK_Up)
		move_up(game);
	if (keysym == XK_a || keysym == XK_Left)
		move_left(game);
	if (keysym == XK_s || keysym == XK_Down)
		move_down(game);
	if (keysym == XK_d || keysym == XK_Right)
		move_right(game);
	(void)game;
}
