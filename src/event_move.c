/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:14:21 by kvisouth          #+#    #+#             */
/*   Updated: 2023/02/27 13:46:29 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// Swap 'P' with '0' and '0' with 'P' upwards.
// Do nothing it there is a '1' or 'E' upwards.
void	move_up(t_game *game)
{
	int	x;
	int	y;

	x = game->goblin->x;
	y = game->goblin->y;
	if (game->map[y - 1][x] == '0')
	{
		game->map[y - 1][x] = 'P';
		game->map[y][x] = '0';
		game->goblin->y--;
		game->goblin->moves++;
	}
	else if (game->map[y - 1][x] == 'C')
	{
		game->map[y - 1][x] = 'P';
		game->map[y][x] = '0';
		game->goblin->y--;
		game->goblin->coins++;
		game->goblin->moves++;
	}
	else if (game->map[y - 1][x] == 'E')
		exit_game(game);
}

// Same but to the left.
void	move_left(t_game *game)
{
	int	x;
	int	y;

	x = game->goblin->x;
	y = game->goblin->y;
	if (game->map[y][x - 1] == '0')
	{
		game->map[y][x - 1] = 'P';
		game->map[y][x] = '0';
		game->goblin->x--;
		game->goblin->moves++;
	}
	else if (game->map[y][x - 1] == 'C')
	{
		game->map[y][x - 1] = 'P';
		game->map[y][x] = '0';
		game->goblin->x--;
		game->goblin->coins++;
		game->goblin->moves++;
	}
	else if (game->map[y][x - 1] == 'E')
		exit_game(game);
}

// Same but downwards.
void	move_down(t_game *game)
{
	int	x;
	int	y;

	x = game->goblin->x;
	y = game->goblin->y;
	if (game->map[y + 1][x] == '0')
	{
		game->map[y + 1][x] = 'P';
		game->map[y][x] = '0';
		game->goblin->y++;
		game->goblin->moves++;
	}
	else if (game->map[y + 1][x] == 'C')
	{
		game->map[y + 1][x] = 'P';
		game->map[y][x] = '0';
		game->goblin->y++;
		game->goblin->coins++;
		game->goblin->moves++;
	}
	else if (game->map[y + 1][x] == 'E')
		exit_game(game);
}

// Same but to the right.
void	move_right(t_game *game)
{
	int	x;
	int	y;

	x = game->goblin->x;
	y = game->goblin->y;
	if (game->map[y][x + 1] == '0')
	{
		game->map[y][x + 1] = 'P';
		game->map[y][x] = '0';
		game->goblin->x++;
		game->goblin->moves++;
	}
	else if (game->map[y][x + 1] == 'C')
	{
		game->map[y][x + 1] = 'P';
		game->map[y][x] = '0';
		game->goblin->x++;
		game->goblin->coins++;
		game->goblin->moves++;
	}
	else if (game->map[y][x + 1] == 'E')
		exit_game(game);
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
	print_moves(game);
	(void)game;
}
