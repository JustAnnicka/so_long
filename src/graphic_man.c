/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_man.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 13:54:28 by aehrl             #+#    #+#             */
/*   Updated: 2024/10/22 19:37:06 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Progam has to display in a new window
// -> Window management has to remain smooth (changing to another window, resize, etc)
// -> Pressing ESC or window X must close the window & quit the programm in a clean way
// The use of the images of MLX is mandatory
#include "so_long.h"

void	ft_clear_window(mlx_t *mlx, t_game *game)
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
	mlx_delete_image(mlx, game->assets->collectable);
	game->end = 1;
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

/* void	ft_shift_row_up(t_game *g, int row_size, int height)
{
	uint8_t		*buffer;
	int			row;
	int			*pixels;

	row = 0;
	pixels = (int *)g->assets->img->pixels;
	buffer = (uint8_t *)malloc(row_size);
	ft_memcpy(buffer, pixels, row_size);
	while (row < height - 1)
	{
		ft_memcpy(&pixels[row * row_size], &pixels[(row + 1) * row_size], row_size);
		row++;
	}
	ft_memcpy(&pixels[(height - 1) * row_size], buffer, row_size);
	free(buffer);

} */
void 	ft_shift_first_row_up(void *param)
{
	t_game		*g;
	static int	frame;
	int			row;
	int			row_size;
	uint8_t		*buffer;

	g = param;
	row = 0;
	buffer = 0;
    row_size = g->assets->img->width * 4;
	if(g->end == 1)
		return ;
	frame++;
	if (frame == 5)
	{
		buffer = (uint8_t *)malloc(row_size);
		ft_memcpy(buffer, g->assets->img->pixels, row_size);
		while (row < (int)g->assets->img->height - 1)
		{
			ft_memcpy(&g->assets->img->pixels[row * row_size], &g->assets->img->pixels[(row + 1) * row_size], row_size);
			row++;
		}
		ft_memcpy(&g->assets->img->pixels[((int)g->assets->img->height - 1) * row_size], buffer, row_size);
		free(buffer);
		frame = 0;
	}
}

/* void	ft_level_complete(t_game *game)
{
	mlx_texture_t	*tex;
	mlx_image_t		*blk;


} */
/* 
void	ft_level_fail(mlx_t mlx, t_game *game)
{

} */