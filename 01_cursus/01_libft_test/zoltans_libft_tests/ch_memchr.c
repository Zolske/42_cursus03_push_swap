/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:39:51 by zkepes            #+#    #+#             */
/*   Updated: 2023/11/06 13:41:26 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include"../01_libft/libft.h"
#include<string.h>
#include<stdlib.h>

int	main(void)
{
	printf("%p \n", ft_memchr("Hello What is up", 'u', 2));
	printf("%p", memchr("Hello What is up", 'u', 2));
	return (0);
}
