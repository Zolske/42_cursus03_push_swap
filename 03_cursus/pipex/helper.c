/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 13:36:34 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/17 14:45:13 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*returns the length of an **tab if it is '\0'*/
int	tab_len(char **tab)
{
	int	idx;

	idx = 0;
	while (tab[idx])
		idx++;
	return (idx);
}

/*return a pointer to a new malloc, concatenate the input strings + '\0'*/
char *new_str_from_cat(char *str_path, char *str_cmd)
{
	int len_total;
	int len;
	char *str_cat;

	len_total = ft_strlen(str_path);
	len_total += ft_strlen(str_cmd);
	str_cat = (char *)malloc(sizeof(char) * len_total + 2);
	len = 0;
	while (*str_path)
	{
		str_cat[len] = *str_path;
		str_path++;
		len++;
	}
	str_cat[len] = '/';
	len++;
	while (*str_cmd)
	{
		str_cat[len] = *str_cmd;
		str_cmd++;
		len++;
	}
	str_cat[len] = '\0';
	return (str_cat);
}
