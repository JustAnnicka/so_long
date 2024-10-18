/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 18:05:32 by aehrl             #+#    #+#             */

/*   Updated: 2024/10/11 18:00:10 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Written by Bruh
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "so_long.h"
#include <string.h>


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

t_game	*ft_game_ini(t_game *game)
{
	game->mlx = malloc(sizeof(mlx_t));
	if (!game->mlx)
        return (NULL); 
	game->width = 0;
	game->height = 3;
	game->p = 0;
	game->c = 0;
	game->e = 0;
	game->c_c = 0;
	game->c_e = 0;
	game->pos[0] = 0;
	game->pos[1] = 0;
	game->exit[0] = 0;
	game->exit[1] = 0;
	game->enemy[0] = 0;
	game->enemy[1] = 0;
	game->assets = malloc(sizeof(t_asset));
	if (!game->assets)
        return (NULL); 
	game->assets->font = malloc(sizeof(t_font));
	if (!game->assets->font)
        return (NULL); 
	return (game);
}

int32_t	main(int argc, char **argv)
{
	t_game				*game;
	int					fd;
	
	game = malloc(sizeof(t_game));
	if (!game)
        return (-1); 
	game = ft_game_ini(game);
	if (argc >= 2)
	{
		if (ft_check_file_type(argv[1]) != 0)
			return (0);
		fd = open(argv[1], O_RDONLY);
		game->map = ft_check_map(fd, game);
		if (game->map == NULL)
			return (0);
		//mlx_set_setting(MLX_MAXIMIZED, true);
		if (!(game->mlx = mlx_init((game->width * SCALE), 
			(game->height * SCALE), "SO_LONG", true)))
			ft_error();
		//mlxctx = game->mlx->context;
		ft_assets_ini(game, game->mlx);
		//add ft_draw_map into ft_init(ft_assets_ini)s
		ft_draw_map(game->map, game, game->mlx);
		mlx_loop_hook(game->mlx, ft_window_handling, game->mlx);
		mlx_key_hook(game->mlx, ft_player_movement_keyhook, game);
		int i = game->assets->empty->count - 1;
		ft_printf("wall - z:%d\n", game->assets->empty->instances[i].z);
		ft_printf("steps - z:%d\n", game->assets->font->steps->instances[0].z);
		/* if (game.c_c == 0 && game.pos[0] == game.exit[0] && game.exit[1] == game.pos[1])
			mlx_lstclear((mlx_list_t**)(&mlxctx->images), &mlx_free_image); */
		mlx_loop(game->mlx);
	}
	else
		return (-1);
	//mlx_delete_image(mlx, img_empty_space); <- This should go into a clear function
	mlx_terminate(game->mlx);
	return (EXIT_SUCCESS);
}
