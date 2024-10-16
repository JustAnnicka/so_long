/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 13:47:50 by aehrl             #+#    #+#             */
/*   Updated: 2024/10/16 17:24:43 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Map has to be constructed with 3 Components; Wall, Collectables & free space
// -> Map is composed of 5 characters 0(free space), 1(wall), C(collectable),
// -> Map must contain 1 exit, minimum 1 collectable & 1 player start position
// -> Map must be rectangular & enclosed by walls
// Any missconficuration must return an error

// Map checks
// -> Main check before opening the file
//	-> Check that the file is .ber (only .ber & nothing extended)
// -> Check before validating the content
//	-> Check that the map is rectangular
// -> Check to see if the map is valid
//	-> Wall enclosing the entire area
//	-> P == 1, E == 1, C >= 1
//	-> Check if player can reach the exit and all collectables

#include "so_long.h"

/* int	ft_check_file_type(char *argv)
{
	size_t	start;

	start = ft_strncmp
	//do a check for folder structure strncmp('.')
	while (*argv != '.' && *argv != '\0')
		argv++;
	if (*argv == '\0')
		return (ft_printf("Error\nWrong file type"), -1);
	if (ft_strncmp(".ber", argv, 4) != 0)
		return (ft_printf("Error\nWrong file type"), -1);
	if (argv[4] != '\0')
		return (ft_printf("Error\nWrong file type"), -1);
	return (0);
} */
int	ft_check_file_type(char *argv)
{
	//do a check for folder structure strncmp('.')
	while (*argv != '.' && *argv != '\0')
		argv++;
	if (*argv == '\0')
		return (ft_printf("Error\nWrong file type"), -1);
	if (ft_strncmp(".ber", argv, 4) != 0)
		return (ft_printf("Error\nWrong file type"), -1);
	if (argv[4] != '\0')
		return (ft_printf("Error\nWrong file type"), -1);
	return (0);
}

static int	ft_check_map_rect(char *map, t_game *game_stat)
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
			game_stat->width = i;
		if ((i - (game_stat->width * y) - (1 * y)) != game_stat->width)
			return (-1);
		y++;
		if (map[i] == '\0')
			break ;
		i++;
	}
	if (y < game_stat->height)
		return (-1);
	game_stat->height = y;
	return (0);
}

static int	ft_check_map_valid(char **map, t_game *game_stat)
{
	int y = 0;
	int x = 0;
	while (y < game_stat->height)
	{
		while (x < game_stat->width)
		{
			if (((y == 0 || y == game_stat->height - 1) && map[y][x] != '1')
				|| ((x == 0 || x == game_stat->width) && map[y][x] != '1'))
				return (ft_printf("Error\nMap error - map not enclosed"), -1);
			if (map[y][x] == 'P')
			{
				ft_assign_coord(y, x, game_stat->pos);
				game_stat->p++;
			}
			else if (map[y][x] == 'C')
				game_stat->c++;
			else if (map[y][x] == 'E')
			{
				ft_assign_coord(y, x, game_stat->exit);
				game_stat->e++;
			}
			if(map[y][x] != '1' && map[y][x] != '0' && map[y][x] != 'E'
				&& map[y][x] != 'P' && map[y][x] != 'C')
				return ft_printf("Error\nMap error - character not recognised");
			x++;
		}
		x = 0;
		y++;
	}
	if (game_stat->p == 0 || game_stat->p > 1)
		return (ft_printf("Error\nMap error - player start position"), -1);
	if (game_stat->e == 0 || game_stat->e > 1)
		return (ft_printf("Error\nMap error - exit"), -1);
	if (game_stat->c == 0)
		return (ft_printf("Error\nMap error - no collectable"), -1);
	return (0);
}

int	ft_check_map_solve(t_game *game_stat)
{
	ft_flood_fill(game_stat->pos[0], game_stat->pos[1], game_stat);
	if (game_stat->c_c != game_stat->c || game_stat->c_e != game_stat->e)
	{
		ft_printf("Error\nMap not solvable");
		exit(0);
	}
	return (0);
}

char	**ft_check_map(int fd, t_game *game_stat)
{
	char	*temp;
	char	*temp_map;
	int		i;

	i = 0;
	temp = NULL;
	temp_map = NULL;
	while ((temp = get_next_line(fd)) != NULL)
		temp_map = ft_gnl_strjoin(temp_map, temp);
	free(temp);
	if (ft_check_map_rect(temp_map, game_stat) == -1)
		return (ft_printf("Error\nThe map is not rectangular"), NULL);
	game_stat->map = ft_calloc(game_stat->height, sizeof(char *));
	game_stat->path = ft_calloc(game_stat->height, sizeof(char *));
	if (!game_stat->map || !game_stat->path)
		return (NULL);
	while (temp_map != NULL)
	{
		game_stat->map[i] = ft_extract_line(temp_map);
		game_stat->path[i] = ft_strdup(game_stat->map[i]);
		temp_map = ft_update_bufffer(temp_map);
		i++;
	}
	free(temp_map);
	if (ft_check_map_valid(game_stat->map, game_stat) == -1
		|| ft_check_map_solve(game_stat) == -1)
		return (NULL);
	return (game_stat->map);
}
