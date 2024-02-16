/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:35:24 by zkepes            #+#    #+#             */
/*   Updated: 2023/11/02 16:56:36 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include"../01_libft/libft.h"
#include<string.h>

int	main(void)
{
	char	str1[200];
	char	str2[200];
	int		n;

	printf("Compare the 'n' the characters of two strings. Exit with 'CTRL'+'c'.");
	while (1)
	{
		printf("Enter first string and confirm with ENTER.\n");
		scanf("%s", str1);
		printf("Enter second string and confirm with ENTER.\n");
		scanf("%s", str2);
		printf("How many character do you want do you to compare and confirm with ENTER.\n");
		scanf("%d", &n);
		printf("-------------------------------------------------------------------------\n");
		printf("s1: %s \n", str1);
		printf("s1: %s \n", str2);
		printf("for the first %d characters.\n", n);
		printf("-------------------------------------------------------------------------\n");
		printf("|ft_strncmp return : %d for the string : %s & %s|\n", ft_strncmp(str1, str2, n), str1, str2);
		printf("|   strncmp return : %d for the string : %s & %s|\n", ft_strncmp(str1, str2, n), str1, str2);
		printf("-------------------------------------------------------------------------\n");
	}
	return (0);
}
