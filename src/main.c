/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 18:05:32 by aehrl             #+#    #+#             */
/*   Updated: 2024/10/10 22:28:53 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Written by Bruh
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "so_long.h"
#include <string.h>

static mlx_image_t	*image;

// -----------------------------------------------------------------------------

static void	ft_error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	ft_window_handling(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}
void	ft_player_movement(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		image->instances[0].y -= 64;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		image->instances[0].y += 64;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		image->instances[0].x -= 64;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		image->instances[0].x += 64;
}
void	ft_game_ini(t_game *game_stat)
{
	game_stat->width = 0;
	game_stat->height = 3;
	game_stat->p = 0;
	game_stat->c = 0;
	game_stat->e = 0;
	game_stat->c_c = 0;
	game_stat->c_e = 0;
	// game_stat->collect
	game_stat->p_start[0] = 0;
	game_stat->p_start[1] = 0;
	game_stat->exit[0] = 0;
	game_stat->exit[1] = 0;
	game_stat->enemy[0] = 0;
	game_stat->enemy[1] = 0;
}
// -----------------------------------------------------------------------------
int32_t	main(int argc, char **argv)
{
	mlx_t			*mlx;
	mlx_texture_t	*tex_empty_space;
	mlx_image_t		*img_empty_space;
	mlx_texture_t	*tex_wall;
	mlx_image_t		*img_wall;
	t_game	game_stat;
	int				fd;
	char			**map;

	map = NULL;
	ft_game_ini(&game_stat);
	if (argc >= 2)
	{
		if (ft_check_file_type(argv[1]) != 0)
			return (0);
		fd = open(argv[1], O_RDONLY);
		map = ft_check_map(fd, &game_stat);
		if (map == NULL)
			return (0);
		mlx_set_setting(MLX_MAXIMIZED, true);
		// Gotta error check this stuff
		if (!(mlx = mlx_init((game_stat.width * GAME_SIZE), (game_stat.height
						* GAME_SIZE), "SO_LONG", true)))
			ft_error();
		tex_empty_space = mlx_load_png("./assets/png/sand_1.png");
		tex_wall = mlx_load_png("./assets/png/water.png");
		if (!tex_empty_space || !tex_wall)
			ft_error();
		img_empty_space = mlx_texture_to_image(mlx, tex_empty_space);
		img_wall = mlx_texture_to_image(mlx, tex_wall);
		if (!img_empty_space || !img_wall)
			ft_error();
		// Display an instance of the image
		if (mlx_image_to_window(mlx, img_empty_space, 0, 0) < 0
			|| mlx_image_to_window(mlx, img_wall, 0, 64))
			ft_error();
		mlx_loop_hook(mlx, ft_player_movement, mlx);
		// mlx_loop_hook(mlx, ft_window_handling, mlx);
		mlx_loop(mlx);
	}
	mlx_delete_image(mlx, img_empty_space);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

/* int32_t main(void)
{
		ft_error ();
		ft_error ();
		ft_error ();

	mlx_t* mlx;
	mlx_texture_t*	tex_empty_space;
	mlx_image_t*	img_empty_space;
	mlx_texture_t*	tex_wall;
	mlx_image_t*	img_wall;
	mlx_set_setting(MLX_MAXIMIZED, true);
	// Gotta error check this stuff
	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
		if (!(image = mlx_new_image(mlx, 128, 128)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	mlx_loop_hook(mlx, ft_randomize, mlx);
	mlx_loop_hook(mlx, ft_hook, mlx);
	// CREATE AND DISPLAY AN IMAGE (Currently just set to white)
	tex_empty_space = mlx_load_png("./assets/png/sand_1.png");
	tex_wall = mlx_load_png("./assets/png/water.png");
	if (!tex_empty_space || !tex_wall)
		ft_error();
	img_empty_space = mlx_texture_to_image(mlx, tex_empty_space);
	img_wall = mlx_texture_to_image(mlx, tex_wall);
	if (!img_empty_space || !img_wall)
	// Display an instance of the image
	if (mlx_image_to_window(mlx, img_empty_space, 0, 0) < 0
		|| mlx_image_to_window(mlx, img_wall, 0, 64))
	mlx_loop_hook(mlx, ft_player_movement, mlx);
	//mlx_loop_hook(mlx, ft_window_handling, mlx);
	mlx_loop(mlx);
	mlx_delete_image(mlx, img_empty_space);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
 */