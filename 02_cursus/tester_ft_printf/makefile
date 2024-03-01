# for testing ONLY
NAME 			= libftprintf.a
SRC 			= ft_printf.c
SRC_HLP 		= find.c hex.c print_more.c print.c write.c
LIBFT			= libft/libft.a
LIB_OBJ			= ft_isdigit.o ft_atoi.o ft_memset.o ft_strlen.o
BONUS 			= libftprintf_bonus.a
SRC_BON 		= ft_printf_bonus.c
SRC_HLP_BON 	= find_bonus.c hex_bonus.c print_more_bonus.c \
				print_bonus.c write_bonus.c
VPATH			= helper_functions helper_functions_bonus
CC = gcc
FLAG = -Wextra -Wall -Werror

all: $(NAME)

$(NAME): $(SRC:.c=.o) $(SRC_HLP:.c=.o) $(LIBFT) ft_printf.h
	ar -xv mylib.a $(LIB_OBJ)
	ar rcs $(NAME) $(SRC:.c=.o) $(SRC_HLP:.c=.o) $(LIB_OBJ)

$(LIBFT): 
	make -C libft

%.o: %.c
	$(CC) -c  $(FLAG) $< -o $@

bonus: $(BONUS)

$(BONUS): $(SRC_BON:.c=.o) $(SRC_HLP_BON:.c=.o) $(LIBFT) ft_printf_bonus.h
	ar -xv $(LIBFT) $(LIB_OBJ)
	ar rcs $(BONUS) $(SRC_BON:.c=.o) $(SRC_HLP_BON:.c=.o) $(LIB_OBJ)

clean:
	rm -rf *.o 
	make clean -C libft

fclean: clean
	make fclean -C libft
	rm -rf $(NAME)
	rm -rf $(BONUS)

re: fclean all

t:
	$(CC) -c  $(FLAG) tester.c -o tester.o
	make bonus
	gcc -o test -L. tester.o -lftprintf_bonus 

.PHONY: all clean fclean re bonus
