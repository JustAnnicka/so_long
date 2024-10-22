/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 20:52:42 by aehrl             #+#    #+#             */
/*   Updated: 2024/10/21 14:59:50 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_resize_assets_img(t_game *g)
{
	mlx_resize_image(g->assets->img, SCALE, SCALE);
	mlx_resize_image(g->assets->img_top, SCALE, SCALE);
	mlx_resize_image(g->assets->img_bot, SCALE, SCALE);
	mlx_resize_image(g->assets->img_tlc, SCALE, SCALE);
	mlx_resize_image(g->assets->img_trc, SCALE, SCALE);
	mlx_resize_image(g->assets->img_blc, SCALE, SCALE);
	mlx_resize_image(g->assets->img_brc, SCALE, SCALE);
	mlx_resize_image(g->assets->img_ctlc, SCALE, SCALE);
	mlx_resize_image(g->assets->img_cblc, SCALE, SCALE);
	mlx_resize_image(g->assets->img_ls, SCALE, SCALE);
	mlx_resize_image(g->assets->img_rs, SCALE, SCALE);
	mlx_resize_image(g->assets->empty, SCALE, SCALE);
	mlx_resize_image(g->assets->exit, 48, 48);
	mlx_resize_image(g->assets->enemy, 48, 48);
	mlx_resize_image(g->assets->player, 48, 48);
	mlx_resize_image(g->assets->collectable, 32, 32);
	mlx_resize_image(g->assets->foot, SCALE, SCALE);
}
void	ft_init_tex(t_game *g)
{		
	g->assets->tex = mlx_load_png("./assets/png/tile_0018.png");
	g->assets->tex_tlc = mlx_load_png("./assets/png/tile_0003.png");
	g->assets->tex_trc = mlx_load_png("./assets/png/tile_0005.png");
	g->assets->tex_top = mlx_load_png("./assets/png/tile_0004.png");
	g->assets->tex_bot = mlx_load_png("./assets/png/tile_0038.png");
	g->assets->tex_ls = mlx_load_png("./assets/png/tile_0020.png");
	g->assets->tex_rs = mlx_load_png("./assets/png/tile_0022.png");
	g->assets->tex_cblc = mlx_load_png("./assets/png/tile_0072.png");
	g->assets->tex_ctlc = mlx_load_png("./assets/png/tile_0073.png");
	g->assets->tex_blc = mlx_load_png("./assets/png/tile_0037.png");
	g->assets->tex_brc = mlx_load_png("./assets/png/tile_0039.png");
	g->assets->tex_empty = mlx_load_png("./assets/png/tile_0001.png");
	g->assets->tex_exit = mlx_load_png("./assets/png/tile_0135.png");
	g->assets->tex_enemy = mlx_load_png("./assets/png/tile_0126.png");
	g->assets->tex_player = mlx_load_png("./assets/png/mono/tile_0125.png");
	g->assets->tex_collectable = mlx_load_png("./assets/png/tile_0104.png");
	g->assets->tex_foot = mlx_load_png("./assets/png/tile_0135.png");
}

void	ft_init_imgs(t_game *g, mlx_t *mlx)
{
	g->assets->img = mlx_texture_to_image(mlx, g->assets->tex);
	g->assets->img_top = mlx_texture_to_image(mlx, g->assets->tex_top);
	g->assets->img_bot = mlx_texture_to_image(mlx, g->assets->tex_bot);
	g->assets->img_tlc = mlx_texture_to_image(mlx, g->assets->tex_tlc);
	g->assets->img_trc = mlx_texture_to_image(mlx, g->assets->tex_trc);
	g->assets->img_blc = mlx_texture_to_image(mlx, g->assets->tex_blc);
	g->assets->img_brc = mlx_texture_to_image(mlx, g->assets->tex_brc);
	g->assets->img_ctlc = mlx_texture_to_image(mlx, g->assets->tex_ctlc);
	g->assets->img_cblc = mlx_texture_to_image(mlx, g->assets->tex_cblc);
	g->assets->img_ls = mlx_texture_to_image(mlx, g->assets->tex_ls);
	g->assets->img_rs = mlx_texture_to_image(mlx, g->assets->tex_rs);
	g->assets->empty = mlx_texture_to_image(mlx, g->assets->tex_empty);
	g->assets->exit = mlx_texture_to_image(mlx, g->assets->tex_exit);
	g->assets->enemy = mlx_texture_to_image(mlx, g->assets->tex_enemy);
	g->assets->player = mlx_texture_to_image(mlx, g->assets->tex_player);
	g->assets->collectable = mlx_texture_to_image(mlx, g->assets->tex_collectable);
	g->assets->foot = mlx_texture_to_image(mlx, g->assets->tex_foot);
	mlx_delete_texture(g->assets->tex);
	mlx_delete_texture(g->assets->tex_top);
	mlx_delete_texture(g->assets->tex_bot);
	mlx_delete_texture(g->assets->tex_tlc);
	mlx_delete_texture(g->assets->tex_trc);
	mlx_delete_texture(g->assets->tex_blc);
	mlx_delete_texture(g->assets->tex_brc);
	mlx_delete_texture(g->assets->tex_ctlc);
}

void ft_init_font(t_game *g)
{
	mlx_get_font();
	g->assets->font->win = mlx_put_string(g->mlx, "WIN", 64, 64);
	g->assets->font->loose = mlx_put_string(g->mlx, "LOOSE", 0, 0);
	g->assets->font->steps = mlx_put_string(g->mlx, "STEPS:", g->mlx->width - (SCALE * 2.5), g->mlx->height - (SCALE / 1.5));
	g->assets->font->win->instances[0].enabled = false;
	g->assets->font->loose->instances[0].enabled = false;
	mlx_set_instance_depth(&g->assets->font->steps->instances[0], 160);
	mlx_resize_image(g->assets->font->steps, SCALE, SCALE / 2);
}

void	ft_assets_ini(t_game *g, mlx_t *mlx)
{
	mlx_set_window_limit(mlx, g->width * SCALE, g->height * SCALE, 8000, 8000);
	ft_init_tex(g);
	ft_init_imgs(g, mlx);
	ft_resize_assets_img(g);
	ft_init_font(g);
}