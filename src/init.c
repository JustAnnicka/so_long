/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 20:52:42 by aehrl             #+#    #+#             */
/*   Updated: 2024/10/11 22:06:58 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
//INITITATE FILE

//INITIATE IMAGES MAP

//INITIATE IMAGES ASSETS

void	ft_init_map_tex(t_asset *map, mlx_t *mlx)
{
	map->wall->tex = mlx_load_png("./assets/png/tile_0018.png");
	map->wall->tex_tlc = mlx_load_png("./assets/png/tile_0003.png");
	map->wall->tex_trc = mlx_load_png("./assets/png/tile_0005.png");
	map->wall->tex_top = mlx_load_png("./assets/png/tile_0004.png");
	map->wall->tex_bot = mlx_load_png("./assets/png/tile_0038.png");
	map->wall->tex_ls = mlx_load_png("./assets/png/tile_0020.png");
	map->wall->tex_rs = mlx_load_png("./assets/png/tile_0022.png");
	map->wall->tex_ctlc = mlx_load_png("./assets/png/tile_0073.png");
	map->wall->tex_blc = mlx_load_png("./assets/png/tile_0037.png");
	map->wall->img = mlx_texture_to_image(mlx, map->wall->tex);
	map->wall->img_top = mlx_texture_to_image(mlx, map->wall->tex_top);
	map->wall->img_bot = mlx_texture_to_image(mlx, map->wall->tex_bot);
	map->wall->img_tlc = mlx_texture_to_image(mlx, map->wall->tex_tlc);
	map->wall->img_trc = mlx_texture_to_image(mlx, map->wall->tex_trc);
	map->wall->img_blc = mlx_texture_to_image(mlx, map->wall->tex_blc);
	map->wall->img_ctlc = mlx_texture_to_image(mlx, map->wall->tex_ctlc);
	map->wall->img_ls = mlx_texture_to_image(mlx, map->wall->tex_ls);
	map->wall->img_rs = mlx_texture_to_image(mlx, map->wall->tex_rs);
	
}
/* void	ft_init_map_tex(t_tmap *map, mlx_t *mlx)
{
	map->tex = mlx_load_png("./assets/png/tile_0018.png");
	map->tex_tlc = mlx_load_png("./assets/png/tile_0003.png");
	map->tex_trc = mlx_load_png("./assets/png/tile_0005.png");
	map->tex_top = mlx_load_png("./assets/png/tile_0004.png");
	map->tex_bot = mlx_load_png("./assets/png/tile_0038.png");
	map->tex_ls = mlx_load_png("./assets/png/tile_0020.png");
	map->tex_rs = mlx_load_png("./assets/png/tile_0022.png");
	map->tex_ctlc = mlx_load_png("./assets/png/tile_0073.png");
	map->tex_blc = mlx_load_png("./assets/png/tile_0037.png");
	map->img = mlx_texture_to_image(mlx, map->tex);
	map->img_top = mlx_texture_to_image(mlx, map->tex_top);
	map->img_bot = mlx_texture_to_image(mlx, map->tex_bot);
	map->img_tlc = mlx_texture_to_image(mlx, map->tex_tlc);
	map->img_trc = mlx_texture_to_image(mlx, map->tex_trc);
	map->img_blc = mlx_texture_to_image(mlx, map->tex_blc);
	map->img_ctlc = mlx_texture_to_image(mlx, map->tex_ctlc);
	map->img_ls = mlx_texture_to_image(mlx, map->tex_ls);
	map->img_rs = mlx_texture_to_image(mlx, map->tex_rs);
	
} */
void	ft_resize_assets_img(t_asset *assets)
{
	mlx_resize_image(assets->wall->img, SCALE, SCALE);
	mlx_resize_image(assets->wall->img_top, SCALE, SCALE);
	mlx_resize_image(assets->wall->img_bot, SCALE, SCALE);
	mlx_resize_image(assets->wall->img_tlc, SCALE, SCALE);
	mlx_resize_image(assets->wall->img_trc, SCALE, SCALE);
	mlx_resize_image(assets->wall->img_blc, SCALE, SCALE);
	mlx_resize_image(assets->wall->img_ctlc, SCALE, SCALE);
	mlx_resize_image(assets->wall->img_ls, SCALE, SCALE);
	mlx_resize_image(assets->wall->img_rs, SCALE, SCALE);
}
/* void	ft_assets_ini(t_asset *assets, mlx_t *mlx)
{
	assets->tex_empty = mlx_load_png("./assets/png/tile_0001.png");
	assets->tex_exit = mlx_load_png("./assets/png/tile_0135.png");
	assets->tex_enemy = mlx_load_png("./assets/png/tile_0126.png");
	assets->tex_player = mlx_load_png("./assets/png/tile_0125.png");
	assets->tex_collectable = mlx_load_png("./assets/png/tile_0104.png");
	assets->tex_foot = mlx_load_png("./assets/png/tile_0135.png");
	assets->empty = mlx_texture_to_image(mlx, assets->tex_empty);
	assets->exit = mlx_texture_to_image(mlx, assets->tex_exit);
	assets->enemy = mlx_texture_to_image(mlx, assets->tex_enemy);
	assets->player = mlx_texture_to_image(mlx, assets->tex_player);
	assets->collectable = mlx_texture_to_image(mlx, assets->tex_collectable);
	assets->foot = mlx_texture_to_image(mlx, assets->tex_foot);
	ft_printf("HELLO");
	//ft_init_map_tex(assets, mlx);
	ft_resize_assets_img(assets);
	ft_printf("HELLO");
} */
/* void	ft_assets_ini(t_asset *assets, mlx_t *mlx)
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
} */
/* void	ft_assets_ini(t_asset *assets, mlx_t *mlx)
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
	assets->wall->tex_empty = mlx_load_png("./assets/png/tile_0001.png");
	assets->tex_exit = mlx_load_png("./assets/png/tile_0135.png");
	assets->tex_enemy = mlx_load_png("./assets/png/tile_0126.png");
	assets->tex_player = mlx_load_png("./assets/png/tile_0125.png");
	assets->tex_collectable = mlx_load_png("./assets/png/tile_0104.png");
	assets->tex_foot = mlx_load_png("./assets/png/tile_0135.png");
	assets->wall->img = mlx_texture_to_image(mlx, assets->wall, tex_wall);
	assets->wall->img_top = mlx_texture_to_image(mlx, assets->wall->tex_top);
	assets->wall->img_bot = mlx_texture_to_image(mlx, assets->wall->tex_bot);
	assets->wall->img_tlc = mlx_texture_to_image(mlx, assets->wall->tex_tlc);
	assets->wall->img_trc = mlx_texture_to_image(mlx, assets->wall->tex_trc);
	assets->wall->tex_blc = mlx_texture_to_image(mlx, assets->wall->tex_blc);
	assets->wall->tex_ctlc = mlx_texture_to_image(mlx, assets->wall->tex_ctlc);
	assets->wall->tex_ls = mlx_texture_to_image(mlx, assets->wall->tex_ls);
	assets->wall->rs = mlx_texture_to_image(mlx, assets->wall->tex_rs);
	assets->empty = mlx_texture_to_image(mlx, assets->wall->tex_empty);
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
	mlx_resize_image(assets->wall->tex_blc, SCALE, SCALE);
	mlx_resize_image(assets->wall->tex_ctlc, SCALE, SCALE);
	mlx_resize_image(assets->wall->tex_ls, SCALE, SCALE);
	mlx_resize_image(assets->wall->rs, SCALE, SCALE);
	mlx_resize_image(assets->empty, SCALE, SCALE);
	mlx_resize_image(assets->exit, 48, 48);
	mlx_resize_image(assets->enemy, 48, 48);
	mlx_resize_image(assets->player, 48, 48);
	mlx_resize_image(assets->collectable, 32, 32);
	mlx_resize_image(assets->foot, SCALE, SCALE);
} */