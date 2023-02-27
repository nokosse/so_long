/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:51:02 by kvisouth          #+#    #+#             */
/*   Updated: 2023/02/27 13:48:23 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// This function will print the number of moves the player has made in total.
// We have to use a static variable to keep track of the number of moves.
int	print_moves(t_game *game)
{
	static int	moves;

	if (game->goblin->moves > moves)
	{
		moves = game->goblin->moves;
		ft_putnbr_fd(moves, 1);
		write(1, "\n", 1);
	}
	return (0);
}

// This function is called when the player reach the exit.
int	exit_game(t_game *data)
{
	mlx_destroy_window(data->mlx, data->win);
	return (0);
}

// This function is called every frame.
// For the test, it will just print the map instead of rendering it.
int	render_next_frame(t_game *data)
{
	put_ground(&*data);
	put_coins(&*data);
	put_player(&*data);
	return (0);
	(void)data;
}

// This function is called when a key is pressed.
int	handle_keypress(int keysym, t_game *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx, data->win);
	if (keysym == XK_w || keysym == XK_a || keysym == XK_s || keysym == XK_d
		|| keysym == XK_Up || keysym == XK_Down || keysym == XK_Left
		|| keysym == XK_Right)
		move_player(keysym, data);
	return (0);
}

// This function is called when a key is released.
int	handle_keyrelease(int keysym, t_game *data)
{
	return (0);
	(void)data;
	(void)keysym;
}
