/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:03:57 by aehrl             #+#    #+#             */
/*   Updated: 2024/10/23 21:08:58 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_random_number(int max)
{
	int	i;
	int	min;

	min = 1;
	i = rand() % (max - min + 1) + min;
	return (i);
}

void	ft_spawn_enemy(t_game *g)
{
	int	y;
	int	x;

	y = ft_random_number(g->height);
	x = ft_random_number(g->width);
	while (g->map[y][x] != '0')
	{
		y = ft_random_number(g->height);
		x = ft_random_number(g->width);
	}
	g->enemy[0] = y;
	g->enemy[1] = x;
}

void	ft_enemy_movement(t_game *g)
{
	int	move;

	move = ft_random_number(4);
	if (move == 1 && g->path[g->enemy[0] - 1][g->enemy[1]] == 'X')
	{
		g->assets->enemy->instances[0].y -= SCALE;
		g->enemy[0] = g->enemy[0] - 1;
	}
	else if (move == 2 && g->path[g->enemy[0] + 1][g->enemy[1]] == 'X')
	{
		g->assets->enemy->instances[0].y += SCALE;
		g->enemy[0] = g->enemy[0] + 1;
	}
	else if (move == 3 && g->path[g->enemy[0]][g->enemy[1] - 1] == 'X')
	{
		g->assets->enemy->instances[0].x -= SCALE;
		g->enemy[1] = g->enemy[1] - 1;
	}
	else if (move == 4 && g->path[g->enemy[0]][g->enemy[1] + 1] == 'X')
	{
		g->assets->enemy->instances[0].x += SCALE;
		g->enemy[1] = g->enemy[1] + 1;
	}
}
