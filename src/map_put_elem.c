/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_put_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:49:14 by kvisouth          #+#    #+#             */
/*   Updated: 2023/02/27 19:26:45 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// t stands for texture
// w stands for width
// h stands for height
// g stands for game
void	put_walls(t_game *g)
{
	t_texture	t;
	int			w;
	int			h;
	int			i;
	int			j;

	t.path = "./assets/wall64.xpm";
	t.img = mlx_xpm_file_to_image(g->mlx, t.path, &w, &h);
	i = 0;
	while (g->map[i] != NULL)
	{
		j = 0;
		while (g->map[i][j] != '\0')
		{
			if (g->map[i][j] == '1')
			{
				mlx_put_image_to_window(g->mlx, g->win, t.img, j * w, i * h);
			}
			j++;
		}
		i++;
	}
	mlx_destroy_image(g->mlx, t.img);
}

void	put_ground(t_game *g)
{
	t_texture	t;
	int			w;
	int			h;
	int			i;
	int			j;

	t.path = "./assets/ground64.xpm";
	t.img = mlx_xpm_file_to_image(g->mlx, t.path, &w, &h);
	i = 0;
	while (g->map[i] != NULL)
	{
		j = 0;
		while (g->map[i][j] != '\0')
		{
			if (g->map[i][j] == '0')
			{
				mlx_put_image_to_window(g->mlx, g->win, t.img, j * w, i * h);
			}
			j++;
		}
		i++;
	}
	mlx_destroy_image(g->mlx, t.img);
}

void	put_coins(t_game *g)
{
	t_texture	t;
	int			w;
	int			h;
	int			i;
	int			j;

	t.path = "./assets/coin64.xpm";
	t.img = mlx_xpm_file_to_image(g->mlx, t.path, &w, &h);
	i = 0;
	while (g->map[i] != NULL)
	{
		j = 0;
		while (g->map[i][j] != '\0')
		{
			if (g->map[i][j] == 'C')
			{
				mlx_put_image_to_window(g->mlx, g->win, t.img, j * w, i * h);
			}
			j++;
		}
		i++;
	}
	mlx_destroy_image(g->mlx, t.img);
}

void	put_exit_closed(t_game *g)
{
	t_texture	t;
	int			w;
	int			h;
	int			i;
	int			j;

	t.path = "./assets/door_closed64.xpm";
	t.img = mlx_xpm_file_to_image(g->mlx, t.path, &w, &h);
	i = 0;
	while (g->map[i] != NULL)
	{
		j = 0;
		while (g->map[i][j] != '\0')
		{
			if (g->map[i][j] == 'E')
			{
				mlx_put_image_to_window(g->mlx, g->win, t.img, j * w, i * h);
			}
			j++;
		}
		i++;
	}
	mlx_destroy_image(g->mlx, t.img);
}

void	put_player(t_game *g)
{
	t_texture	t;
	int			w;
	int			h;
	int			i;
	int			j;

	t.path = "./assets/goblin64.xpm";
	t.img = mlx_xpm_file_to_image(g->mlx, t.path, &w, &h);
	i = 0;
	while (g->map[i] != NULL)
	{
		j = 0;
		while (g->map[i][j] != '\0')
		{
			if (g->map[i][j] == 'P')
			{
				mlx_put_image_to_window(g->mlx, g->win, t.img, j * w, i * h);
			}
			j++;
		}
		i++;
	}
	mlx_destroy_image(g->mlx, t.img);
}
