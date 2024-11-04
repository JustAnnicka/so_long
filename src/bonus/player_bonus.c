/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 13:48:04 by aehrl             #+#    #+#             */
/*   Updated: 2024/11/04 20:38:56 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_player_step(t_game *g, int x, int y)
{
	static int	step_count;

	if (g->path[y][x] != 'X')
		return (-1);
	if (g->map[y][x] == 'C')
	{
		g->pos[0] = y;
		g->pos[1] = x;
		ft_map_interact(g);
		g->map[y][x] = '0';
	}
	else if (g->map[y][x] == 'E' && g->c_c == 0)
		return (ft_clear_window(g, 1), ft_level_complete(g), 0);
	g->pos[0] = y;
	g->pos[1] = x;
	step_count++;
	ft_ui_stepcount(g, step_count);
	ft_enemy_movement(g);
	if (g->pos[0] == g->enemy[0] && g->pos[1] == g->enemy[1])
		return (ft_clear_window(g, -2), ft_level_fail(g), -2);
	if ((g->map[y][x] == 'E' && g->c_c == 0) ||
		(g->pos[0] == g->enemy[0] && g->pos[1] == g->enemy[1]))
		g->assets->enemy->instances[0].enabled = false;
	return (0);
}

void	ft_map_interact(t_game *g)
{
	int	i;

	i = g->assets->collectable->count;
	if (g->map[g->pos[0]][g->pos[1]] == 'C')
	{
		while ((g->assets->collectable->instances[i].y != (g->pos[0] * SCALE)
				+ 16 || g->assets->collectable->instances[i].x != (g->pos[1]
					* SCALE) + 16) && i >= 0)
			i--;
		g->assets->collectable->instances[i].enabled = false;
		g->c_c--;
	}
	if (g->c_c == 0)
	{
		g->assets->exit->instances[0].enabled = false;
		g->assets->exit_open->instances[0].enabled = true;
	}
}

void	ft_player_movement_keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*g;

	g = param;
	if (g->assets->player->instances[0].enabled == true)
	{
		if ((keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
			&& (ft_player_step(g, g->pos[1], g->pos[0] - 1) != -1))
			g->assets->player->instances[0].y -= SCALE;
		else if ((keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
			&& (ft_player_step(g, g->pos[1], g->pos[0] + 1) != -1))
			g->assets->player->instances[0].y += SCALE;
		else if ((keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
			&& (ft_player_step(g, g->pos[1] - 1, g->pos[0]) != -1))
			g->assets->player->instances[0].x -= SCALE;
		else if ((keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
			&& (ft_player_step(g, g->pos[1] + 1, g->pos[0]) != -1))
			g->assets->player->instances[0].x += SCALE;
	}
}
