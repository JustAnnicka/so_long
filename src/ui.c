/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:05:17 by aehrl             #+#    #+#             */
/*   Updated: 2024/10/22 21:00:03 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_ui_stepcount(t_game *g, int step_count)
{
	char	*num;

	num = ft_itoa(step_count);
	if (g->assets->font->count)
		mlx_delete_image(g->mlx, g->assets->font->count);
	g->assets->font->count = mlx_put_string(g->mlx, num, g->mlx->width - (SCALE
				* 1.2), g->mlx->height - (SCALE / 1.5));
	if (step_count < 10)
		mlx_resize_image(g->assets->font->count, SCALE / 3, SCALE / 2);
	else
		mlx_resize_image(g->assets->font->count, SCALE / 2, SCALE / 2);
}

void	ft_level_complete(t_game *g)
{
	mlx_texture_t	*tex;
	mlx_image_t		*blk;

	tex = mlx_load_png("./assets/png/tile_0057.png");
	blk = mlx_texture_to_image(g->mlx, tex);
	mlx_resize_image(blk, SCALE, SCALE);
	ft_fill_window(g, g->mlx, blk);
	mlx_get_font();
	g->assets->font->win->instances[0].enabled = true;
	mlx_set_instance_depth(&g->assets->font->win->instances[0], 260);
	g->assets->font->count->instances[0].y =  g->mlx->height / 2 + SCALE;
	g->assets->font->count->instances[0].x =  g->mlx->width / 2 - 5;
	g->assets->font->steps->instances[0].y =  g->mlx->height / 2 + SCALE - 30;
	g->assets->font->steps->instances[0].x =  g->mlx->width / 2 - (SCALE / 3);
	mlx_set_instance_depth(&g->assets->font->count->instances[0], 300);
	mlx_set_instance_depth(&g->assets->font->steps->instances[0], 300);

}

void	ft_level_fail(t_game *g)
{
	mlx_texture_t	*tex;
	mlx_image_t		*blk;

	tex = mlx_load_png("./assets/png/tile_0057.png");
	blk = mlx_texture_to_image(g->mlx, tex);
	mlx_resize_image(blk, SCALE, SCALE);
	ft_fill_window(g, g->mlx, blk);
	mlx_get_font();
	g->assets->font->loose->instances[0].enabled = true;
	mlx_set_instance_depth(&g->assets->font->loose->instances[0], 260);
}