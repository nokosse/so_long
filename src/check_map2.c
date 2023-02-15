/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:13:53 by kvisouth          #+#    #+#             */
/*   Updated: 2023/02/15 16:16:05 by kvisouth         ###   ########.fr       */
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
