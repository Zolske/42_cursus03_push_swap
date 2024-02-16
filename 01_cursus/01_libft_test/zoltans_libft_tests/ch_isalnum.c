/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:11:22 by zkepes            #+#    #+#             */
/*   Updated: 2023/10/31 15:34:14 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Ask user for input and print out the return value of ...
 * ft_isalnum and isalnum .
 * The user has to enter and confirm 'ESC' to leave the program.
 * NOTE:	-read sting %s not character %c* otherwise the test function is
 * 			called twice.
 */

#include<stdio.h>
#include<ctype.h>
#include"../01_libft/libft.h"

int	main(void)
{
	char	input[1];

	input[0] = 1;
	printf("test 'ft_isalnum()' and 'isalnum()', enter 1 character or 'ESC' \
to exit, confirm with Enter.\n If input is character 'A'-'Z', 'a'-'z' '0'-'9', \
than return not '0'\n");
	while (1)
	{
		scanf("%1s", input);
		if (*input == 27)
			return (0);
		printf("---------------------------------\n");
		printf("|'ft_isalnum()' return: '%d'\t|\n", ft_isalnum(*input));
		printf("|   'isalnum()' return: '%d'\t|\n", isalnum(*input));
		printf("---------------------------------\n");
	}
	return (0);
}

