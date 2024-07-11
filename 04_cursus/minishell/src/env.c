/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:12:43 by zkepes            #+#    #+#             */
/*   Updated: 2024/07/11 13:02:39 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	copy_env(t_data *d, char *arge[])
{
	int	len;
	int	free_space;
	int	idx;
	
	len = 0;
	free_space = 10;
	idx = 0;
	while (arge[len])
		len++;
	d->env = (char **) malloc(sizeof(char *) * (len + free_space + 1));
	d->env[len + free_space] = NULL;
	while (arge[idx])
	{
		d->env[idx] = ft_strdup(arge[idx]);
		idx++;
	}
	while (free_space--)
	{
		d->env[idx] = ft_strdup("!FREE!");
		idx++;
	}
}

/*returns a pointer to the value of the "env variable name", if not exist
return NULL which can cause problems with printf*/
char	*return_env_value(t_data *d, char *var_name)
{
	int		idx;
	int		len_var;

	idx = 0;
	len_var = ft_strlen(var_name);
	while (d->env[idx])
	{
		if (!ft_strncmp(d->env[idx], var_name, len_var)
			&& d->env[idx][len_var] == '=')
			return &(d->env[idx][len_var + 1]);

		idx++;
	}
	return NULL;
}


