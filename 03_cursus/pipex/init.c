/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:34:40 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/13 12:44:05 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void init_data_null(t_data **d)
{
	(*d)->cmd = NULL;
	(*d)->cmd_arg = NULL;
	(*d)->cmd_full = NULL;
	(*d)->cmd_path = NULL;
}

/*initialize file names, num of commands, idx = 0; if input from CL*/
void init_file_val(int argc, char *argv[], t_data **d)
{
	(*d)->in_fl = argv[1];
	(*d)->n_cmd = argc - 3;
	(*d)->out_fl = argv[argc - 1];
	(*d)->idx = 0;
	if (0 == ft_strncmp(argv[1], "here_doc\0", 9))
		(*d)->in_cl = true;
	else
		(*d)->in_cl = false;
}

void init_cmd_data(char *argv[], char *envp[], t_data **d)
{
	init_cmd(argv, d);
	init_cmd_full(argv, d);
	init_cmd_arg(argv, d);
	init_cmd_path(envp, d);
}

void init_cmd(char *argv[], t_data **d)
{
	int idx_c;

	(*d)->cmd = (char **)malloc(sizeof(char *) * (*d)->n_cmd);
	while ((*d)->idx < (*d)->n_cmd)
	{
		idx_c = 0;
		while (argv[(*d)->idx + 2][idx_c] != ' ' && argv[(*d)->idx + 2][idx_c])
			idx_c++;
		(*d)->cmd[(*d)->idx] = (char *)malloc(sizeof(char) * idx_c + 1);
		idx_c = 0;
		while (argv[(*d)->idx + 2][idx_c] != ' ' && argv[(*d)->idx + 2][idx_c])
		{
			(*d)->cmd[(*d)->idx][idx_c] = argv[(*d)->idx + 2][idx_c];
			idx_c++;
		}
		(*d)->cmd[(*d)->idx][idx_c] = '\0';
		// printf("cmd arg malloc: %s\n", (*d)->cmd[0]);
		((*d)->idx)++;
	}
	(*d)->idx = 0;
}

/*program argument by itself, "cmd" needs to be initalized first*/
void init_cmd_arg(char *argv[], t_data **d)
{
	int idx;
	int arg;

	arg = 0;
	(*d)->cmd_arg = (char **)malloc(sizeof(char *) * (*d)->n_cmd);
	while (arg < (*d)->n_cmd)
	{
		idx = 0;
		while ((*d)->cmd[arg][idx] == argv[arg + 2][idx])
		{
			if (argv[arg + 2][idx] == '\0')
			{
				(*d)->cmd_arg[arg] = NULL;
				break;
			}
			idx++;
		}
		// (*d)->cmd_arg[arg] =  &argv[arg + 2][idx];
		(*d)->cmd_arg[arg] = ft_strdup(&argv[arg + 2][idx]);
		arg++;
	}
	(*d)->idx = 0;
}

void init_cmd_full(char *argv[], t_data **d)
{
	(*d)->cmd_full = (char **)malloc(sizeof(char *) * (*d)->n_cmd);
	while ((*d)->idx < (*d)->n_cmd)
	{
		(*d)->cmd_full[(*d)->idx] = ft_strdup(argv[(*d)->idx + 2]);
		// printf("cmd arg malloc: %s\n", (*d)->cmd_full[0]);
		((*d)->idx)++;
	}
	(*d)->idx = 0;
}

/*add working path + command to data, except for 2nd if 1st arg is "doc_here"*/
void init_cmd_path(char *envp[], t_data **d)
{
	char **tab_env;

	tab_env = init_env_path(envp, d);
	(*d)->cmd_path = (char **)malloc(sizeof(char *) * (*d)->n_cmd);
	while ((*d)->idx < (*d)->n_cmd)
	{
		if (false == ((*d)->in_cl && (*d)->idx == 0))
			(*d)->cmd_path[(*d)->idx] = get_command_path(tab_env, (*d)->cmd[(*d)->idx]);
		((*d)->idx)++;
	}
	(*d)->idx = 0;
	// free_data_entry(&tab_env, ft_strlen(&tab_env));
	// printf("len tab: %d\n", tablen(tab_env));
	free_data_entry(&tab_env, tablen(tab_env));
}

char *get_command_path(char **tab_env, char *cmd)
{
	int idx;
	char *str_path;

	idx = 0;
	while (tab_env[idx])
	{
		if (cmd)
		{
			str_path = new_str_from_cat(tab_env[idx], cmd);
			// printf("get command: %s\n", str_path);
			if (0 == access(str_path, (R_OK | W_OK) & X_OK))
				return (str_path);
			free(str_path);
			str_path = NULL;
			idx++;
		}
		// else
		// printf("\n >> %s <<\n", cmd);
	}
	perror(cmd);
	return (NULL);
}

/*return a pointer to a new malloc, table of strings containing the env. paths*/
char **init_env_path(char *envp[], t_data **d)
{
	while (*envp)
	{
		if (0 == ft_strncmp(*envp, "PATH=", 5))
			break;
		envp++;
	}
	return (ft_split(&envp[0][5], ':'));
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
	// printf("string path: %s\n", str_path);
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
	// printf("in side cat: %s\n", str_cat);
	return (str_cat);
}

/*returns the length of an **tab if it is '\0'*/
int	tablen(char **tab)
{
	int	idx;

	idx = 0;
	while (tab[idx])
		idx++;
	return (idx);
}