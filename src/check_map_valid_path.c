/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_valid_path.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:14:42 by kvisouth          #+#    #+#             */
/*   Updated: 2023/02/16 15:36:22 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	check_possible_path(char **map, int height, int width)
{
	int	player_row;
	int	player_col;
	int	exit_row;
	int	exit_col;
	int	found_player;
	int	found_exit;
	int	row;
	int	col;
	int	**stack;
	int	top;
	int	i;
	int	**visited;

	player_row = -1;
	player_col = -1;
	exit_row = -1;
	exit_col = -1;
	found_player = 0;
	found_exit = 0;
	row = 0;
	col = 0;
	stack = (int **)malloc(sizeof(int *) * height * width);
	i = 0;
	while (i < height * width)
		stack[i++] = (int *)malloc(sizeof(int) * 2);
	visited = (int **)malloc(sizeof(int *) * height);
	i = 0;
	while (i < height)
		visited[i++] = (int *)calloc(width, sizeof(int));
	while (!found_player || !found_exit)
	{
		if (map[row][col] == 'P')
		{
			player_row = row;
			player_col = col;
			found_player = 1;
		}
		else if (map[row][col] == 'E')
		{
			exit_row = row;
			exit_col = col;
			found_exit = 1;
		}
		col++;
		if (col == width)
		{
			col = 0;
			row++;
		}
	}
	top = 0;
	stack[top][0] = player_row;
	stack[top][1] = player_col;
	while (top >= 0)
	{
		row = stack[top][0];
		col = stack[top][1];
		top--;
		if (row == exit_row && col == exit_col)
			return (1);
		if (visited[row][col] || map[row][col] == '1')
			continue ;
		visited[row][col] = 1;
		if (row > 0)
		{
			top++;
			stack[top][0] = row - 1;
			stack[top][1] = col;
		}
		if (col > 0)
		{
			top++;
			stack[top][0] = row;
			stack[top][1] = col - 1;
		}
		if (row < height - 1)
		{
			top++;
			stack[top][0] = row + 1;
			stack[top][1] = col;
		}
		if (col < width - 1)
		{
			top++;
			stack[top][0] = row;
			stack[top][1] = col + 1;
		}
	}
	return (0);
}

// La fonction check_possible_path prend en entrée un tableau 2D map 
// représentant une carte avec un joueur (P), une sortie (E) et des murs
// (1) et renvoie 1 si un chemin est possible entre le joueur et la sortie
// sinon 0. La fonction utilise une méthode de recherche en profondeur pour
// explorer tous les chemins possibles à partir de la position du joueur.

// Le premier bloc de code de la fonction consiste à trouver la position du
// joueur et de la sortie dans la carte. La position du joueur est stockée dans
// player_row et player_col, et la position de la sortie est stockée dans
// exit_row et exit_col. Cela est réalisé en parcourant chaque case de la carte
// de gauche à droite et de haut en bas jusqu'à ce que les positions du joueur
// et de la sortie soient trouvées.

// Ensuite, la fonction initialise une pile de cases à visiter, qui contient
// initialement la position du joueur, et une matrice de cases visitées, qui est
// initialisée à 0. La pile de cases à visiter est implémentée à l'aide d'un
// tableau 2D stack et d'un pointeur top qui pointe vers le sommet de la pile.
// La matrice de cases visitées est implémentée à l'aide d'un tableau 2D visited
// dont les éléments sont initialisés à 0 à l'aide de la fonction memset.

// La boucle principale de la fonction parcourt la pile de cases à visiter
// jusqu'à ce qu'elle soit vide. À chaque étape, la fonction dépile la case du
// sommet de la pile et la vérifie. Si la case est la sortie, la fonction
// renvoie 1 pour indiquer qu'un chemin a été trouvé. Sinon, la fonction marque
// la case comme visitée dans la matrice visited et ajoute toutes les cases
// adjacentes qui n'ont pas encore été visitées et qui ne sont pas des murs à la
// pile de cases à visiter. Les cases adjacentes sont ajoutées à la pile en haut
// de celle-ci à l'aide du pointeur top.

// Enfin, si la pile de cases à visiter est vidée sans avoir atteint la sortie
// la fonction renvoie 0 pour indiquer qu'aucun chemin n'est possible.