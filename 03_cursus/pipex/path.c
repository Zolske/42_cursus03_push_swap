/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:22:00 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/21 12:34:41 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*return a pointer to a new malloc, table of strings containing the env. paths*/
char	**init_env_path(char *envp[])
{
	char	**tab_env;

	while (*envp)
	{
		if (0 == ft_strncmp(*envp, "PATH=", 5))
			break ;
		envp++;
	}
	tab_env = ft_split(&envp[0][5], ':');
	return (tab_env);
}

/*returns the valid path for the command*/
char	*get_command_path(t_data *d, char *cmd, char **tab_env, char *envp[])
{
	int		idx;
	char	*str_path;

	idx = 0;
	while (tab_env[idx])
	{
		str_path = new_str_from_cat(tab_env[idx], cmd);
		if (0 == access(str_path, (R_OK | W_OK) & X_OK))
			return (str_path);
		free(str_path);
		str_path = NULL;
		idx++;
	}
	write(2, "command not found: ", 19);
	write(2, cmd, ft_strlen(cmd));
	write(2, "\n", 1);
	free_tab(tab_env);
	free_all(d);
	exit(errno);
	return (NULL);
}
