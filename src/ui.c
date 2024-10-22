/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:05:17 by aehrl             #+#    #+#             */
/*   Updated: 2024/10/18 18:27:16 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// UI
// -> # of movement count should display on screen (instead of in the shell)
// Extra
// -> Display Win/Loose text
#include "so_long.h"

void	ft_ui_stepcount(t_game *g, int step_count)
{
	char	*num;

	num = ft_itoa(step_count);
	if (g->assets->font->count)
		mlx_delete_image(g->mlx, g->assets->font->count);
	g->assets->font->count = mlx_put_string(g->mlx, num, g->mlx->width - (SCALE
				* 1.2), g->mlx->height - (SCALE / 1.5));
	if (step_count < 10)
		mlx_resize_image(g->assets->font->count, SCALE / 3, SCALE / 2);
	else
		mlx_resize_image(g->assets->font->count, SCALE / 2, SCALE / 2);
}
