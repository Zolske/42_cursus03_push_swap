/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:44:07 by zkepes            #+#    #+#             */
/*   Updated: 2023/11/15 16:20:02 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
Returns a pointer to the last occurrence of the character c in the string s.
PARAMETER
*str ->	string to be checked
c ->	character to be checked in string
RETURN
A pointer to the matched character or NULL if the character is not
found. The terminating null byte is considered part of the string, so that if
c is specified as '\0', these functions return a pointer to the terminator.
NOTE
The argument 'c' needs to be casted to an character.
The return needs to be casted to a poniter of char return ((char *) &str[ind]),
because of the const parameter*/

#include<stdio.h>

char	*ft_strrchr(const char *str, int c)
{
	int		ind;

	ind = 0;
	while (str[ind])
		ind++;
	while (ind >= 0)
	{
		if ((unsigned char)str[ind] == (char)c)
			return ((char *) &str[ind]);
		ind--;
	}
	return (NULL);
}
