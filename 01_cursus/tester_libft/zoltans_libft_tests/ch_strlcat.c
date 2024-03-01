/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:31:36 by zkepes            #+#    #+#             */
/*   Updated: 2023/11/01 19:03:54 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include"../01_libft/libft.h"
#include<string.h>

int	main(void)
{
	char	dest[30] = "Hello You";
	const char	*sour  = " And Good bye";
	char	dest_1[30] = "Hello You";
	size_t	sour_len;
	size_t	sour_len_1;

	sour_len = ft_strlcat(dest, sour, 25);
	sour_len_1 = strlcat(dest_1, sour, 25);
	printf("ft_stlcat return: %ld, new string: %s\n", sour_len, dest);
	printf("   stlcat return: %ld, new string: %s\n", sour_len_1, dest_1);
	return (0);
}
