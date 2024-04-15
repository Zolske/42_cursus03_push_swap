NAME			= so_long
MAIN			= main/so_long.c
MAIN_OBJ		= obj/so_long.o
# BONUS
NAME_BONUS		= so_long_bonus
MAIN_BONUS 		= main/so_long_bonus.c
MAIN_BONUS_OBJ	= obj/so_long_bonus.o
# HEADER
HEADER			= include/so_long.h include/struct.h
# SOURCE
SRC_DIR			= src/
SRC				= $(addprefix $(SRC_DIR), \
			file_into_struct.c validate_map.c validate_map_help.c \
			floodfill.c floodfill_help.c \
			move.c move_player.c dragon.c dragon_can_move.c \
			array_4d.c update.c update_help.c keys_window.c \
			render.c put_img.c \
			init_img.c init_img_num.c init_img_player.c init_img_dragon_talk.c \
			free_img.c free_img_num.c free_img_player.c free_img_dragon_talk.c \
			free.c error.c)
# OBJECTS
OBJ_DIR			= obj/
OBJ				= $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
# LIBRARY
LIB_FT			= -L./libft -lft
LIB_MLX 		= -L./libmlx -lmlx
LIB_X			= -L/usr/X11/lib -lXext -lX11 -lz
LIB				= $(LIB_MLX) $(LIB_FT) $(LIB_X)
ARC				= libft/libft.a libmlx/libmlx.a
# COMPILE
CC				= cc
FLAGS			= -Werror -Wextra -Wall -g -O3

$(NAME): $(MAIN) $(SRC) $(OBJ_DIR) $(MAIN_OBJ) $(OBJ) $(HEADER) $(ARC)
	@if [ -f $(MAIN_BONUS_OBJ) ]; then \
	rm $(MAIN_BONUS_OBJ); \
	fi
	$(CC) $(FLAGS) $(OBJ_DIR)*.o -o $(NAME) $(LIB)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(MAIN_OBJ): $(MAIN) $(HEADER)
	@$(CC) -c $(FLAG) $(MAIN) -o $(MAIN_OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	@$(CC) -c $(FLAG) $< -o $@

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(MAIN_BONUS) $(SRC) $(OBJ_DIR) $(MAIN_BONUS_OBJ) $(OBJ) $(HEADER) $(ARC)
	@if [ -f $(MAIN_OBJ) ]; then \
	rm $(MAIN_OBJ); \
	fi
	$(CC) $(FLAGS) $(OBJ_DIR)*.o -o $(NAME_BONUS) $(LIB)

$(MAIN_BONUS_OBJ): $(MAIN_BONUS) $(HEADER)
	@$(CC) -c $(FLAG) $(MAIN_BONUS) -o $(MAIN_BONUS_OBJ)

$(ARC):
	@make -s -C libft
	@make -s -C libmlx -f Makefile.mk

clean:
	@rm -rf $(OBJ_DIR)
	@make -s clean -C libft

fclean: clean
	@rm -rf $(NAME) $(NAME_BONUS)
	@make -s fclean -C libft
	@make -s clean -C libmlx -f Makefile.mk

re: fclean $(NAME)

.PHONY: clean fclean re

# NOTE: for more informatin how to include the mlx_Library see:
# https://reactive.so/post/42-a-comprehensive-guide-to-so_long
# "mlx.h" file is included in "so_long.h" and located in dir "mlx_Linux"

# to targed a specific makefile use the -f and name of file e.g.
# make -s -C libmlx -f Makefile.mk

# to remove a file only if it exist, use if condition:
# 	@if [ -f $(MAIN_OBJ) ]; then \
#	rm $(MAIN_OBJ); \
#	fi