/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:20:13 by zkepes            #+#    #+#             */
/*   Updated: 2023/11/15 15:41:31 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
Calculates the length of the string pointed to by s up to the first terminating
null byte ('\0').
PARAMETERS
*s ->	string of which the length is to be counted
RETURN
The number of bytes in the string pointed to by s without '\0' up to the first
'\0'*/

#include<stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}
