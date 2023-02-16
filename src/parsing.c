/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:16:43 by kvisouth          #+#    #+#             */
/*   Updated: 2023/02/16 19:41:31 by kvisouth         ###   ########.fr       */
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

	if ((ac != 2) || (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".ber", 4) != 0))
		return (0);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (0);
	readed = read(fd, NULL, 0);
	if (readed == -1)
		return (0);
	close(fd);
	return (1);
}

// This function will check if all the lines in the map are the same length.
// It read the first line and get it's length with ft_strlen.
// Then it read all the other lines, comparing to the first line length.
// If the length is different, it will return 0.
// It frees the line readed and the line readed before.
int	check_width_loop(int fd, int width)
{
	char	*line;
	int		i;

	line = get_next_line(fd);
	while (line != NULL)
	{
		i = ft_strlen(line);
		if (line[i - 1] != '\n')
			i++;
		free(line);
		line = get_next_line(fd);
		if (i != width)
		{
			i = 0;
			while (i < width)
			{
				free(line);
				line = get_next_line(fd);
				i++;
			}
			return (0);
		}
	}
	return (free(line), 1);
}

int	check_map_width(char **path)
{
	int		fd;
	char	*line;
	int		width;

	fd = open(path[1], O_RDONLY);
	line = get_next_line(fd);
	width = ft_strlen(line);
	free(line);
	if (!check_width_loop(fd, width))
		return (close(fd), 0);
	return (close(fd), 1);
}

// This function will create a 2D array of char
// Being a representation of the map.
// Each line will be \0 terminated instead of \n
char	**ber_to_2d_array(char **path, int height, int width)
{
	int		fd;
	char	*line;
	char	**map;
	int		i;

	fd = open(path[1], O_RDONLY);
	map = malloc(sizeof(char *) * (height + 1));
	if (map == NULL)
		return (NULL);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		map[i] = malloc(sizeof(char) * (width + 1));
		if (!map[i])
			return (NULL);
		ft_strlcpy(map[i], line, width + 1);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	free(line);
	close(fd);
	return (map);
}

int	check_map(int ac, char **av)
{
	int		height;
	int		width;
	int		*dimensions;
	char	**map;

	if (check_empty(av) || !(map_file_exist(ac, av)) || !(check_map_width(av)))
		return (0);
	height = get_map_height(av);
	width = get_map_width(av) - 1;
	dimensions = get_dims(height, width);
	map = ber_to_2d_array(av, height, width);
	if ((!check_map_surrounded(map)) || (!check_map_elements(map)))
		return (free(dimensions), free_map(map), 0);
	if (check_possible_path(map, dimensions) == 0)
		return (free(dimensions), free_map(map), 0);
	return (free(dimensions), free_map(map), 1);
	(void)map;
}
