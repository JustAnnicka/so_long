/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_man.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 13:54:28 by aehrl             #+#    #+#             */
/*   Updated: 2024/11/05 17:42:23 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_delete_level(t_game *g)
{
	mlx_delete_image(g->mlx, g->assets->img_top);
	mlx_delete_image(g->mlx, g->assets->img_bot);
	mlx_delete_image(g->mlx, g->assets->img_tlc);
	mlx_delete_image(g->mlx, g->assets->img_trc);
	mlx_delete_image(g->mlx, g->assets->img_ctlc);
	mlx_delete_image(g->mlx, g->assets->img_cblc);
	mlx_delete_image(g->mlx, g->assets->img_blc);
	mlx_delete_image(g->mlx, g->assets->img_brc);
	mlx_delete_image(g->mlx, g->assets->img_ls);
	mlx_delete_image(g->mlx, g->assets->img_rs);
	mlx_delete_image(g->mlx, g->assets->empty);
	mlx_delete_image(g->mlx, g->assets->exit);
	mlx_delete_image(g->mlx, g->assets->collectable);
}

void	ft_clear_window(t_game *g, int state)
{
	g->end = state;
	ft_delete_level(g);
	ft_fill_window(g, g->mlx, g->assets->blk);
	if (state == 1)
	{
		mlx_get_font();
		g->assets->font->win->instances[0].enabled = true;
		mlx_set_instance_depth(&g->assets->font->win->instances[0], 260);
	}
	else if (state == -2)
	{
		mlx_get_font();
		g->assets->font->loose->instances[0].enabled = true;
		mlx_set_instance_depth(&g->assets->font->loose->instances[0], 260);
	}
	g->assets->player->instances[0].enabled = false;
}

static void	ft_shift_row_up(t_game *g, int row_size, int height)
{
	uint8_t	*buffer;
	int		row;
	uint8_t	*pixels;

	row = 0;
	pixels = g->assets->img->pixels;
	buffer = (uint8_t *)malloc(row_size);
	ft_memcpy(buffer, pixels, row_size);
	while (row < height - 1)
	{
		ft_memcpy(&pixels[row * row_size], &pixels[(row + 1) * row_size],
			row_size);
		row++;
	}
	ft_memcpy(&pixels[(height - 1) * row_size], buffer, row_size);
	free(buffer);
}

void	ft_water_animation(void *param)
{
	t_game		*g;
	static int	frame;
	int			row_size;

	g = param;
	row_size = g->assets->img->width * 4;
	if (g->end != 0)
		return ;
	frame++;
	if (frame == 5)
	{
		ft_shift_row_up(g, row_size, g->assets->img->height);
		frame = 0;
	}
}

void	ft_boat_animation(void *param)
{
	t_game		*g;
	static int	frame;
	int			x;

	g = param;
	x = g->width * SCALE;
	if (g->end != 0)
		return ;
	frame++;
	if (frame == 8)
	{
		g->assets->foot->instances[0].enabled = true;
		if ((g->assets->foot->instances[0].x + SCALE) <= x)
			g->assets->foot->instances[0].x += 8;
		else
		{
			g->assets->foot->instances[0].x = 0;
			g->assets->foot->instances[0].enabled = false;
		}
		frame = 0;
	}
}
