/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_elem.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 23:35:29 by kvisouth          #+#    #+#             */
/*   Updated: 2023/02/17 10:58:28 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// This function will check if there is something else than 0, 1, C, E, P in map.
int	check_junk_char(char **map)
{
	int		i;
	int		j;
	char	*valid_chars;

	valid_chars = "01CEP";
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (ft_strchr(valid_chars, map[i][j]) == NULL)
			{
				err();
				write(2, "There is a junk character in the map !\n", 39);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
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
	if (count == 0)
		return (err(), write(2, "There is no goblin in the map !\n", 32), 0);
	err();
	return (write(2, "There is more than 1 goblin in the map !\n", 41), 0);
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
	if (count == 0)
		return (err(), write(2, "There is no exit in the map !\n", 30), 0);
	return (err(), write(2, "There is more than 1 exit in the map !\n", 39), 0);
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
	if (check_junk_char(map) == 0)
		return (0);
	if (check_play_map(map) == 0)
		return (0);
	if (check_exit_map(map) == 0)
		return (0);
	if (check_coin_map(map) == 0)
	{
		err();
		write(2, "There is no coins for the goblin on the map !\n", 46);
		return (0);
	}
	return (1);
}
