NAME	= so_long
HEADER	= include/so_long.h include/struct.h
SRC_DIR = src/
SRC		= $(addprefix $(SRC_DIR), \
			so_long.c file_into_struct.c validate_map.c validate_map_help.c \
			error.c floodfill.c  floodfill_help.c free.c \
			validate_map.c render.c validate_map_help.c put_img.c \
			move_player.c init_img_player.c init_img.c array_4d.c free_img.c \
			free_img_player.c update.c move.c keys_window.c)
# print.c
OBJ_DIR	= obj/
OBJ		= $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
LIB_FT	= -L./libft -lft
LIB_MLX = -L./libmlx -lmlx
LIB_X	= -L/usr/X11/lib -lXext -lX11 -lz
LIB		= $(LIB_MLX) $(LIB_FT) $(LIB_X)
CC		= cc
FLAGS	= -Werror -Wextra -Wall -g -O3

$(NAME): $(OBJ_DIR) $(OBJ) $(SRC) $(HEADER) libft/libft.a
	$(CC) $(FLAGS) $(OBJ_DIR)*.o -o $(NAME) $(LIB)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	@$(CC) -c $(FLAG) $< -o $@

libft/libft.a:
	@make -s -C libft

clean:
	@rm -rf $(OBJ_DIR)
	@make -s clean -C libft

fclean: clean
	@rm -rf $(NAME)
	@make -s fclean -C libft

re: fclean $(NAME)

.PHONY: clean fclean re make_lib

# NOTE: for more informatin how to include the mlx_Library see:
# https://reactive.so/post/42-a-comprehensive-guide-to-so_long
# "mlx.h" file is included in "so_long.h" and located in dir "mlx_Linux"
