/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:30:01 by aehrl             #+#    #+#             */
/*   Updated: 2024/10/10 22:28:12 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_assign_coord(int y, int x, int *game_stat)
{
	game_stat[0] = y;
	game_stat[1] = x;
}

int	ft_check_if_enclosed(char **map, int y, int x)
{
	if (map[y - 1][x] == '1' && map[y + 1][x] == '1' && map[y][x - 1] == '1'
		&& map[y][x + 1] == '1')
		return (-1);
	return (0);
}
void	ft_flood_fill(int y, int x, t_game *game_stat)
{
	if ((y < 0 || y >= game_stat->height || x < 0 || x >= game_stat->width
			|| game_stat->path[y][x] == '1' || game_stat->path[y][x] == 'X'))
		return ;
	if (game_stat->path[y][x] != '1'){
		if (game_stat->path[y][x] == 'C')
			game_stat->c_c++;
		if (game_stat->path[y][x] == 'E')
			game_stat->c_e++;
		game_stat->path[y][x] = 'X';
	}
	ft_flood_fill(y + 1, x, game_stat);
	ft_flood_fill(y - 1, x, game_stat);
	ft_flood_fill(y, x + 1, game_stat);
	ft_flood_fill(y, x - 1, game_stat);
	return ;
}
