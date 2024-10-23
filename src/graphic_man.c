/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_man.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 13:54:28 by aehrl             #+#    #+#             */
/*   Updated: 2024/10/23 20:47:27 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Progam has to display in a new window
// -> Window management has to remain smooth (changing to another window, resize, etc)
// -> Pressing ESC or window X must close the window & quit the programm in a clean way
// The use of the images of MLX is mandatory
#include "so_long.h"

void	ft_clear_window(mlx_t *mlx, t_game *g)
{
	mlx_delete_image(mlx, g->assets->img);
	mlx_delete_image(mlx, g->assets->img_top);
	mlx_delete_image(mlx, g->assets->img_bot);
	mlx_delete_image(mlx, g->assets->img_tlc);
	mlx_delete_image(mlx, g->assets->img_trc);
	mlx_delete_image(mlx, g->assets->img_ctlc);
	mlx_delete_image(mlx, g->assets->img_cblc);
	mlx_delete_image(mlx, g->assets->img_blc);
	mlx_delete_image(mlx, g->assets->img_brc);
	mlx_delete_image(mlx, g->assets->img_ls);
	mlx_delete_image(mlx, g->assets->img_rs);
	mlx_delete_image(mlx, g->assets->empty);
	mlx_delete_image(mlx, g->assets->exit);
	mlx_delete_image(mlx, g->assets->enemy);
	mlx_delete_image(mlx, g->assets->collectable);
	g->end = 1;
	g->assets->player->instances[0].enabled = false;

}

static void	ft_shift_row_up(t_game *g, int row_size, int height)
{
	uint8_t		*buffer;
	int			row;
	uint8_t		*pixels;

	row = 0;
	pixels = g->assets->img->pixels;
	buffer = (uint8_t *)malloc(row_size);
	ft_memcpy(buffer, pixels, row_size);
	while (row < height - 1)
	{
		ft_memcpy(&pixels[row * row_size], &pixels[(row + 1) * row_size], row_size);
		row++;
	}
	ft_memcpy(&pixels[(height - 1) * row_size], buffer, row_size);
	free(buffer);
}
void 	ft_water_animation(void *param)
{
	t_game		*g;
	static int	frame;
	int			row_size;

	g = param;
    row_size = g->assets->img->width * 4;
	if(g->end == 1)
		return ;
	frame++;
	if (frame == 5)
	{
		ft_shift_row_up(g, row_size, g->assets->img->height);
		frame = 0;
	}
}
