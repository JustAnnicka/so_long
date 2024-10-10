/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:17:55 by aehrl             #+#    #+#             */
/*   Updated: 2024/10/10 22:28:38 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

//Include Libraries
# include "libft.h"
# include "MLX42.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

#define GAME_SIZE 64

//Define typedef structure
//Make this a different structure with **cord
typedef	struct s_collect
{
	void				**pos;
	struct s_collect	*next;
}		t_collect;

typedef struct s_game
{
	int			width;
	int			height;
	int			p;
	int			c;
	int			e;
	int			c_c;
	int			c_e;
	//t_collect	**collect;
	int			p_start[2];
	int			exit[2];
	int			enemy[2];
	char		**path;
}		t_game;

//Map functions
int		ft_check_file_type(char *argv);
char 	**ft_check_map(int fd, t_game *game_stat);
void	ft_assign_coord(int y, int x, int *game_stat);
int		ft_check_if_enclosed(char **map, int y, int x);
void	ft_flood_fill(int y, int x, t_game *game_stat);

#endif