/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:16:22 by kvisouth          #+#    #+#             */
/*   Updated: 2023/02/07 18:51:54 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

int	main(void)
{
	//open a window
	void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, 640, 360, "so_long");
    mlx_loop(mlx);
    (void)win;
}