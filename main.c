/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:16:22 by kvisouth          #+#    #+#             */
/*   Updated: 2023/02/17 15:29:08 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

/* If you want to check the parsing, go to src/parsing.c and read comments */

int	main(int ac, char **av)
{
	void	*img;
	char	*relative_path = "./assets/wall64.xpm";
	int		img_width;
	int		img_height;
	t_game	game;


	if (check_map(ac, av) == 0)
		return (0);
	game.map = get_map(av);
	game.mlx = mlx_init();
	game.map_dim = get_dims(get_map_height(av), get_map_width(av) - 1);
	// game.mlx_win = window_init(game.mlx, game.map_dim[1], game.map_dim[0]);
	// map_init(game);
	// print_map(game.map);
	game.mlx_win = mlx_new_window(game.mlx, game.map_dim[1] * 64, game.map_dim[0] * 64, "so_long");
	img = mlx_xpm_file_to_image(game.mlx, relative_path, &img_width, &img_height);
	
	// Put walls on the '1' of the map
	int	i = 0;
	int	j = 0;
	while (game.map[i] != NULL)
	{
		j = 0;
		while (game.map[i][j] != '\0')
		{
			if (game.map[i][j] == '1')
			{
				mlx_put_image_to_window(game.mlx, game.mlx_win, img, j * 64, i * 64);
			}
			j++;
		}
		i++;
	}

	// Put ground on the '0' of the map
	i = 0;
	j = 0;
	relative_path = "./assets/ground64.xpm";
	img = mlx_xpm_file_to_image(game.mlx, relative_path, &img_width, &img_height);
	while (game.map[i] != NULL)
	{
		j = 0;
		while (game.map[i][j] != '\0')
		{
			if (game.map[i][j] == '0')
			{
				mlx_put_image_to_window(game.mlx, game.mlx_win, img, j * 64, i * 64);
			}
			j++;
		}
		i++;
	}

	// Put player on the 'P' of the map
	i = 0;
	j = 0;
	relative_path = "./assets/goblin64.xpm";
	img = mlx_xpm_file_to_image(game.mlx, relative_path, &img_width, &img_height);
	while (game.map[i] != NULL)
	{
		j = 0;
		while (game.map[i][j] != '\0')
		{
			if (game.map[i][j] == 'P')
			{
				mlx_put_image_to_window(game.mlx, game.mlx_win, img, j * 64, i * 64);
			}
			j++;
		}
		i++;
	}

	// Put exit on the 'E' of the map
	i = 0;
	j = 0;
	relative_path = "./assets/door_open64.xpm";
	img = mlx_xpm_file_to_image(game.mlx, relative_path, &img_width, &img_height);
	while (game.map[i] != NULL)
	{
		j = 0;
		while (game.map[i][j] != '\0')
		{
			if (game.map[i][j] == 'E')
			{
				mlx_put_image_to_window(game.mlx, game.mlx_win, img, j * 64, i * 64);
			}
			j++;
		}
		i++;
	}

	// Put collectibles on the 'C' of the map
	i = 0;
	j = 0;
	relative_path = "./assets/coin64.xpm";
	img = mlx_xpm_file_to_image(game.mlx, relative_path, &img_width, &img_height);
	while (game.map[i] != NULL)
	{
		j = 0;
		while (game.map[i][j] != '\0')
		{
			if (game.map[i][j] == 'C')
			{
				mlx_put_image_to_window(game.mlx, game.mlx_win, img, j * 64, i * 64);
			}
			j++;
		}
		i++;
	}
	
	
	free_map(game.map);
	mlx_loop(game.mlx);	
}