EXE		=	add_history chdir dir fstat getcwd getenv rl_on_new_line \
			rl_replace_line stat unlink int_env
FLAG	=	-Werror -Wextra -Wall

all: $(EXE) $(EXE)*c

%: %.c
	@$(CC) $(FLAG) $< -o $@ -lreadline -lhistory

clean:
	rm $(EXE)
