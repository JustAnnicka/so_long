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

//static mlx_image_t	*image;
//static char	**map;
//static char **path;

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
/* void	ft_player_movement(void *param)
{
	int x;
	int	y;
	mlx_t	*mlx;

	x = image->instances[0].x / SCALE;
	y = image->instances[0].y / SCALE;
	ft_printf("(%d, %d)\n", y, x);
	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_UP) && map[y - 1][x] == 'X')
		image->instances[0].y -= 64;
	else if (mlx_is_key_down(mlx, MLX_KEY_DOWN) && map[y + 1][x] == 'X')
		image->instances[0].y += 64;
	else if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		image->instances[0].x -= 64;
	else if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		image->instances[0].x += 64;
} */
void	ft_game_ini(t_game *game_stat)
{
	game_stat->width = 0;
	game_stat->height = 3;
	game_stat->p = 0;
	game_stat->c = 0;
	game_stat->e = 0;
	game_stat->c_c = 0;
	game_stat->c_e = 0;
	// game_stat->collect
	game_stat->pos[0] = 0;
	game_stat->pos[1] = 0;
	game_stat->exit[0] = 0;
	game_stat->exit[1] = 0;
	game_stat->enemy[0] = 0;
	game_stat->enemy[1] = 0;
}

void	ft_assets_ini(t_game *g, mlx_t *mlx)
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
	g->assets->tex_player = mlx_load_png("./assets/png/tile_0125.png");
	g->assets->tex_collectable = mlx_load_png("./assets/png/tile_0104.png");
	g->assets->tex_foot = mlx_load_png("./assets/png/tile_0135.png");
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
	//mlx_put_pixel(assets,14,14, 0x000000FF);
	//mlx_put_pixel(assets,12,12, 0x000000FF);
	//mlx_put_pixel(assets,10,10, 0x000000FF); 
}
int32_t	main(int argc, char **argv)
{
	mlx_t			*mlx;
	t_game			game_stat;
	int				fd;

	ft_game_ini(&game_stat);
	if (argc >= 2)
	{
		if (ft_check_file_type(argv[1]) != 0)
			return (0);
		fd = open(argv[1], O_RDONLY);
		game_stat.map = ft_check_map(fd, &game_stat);
		if (game_stat.map == NULL)
			return (0);
		mlx_set_setting(MLX_MAXIMIZED, true);
		if (!(mlx = mlx_init((game_stat.width * SCALE), 
			(game_stat.height * SCALE), "SO_LONG", true)))
			ft_error();
		ft_assets_ini(&game_stat, mlx);
		ft_resize_assets_img(&game_stat);
		//game_stat.player = game_stat.assets->player;
		ft_draw_map(game_stat.map, &game_stat, mlx);
		mlx_loop_hook(mlx, ft_window_handling, mlx);
		mlx_key_hook(mlx, ft_player_movement_keyhook, &game_stat);
		mlx_loop(mlx);
	}
	//mlx_delete_image(mlx, img_empty_space);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
