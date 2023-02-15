/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:16:43 by kvisouth          #+#    #+#             */
/*   Updated: 2023/02/15 23:34:19 by kvisouth         ###   ########.fr       */
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
// By comparing the len of the first line with the len of the other lines.
// Last line don't always have a \n so we add 1 to the len.
int	check_map_width(char **path)
{
	char	*line;
	int		width;
	int		line_width;
	int		fd;

	fd = open(path[1], O_RDONLY);
	line = get_next_line(fd);
	width = ft_strlen(line);
	free(line);
	line = get_next_line(fd);
	while (line != NULL)
	{
		line_width = ft_strlen(line);
		if (line[line_width - 1] != '\n')
			line_width++;
		if (line_width != width)
			return (0);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (1);
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

// This function will check if the file is empty.
// Pretending the file is valid.
int	check_empty(char **path)
{
	int		fd;
	char	*line;

	fd = open(path[1], O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL)
		return (1);
	free(line);
	close(fd);
	return (0);
}

// Subject ask to check if the map has :
// 1. 1 player(P), 1 exit(E), 1 or + collectibles(C).
// 4. If there is a possible path to the exit (E)
// TODO : Check step 1 and 4
int	check_map(int ac, char **av)
{
	int		height;
	int		width;
	char	**map;

	if (check_empty(av) || !(map_file_exist(ac, av)) || !(check_map_width(av)))
		return (0);
	height = get_map_height(av);
	width = get_map_width(av) - 1;
	map = ber_to_2d_array(av, height, width);
	if (check_map_surrounded(map) == 0)
		return (0);
	return (1);
	(void)map;
}
