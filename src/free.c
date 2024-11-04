/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:51:57 by aehrl             #+#    #+#             */
/*   Updated: 2024/11/03 18:23:43 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(t_game *g)
{
	int	i_map;
	int	i_path;

	i_map = 0;
	i_path = 0;
	if (g->map)
	{
		while (i_map < g->height && g->map[i_map])
		{
			free(g->map[i_map]);
			i_map++;
		}
		free(g->map);
		g->map = NULL;
	}
	if (g->path)
	{
		while (i_path < g->height && g->path[i_path])
		{
			free(g->path[i_path]);
			i_path++;
		}
		free(g->path);
		g->path = NULL;
	}
}

void	ft_free_game(t_game *g)
{
	if (!g)
		return ;
	ft_free_map(g);
	if (g->assets)
	{
		if (g->assets->font)
			free(g->assets->font);
		free(g->assets);
	}
	if (g->mlx)
	{
		mlx_terminate(g->mlx);
		g->mlx = NULL;
	}
	free(g);
}
