/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:16:22 by kvisouth          #+#    #+#             */
/*   Updated: 2023/02/15 13:13:14 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

int	main(int ac, char **av)
{
	// void	*mlx;
	// void	*img;
	// char	*relative_path = "./assets/goblin64.xpm";
	// int		img_width;
	// int		img_height;
	// void	*mlx_win;

	if (check_map(ac, av) == 0)
		return (write(2, "Error\n", 6) , 0);
	else
		write(1, "Map is valid\n", 13);
	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 1280, 720, "so_long");
	// img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	// mlx_put_image_to_window(mlx, mlx_win, img, 400, 300);
	// mlx_loop(mlx);	
}