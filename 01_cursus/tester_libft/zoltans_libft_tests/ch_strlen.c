/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:34:46 by zkepes            #+#    #+#             */
/*   Updated: 2023/10/31 16:49:49 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Ask the user to enter a string, the length of the string is than returned
 * without the null terminator.*/

#include<stdio.h>
#include"../01_libft/libft.h"
#include<string.h>

int		main(void)
{
	char	input[40];

	input[0] = 1;
	printf("test 'ft_isalnum()' and 'isalnum()', enter max 40 character or 'ESC' \
to exit, confirm with Enter.\n returns the length of the string without null \
terminatonr.\n");
	while (1)
	{
		scanf("%40s", input);
		if (*input == 27)
			return (0);
		printf("---------------------------------\n");
		printf("|'ft_strlen()' return: '%ld'\t|\n", ft_strlen(input));
		printf("|   'strlen()' return: '%ld'\t|\n", strlen(input));
		printf("---------------------------------\n");
	}
	return (0);
}
