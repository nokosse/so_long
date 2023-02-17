/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:14:39 by kvisouth          #+#    #+#             */
/*   Updated: 2023/02/17 10:41:32 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <string.h>
# include <stdint.h>
# include <fcntl.h>
# include <limits.h>
# include "../libft/inc/libft.h"
# include "../libft/inc/get_next_line.h"
# include "../libft/inc/ft_printf.h"
# include "../mlx_linux/mlx.h"

int		check_map(int ac, char **av);
int		get_map_width(char **path);
int		get_map_height(char **path);
int		*get_dims(int height, int width);
int		check_map_surrounded(char **map);
int 	check_map_elements(char **map);
int		check_possible_path(char **map, int* dimensions);
void	free_map(char **map);
int		check_empty(char **path);
void	err(void);

#endif