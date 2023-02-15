/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:16:43 by kvisouth          #+#    #+#             */
/*   Updated: 2023/02/15 13:50:40 by kvisouth         ###   ########.fr       */
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

// Subject ask to check if the map has :
// 1. 1 player(P), 1 exit(E), 1 or + collectibles(C).
// 2. Map is a rectangle (or square).
// 3. Map is surrounded by walls. (1 are walls, 0 are empty space)
// 4. ADVANCED! If there is a possible path to the exit (E)
//
// We will first check 2 then 3 then 1 then 4.
// But before that, we have to make the map into a 2D array. (char **map)
// Using char *get_next_line(int fd) to read the map line by line.
// And put it into a 2D array. (char **map)

char	**ber_to_2d_array(int fd)
{
	char	**map;
	int		i;
}

int	check_map(int ac, char **av)
{
	int		fd;
	char	**map;

	if (!(map_file_exist(ac, av)))
		return (0);
	return (1);
	fd = open(av[1], O_RDONLY);
	close(fd);
}
