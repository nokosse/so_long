/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:14:42 by kvisouth          #+#    #+#             */
/*   Updated: 2023/03/04 14:44:37 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// flood_fill algorithm, to check if the player can reach :
// ALL the coins in the map AND the only exit in the map.
// If it's not the case, return 0, else return 1.

// Function to get the player position in the map.
// pos[0] = x, pos[1] = y.
static int	*get_pos(char **map, int width, int height)
{
	int	*pos;
	int	i;
	int	j;

	pos = malloc(sizeof(int) * 2);
	if (pos == NULL)
		return (NULL);
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

// Function to check if there is still some 'C' or 'E' in the map.
// Returns 0 if there is still some, else returns 1.
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

// Function to fill the map with 'X' starting from the player position (x, y).
// pos[0] = x, pos[1] = y.
// It returns the modified map.
// We recursively call the function to fill the map with X in every directions.
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

// function flood_fill.
// It will fill the map with 'X' starting from the player position (x, y).
// pos[0] = x, pos[1] = y.
// It can fill every characters (P, C, E, 0) exept the walls (1).
// Once the map is filled we will check if there is still some 'C' or 'E'.
// If there is still some : it means they are unreachable, so we return 0.
// If there is no more C or E in map : it means we can reach all of them.
int	flood_fill(char **map, int width, int height)
{
	int		*pos;

	pos = get_pos(map, width, height);
	map = fill_map(map, width, height, pos);
	if (check_for_elem(map, width, height) == 0)
	{
		err();
		write(2, "No paths to finish the game !\n", 30);
		return (free(pos), 0);
	}
	return (free(pos), 1);
}
