/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:06:37 by kvisouth          #+#    #+#             */
/*   Updated: 2023/02/17 15:17:56 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// At the moment, will put "../assets/wall64.xpm" on '1' of **map.
void	map_init(t_game game)
{
	void	*wall_img;
	char	*wall_path;
	int		img_width;
	int		img_height;
	int		i;
	int		j;

	wall_path = "../assets/wall64.xpm";
	wall_img = mlx_xpm_file_to_image(game.mlx, wall_path, &img_width, &img_height);
	i = 0;
	while (game.map[i] != NULL)
	{
		j = 0;
		while (game.map[i][j] != '\0')
		{
			if (game.map[i][j] == '1')
			{
				mlx_put_image_to_window(game.mlx, game.mlx_win, wall_img, j * 64, i * 64);
			}
			j++;
		}
		i++;
	}
}