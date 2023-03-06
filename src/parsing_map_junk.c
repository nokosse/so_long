/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_junk.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:18:04 by kvisouth          #+#    #+#             */
/*   Updated: 2023/03/06 13:48:14 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// This function will free all the arrays in the 2D array
void	free_2d_array(char **map)
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

// This function will count the number of lines in the file
int	count_lines(char **path)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(path[1], O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	return (i);
}

// This function will convert the file to a 2D array
char	**file_to_2d_array(char **path)
{
	int		fd;
	char	*line;
	char	**map;
	int		i;

	i = 0;
	fd = open(path[1], O_RDONLY);
	line = get_next_line(fd);
	map = malloc(sizeof(char *) * (count_lines(path) + 1));
	if (map == NULL)
		return (NULL);
	while (line != NULL)
	{
		map[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	return (map);
}

// This function will check if map[0][0] is a '1'
// And if the last character of the last array is a '1'
int	check_map_junk(char **path)
{
	char	**map;
	int		i;
	int		j;

	map = file_to_2d_array(path);
	i = 0;
	j = 0;
	if (map[0][0] != '1')
	{
		err();
		write(2, "Junk characters at the top of map.\n", 35);
		free_2d_array(map);
		return (0);
	}
	while (map[i] != NULL)
		i++;
	if (map[i - 1][j] != '1')
	{
		err();
		write(2, "Junk characters at the bottom of map.\n", 38);
		free_2d_array(map);
		return (0);
	}
	free_2d_array(map);
	return (1);
}
