/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:51:02 by kvisouth          #+#    #+#             */
/*   Updated: 2023/02/18 19:22:03 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// This function is called every frame.
// For the test, it will just print the map instead of rendering it.
int	render_next_frame(t_game *data)
{
	print_map(data->map);
	write(1, "\n", 1);
	return (0);
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
