/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:11:22 by zkepes            #+#    #+#             */
/*   Updated: 2023/10/31 16:12:43 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Ask user for input and print out the return value of ...
 * ft_isascii and isascii .
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
	printf("test 'ft_isascii()' and 'isascii()', enter 1 character or 'ESC' \
to exit, confirm with Enter.\n If input is ascii character '0' - '177', \
than return not '0'\n");
	while (1)
	{
		scanf("%1s", input);
		if (*input == 27)
			return (0);
		printf("---------------------------------\n");
		printf("|'ft_isascii()' return: '%d'\t|\n", ft_isascii(*input));
		printf("|   'isascii()' return: '%d'\t|\n", isascii(*input));
		printf("---------------------------------\n");
	}
	return (0);
}

