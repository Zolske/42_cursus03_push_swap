/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:09:18 by zkepes            #+#    #+#             */
/*   Updated: 2023/11/02 10:25:50 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include"../01_libft/libft.h"
#include<string.h>
#include<ctype.h>
int	main(void)
{
	char	input[1];

	input[0] = 1;
	printf("test 'ft_toupper()' and 'toupper()', enter 1 character or 'ESC' \
to exit, confirm with Enter.\n If input is character a lowercase alphabetic \
character it will be returned as uppercase, othewise tha same char. is returned.\n");
	while (1)
	{
		scanf("%1s", input);
		if (*input == 27)
			return (0);
		printf("---------------------------------\n");
		printf("|'ft_toupper()' return: '%c'\t|\n", ft_toupper(*input));
		printf("|   'toupper()' return: '%c'\t|\n", toupper(*input));
		printf("---------------------------------\n");
	}
	return (0);
}
