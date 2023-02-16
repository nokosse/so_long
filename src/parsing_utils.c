/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:02:10 by kvisouth          #+#    #+#             */
/*   Updated: 2023/02/16 19:26:20 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
		return (1);
	free(line);
	close(fd);
	return (0);
}
