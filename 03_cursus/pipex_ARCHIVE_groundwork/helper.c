/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:15:29 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/07 10:56:10 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*create a malloc string with the the first word till an empty space or the
'\0' -> to be used for getting the command without any arguments*/
char	*get_command(char *str)
{
	int		len;
	int		idx;
	char	*str_co;

	len = 0;
	idx = 0;
	// printf("input: %s\n", str);
	while (str[len] != ' ' && str[len])
		len++;
	str_co = (char *) malloc(sizeof(char) * len + 1);
	if (NULL == str_co)
		return NULL;
	while (idx < len)
	{
		str_co[idx] = str[idx];
		idx++;
	}
	str_co[idx] = '\0';
	// printf("input M: |%s|\n", str_co);
	return (str_co);
	// return (NULL);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	bool			s1_no_end;
	bool			s2_no_end;
	size_t			ind;
	unsigned char	*s1_cp;
	unsigned char	*s2_cp;

	s1_no_end = true;
	s2_no_end = true;
	ind = 0;
	s1_cp = (unsigned char *) s1;
	s2_cp = (unsigned char *) s2;
	while (ind < n
		&& s1_no_end
		&& s2_no_end)
	{
		if (s1_cp[ind] == '\0')
			s1_no_end = false;
		if (s2_cp[ind] == '\0')
			s2_no_end = false;
		if (s1_cp[ind] != s2_cp[ind])
			return ((int) s1_cp[ind] - (int) s2_cp[ind]);
		ind++;
	}
	return (0);
}

/*returns a pointer to the new string created from source n characters long,
 adds '/' and  '\0' to the end*/
char	*new_str_from_src(char *src, int n)
{
	int		idx;
	char	*str_new;

	str_new = (char *) malloc(sizeof(char) * n + 2);
	idx = 0;
	while (idx < n)
	{
			str_new[idx] = src[idx];
			idx++;
	}
	str_new[idx] = '/';
	idx++;
	str_new[idx] = '\0';
	// printf("new str from src: %s\n", str_new);
	return (str_new);
}

char	*new_str_from_cat(char *str_path, char *str_com)
{
	int		len_total;
	int		len;
	char	*str_cat;

	len_total = 0;
	len = 0;
	while (str_path[len_total])
		len_total++;
	while (str_com[len])
		len++;
	len_total += len;
	str_cat = (char *) malloc(sizeof(char) * len_total + 1);
	len = 0;
	// printf("string path: %s\n", str_path);
	while (*str_path)
	{
		str_cat[len] = *str_path;
		str_path++;
		len++;
	}
	while (*str_com)
	{
		str_cat[len] = *str_com;
		str_com++;
		len++;
	}
	str_cat[len] =  '\0';
	// printf("in side cat: %s\n", str_cat);
	return (str_cat);
}

// size_t	ft_strlen(const char *s)
// {
// 	size_t	count;

// 	count = 0;
// 	while (s[count])
// 		count++;
// 	return (count);
// }