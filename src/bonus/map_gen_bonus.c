/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_gen_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:16:31 by aehrl             #+#    #+#             */
/*   Updated: 2024/10/23 20:57:09 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_instances(char **map, t_game *g, mlx_image_t *img,
		mlx_t *mlx, char c, int pad)
{
	int	y;
	int	x;

	y = -1;
	x = -1;
	while (y++ < g->height - 1)
	{
		while (x++ < g->width - 1)
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
		x = 0;
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
	ft_draw_instances(map, g, g->assets->img, mlx, '1', 0);
	ft_draw_instances(g->path, g, g->assets->empty, mlx, 'X', 0);
	ft_draw_island(g, mlx, 0, 0);
	ft_draw_island_connector(g, mlx, 0, 0);
	ft_draw_island_corners(g, mlx, 0, 0);
	ft_draw_instances(map, g, g->assets->collectable, mlx, 'C', 16);
	mlx_image_to_window(mlx, g->assets->exit, SCALE * g->exit[1] + 8,
		SCALE * g->exit[0] + 8);
	mlx_image_to_window(mlx, g->assets->player, SCALE * g->pos[1] + 8,
		SCALE * g->pos[0] + 8);
	ft_spawn_enemy(g);
	mlx_image_to_window(mlx, g->assets->enemy, SCALE * g->enemy[1] + 8,
		SCALE * g->enemy[0] + 8);
	g->assets->font->steps->instances[0].enabled = true;
}
