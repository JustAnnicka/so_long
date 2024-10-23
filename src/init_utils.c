/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:29:29 by aehrl             #+#    #+#             */
/*   Updated: 2024/10/23 17:31:33 by aehrl            ###   ########.fr       */
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

void	ft_delete_textures(t_game *g)
{
	mlx_delete_texture(g->assets->tex);
	mlx_delete_texture(g->assets->tex_top);
	mlx_delete_texture(g->assets->tex_bot);
	mlx_delete_texture(g->assets->tex_tlc);
	mlx_delete_texture(g->assets->tex_trc);
	mlx_delete_texture(g->assets->tex_blc);
	mlx_delete_texture(g->assets->tex_brc);
	mlx_delete_texture(g->assets->tex_ctlc);
	mlx_delete_texture(g->assets->tex_cblc);
	mlx_delete_texture(g->assets->tex_ls);
	mlx_delete_texture(g->assets->tex_rs);
	mlx_delete_texture(g->assets->tex_empty);
	mlx_delete_texture(g->assets->tex_exit);
	mlx_delete_texture(g->assets->tex_enemy);
	mlx_delete_texture(g->assets->tex_player);
	mlx_delete_texture(g->assets->tex_collectable);
	mlx_delete_texture(g->assets->tex_foot);
}
