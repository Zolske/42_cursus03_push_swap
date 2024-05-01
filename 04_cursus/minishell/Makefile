NAME			= minishell
# HEADER
HEADER			= include/minishell.h
# SOURCE
SRC_DIR			= src/
SRC				= $(addprefix $(SRC_DIR), \
				minishell.c print.c free.c)
# OBJECTS
OBJ_DIR			= obj/
OBJ				= $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
# LIBRARY
LIB				= -L./libft -lft
ARC				= libft/libft.a
# COMPILE
CC				= cc
FLAGS			= -Werror -Wextra -Wall -g -lreadline

all: $(NAME)

$(NAME): $(SRC) $(OBJ_DIR) $(OBJ) $(HEADER) $(ARC)
	$(CC) $(FLAGS) $(OBJ_DIR)*.o -o $(NAME) $(LIB)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)/%.c $(HEADER)
	@$(CC) -c $(FLAG) $< -o $@

$(ARC):
	@make -s -C libft

clean:
	@rm -rf $(OBJ_DIR)
	@make -s clean -C libft

fclean: clean
	@rm -rf $(NAME)
	@make -s fclean -C libft

re: fclean $(NAME)

norm:
	clear && norminette main src

.PHONY: all clean fclean re norm

# YOU NEED to compile with the "-lreadline" flag!!
# e.g. cc -lreadline readline.c -o main