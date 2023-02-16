/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:13:53 by kvisouth          #+#    #+#             */
/*   Updated: 2023/02/15 23:29:56 by kvisouth         ###   ########.fr       */
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

// This function return 1 if the line only contain '1'
int	check_only_wall(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

// This function return 1 if the line[0] and line[len - 1] are '1'
int	check_fst_lst_wall(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (line[0] != '1' || line[len - 1] != '1')
		return (0);
	return (1);
}

// This function will check if the map is surrounded by walls.
// Use 'check_only_wall' on the first
// Use 'check_fst_lst_wall' on the lines that are not the first and the last
// Use 'check_only_wall' on the last
int	check_map_surrounded(char **map)
{
	int	i;

	i = 0;
	if (check_only_wall(map[0]) == 0)
		return (0);
	while (map[i + 1])
	{
		if (check_fst_lst_wall(map[i]) == 0)
			return (0);
		i++;
	}
	if (check_only_wall(map[i]) == 0)
		return (0);
	return (1);
}
