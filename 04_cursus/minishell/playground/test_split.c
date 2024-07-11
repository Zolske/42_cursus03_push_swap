#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

/*if the the input string is empty or null, then ft_split returns NULL*/
int	main(int argc, char *argv[])
{
	char		**tab;
	const char	DELIMITER = '$';
	int			idx;
	(void) argc;
	// (void) argv;

		tab = ft_split("$1234$HOME$?$NO_VAR", DELIMITER);

		// printf("argv: |%s|\n", *tab);
		// free(tab);
		idx = 0;
		if (argv[1])
		{
			// printf("tab is true %s\n", *tab);
			while (tab[idx])
			{
				printf("%s\n", tab[idx]);
				idx++;
			}
		}
		else
			printf("tab is false %s\n", *tab);
}