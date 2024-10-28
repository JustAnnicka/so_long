/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:51:57 by aehrl             #+#    #+#             */
/*   Updated: 2024/10/28 18:20:39 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	ft_free_map(t_game *g)
{
	int	i;

	i = 0;
	if (g->map)
	{
		while(i < g->height && g->map[i])
		{
			free(g->map[i]);
			i++;
		}
		free(g->map);
	}
	i = 0;
	if (g->path)
	{
		while(i < g->height && g->path[i])
		{
			free(g->path[i]);
			i++;
		}
		free(g->path);
	}
}
void ft_free_game(t_game *g)
{
    if (g)
    {
		ft_free_map(g);
        if (g->mlx)
            mlx_terminate(g->mlx);
        if (g->assets)
        {
            if (g->assets->font)
            {
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