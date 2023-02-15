/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:13:53 by kvisouth          #+#    #+#             */
/*   Updated: 2023/02/15 21:08:41 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// This function will get the height of the map.
// By counting the number of lines in the file readed.
int	get_map_height(char **path)
{
	int		fd;
	char	*line;
	int		height;

	fd = open(path[1], O_RDONLY);
	height = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (height);
}

// This function will get the width of the map.
// By counting the number of characters (ft_strlen) of the first line.
// Then read all the lines to avoid still reachable memory.
int	get_map_width(char **path)
{
	int		fd;
	char	*line;
	int		width;

	fd = open(path[1], O_RDONLY);
	line = get_next_line(fd);
	width = ft_strlen(line);
	free(line);
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (width);
}

// This function will check if the map is surrounded by walls.
// We check if first line and last line are only walls.
// Then we check if the first and last character of each line are walls.
// Walls are represented by '1' in the map.
int	check_map_surrounded(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i] != NULL)
	{
		if (map[i][j] != '1')
			return (0);
		j = ft_strlen(map[i]) - 1;
		if (map[i][j] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if ((i == 0 || (size_t)i == ft_strlen(map[i]) - 1) && map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}