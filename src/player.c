/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 13:48:04 by aehrl             #+#    #+#             */
/*   Updated: 2024/10/18 17:22:44 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Function to move player (WASD)
// -> Check to see if the path is walkable
// -> Check if there is a collectable/enemy/exit at current positions

/* void	key_hook(mlx_key_data_t keydata, void* param)
{
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE && keydata.modifier == MLX_CONTROL)
		puts("Gotta grab it all!");
} */
int	ft_player_step(t_game *game, int x, int y)
{
	static int	step_count;

	if (game->path[y][x] != 'X')
			return (-1);
	if (game->map[y][x] == 'C')
	{
		game->pos[0] = y;
		game->pos[1] = x;
		ft_map_interact(game);
		game->map[y][x] = '0';
	}	
	else if (game->map[y][x] == 'E' && game->c_c == 0)
		return (ft_printf("YAY COMPLETE!"), ft_clear_map(game->mlx, game), 0);
	game->pos[0] = y;
	game->pos[1] = x;
	step_count++;
	ft_printf("Step Count: %d\n", step_count);
	ft_enemy_movement(game);
	if(game->pos[0] == game->enemy[0] && game->pos[1] == game->enemy[1])
		return (ft_printf("OH NO YOU LOOSE"),ft_clear_map(game->mlx, game), - 2);
	return (0);
}

void	ft_map_interact(t_game *game)
{
	int	i;

	i = game->assets->collectable->count;
	if (game->map[game->pos[0]][game->pos[1]] == 'C')
	{
		while ((game->assets->collectable->instances[i].y != (game->pos[0] * SCALE) + 16
			|| game->assets->collectable->instances[i].x != (game->pos[1] * SCALE) + 16) && i >= 0)
			i--;
		game->assets->collectable->instances[i].enabled = false;
		game->c_c--;
	}
	// We can add an animation for the exit once game->c_c == 0
}

void	ft_player_movement_keyhook(mlx_key_data_t keydata, void* param)
{
	t_game	*game;

	game = param;
	if (game->assets->player->instances[0].enabled == true)
	{
		if ((keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
			&& (ft_player_step(game, game->pos[1], game->pos[0] - 1) != -1))
				game->assets->player->instances[0].y -= SCALE;
		else if ((keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
			&& (ft_player_step(game, game->pos[1], game->pos[0] + 1) != -1))
				game->assets->player->instances[0].y += SCALE;
		else if ((keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
			&& (ft_player_step(game, game->pos[1] - 1, game->pos[0]) != -1))
				game->assets->player->instances[0].x -= SCALE;
		else if ((keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
			&& (ft_player_step(game, game->pos[1] + 1, game->pos[0]) != -1))
				game->assets->player->instances[0].x += SCALE;
	}
}
