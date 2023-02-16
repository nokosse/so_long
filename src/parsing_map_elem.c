/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_elements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 23:35:29 by kvisouth          #+#    #+#             */
/*   Updated: 2023/02/16 19:28:55 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// This function takes height and width, and returns int *dimensions.
// dimensions[0] = height
// dimensions[1] = width
int	*get_dims(int height, int width)
{
	int	*dimensions;

	dimensions = malloc(sizeof(int) * 2);
	if (dimensions == NULL)
		return (NULL);
	dimensions[0] = height;
	dimensions[1] = width;
	return (dimensions);
}

// This function will check if there is 1 and only 1 character 'P' in map.
int	check_play_map(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
				count++;
			j++;
		}
		i++;
	}
	if (count == 1)
		return (1);
	return (0);
}

// This function will check if there is 1 and only 1 character 'E' in map.
int	check_exit_map(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'E')
				count++;
			j++;
		}
		i++;
	}
	if (count == 1)
		return (1);
	return (0);
}

// This function will check if there is at least 1 character 'C' in map.
int	check_coin_map(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	if (count >= 1)
		return (1);
	return (0);
}

// This function will check if the map contains :
// Only 1 player ('P')
// Only 1 exit   ('E')
// 1 coin or +   ('C')
int	check_map_elements(char **map)
{
	if (check_play_map(map) == 0)
		return (0);
	if (check_exit_map(map) == 0)
		return (0);
	if (check_coin_map(map) == 0)
		return (0);
	return (1);
}
