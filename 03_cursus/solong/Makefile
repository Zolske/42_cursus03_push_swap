NAME	= so_long
HEADER	= so_long.h libft.h
SRC		= so_long.c file_into_struct.c validate_map.c validate_map_help.c \
		  error.c print.c floodfill.c\
		  free.c
LIBFT	= libft/libft.a
CC		= cc
FLAGS	= -Werror -Wextra -Wall -g
IN_LIBX = -I/usr/include -Imlx_linux -O3
MLX_DIR = mlx_Linux
# Link X11 and MLX
MLX_FLAGS = -L$(MLX_DIR) -l$(MLX_DIR) -L/usr/lib/X11 -lXext -lX11
vpath libft.h libft

all: $(NAME)

$(NAME): $(HEADER) $(SRC) $(SRC:.c=.o) ${LIBFT}
	$(CC) $(FLAGS) $(SRC:.c=.o) $(MLX_FLAGS) -L./libft -lft -o $(NAME)

$(LIBFT):
	make -C libft

%.o: %.c
	$(CC) -c $(FLAG) $(INCLUDES) $< -o $@

clean:
	rm -rf *.o
	make clean -C libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re

# NOTE: for more informatin how to include the mlx_Library see:
# https://reactive.so/post/42-a-comprehensive-guide-to-so_long
# "mlx.h" file is included in "so_long.h" and located in dir "mlx_Linux"