/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_gen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:16:31 by aehrl             #+#    #+#             */
/*   Updated: 2024/10/18 18:30:14 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_instances(char **map, t_game *game, mlx_image_t *img,
		mlx_t *mlx, char c, int pad)
{
	int	y;
	int	x;

	y = -1;
	x = -1;
	while (y++ < game->height - 1)
	{
		while (x++ < game->width - 1)
		{
			if (map[y][x] == c)
			{
				if (mlx_image_to_window(mlx, img, SCALE * x + pad, SCALE * y
						+ pad) < 0)
					ft_error();
			}
		}
		x = -1;
	}
}

void	ft_draw_island_corners(t_game *g, mlx_t *mlx, int x, int y)
{
	while (y++ < g->height - 1)
	{
		while (x++ < g->width - 1)
		{
			if (g->path[y][x] != '1')
			{
				// Top corners
				if (g->path[y - 1][x] == '1' && g->path[y - 1][x - 1] == '1'
					&& g->path[y][x - 1] == '1')
					mlx_image_to_window(mlx, g->assets->img_tlc, (SCALE * x)
						- 16, (SCALE * y) - 16);
				else if (g->path[y - 1][x] == '1' && g->path[y][x + 1] == '1'
					&& g->path[y - 1][x + 1] == '1')
					mlx_image_to_window(mlx, g->assets->img_trc, (SCALE * x),
						(SCALE * y) - 16);
				// Bottom corners
				else if (g->path[y][x - 1] == '1' && g->path[y + 1][x
					- 1] == '1' && g->path[y + 1][x] == '1')
					mlx_image_to_window(mlx, g->assets->img_blc, (SCALE * x)
						- 16, (SCALE * y) + 14);
			}
		}
		x = 0;
	}
}

void	ft_draw_island_connector(t_game *g, mlx_t *mlx, int x, int y)
{
	while (y++ < g->height - 1)
	{
		while (x++ < g->width - 1)
		{
			if (g->path[y][x] != '1')
			{
				if (g->path[y][x + 1] == '1' && g->path[y + 1][x + 1] == '1'
					&& g->path[y + 1][x] == '1')
					mlx_image_to_window(mlx, g->assets->img_brc, (SCALE * x)
						+ 16, (SCALE * y) + 14);
				// corner connect tlc
				else if (g->path[y - 1][x - 1] == '1' && g->path[y
					- 1][x] == 'X' && g->path[y][x - 1] == 'X')
					mlx_image_to_window(mlx, g->assets->img_ctlc, (SCALE * x)
						- 16, (SCALE * y) - 16);
				else if (g->path[y][x + 1] == 'X' && g->path[y - 1][x] == 'X'
					&& g->path[y - 1][x + 1] == '1')
					mlx_image_to_window(mlx, g->assets->img_cblc, (SCALE * x),
						(SCALE * y) - 16);
			}
		}
		x = 0;
	}
}

void	ft_draw_island(t_game *g, mlx_t *mlx, int x, int y)
{
	while (y++ < g->height - 1)
	{
		while (x++ < g->width - 1)
		{
			if (g->path[y][x] != '1')
			{
				if (g->path[y][x - 1] == '1')
					mlx_image_to_window(mlx, g->assets->img_ls, (SCALE * x)
						- 16, SCALE * y);
				else if (g->path[y][x + 1] == '1')
					mlx_image_to_window(mlx, g->assets->img_rs, (SCALE * x)
						+ 16, SCALE * y);
				else if (g->path[y - 1][x] == '1')
					mlx_image_to_window(mlx, g->assets->img_top, SCALE * x,
						(SCALE * y) - 16);
				else if (g->path[y + 1][x] == '1')
					mlx_image_to_window(mlx, g->assets->img_bot, SCALE * x,
						(SCALE * y) + 16);
			}
		}
		x = 0;
	}
}
void	ft_draw_map(char **map, t_game *game, mlx_t *mlx)
{
	ft_draw_instances(map, game, game->assets->img, mlx, '1', 0);
	ft_draw_instances(game->path, game, game->assets->empty, mlx, 'X', 0);
	ft_draw_island(game, mlx, 0, 0);
	ft_draw_island_connector(game, mlx, 0, 0);
	ft_draw_island_corners(game, mlx, 0, 0);
	ft_draw_instances(map, game, game->assets->collectable, mlx, 'C', 16);
	mlx_image_to_window(mlx, game->assets->exit, SCALE * game->exit[1] + 8,
		SCALE * game->exit[0] + 8);
	mlx_image_to_window(mlx, game->assets->player, SCALE * game->pos[1] + 8,
		SCALE * game->pos[0] + 8);
	ft_spawn_enemy(game);
	mlx_image_to_window(mlx, game->assets->enemy, SCALE * game->enemy[1] + 8,
		SCALE * game->enemy[0] + 8);
}
