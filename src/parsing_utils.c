/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:02:10 by kvisouth          #+#    #+#             */
/*   Updated: 2023/02/17 10:54:12 by kvisouth         ###   ########.fr       */
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

// This function free the map
void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

// This function will check if the file is empty.
// Pretending the file is valid.
int	check_empty(char **path)
{
	int		fd;
	char	*line;

	fd = open(path[1], O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL)
		return (err(), write(2, "The map exist but is empty !\n", 29), 1);
	free(line);
	close(fd);
	return (0);
}

// This function write "Error\n" in STDERR_FILENO.
void	err(void)
{
	write(2, "Error\n", 6);
}
