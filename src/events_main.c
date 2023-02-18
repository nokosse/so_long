/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:51:02 by kvisouth          #+#    #+#             */
/*   Updated: 2023/02/18 13:13:13 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	handle_no_event(void *data)
{
	return (0);
	(void)data;
}

int	handle_keypress(int keysym, t_game *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx, data->win);
	printf("Key %d pressed\n", keysym);
	return (0);
}

int	handle_keyrelease(int keysym, t_game *data)
{
	printf("Key %d released\n", keysym);
	return (0);
	(void)data;
}
