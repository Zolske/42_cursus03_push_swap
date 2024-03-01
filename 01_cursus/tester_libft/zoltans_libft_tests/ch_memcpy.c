/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:05:55 by zkepes            #+#    #+#             */
/*   Updated: 2023/11/01 15:19:08 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The C library function void *memcpy(void *dest, const void *src, size_t n)
 * copies n characters from memory area src to memory area dest.
 * RETURN VALUE: The memcpy() function returns a pointer to dest, at which the
 * destination was changed.*/

#include<stdio.h>
#include <string.h>
#include"../01_libft/libft.h"

int	main(void)
{
	/*const char src[60] = "******";
	char dest[60];
	const char co_src[60] = "******";
	char co_dest[60];
	void *ptr;
	void *co_ptr;
	strcpy(dest,"https://www.notes.zoltankepes.com");
	strcpy(co_dest,"https://www.notes.zoltankepes.com");
	printf("---\nBefore ft_memcpy dest = %s\n", co_dest);
	printf("Before    memcpy dest = %s\n", co_dest);
	ptr = ft_memcpy(dest + 18, src, strlen(src));
	co_ptr = memcpy(co_dest + 18, co_src, strlen(co_src));
	printf("---\nAfter ft_memcpy dest = %s\n", dest);
	printf("After    memcpy dest = %s\n", co_dest);
	printf("---\nft_memcpy function return: %s\n", (char*)ptr - 18);
	printf("   memcpy function return: %s", (char*)co_ptr - 18);*/

	const char src[60] = "abcdefghijklmnopqrstuvwxyz";
	char dest[60];
	const char co_src[60] = "abcdefghijklmnopqrstuvwxyz";
	char co_dest[60];
	void *ptr;
	void *co_ptr;

	strcpy(dest,"abcdefghijklmnopqrstuvwxyz");
	strcpy(co_dest,"abcdefghijklmnopqrstuvwxyz");
	printf("---\nBefore ft_memcpy dest = %s\n", co_dest);
	printf("Before    memcpy dest = %s\n", co_dest);
	ptr = ft_memcpy(dest + 6, dest + 4, 10);
	co_ptr = memcpy(co_dest + 6, dest + 4, 10);
	printf("---\nAfter ft_memcpy dest = %s\n", dest);
	printf("After    memcpy dest = %s\n", co_dest);
	printf("---\nft_memcpy function return: %s\n", (char*)ptr - 18);
	printf("   memcpy function return: %s", (char*)co_ptr - 18);

   return(0);
}
