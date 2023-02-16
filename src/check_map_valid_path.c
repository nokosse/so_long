/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_valid_path.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:14:42 by kvisouth          #+#    #+#             */
/*   Updated: 2023/02/16 16:51:03 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	dfs(char **map, int row, int col, int *dimensions)
{
	int	res;

	if (row < 0 || row >= dimensions[0] || col < 0 || col >= dimensions[1]
		|| map[row][col] == '1')
		return (0);
	if (map[row][col] == 'E')
		return (1);
	res = 0;
	map[row][col] = '1';
	res |= dfs(map, row - 1, col, dimensions);
	res |= dfs(map, row + 1, col, dimensions);
	res |= dfs(map, row, col - 1, dimensions);
	res |= dfs(map, row, col + 1, dimensions);
	return (res);
}

int	check_possible_path(char **map, int *dimensions)
{
	int	player_row;
	int	player_col;
	int	exit_row;
	int	i;
	int	j;

	i = 0;
	player_row = -1;
	player_col = -1;
	exit_row = -1;
	while (i < dimensions[0])
	{
		j = 0;
		while (j < dimensions[1])
		{
			if (map[i][j] == 'P')
			{
				player_row = i;
				player_col = j;
			}
			if (map[i][j] == 'E')
				exit_row = i;
			j++;
		}
		i++;
	}
	if (player_row == -1 || exit_row == -1)
		return (0);
	return (dfs(map, player_row, player_col, dimensions));
}
