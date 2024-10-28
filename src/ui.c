/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:05:17 by aehrl             #+#    #+#             */
/*   Updated: 2024/10/23 21:10:14 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
}

void	ft_level_fail(t_game *g)
{
	mlx_texture_t *tex;
	mlx_image_t *blk;

	tex = mlx_load_png("./assets/png/tile_0057.png");
	blk = mlx_texture_to_image(g->mlx, tex);
	mlx_resize_image(blk, SCALE, SCALE);
	ft_fill_window(g, g->mlx, blk);
	mlx_get_font();
	g->assets->font->loose->instances[0].enabled = true;
	mlx_set_instance_depth(&g->assets->font->loose->instances[0], 260);
}