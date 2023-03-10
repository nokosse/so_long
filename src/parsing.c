/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:16:43 by kvisouth          #+#    #+#             */
/*   Updated: 2023/03/06 14:14:55 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// This function will check if there is only 1 argument and if it's a .ber file.
// Then it will check if the argument given (path to .ber map) is valid.
// By reading the argument with read() and checking if it returns -1.
int	map_file_exist(int ac, char **av)
{
	int	fd;
	int	readed;

	if (ac > 2)
		return (err(), write(2, "More than 1 file specified.\n", 28), 0);
	if (ac < 2)
	{
		err();
		write(2, "No file specified.\n", 19);
		write(2, "Usage: ./so_long <map.ber>\n", 27);
		return (0);
	}
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".ber", 4) != 0)
		return (err(), write(2, "Specified file is not a .ber file.\n", 35), 0);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (err(), write(2, "Specified file does not exist.\n", 31), 0);
	readed = read(fd, NULL, 0);
	if (readed == -1)
		return (err(), write(2, "Specified file is not readable.\n", 32), 0);
	close(fd);
	return (1);
}

// This function will compare the length of the first line of the file
// to the length of the other lines.
// If all the length of all lines are the same, it will return 1.
// If not, it will return 0.
int	check_map_width(char **path)
{
	int		fd;
	char	*line;
	size_t	width;

	fd = open(path[1], O_RDONLY);
	line = get_next_line(fd);
	width = ft_strlen(line);
	free(line);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (ft_strlen(line) != width)
		{
			write(2, "Map is not rectangular OR newline is missing\n", 45);
			while (line != NULL)
			{
				free(line);
				line = get_next_line(fd);
			}
			return (free(line), close(fd), 0);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (close(fd), 1);
}

// If the argument is not valid or map is empty, it will return 0.
// It will parse the map to satisfy the following conditions:
// - The map can only have these characters: 0, 1, C, E, P
// - There can only by 1 exit, 1 player and at least 1 collectible.
// - The map must be rectangular.
// - The map must be surrounded by walls.
// - There must be at least 1 path to the exit from P to E.
// This is all the given conditions by the fr.subject.pdf
// dimensions[0] = height, dimensions[1] = width.
int	check_map(int ac, char **av)
{
	int		height;
	int		width;
	int		*dimensions;
	char	**map;
	char	**map_copy;

	if (map_file_exist(ac, av) == 0 || check_empty(av)
		|| check_map_junk(av) == 0)
		return (0);
	if (!(map_file_exist(ac, av)) || check_empty(av) || !(check_map_width(av)))
		return (0);
	height = get_map_height(av);
	width = get_map_width(av) - 1;
	dimensions = get_dims(height, width);
	map = get_map(av);
	map_copy = get_map(av);
	if ((!check_map_surrounded(map)) || (!check_map_elements(map)))
		return (free(dimensions), free_map(map), free_map(map_copy), 0);
	if (flood_fill(map, width, height) == 0
		|| flood_fill2(map_copy, width, height) == 0)
		return (free(dimensions), free_map(map), free_map(map_copy), 0);
	return (free(dimensions), free_map(map), free_map(map_copy), 1);
}

// To check if check_map() is working you can test the following cases :
// - No arguments
// - More than 1 argument
// - Argument is not a .ber file
// - Argument is .ber suffix but does not exist
// - Argument is .ber suffix but is not readable
// - Argument is .ber suffix but is empty
//
// To test a existing map with invalid rules :
// - The map have something else than 0, 1, C, E, P
// - The map don't have P, E or C
// - The map have more than one P or E
// - The map is not rectangular
// - The map is not surrounded by walls
// - The map have no path to the exit