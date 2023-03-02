/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:55:50 by kvisouth          #+#    #+#             */
/*   Updated: 2023/03/02 15:13:41 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// This function print the map in the terminal
void	print_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			write(1, &map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

// This function erease the \n at the end of the lines in map
// dimensions[0] = height
// dimensions[1] = width
char	**erease_n(char ***map, int	*dimensions)
{
	char	**new_map;
	int		i;
	int		j;

	new_map = malloc(sizeof(char *) * (dimensions[0] + 1));
	if (new_map == NULL)
		return (NULL);
	i = 0;
	while (i < dimensions[0])
	{
		new_map[i] = malloc(sizeof(char) * (dimensions[1] + 1));
		if (new_map[i] == NULL)
			return (NULL);
		j = 0;
		while (j < dimensions[1])
		{
			new_map[i][j] = (*map)[i][j];
			j++;
		}
		new_map[i][j] = '\0';
		i++;
	}
	new_map[i] = NULL;
	free_map(*map);
	return (new_map);
}

// This function takes a path to a map file .ber and returns the map as a **char
char	**get_map(char **path)
{
	int		fd;
	int		*dimensions;
	char	**map;
	int		i;

	dimensions = get_dims(get_map_height(path), get_map_width(path) - 1);
	map = malloc(sizeof(char *) * (dimensions[0] + 1));
	if (map == NULL)
		return (NULL);
	fd = open(path[1], O_RDONLY);
	i = 0;
	while (i < dimensions[0])
	{
		map[i] = get_next_line(fd);
		i++;
	}
	while (get_next_line(fd) != NULL)
		;
	map[i] = NULL;
	close(fd);
	map = erease_n(&map, dimensions);
	free(dimensions);
	return (map);
}
