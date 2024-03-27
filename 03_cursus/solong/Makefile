NAME	= so_long
HEADER	= so_long.h libft.h
SRC		= so_long.c file_into_struct.c validate_map.c validate_map_help.c \
		  error.c print.c floodfill.c\
		  free.c
LIBFT	= libft/libft.a
CC		= cc
FLAGS	= -Werror -Wextra -Wall -g
vpath libft.h libft

all: $(NAME)

$(NAME): $(HEADER) $(SRC) $(SRC:.c=.o) ${LIBFT}
	$(CC) $(FLAGS) $(SRC:.c=.o) -L./libft -lft -o $(NAME)

$(LIBFT):
	make -C libft

%.o: %.c
	$(CC) -c $(FLAG) $< -o $@

clean:
	rm -rf *.o
	make clean -C libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
