/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:14:42 by kvisouth          #+#    #+#             */
/*   Updated: 2023/02/27 18:36:15 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// This is the DFS algorithm.
// This function implements a depth-first search (DFS) algorithm that searches
// for a path from the current position in the maze to the exit. The function
// takes in a 2D array map representing the maze, the current position
// row and col and the dimensions of the map dimensions.

// The function first checks if the current position is out of bounds or
// if it has already been visited. If either condition is true
// the function returns 0 (false). If the current position is the exit
// the function returns 1 (true).

// If the current position has not been visited and is not the exit
// the function marks the current position as visited by setting the value
// in the map array to '1'. It then recursively calls itself for each
// neighboring cell and combines the results using bitwise OR (|=).
// Finally, it returns the result.
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

// This function is used to make check_possible_path shorter.
// I was using that loop in check_possible_path, but I just split it into
// this function.

// The purpose of the check_loop function is to iterate over the entire maze
// and find the player's position and the row index of the exit. It does this
// by using two nested loops to visit each cell in the maze. For each cell
// it checks whether the value is 'P' or 'E' and updates the corresponding
// variables accordingly.

// If the function finds the player's position and the exit row index
// it will update the player_pos array and the exit_row variable passed by
// reference to the function. If the player's position or the exit row index
// is not found in the maze, these variables will be set to -1.

// Once the check_loop function has completed its execution, the player_pos
// and exit_row variables will contain the necessary information to determine
// if there is a path from the player to the exit in the maze.
void	check_loop(char **map, int *dims, int *player_pos, int *exit_row)
{
	int	i;
	int	j;

	i = 0;
	while (i < dims[0])
	{
		j = 0;
		while (j < dims[1])
		{
			if (map[i][j] == 'P')
			{
				player_pos[0] = i;
				player_pos[1] = j;
			}
			if (map[i][j] == 'E')
				*exit_row = i;
			j++;
		}
		i++;
	}
}

// This function is used to make check_possible_path shorter.
// I was using height and width as parameters, but I changed it to dimensions.
// I have to use this because I need to send less than 5 parameters to
// check_loop function.
int	*player_col_row(void)
{
	int	*player_pos;

	player_pos = (int *)malloc(sizeof(int) * 2);
	if (!player_pos)
		return (NULL);
	player_pos[0] = -1;
	player_pos[1] = -1;
	return (player_pos);
}

// This function check if there is a possible path from player to exit.
// It is using DFS algorithm.
int	check_possible_path(char **map, int *dimensions)
{
	int	*player_pos;
	int	exit_row;
	int	row;
	int	col;

	player_pos = player_col_row();
	check_loop(map, dimensions, player_pos, &exit_row);
	if (player_pos[0] == -1 || exit_row == -1)
		return (0);
	row = player_pos[0];
	col = player_pos[1];
	free(player_pos);
	return (dfs(map, row, col, dimensions));
}
