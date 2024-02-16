/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:39:51 by zkepes            #+#    #+#             */
/*   Updated: 2023/11/06 17:52:12 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include"../01_libft/libft.h"
#include<string.h>
#include<stdlib.h>

int	main(void)
{
	printf("ft_strchr %p \n", ft_strchr("Hello What is up", '\0'));
	printf("strchr %p", strchr("Hello What is up", '\0'));
	return (0);
}
