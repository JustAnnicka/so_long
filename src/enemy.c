/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:03:57 by aehrl             #+#    #+#             */
/*   Updated: 2024/10/16 17:25:16 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Spawn enemy partols on the map
// -> should have movement (not specified in project)
// -> if the player touches an enemy the loose
// -> Have the enemy spawn reandomly on a empty field (min 2 spaces away from player)
//	-> Should be placed in a position that does not stop the player from reaching the exit
//  -> Move *.c to a src folder.........
#include "so_long.h"

int	ft_random_number(int max)
{
	int	i;
	int	min;

	min = 1;
	i = rand() % (max - min + 1) + min;
	return (i);
}

void	ft_spawn_enemy(t_game *game)
{
	int y;
	int x;

	y = ft_random_number(game->height);
	x = ft_random_number(game->width);
	while (game->map[y][x] != '0')
	{
		y = ft_random_number(game->height);
		x = ft_random_number(game->width);
	}
	game->enemy[0] = y;
	game->enemy[1] = x;
}

void	ft_enemy_movement(t_game *game)
{	
	int	move;

	move = ft_random_number(4);
	if (move == 1 && game->path[game->enemy[0] - 1][game->enemy[1]] == 'X')
	{
		game->assets->enemy->instances[0].y -= SCALE;
		game->enemy[0] = game->enemy[0] - 1;
	}	
	else if (move == 2 && game->path[game->enemy[0] + 1][game->enemy[1]] == 'X')
	{
		game->assets->enemy->instances[0].y += SCALE;
		game->enemy[0] = game->enemy[0] + 1;
	}
	else if (move == 3 && game->path[game->enemy[0]][game->enemy[1] - 1] == 'X')
	{
		game->assets->enemy->instances[0].x -= SCALE;
		game->enemy[1] = game->enemy[1] - 1;

	}
	else if (move == 4 && game->path[game->enemy[0]][game->enemy[1] + 1] == 'X')
	{
		game->assets->enemy->instances[0].x += SCALE;
		game->enemy[1] = game->enemy[1] + 1;
	}
}
