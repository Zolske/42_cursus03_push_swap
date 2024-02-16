/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:52:19 by zkepes            #+#    #+#             */
/*   Updated: 2023/11/02 15:51:21 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include"../01_libft/libft.h"
#include<string.h>
#include<stdlib.h>

int	main(void)
{
	const char str[] = "https://www.tutorialspoint.com";
	printf("%s \n", ft_strrchr(str, 'i'));
	printf("%s", strrchr(str, 'i'));
	return (0);
}
