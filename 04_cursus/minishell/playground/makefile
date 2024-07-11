EXE		=	add_history chdir dir fstat getcwd getenv rl_on_new_line \
			rl_replace_line stat unlink init_env test_split
LIB		= -L../libft -lft
FLAG	=	-Werror -Wextra -Wall

all: $(EXE) $(EXE)*c

%: %.c
	@$(CC) $(FLAG) $< -o $@ $(LIB) -lreadline -lhistory

clean:
	rm $(EXE)
