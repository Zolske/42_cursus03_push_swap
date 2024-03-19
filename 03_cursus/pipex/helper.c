/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 13:36:34 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/19 17:58:12 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*returns the length of an **tab if it is '\0'*/
int	tab_l(char **tab)
{
	int	idx;

	idx = 0;
	while (tab[idx])
		idx++;
	return (idx);
}

/*return a pointer to a new malloc, concatenate the input strings + '\0'*/
char	*new_str_from_cat(char *str_path, char *str_cmd)
{
	int		len_total;
	int		len;
	char	*str_cat;

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

/*remove "tempfile" (stores user input) if exist ("F_OK")*/
void	remove_tempfile(void)
{
	if (access(TEMP_FILE, F_OK) == 0)
	{
		if (unlink(TEMP_FILE) == -1)
			perror("failed to remove tempfile");
	}
}
