/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_paths2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:04:28 by kvisouth          #+#    #+#             */
/*   Updated: 2023/03/02 16:15:39 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	*get_pos(char **map, int width, int height)
{
	int	*pos;
	int	i;
	int	j;

	pos = malloc(sizeof(int) * 2);
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (map[i][j] == 'P')
			{
				pos[0] = i;
				pos[1] = j;
				return (pos);
			}
			j++;
		}
		i++;
	}
	return (pos);
}

static int	check_for_elem(char **map, int width, int height)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static char	**fill_map(char **map, int width, int height, int *pos)
{
	if (pos[0] < 0 || pos[0] >= height || pos[1] < 0 || pos[1] >= width)
		return (map);
	if (map[pos[0]][pos[1]] == '1')
		return (map);
	if (map[pos[0]][pos[1]] == 'X')
		return (map);
	map[pos[0]][pos[1]] = 'X';
	fill_map(map, width, height, (int []){pos[0] + 1, pos[1]});
	fill_map(map, width, height, (int []){pos[0] - 1, pos[1]});
	fill_map(map, width, height, (int []){pos[0], pos[1] + 1});
	fill_map(map, width, height, (int []){pos[0], pos[1] - 1});
	return (map);
}

// transforms 'E' to '1'
char	**exit_to_wall(char **map, int width, int height)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (map[i][j] == 'E')
				map[i][j] = '1';
			j++;
		}
		i++;
	}
	return (map);
}

int	flood_fill2(char **map, int width, int height)
{
	int		*pos;

	pos = get_pos(map, width, height);
	map = exit_to_wall(map, width, height);
	map = fill_map(map, width, height, pos);
	if (check_for_elem(map, width, height) == 0)
	{
		err();
		write(2, "No paths to finish the game !\n", 30);
		return (free(pos), 0);
	}
	return (free(pos), 1);
}
