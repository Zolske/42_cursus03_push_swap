/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:31:36 by zkepes            #+#    #+#             */
/*   Updated: 2023/11/01 18:35:03 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include"../01_libft/libft.h"
#include<string.h>

int	main(void)
{
	char	dest[30] = "Hello You";
	const char	*sour  = "Good by";
	char	dest_1[30] = "Hello You";
	size_t	sour_len;
	size_t	sour_len_1;

	sour_len = ft_strlcpy(dest, sour, 4);
	sour_len_1 = strlcpy(dest_1, sour, 4);
	printf("ft_stlcpy return: %ld, new string: %s\n", sour_len, dest);
	printf("   stlcpy return: %ld, new string: %s\n", sour_len_1, dest_1);
	return (0);
}
