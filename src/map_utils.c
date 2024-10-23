/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:30:01 by aehrl             #+#    #+#             */
/*   Updated: 2024/10/23 15:12:33 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_fill_window(t_game *g, mlx_t *mlx, mlx_image_t *img)
{
	int	y;
	int	x;

	y = -1;
	x = -1;
	while (y++ < g->height - 1)
	{
		while (x++ < g->width - 1)
		{
			if (mlx_image_to_window(mlx, img, SCALE * x , SCALE * y) < 0)
				ft_error();
		}
		x = -1;
	}
}

int	ft_assign_coord(int y, int x, int *g)
{
	g[0] = y;
	g[1] = x;
	return (1);
}
void	ft_init_maps(t_game *g)
{
	g->map = ft_calloc(g->height, sizeof(char *));
	g->path = ft_calloc(g->height, sizeof(char *));
}

void ft_map_error_handle(t_game *g)
{
	if (g->p == 0 || g->p > 1)
		ft_printf("Error\nMap error - player start position");
	if (g->e == 0 || g->e > 1)
		ft_printf("Error\nMap error - exit");
	if (g->c == 0)
		ft_printf("Error\nMap error - no collectable");
}

void	ft_flood_fill(int y, int x, t_game *g)
{
	if ((y < 0 || y >= g->height || x < 0 || x >= g->width
			|| g->path[y][x] == '1' || g->path[y][x] == 'X'))
		return ;
	if (g->path[y][x] != '1'){
		if (g->path[y][x] == 'C')
			g->c_c++;
		if (g->path[y][x] == 'E')
			g->c_e++;
		g->path[y][x] = 'X';
	}
	ft_flood_fill(y + 1, x, g);
	ft_flood_fill(y - 1, x, g);
	ft_flood_fill(y, x + 1, g);
	ft_flood_fill(y, x - 1, g);
	return ;
}
