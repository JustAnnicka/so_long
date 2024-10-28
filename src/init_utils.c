/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:29:29 by aehrl             #+#    #+#             */
/*   Updated: 2024/10/28 15:11:00 by aehrl            ###   ########.fr       */
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

/* void ft_free_game(t_game *g)
{
    if (g)
    {
        if (g->mlx)
            free(g->mlx);

        if (g->assets)
        {
            if (g->assets->font)
                free(g->assets->font);
            free(g->assets);
        }

        free(g);
    }
} */

void	ft_free_textures(t_game	*g)
{
	free(g->assets->tex_exit);
	free(g->assets->tex_empty);
	free(g->assets->tex_enemy);
	free(g->assets->tex_player);
	free(g->assets->tex_collectable);
	free(g->assets->tex_foot);
	free(g->assets->tex);
	free(g->assets->tex_top);
	free(g->assets->tex_bot);
	free(g->assets->tex_tlc);
	free(g->assets->tex_trc);
	free(g->assets->tex_ls);
	free(g->assets->tex_rs);
	free(g->assets->tex_ctlc);
	free(g->assets->tex_cblc);
	free(g->assets->tex_blc);
	free(g->assets->tex_brc);
}
void	ft_free_assets(t_game *g)
{
	free(g->assets->exit);
	free(g->assets->empty);
	free(g->assets->enemy);
	free(g->assets->player);
	free(g->assets->collectable);
	free(g->assets->foot);
	free(g->assets->img);
	free(g->assets->img_top);
	free(g->assets->img_bot);
	free(g->assets->img_tlc);
	free(g->assets->img_trc);
	free(g->assets->img_ctlc);
	free(g->assets->img_cblc);
	free(g->assets->img_blc);
	free(g->assets->img_brc);
	free(g->assets->img_ls);
	free(g->assets->img_rs);
	free(g->assets);
}
void ft_free_game(t_game *g)
{
    if (g)
    {
        // Free mlx pointer if allocated
        if (g->mlx)
            free(g->mlx);

        // Free assets if allocated
        if (g->assets)
        {
            // Free font if allocated
            if (g->assets->font)
            {
                // Free images in font structure
                if (g->assets->font->win)
                    free(g->assets->font->win);
                if (g->assets->font->loose)
                    free(g->assets->font->loose);
                if (g->assets->font->steps)
                    free(g->assets->font->steps);
                if (g->assets->font->count)
                    free(g->assets->font->count);
                
                free(g->assets->font);
            }

           ft_free_textures(g);
		   ft_free_assets(g);
        }

        // Free game structure
        free(g);
    }
}
/* void ft_free_game(t_game *g)
{
    if (g->assets) {
        if (g->assets->font) {
            free(g->assets->font->win);
            free(g->assets->font->loose);
            free(g->assets->font->steps);
            free(g->assets->font->count);
            free(g->assets->font);
        }
        free(g->assets->tex_exit);
        free(g->assets->tex_empty);
        free(g->assets->tex_enemy);
        free(g->assets->tex_player);
        free(g->assets->tex_collectable);
        free(g->assets->tex_foot);
        free(g->assets->exit);
        free(g->assets->empty);
        free(g->assets->enemy);
        free(g->assets->player);
        free(g->assets->collectable);
        free(g->assets->foot);
        free(g->assets);  // Free assets last after all nested frees
    }
    if (g->mlx) {
        mlx_terminate(g->mlx);  // Assuming mlx_terminate correctly frees mlx_t allocations
    }
    free(g->map);  // Free map if it was allocated
    free(g->path); // Free path if it was allocated
    free(g);
}

 */