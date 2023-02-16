/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_valid_path.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:14:42 by kvisouth          #+#    #+#             */
/*   Updated: 2023/02/16 11:19:00 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// This function will check if 'P' can reach 'E' in **map.
// The only way to reach 'E' is to go through '0' and 'C'.
int check_possible_path(char **map)
{
    int i;
    int j;
    int p;
    int e;

    i = 0;
    p = 0;
    e = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'P')
                p++;
            if (map[i][j] == 'E')
                e++;
            j++;
        }
        i++;
    }
    if (p != 1 || e != 1)
        return (0);
    return (1);
}