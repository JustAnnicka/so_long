/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_man.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 13:54:28 by aehrl             #+#    #+#             */
/*   Updated: 2024/10/18 17:21:37 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Progam has to display in a new window
// -> Window management has to remain smooth (changing to another window, resize, etc)
// -> Pressing ESC or window X must close the window & quit the programm in a clean way
// The use of the images of MLX is mandatory
#include "so_long.h"

void	ft_clear_map(mlx_t *mlx, t_game *game)
{
	mlx_delete_image(mlx, game->assets->img);
	mlx_delete_image(mlx, game->assets->img_top);
	mlx_delete_image(mlx, game->assets->img_bot);
	mlx_delete_image(mlx, game->assets->img_tlc);
	mlx_delete_image(mlx, game->assets->img_trc);
	mlx_delete_image(mlx, game->assets->img_ctlc);
	mlx_delete_image(mlx, game->assets->img_cblc);
	mlx_delete_image(mlx, game->assets->img_blc);
	mlx_delete_image(mlx, game->assets->img_brc);
	mlx_delete_image(mlx, game->assets->img_ls);
	mlx_delete_image(mlx, game->assets->img_rs);
	mlx_delete_image(mlx, game->assets->empty);
	mlx_delete_image(mlx, game->assets->exit);
	mlx_delete_image(mlx, game->assets->enemy);
	//ft_printf("TEST\n");
	//mlx_delete_image(mlx, game->assets->player);
	mlx_delete_image(mlx, game->assets->collectable);
	game->assets->player->instances[0].enabled = false;

}
/* void	ft_clear_map(t_game *game)
{
	int	i;

	i = game->assets->collectable->count + 1;
	while (--i >= 0)
		game->assets->collectable->instances[i].enabled = false;
	i = game->assets->empty->count + 1;
	while (--i >= 0)
		game->assets->empty->instances[i].enabled = false;
	i = game->assets->img->count + 1;
	 while (--i >= 0)
		game->assets->img->instances[i].enabled = false; 
	i = game->assets->img_top->count + 1;
	while (--i >= 0)
		game->assets->img_top->instances[i].enabled = false;
	i = game->assets->img_bot->count + 1;
	while (--i >= 0)
		game->assets->img_bot->instances[i].enabled = false;
	i = game->assets->img_trc->count + 1;
	while (--i >= 0)
		game->assets->img_trc->instances[i].enabled = false;
	game->assets->player->instances[0].enabled = false;
	game->assets->enemy->instances[0].enabled = false;
	game->assets->exit->instances[0].enabled = false;
	//void mlx_delete_image(mlx_t* mlx, mlx_image_t* image)
} */

/* void	ft_clear_window(mlx_t mlx)
{
	//SEE IF WE CAN MAKE A SIMILIAR FUNCTION TO mlx_delete_image BUT WITH ALL IMAGES IN THE LIST
	mlx_ctx_t	*mlxctx;

	mlxctx = mlx->context;
	
} */

/* void	ft_level_complete(mlx_t mlx, t_game *game)
{
	
} */
/* 
void	ft_level_fail(mlx_t mlx, t_game *game)
{

} */