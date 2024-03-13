NAME	= pipex
HEADER	= pipex.h libft.h
SRC		= pipex.c init.c free.c error.c init_pipe.c \
		  print.c
LIBFT	= libft/libft.a
CC		= cc
FLAGS	= -Werror -Wextra -Wall -g
vpath libft.h libft

all: NAME

NAME: $(HEADER) $(SRC) $(SRC:.c=.o) ${LIBFT}
	$(CC) $(FLAGS) $(SRC:.c=.o) -L./libft -lft -o $(NAME)

$(LIBFT): 
	make -C libft

%.o: %.c
	$(CC) -c $(FLAG) $< -o $@

clean:
	rm -rf *.o
	make clean -C libft

fclean:
	rm -rf $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re