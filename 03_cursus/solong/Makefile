NAME	= so_long
NAME_B	= so_long_bonus
HEADER	= include/so_long.h include/struct.h
SRC_DIR = src/
MAIN	= main/so_long.c
MAIN_O	= obj/so_long.o
MAIN_B	= main/so_long_bonus.c
MAIN_BO	= obj/so_long_bonus.o
SRC		= $(addprefix $(SRC_DIR), \
			file_into_struct.c validate_map.c validate_map_help.c \
			error.c floodfill.c floodfill_help.c free.c \
			validate_map.c render.c validate_map_help.c put_img.c \
			move_player.c init_img_player.c init_img.c array_4d.c free_img.c \
			free_img_player.c update.c move.c keys_window.c init_img_dragon_talk.c \
			dragon.c free_img_dragon_talk.c init_img_num.c free_img_num.c update_help.c dragon_can_move.c \
			)
# print.c
OBJ_DIR	= obj/
OBJ		= $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
LIB_FT	= -L./libft -lft
LIB_MLX = -L./libmlx -lmlx
LIB_X	= -L/usr/X11/lib -lXext -lX11 -lz
LIB		= $(LIB_MLX) $(LIB_FT) $(LIB_X)
CC		= cc
FLAGS	= -Werror -Wextra -Wall -g -O3

$(NAME): $(MAIN) $(SRC) $(OBJ_DIR) $(MAIN_O) $(OBJ) $(HEADER) libft/libft.a
	@if [ -f $(MAIN_BO) ]; then \
	rm $(MAIN_BO); \
	fi
	$(CC) $(FLAGS) $(OBJ_DIR)*.o -o $(NAME) $(LIB)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(MAIN_O): $(MAIN) $(HEADER)
	@$(CC) -c $(FLAG) $(MAIN) -o $(MAIN_O)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	@$(CC) -c $(FLAG) $< -o $@

bonus: $(NAME_B)

$(NAME_B): $(MAIN_B) $(SRC) $(OBJ_DIR) $(MAIN_BO) $(OBJ) $(HEADER) libft/libft.a
	@if [ -f $(MAIN_O) ]; then \
	rm $(MAIN_O); \
	fi
	@echo "bonus";
	$(CC) $(FLAGS) $(OBJ_DIR)*.o -o $(NAME_B) $(LIB)

$(MAIN_BO): $(MAIN_B) $(HEADER)
	@$(CC) -c $(FLAG) $(MAIN_B) -o $(MAIN_BO)

libft/libft.a:
	@make -s -C libft

clean:
	@rm -rf $(OBJ_DIR)
	@make -s clean -C libft

fclean: clean
	@rm -rf $(NAME) $(NAME_B)
	@make -s fclean -C libft

re: fclean $(NAME)

.PHONY: clean fclean re make_lib

.SECONDARY: $(MAIN_B)

# NOTE: for more informatin how to include the mlx_Library see:
# https://reactive.so/post/42-a-comprehensive-guide-to-so_long
# "mlx.h" file is included in "so_long.h" and located in dir "mlx_Linux"
