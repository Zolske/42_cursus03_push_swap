vpath libft.h ../01_libft
vpath libft.a ../01_libft
# add names of test programs to the list
PROGRAM = \
 ch_isdigit ch_isalnum ch_isascii ch_isprint ch_strlen ch_memset ch_bzero \
 ch_memcpy ch_memmove ch_strlcpy ch_strlcat ch_toupper ch_tolower ch_strchr \
 ch_strrchr ch_strncmp ch_memchr ch_strnstr

 LIBARY = -lbsd

all: $(PROGRAM)

#$(PROGRAM): $@.o libft.h
#	echo $@
#	gcc $@.o -L../01_libft -lft -o $@

# '$@' the name of the target which coursed the rule to run
$(PROGRAM): $(PROGRAM:=.o) libft.h libft.a
	gcc $@.o -L../01_libft -lft $(LIBARY) -o $@

%.o: %.c
	gcc -c $< -o $@

clean:
	rm *.o

fclean: clean
	rm $(PROGRAM)

re: fclean all

.PHONY = all clean fclean re
