# Group project Instructions

## Structure
The work of the programm is devided into 3 **C cource files, main.c, ft_putchar.c, rush04.c**
### main.c
The purpuse of the main.c code is:
- contains the main() function and there for it works as the entry point into the programm
- calls the rush() function which is definede in the rush04.c source file
- passes the arguments which determen the outcome of the programm to the rush() function
### rush04.c
- handles the logic of which character to print when and where
- takes two arguments (*from main.c*) which are the width and the length of the print out

### ft_putchar.c
- takes an argument (*from rush()*) which is a character and prints it to the screen

## execution
- set the arguments for the colume with (*first argument*) and line hight (*second argument*) in `main.c`
- compile all 3 source files to one executable file  
`cc -Wall -Wextra -Werror ft_putchar.c main.c rush04.c`
- run the programm with the command
`./a.out`

### a detailed look at the rush() function
- this function runs first because it is the one called by main
- it decides what to print at which height
```c
void	rush(int col, int lin)
{
	int	y;

    //works as a count to keep track of the line height
	y = 1;
    //loops as long the counter is smaller or equall to the line height
	while (y <= lin)
	{
        //if on the first line
		if (y == 1)
		{
			write_line(col, 'A', 'B', 'C');
			ft_putchar('\n');
		}
        //if not on the first and not on the last line
		else if (y < lin)
		{
			write_line(col, 'B', ' ', 'B');
			ft_putchar('\n');
		}
        //if the others are not true then execute this one
		else
		{
			write_line(col, 'C', 'B', 'A');
			ft_putchar('\n');
		}
        //increase counter by one
		y++;
	}
}
```
- this function is called by rush and is used to decide which character to print at the line it is called on
```c
void	write_line(int col, char first_char, char second_char, char third_char)
{
	int	x;
    //print the first character of the line which is given by rush()
	ft_putchar(first_char);
    //x keeps track of the horizonal position
	x = 2;
    //loops till the end of the colume
	while (x <= col)
	{
        //don't run if there are no more then one colume and only if you are not on the last colume
		if (col >= 2 && x < col)
		{
			ft_putchar(second_char);
		}
        // else print the last character, there is more then one and you are at the end
		else
		{	
			ft_putchar(third_char);
		}
		x++;
	}
}
```

