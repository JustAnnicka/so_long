/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 13:48:04 by aehrl             #+#    #+#             */
/*   Updated: 2024/10/14 19:51:14 by aehrl            ###   ########.fr       */
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

	//ft_printf("Path: %c\n", game->path[y][x]);
	//ft_printf("Path: (%d, %d)\n", y, x);
	if (game->path[y][x] != 'X')
			return (-1);
	if (game->map[y][x] == 'C')
	{
		game->map[y][x] = '0';
		game->c_c--;
		//mlx_image_to_window();
	}	
	else if (game->map[y][x] == 'E' && game->c_c == 0)
		return (ft_printf("YAY COMPLETE!"), 0);
	game->pos[0] = y;
	game->pos[1] = x;
		//game->assets->collectable[0].enabled = false;
	step_count++;
	ft_printf("Step Count: %d\n", step_count);
	return (0);
}

/* void	ft_map_interact(t_game game, t_asset *assets)
{
	int	x;
	int y;

	x = game.pos[1];
	y = game.pos[0];
	if (map[y][x] == 'C')
	{
		assets->collectable->instances[0].enabled = false;
		game->c--;
	}
} */

void	ft_player_movement_keyhook(mlx_key_data_t keydata, void* param)
{
	t_game	*game;

	game = param;
	if ((keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		&& (ft_player_step(game, game->pos[1], game->pos[0] - 1) == 0))
			game->assets->player->instances[0].y -= SCALE;
	if ((keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		&& (ft_player_step(game, game->pos[1], game->pos[0] + 1) == 0))
			game->assets->player->instances[0].y += SCALE;
	if ((keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		&& (ft_player_step(game, game->pos[1] - 1, game->pos[0]) == 0))
			game->assets->player->instances[0].x -= SCALE;
	if ((keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		&& (ft_player_step(game, game->pos[1] + 1, game->pos[0]) == 0))
			game->assets->player->instances[0].x += SCALE;
}
/* 
void	ft_player_movement(mlx_key_data_t keydata, void* param)
{
	int	x;
	int	y;

	x = game->pos[1];
	y = game->pos[0];
	if (keydata.key == MLX_KEY_W)
	{
		if (game->path[y - 1][x] != 'X')
			return ;
		game->pos[1] = x + 1;
		assets->player->instances[0].y -= SCALE;
	}
	else if (keydata.key == MLX_KEY_S)
	{
		if (game->path[y + 1][x] != 'X')
			return ;
		game->pos[1] = x -1;
		assets->player->instances[0].y += SCALE;
	}
	else if (keydata.key == MLX_KEY_A)
	{
		if (game->path[y][x - 1] != 'X')
			return ;
		game->pos[0] = y + 1;
		assets->player->instances[0].x += SCALE;
	}
	else if (keydata.key == MLX_KEY_D)
	{
		if (game->path[y][x + 1] != 'X')
			return ;
		game->pos[0] = y + 1;
		assets->player->instances[0].x -= SCALE;
	}
} */

/* void	ft_player_movement_keyhook(mlx_key_data_t keydata, t_game *game, t_asset *assets)
{
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		ft_player_movement(keydata.key, game, assets);
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		ft_player_movement(keydata.key, game, assets);
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		ft_player_movement(keydata.key, game, assets);
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		ft_player_movement(keydata.key, game, assets);
} */

/* void	ft_player_movement_keyhook(mlx_key_data_t keydata, t_game *game, t_asset *assets)
{
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		ft_player_movement(keydata.key, game, assets);
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		ft_player_movement(keydata.key, game, assets);
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		ft_player_movement(keydata.key, game, assets);
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		ft_player_movement(keydata.key, game, assets);
} */