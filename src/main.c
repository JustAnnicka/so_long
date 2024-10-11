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

static mlx_image_t	*image;

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
void	ft_player_movement(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		image->instances[0].y -= 64;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		image->instances[0].y += 64;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		image->instances[0].x -= 64;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		image->instances[0].x += 64;
}
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
	game_stat->p_start[0] = 0;
	game_stat->p_start[1] = 0;
	game_stat->exit[0] = 0;
	game_stat->exit[1] = 0;
	game_stat->enemy[0] = 0;
	game_stat->enemy[1] = 0;
}

/* int32_t	main(int argc, char **argv)
{
	mlx_t			*mlx;
	t_game			game_stat;
	t_asset			assets;
	int				fd;
	char			**map;

	map = NULL;
	ft_game_ini(&game_stat);
	if (argc >= 2)
	{
		if (ft_check_file_type(argv[1]) != 0)
			return (0);
		fd = open(argv[1], O_RDONLY);
		map = ft_check_map(fd, &game_stat);
		if (map == NULL)
			return (0);
		mlx_set_setting(MLX_MAXIMIZED, true);
		if (!(mlx = mlx_init((game_stat.width * SCALE), (game_stat.height
						* SCALE), "SO_LONG", true)))
			ft_error();
		ft_init_map_tex(&assets, mlx);
		ft_assets_ini(&assets, mlx);
		ft_draw_map(map, &game_stat, &assets, mlx);
		mlx_loop_hook(mlx, ft_player_movement, mlx);
		// mlx_loop_hook(mlx, ft_window_handling, mlx);
		mlx_loop(mlx);
	}
	//mlx_delete_image(mlx, img_empty_space);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
} */
void	ft_assets_ini(t_asset *assets, mlx_t *mlx)
{
	assets->wall->tex = mlx_load_png("./assets/png/tile_0018.png");
	assets->wall->tex_tlc = mlx_load_png("./assets/png/tile_0003.png");
	assets->wall->tex_trc = mlx_load_png("./assets/png/tile_0005.png");
	assets->wall->tex_top = mlx_load_png("./assets/png/tile_0004.png");
	assets->wall->tex_bot = mlx_load_png("./assets/png/tile_0038.png");
	assets->wall->tex_ls = mlx_load_png("./assets/png/tile_0020.png");
	assets->wall->tex_rs = mlx_load_png("./assets/png/tile_0022.png");
	assets->wall->tex_ctlc = mlx_load_png("./assets/png/tile_0073.png");
	assets->wall->tex_blc = mlx_load_png("./assets/png/tile_0037.png");
	assets->tex_empty = mlx_load_png("./assets/png/tile_0001.png");
	assets->tex_exit = mlx_load_png("./assets/png/tile_0135.png");
	assets->tex_enemy = mlx_load_png("./assets/png/tile_0126.png");
	assets->tex_player = mlx_load_png("./assets/png/tile_0125.png");
	assets->tex_collectable = mlx_load_png("./assets/png/tile_0104.png");
	assets->tex_foot = mlx_load_png("./assets/png/tile_0135.png");
	assets->wall->img = mlx_texture_to_image(mlx, assets->wall->tex);
	assets->wall->img_top = mlx_texture_to_image(mlx, assets->wall->tex_top);
	assets->wall->img_bot = mlx_texture_to_image(mlx, assets->wall->tex_bot);
	assets->wall->img_tlc = mlx_texture_to_image(mlx, assets->wall->tex_tlc);
	assets->wall->img_trc = mlx_texture_to_image(mlx, assets->wall->tex_trc);
	assets->wall->img_blc = mlx_texture_to_image(mlx, assets->wall->tex_blc);
	assets->wall->img_ctlc = mlx_texture_to_image(mlx, assets->wall->tex_ctlc);
	assets->wall->img_ls = mlx_texture_to_image(mlx, assets->wall->tex_ls);
	assets->wall->img_rs = mlx_texture_to_image(mlx, assets->wall->tex_rs);
	assets->empty = mlx_texture_to_image(mlx, assets->tex_empty);
	assets->exit = mlx_texture_to_image(mlx, assets->tex_exit);
	assets->enemy = mlx_texture_to_image(mlx, assets->tex_enemy);
	assets->player = mlx_texture_to_image(mlx, assets->tex_player);
	assets->collectable = mlx_texture_to_image(mlx, assets->tex_collectable);
	assets->foot = mlx_texture_to_image(mlx, assets->tex_foot);
	//mlx_put_pixel(assets->wall,14,14, 0x000000FF);
	//mlx_put_pixel(assets->wall,12,12, 0x000000FF);
	//mlx_put_pixel(assets->wall,10,10, 0x000000FF); 
	mlx_resize_image(assets->wall->img, SCALE, SCALE);
	mlx_resize_image(assets->wall->img_top, SCALE, SCALE);
	mlx_resize_image(assets->wall->img_bot, SCALE, SCALE);
	mlx_resize_image(assets->wall->img_tlc, SCALE, SCALE);
	mlx_resize_image(assets->wall->img_trc, SCALE, SCALE);
	mlx_resize_image(assets->wall->img_blc, SCALE, SCALE);
	mlx_resize_image(assets->wall->img_ctlc, SCALE, SCALE);
	mlx_resize_image(assets->wall->img_ls, SCALE, SCALE);
	mlx_resize_image(assets->wall->img_rs, SCALE, SCALE);
	mlx_resize_image(assets->empty, SCALE, SCALE);
	mlx_resize_image(assets->exit, 48, 48);
	mlx_resize_image(assets->enemy, 48, 48);
	mlx_resize_image(assets->player, 48, 48);
	mlx_resize_image(assets->collectable, 32, 32);
	mlx_resize_image(assets->foot, SCALE, SCALE);
}
int32_t	main(int argc, char **argv)
{
	mlx_t			*mlx;
	t_game			game_stat;
	t_asset			assets;
	int				fd;
	char			**map;

	map = NULL;
	ft_game_ini(&game_stat);
	if (argc >= 2)
	{
		if (ft_check_file_type(argv[1]) != 0)
			return (0);
		fd = open(argv[1], O_RDONLY);
		map = ft_check_map(fd, &game_stat);
		if (map == NULL)
			return (0);
		mlx_set_setting(MLX_MAXIMIZED, true);
		if (!(mlx = mlx_init((game_stat.width * SCALE), (game_stat.height
						* SCALE), "SO_LONG", true)))
			ft_error();
		ft_assets_ini(&assets, mlx);
		ft_draw_map(map, &game_stat, &assets, mlx);
		mlx_loop_hook(mlx, ft_player_movement, mlx);
		// mlx_loop_hook(mlx, ft_window_handling, mlx);
		mlx_loop(mlx);
	}
	//mlx_delete_image(mlx, img_empty_space);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}