/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:41:37 by zkepes            #+#    #+#             */
/*   Updated: 2023/11/06 13:13:02 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include <string.h>
#include"../01_libft/libft.h"

	char message2[60] = "abcdefghijklmnopqrstuvwxyz";
	char temp[60];

int	main(void)
{
    /*strcpy(temp, message2);
    printf("\n\nOriginal message: \t\t\t%s", temp);
    memcpy(temp + 4, temp + 16, 10);
    printf("\nAfter memcpy() without overlap:\t\t%s", temp);
    strcpy(temp, message2);
    memcpy(temp + 6, temp + 4, 10);
    printf("\nAfter memcpy() with overlap:\t\t%s", temp);

    strcpy(temp, message2);
    printf("\n\nOriginal message: \t\t\t%s", temp);
    memmove(temp + 4, temp + 16, 10);
    printf("\nAfter memmove() without overlap:\t%s", temp);
    strcpy(temp, message2);
    memmove(temp + 6, temp + 4, 10);
    printf("\nAfter memmove() with overlap:\t\t%s\n", temp);
	*/
	char csrc[100] = "abcde";
	char csrc_2[100] = "abcde";
    //// go backwards right to left
	// ft_memmove(csrc+2, csrc, 3);
	// printf("%s\n", csrc);
	// memmove(csrc_2+2, csrc_2, 3);
	// printf("%s", csrc_2);
    //// go forward left to right
    ft_memmove(csrc, csrc+2, 3);
	printf("%s\n", csrc);
	memmove(csrc_2, csrc_2+2, 3);
	printf("%s", csrc_2);
	return (0);
}
