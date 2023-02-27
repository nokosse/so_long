/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:16:22 by kvisouth          #+#    #+#             */
/*   Updated: 2023/02/27 13:06:23 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

// et merce pour le poissongue

int	main(int ac, char **av)
{
	t_game	game;

	if (check_map(ac, av) == 0)
		return (0);
	game.map = get_map(av);
	game.mlx = mlx_init();
	game.map_dim = get_dims(get_map_height(av), get_map_width(av) - 1);
	map_init(&game);
	mlx_loop_hook(game.mlx, &render_next_frame, &game);
	mlx_hook(game.win, KeyPress, KeyPressMask, &handle_keypress, &game);
	mlx_hook(game.win, KeyRelease, KeyReleaseMask, &handle_keyrelease, &game);
	mlx_loop(game.mlx);
	free_map(game.map);
	mlx_destroy_display(game.mlx);
	free(game.mlx);
}

// TODO: unit test for maps (rectangular)