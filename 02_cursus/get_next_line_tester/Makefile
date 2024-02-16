# define the C compiler to use
CC              = gcc
# define compiler flags
CFLAGS          = -Wall -Werror -Wextra
CFLAGS          =
# define library paths in addition to to /usr/lib
LFLAGS          =
# define the object files that this project needs
OBJFILES        = tester.o get_next_line.o get_next_line_utils.o
# define the name of the executable file
MAIN            = test
# Marcro definition
MACRO			=  -DBUFFER_SIZE=4
#MACRO			=

# path to files
vpath %.o ../get_next_line
vpath %.c ../get_next_line
vpath %.h ../get_next_line
# all of the below is generic - one typically only adjusts the above

all: $(MAIN)

$(MAIN): $(OBJFILES) get_next_line.h #get_next_line_bonus.h
	$(CC) -g3 $(CFLAGS) $(MACRO) $(OBJFILES) -o $(MAIN)

%.o: %.c
	$(CC) -g3 $(CFLAGS) $(MACRO) -c $< -o $@

clean:	     # remove object files
	rm $(OBJFILES)

fclean: clean	      # remove object, executable and libraries
	rm $(MAIN) *.a

re: fclean all                             # remove object, executable, library files and rebuild

.PHONY: all clean fclean re
