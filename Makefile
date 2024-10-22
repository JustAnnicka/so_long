# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/09 14:05:47 by aehrl             #+#    #+#              #
#    Updated: 2024/10/18 18:07:22 by aehrl            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = so_long
CFLAGS  = -Wall -Wextra -Werror
SRC		= src/main.c src/map_check.c src/map_utils.c src/map_gen.c src/init.c\
		  src/player.c src/enemy.c src/graphic_man.c src/ui.c
OBJ		= ${SRC:.c=.o}
LIBFT = libs/libft/libft.a
INC = inc
MLX = libs/MLX42/libmlx42.a
COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

#ifeq ($(shell whoami), aehrl)
#	BREW = /opt/homebrew/Cellar/glfw/3.3.8/lib/
#else
#	BREW = "/Users/$(USER)/.brew/opt/glfw/lib/"
#endif

all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJ)
	@gcc $(CFLAGS) $(OBJ) $(MLX) -lglfw -L $(INC) -o $(NAME) $(LIBFT)
#	@gcc $(CFLAGS) $(OBJ) $(MLX) -lglfw -L $(BREW) $(INC) -o $(NAME) $(LIBFT)
	@echo "$(COLOUR_GREEN)🔥 🔥 Compliling Everything ✅ ✅$(COLOUR_END)"

$(LIBFT):
	@make -C libs/libft/

$(MLX):
	@make -C libs/MLX42/
clean:
	@rm -rf $(OBJ)
	@make -C libs/MLX42/ clean
	@make -C libs/libft/ clean
	@echo "$(COLOUR_RED)🔥 🔥 Deleting all .o Files 🗑️ 🗑️$(COLOUR_END)"
fclean: clean
	@rm -f $(NAME)
#	@make -C libs/MLX42/ fclean
	@make -C libs/libft/ fclean
	@echo "$(COLOUR_RED)🔥 🔥 Deleting .a File 🗑️ 🗑️$(COLOUR_END)"

%.o: %.c
	@gcc $(CFLAGS) -I ./$(INC) -o $@ -c $<

re: fclean all

.PHONY: all clean fclean re mlx42