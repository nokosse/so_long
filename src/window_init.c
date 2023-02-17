/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:55:53 by kvisouth          #+#    #+#             */
/*   Updated: 2023/02/17 17:05:16 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// This function will open a window with the size of the map.
// It will also set the title of the window to "so_long".
// It will return the pointer to the window.
void	*window_init(void *mlx, int width, int height)
{
	void	*mlx_win;

	mlx_win = mlx_new_window(mlx, width * 64, height * 64, "so_long");
	return (mlx_win);
}
