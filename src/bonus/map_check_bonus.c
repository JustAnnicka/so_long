/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 13:47:50 by aehrl             #+#    #+#             */
/*   Updated: 2024/11/04 20:57:12 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_file_type(char *argv)
{
	char	*p;

	if (!argv)
		return (ft_printf("Error\n File does not exist"), -1);
	p = ft_strrchr(argv, '.');
	if (p == 0)
		return (ft_printf("Error\nWrong file type"), -1);
	else if (ft_strncmp(".ber", p, 4) != 0)
		return (ft_printf("Error\nWrong file type"), -1);
	else if (p[4] != '\0')
		return (ft_printf("Error\nWrong file type"), -1);
	return (0);
}

int	ft_check_map_rect(char *map, t_game *g)
{
	int	y;
	int	i;
	int	count;

	y = 0;
	i = 0;
	count = ft_strlen(map);
	while (count-- > 0)
	{
		while (map[i] != '\n' && map[i] != '\0')
			i++;
		if (y == 0)
			g->width = i;
		if ((i - (g->width * y) - (1 * y)) != g->width)
			return (ft_printf("Error\nThe map is not rectangular"), -1);
		y++;
		if (map[i] == '\0')
			break ;
		i++;
	}
	if (y <= g->height)
		return (ft_printf("Error\nMap not solvable"), -1);
	g->height = y;
	return (0);
}

static int	ft_check_map_valid(char **map, t_game *g, int y, int x)
{
	while (y < g->height)
	{
		x = 0;
		while (x < g->width)
		{
			if (((y == 0 || y == g->height - 1) && map[y][x] != '1') || ((x == 0
						|| x == g->width) && map[y][x] != '1'))
				return (ft_printf("Error\nMap error - map not enclosed"), -1);
			if (map[y][x] == 'P')
				g->p += ft_assign_coord(y, x, g->pos);
			else if (map[y][x] == 'C')
				g->c++;
			else if (map[y][x] == 'E')
				g->e += ft_assign_coord(y, x, g->exit);
			if (map[y][x] != '1' && map[y][x] != '0' && map[y][x] != 'E'
				&& map[y][x] != 'P' && map[y][x] != 'C')
				return (ft_printf("Error\nMap error-char not recognised"), -1);
			x++;
		}
		y++;
	}
	if (g->p == 0 || g->p > 1 || g->e == 0 || g->e > 1 || g->c == 0)
		return (ft_map_error_handle(g), -1);
	return (0);
}

int	ft_check_map_solve(t_game *g)
{
	ft_flood_fill(g->pos[0], g->pos[1], g);
	if (g->c_c != g->c || g->c_e != g->e)
	{
		ft_printf("Error\nMap not solvable");
		return (ft_free_game(g), -1);
	}
	return (0);
}

char	**ft_check_map(int fd, t_game *g)
{
	char	*temp_map;
	int		i;

	i = 0;
	temp_map = ft_init_maps(g, fd);
	if (temp_map == NULL)
		return (ft_free_game(g), NULL);
	while (temp_map != NULL)
	{
		g->map[i] = ft_extract_line(temp_map);
		if (!g->map[i])
			return (free(temp_map), ft_free_game(g), NULL);
		g->path[i] = ft_strdup(g->map[i]);
		if (!g->path[i])
			return (free(temp_map), ft_free_game(g), NULL);
		temp_map = ft_update_bufffer(temp_map);
		i++;
	}
	free(temp_map);
	if (ft_check_map_valid(g->map, g, 0, 0) == -1
		|| ft_check_map_solve(g) == -1)
		return (ft_free_game(g), NULL);
	return (g->map);
}
