/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:17:55 by aehrl             #+#    #+#             */
/*   Updated: 2024/10/18 14:55:18 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

//Include Libraries
# include "libft.h"
# include "MLX42.h"
//# include "../libs/MLX42/include/MLX42/MLX42_Int.h"
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

#define SCALE 64

typedef struct s_font
{
	//void	*font;
	mlx_image_t	*win;
	mlx_image_t	*loose;
	mlx_image_t	*steps;
}	t_font;
typedef	struct	s_asset
{
	t_font			*font;
	mlx_texture_t	*tex_exit;
	mlx_texture_t	*tex_empty;
	mlx_texture_t	*tex_enemy;
	mlx_texture_t	*tex_player;
	mlx_texture_t	*tex_collectable;
	mlx_texture_t	*tex_foot;
	mlx_image_t		*exit;
	mlx_image_t		*empty;
	mlx_image_t		*enemy;
	mlx_image_t		*player;
	mlx_image_t		*collectable;
	mlx_image_t		*foot;
	mlx_texture_t	*tex;
	mlx_texture_t	*tex_top;
	mlx_texture_t	*tex_bot;
	mlx_texture_t	*tex_tlc;
	mlx_texture_t	*tex_trc;
	mlx_texture_t	*tex_ls;
	mlx_texture_t	*tex_rs;
	mlx_texture_t	*tex_ctlc;
	mlx_texture_t	*tex_cblc;
	mlx_texture_t	*tex_blc;
	mlx_texture_t	*tex_brc;
	mlx_image_t		*img;
	mlx_image_t		*img_top;
	mlx_image_t		*img_bot;
	mlx_image_t		*img_tlc;
	mlx_image_t		*img_trc;
	mlx_image_t		*img_ctlc;
	mlx_image_t		*img_cblc;
	mlx_image_t		*img_blc;
	mlx_image_t		*img_brc;
	mlx_image_t		*img_ls;
	mlx_image_t		*img_rs;
}	t_asset;

typedef struct s_game
{
	mlx_t		*mlx;
	int			width;
	int			height;
	int			p;
	int			c;
	int			e;
	int			c_c;
	int			c_e;
	int			pos[2];
	int			exit[2];
	int			enemy[2];
	t_asset		*assets;
	char		**path;
	char		**map;

}	t_game;

//MAP CHECK FUNCTION
int		ft_check_file_type(char *argv);
char 	**ft_check_map(int fd, t_game *game_stat);
int		ft_check_if_enclosed(char **map, int y, int x);

//INITIATE FUNCTIONS
void	ft_init_map_tex(t_asset *map, mlx_t *mlx);
void	ft_assets_ini(t_game *g, mlx_t *mlx);
void	ft_resize_assets_img(t_game *g);

//GRAPHIC RENDERING FUNCTIONS
void	ft_draw_map(char **map, t_game *game, mlx_t *mlx);
void	ft_spawn_enemy(t_game *game);
void	ft_clear_map(mlx_t *mlx, t_game *game);

//GAME MECHANIC FUNCTIONS
//void	ft_player_movement_keyhook(mlx_key_data_t keydata, t_game *game, t_asset assets);
void	ft_player_movement_keyhook(mlx_key_data_t keydata, void* param);
void	ft_map_interact(t_game *game);
void	ft_enemy_movement(t_game *game);

//HELPER FUNCTIONS
void	ft_assign_coord(int y, int x, int *game_stat);
void	ft_flood_fill(int y, int x, t_game *game_stat);
//ERROR HANDLING
void	ft_error(void);

#endif