/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 18:05:32 by aehrl             #+#    #+#             */
/*   Updated: 2024/10/28 14:58:03 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void	ft_error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	ft_window_handling(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

t_game	*ft_game_ini(t_game *g)
{
	g->mlx = ft_calloc(1, sizeof(mlx_t));
	if (!g->mlx)
		return (ft_free_game(g), NULL);
	g->assets = ft_calloc(1, sizeof(t_asset));
	if (!g->assets)
		return (free(g->mlx), free(g), NULL);
	g->assets->font = ft_calloc(1, sizeof(t_font));
	if (!g->assets->font)
		return (free(g->assets), free(g->mlx), ft_free_game(g), NULL);
	g->width = 0;
	g->height = 2;
	g->p = 0;
	g->c = 0;
	g->e = 0;
	g->c_c = 0;
	g->c_e = 0;
	g->pos[0] = 0;
	g->pos[1] = 0;
	g->exit[0] = 0;
	g->exit[1] = 0;
	g->enemy[0] = 0;
	g->enemy[1] = 0;
	g->end = 0;
	// INSTEAD OF RETURN NULL GIVE ERROR MESSAGE AND EXIT
	return (g);
}

int32_t	main(int argc, char **argv)
{
	t_game	*g;
	int		fd;

	g = ft_initiate(NULL);
	if(!g)
		return (-1);
	if (argc >= 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			return (printf("Error\nCould not open file"), -1);
		if (ft_check_file_type(argv[1]) != 0)
			return (-1);
		g->map = ft_check_map(fd, g, 0);
		if (g->map == NULL)
			return (-1);
		if (!(g->mlx = mlx_init((g->width * SCALE), (g->height * SCALE), "",
					true)))
			ft_error();
		ft_assets_ini(g, g->mlx);
		ft_draw_map(g->map, g, g->mlx);
		mlx_loop_hook(g->mlx, ft_window_handling, g->mlx);
		mlx_key_hook(g->mlx, ft_player_movement_keyhook, g);
		mlx_loop_hook(g->mlx, ft_water_animation, g);
		mlx_loop(g->mlx);
	}
	else
		return (-1);
	mlx_terminate(g->mlx);
	return (EXIT_SUCCESS);
}
