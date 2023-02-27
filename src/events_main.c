/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:51:02 by kvisouth          #+#    #+#             */
/*   Updated: 2023/02/27 17:41:19 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// This function handle the windows closure.
// It's called when we press ESC or the cross or reach the Exit
int	destroy_window(t_game *data)
{
	mlx_destroy_window(data->mlx, data->win);
	free_map(data->map);
	exit(0);
}

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

// This function is called every frame.
// It calls put_ground and put_player to render the frames even if the player
// moves or not.
// These functions are called only if the window is open.
int	render_next_frame(t_game *data)
{
	if (data->win)
	{
		put_ground(data);
		put_player(data);
	}
	return (0);
}

// This function is called when a key is pressed.
int	handle_keypress(int keysym, t_game *data)
{
	if (keysym == XK_Escape)
	{
		destroy_window(data);
	}
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
