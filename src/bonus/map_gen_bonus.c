/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_gen_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:16:31 by aehrl             #+#    #+#             */
/*   Updated: 2024/11/05 17:51:26 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_instances(char **map, t_game *g, mlx_image_t *img, char c)
{
	int	y;
	int	x;

	y = -1;
	x = -1;
	while (y++ < g->height - 1)
	{
		while (x++ < g->width - 1)
		{
			if (map[y][x] == c && c == 'C')
			{
				if (mlx_image_to_window(g->mlx, img, SCALE * x + 16, SCALE * y
						+ 16) < 0)
					ft_error();
			}
			else if (map[y][x] == c)
			{
				if (mlx_image_to_window(g->mlx, img, SCALE * x, SCALE * y) < 0)
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
				if (g->path[y - 1][x] == '1' && g->path[y - 1][x - 1] == '1'
					&& g->path[y][x - 1] == '1')
					mlx_image_to_window(mlx, g->assets->img_tlc, (SCALE * x)
						- 16, (SCALE * y) - 16);
				else if (g->path[y - 1][x] == '1' && g->path[y][x + 1] == '1'
					&& g->path[y - 1][x + 1] == '1')
					mlx_image_to_window(mlx, g->assets->img_trc, (SCALE * x),
						(SCALE * y) - 16);
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
		x = 0;
		while (x++ < g->width - 1)
		{
			if (g->path[y][x] != '1')
			{
				if (g->path[y][x + 1] == '1' && g->path[y + 1][x + 1] == '1'
					&& g->path[y + 1][x] == '1')
					mlx_image_to_window(mlx, g->assets->img_brc, (SCALE * x)
						+ 16, (SCALE * y) + 14);
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

void	ft_draw_map(char **map, t_game *g, mlx_t *mlx)
{
	ft_draw_instances(map, g, g->assets->img, '1');
	ft_draw_instances(g->path, g, g->assets->empty, 'X');
	ft_draw_island(g, mlx, 0, 0);
	ft_draw_island_connector(g, mlx, 0, 0);
	ft_draw_island_corners(g, mlx, 0, 0);
	ft_draw_instances(map, g, g->assets->collectable, 'C');
	mlx_image_to_window(mlx, g->assets->exit, SCALE * g->exit[1] + 8, SCALE
		* g->exit[0] + 8);
	mlx_image_to_window(mlx, g->assets->player, SCALE * g->pos[1] + 8, SCALE
		* g->pos[0] + 8);
	ft_spawn_enemy(g);
	mlx_image_to_window(mlx, g->assets->enemy, SCALE * g->enemy[1] + 8, SCALE
		* g->enemy[0] + 8);
	mlx_image_to_window(g->mlx, g->assets->exit_open, SCALE * g->exit[1] + 8,
		SCALE * g->exit[0] + 8);
	mlx_image_to_window(mlx, g->assets->foot, 0, (g->height * 64) - 56);
	g->assets->font->steps->instances[0].enabled = true;
	g->assets->exit_open->instances[0].enabled = false;
}
