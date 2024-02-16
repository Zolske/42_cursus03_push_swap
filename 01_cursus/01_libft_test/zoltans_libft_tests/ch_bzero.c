/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_bzero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:55:01 by zkepes            #+#    #+#             */
/*   Updated: 2023/10/31 18:48:23 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include<stdio.h>
#include <string.h>
#include"../01_libft/libft.h"

int main(void)
{
/*	// NOT working bcause of scanf() buffer?
	char	input[200];
	char	cp_input[200];
	int		char_input;
	int		position;
	size_t	lenght;
	void	*ptr;

	while (1)
	{
	printf("test 'ft_bzero()' and 'bzero()', \nenter a word with max 200 character or 'ESC' \
to exit, confirm with Enter.\n---\n");
		scanf("%180s", input);
	printf("enter one character or 'ESC' \
to exit, confirm with Enter.\n---\n");
		scanf("%d", &char_input);
	printf("enter as a number from where you want to replace the string whit your entered character or 'ESC' \
to exit, confirm with Enter.\n---\n");
		scanf("%d", &position);
	printf("enter how many characters you want to replace from the string you have entered first or 'ESC' \
to exit, confirm with Enter.\n---\n");
		scanf("%ld", &lenght);
		if (*input == 27)
			return (0);
		strcpy(cp_input, input);
		printf("---------------------------------\n");
		printf("|'ft_bzero()' return: '%p'\t|\n", ft_bzero(input + position, char_input, lenght*sizeof(char)));
		printf("|   'bzero()' return: '%p'\t|\n", bzero(cp_input + position, char_input, lenght*sizeof(char)));
		printf("---------------------------------\n");
	}*/
	char str[50] = "GeeksForGeeks is for programming geeks.";
	char ft_str[50] = "GeeksForGeeks is for programming geeks.";
	printf("Before    bzero(): %s\n", str);
	printf("Before ft_bzero(): %s\n", ft_str);
	// Fill 8 characters starting from str[13] with '.'
    bzero(str + 13, 8*sizeof(char));
	ft_bzero(ft_str + 13, 8*sizeof(char));


	printf("After    bzero():  %s\n", str);
	printf("After ft_bzero():  %s\n", ft_str);
	return (0);
}
