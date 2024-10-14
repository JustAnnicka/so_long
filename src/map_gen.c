/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_gen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:16:31 by aehrl             #+#    #+#             */
/*   Updated: 2024/10/14 19:45:46 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	ft_draw_instances(char **map, t_game *game, mlx_image_t *img, mlx_t *mlx, char c, int padding)
{
	int	y;
	int	x;

	y = -1;
	x = -1;
	while (y++ < game->height -1)
	{
		while (x++ < game->width -1)
		{
			if (map[y][x] == c)
			{
				if (mlx_image_to_window(mlx, img, SCALE * x + padding, SCALE * y + padding) < 0)
					ft_error();
			}
		}
		x = -1;
	}
}

void	ft_draw_island(t_game *game, mlx_t *mlx)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y++ < game->height -1)
	{
		while (x++ < game->width -1)
		{	
			if (game->path[y][x] != '1')
			{
				//Top corners
				if (game->path[y - 1][x] == '1' && game->path[y - 1][x - 1] == '1' && game->path[y][x - 1] == '1')
					mlx_image_to_window(mlx, game->assets->img_tlc, (SCALE * x) - 16, (SCALE * y) - 16);
				else if (game->path[y - 1][x] == '1' && game->path[y][x + 1] == '1' && game->path[y - 1][x + 1] == '1')
					mlx_image_to_window(mlx, game->assets->img_trc, (SCALE * x), (SCALE * y) - 16);
				//Bottom corners
				else if (game->path[y][x - 1] == '1' && game->path[y + 1][x - 1] == '1' && game->path[y + 1][x] == '1')
					mlx_image_to_window(mlx, game->assets->img_blc, (SCALE * x) - 16, (SCALE * y) + 14);
				else if (game->path[y][x + 1] == '1' && game->path[y + 1][x + 1] == '1' && game->path[y + 1][x] == '1')
					mlx_image_to_window(mlx, game->assets->img_brc, (SCALE * x) + 16, (SCALE * y) + 14);
				//corner connect tlc
				else if (game->path[y - 1][x - 1] == '1' && game->path[y - 1][x] == 'X' && game->path[y][x - 1] == 'X')
					mlx_image_to_window(mlx, game->assets->img_ctlc, (SCALE * x) - 16, (SCALE * y) - 16);
				else if (game->path[y][x + 1] == 'X' && game->path[y - 1][x] == 'X' && game->path[y -1 ][x + 1] == '1')
					mlx_image_to_window(mlx, game->assets->img_cblc, (SCALE * x), (SCALE * y) - 16);
				//sides
				else if (game->path[y][x - 1] == '1')
					mlx_image_to_window(mlx, game->assets->img_ls, (SCALE * x) - 16, SCALE * y);
				else if (game->path[y][x + 1] == '1')
					mlx_image_to_window(mlx, game->assets->img_rs, (SCALE * x) + 16, SCALE * y);
				//top
				else if (game->path[y - 1][x] == '1')
					mlx_image_to_window(mlx, game->assets->img_top, SCALE * x, (SCALE * y) - 16);
				//bottom
				else if (game->path[y + 1][x] == '1')
					mlx_image_to_window(mlx, game->assets->img_bot, SCALE * x, (SCALE * y) + 16);
			}
		}
		x = 0;
	}
}
/* void	ft_draw_island(t_game *game, t_asset *assets, mlx_t *mlx)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y++ < game->height -1)
	{
		while (x++ < game->width -1)
		{	
			if (game->path[y][x] != '1')
			{
				//Top left corner
				if (game->path[y - 1][x] == '1' && game->path[y - 1][x - 1] == '1' && game->path[y][x - 1] == '1')
					mlx_image_to_window(mlx, assets->wall->img_tlc, SCALE * (x - 1), SCALE * (y - 1));
				//Bottom left corner
				else if (game->path[y + 1][x] == '1' && game->path[y - 1][x - 1] == '1' && game->path[y + 1][x] == '1')
					mlx_image_to_window(mlx, assets->wall->img_blc, SCALE * (x - 1), SCALE * (y + 1));
				//corner connect tlc
				else if (game->path[y - 1][x - 1] == '1' && game->path[y - 1][x] == 'X' && game->path[y][x - 1] == 'X')
					mlx_image_to_window(mlx, assets->wall->img_ctlc, SCALE * (x - 1), SCALE * (y -1));
				//left side
				else if (game->path[y][x + 1] == '1')
					mlx_image_to_window(mlx, assets->wall->img_ls, SCALE * (x - 1), SCALE * y);
				//top side
				else if (game->path[y - 1][x] == '1')
					mlx_image_to_window(mlx, assets->wall->img_top, SCALE * x, SCALE * (y - 1));
			}
		}
		x = 0;
	}
} */

void	ft_draw_map(char **map, t_game *game, mlx_t *mlx)
{
	ft_printf("ENTER\n");
	ft_draw_instances(map, game, game->assets->img, mlx, '1', 0);
	ft_draw_instances(game->path, game, game->assets->empty, mlx, 'X', 0);
	ft_draw_island(game, mlx);
	ft_draw_instances(map, game, game->assets->collectable, mlx, 'C', 16);
	mlx_image_to_window(mlx, game->assets->exit, SCALE * game->exit[1] + 8, SCALE * game->exit[0] + 8);
	mlx_image_to_window(mlx, game->assets->player, SCALE * game->pos[1] + 8, SCALE * game->pos[0] + 8);
	ft_printf("EXIT\n");
}
