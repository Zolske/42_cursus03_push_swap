/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:25:46 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/18 12:55:27 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*if malloc fails, error msg to stder and exit program*/
void	e_mal_exit(char *ptr, t_data *d, char *msg)
{
	if (ptr == NULL)
	{
		perror(msg);
        free_all(d);
        exit(1);
	}
}

/*same as e_mal_exit() but with a **ptr*/
void	e_ptr2_mal_exit(char **ptr, t_data *d, char *msg)
{
	if (ptr == NULL)
	{
		perror(msg);
        free_all(d);
        exit(1);
	}
}

/*same as e_mal_exit() but with a ***ptr*/
void	e_ptr3_mal_exit(char ***ptr, t_data *d, char *msg)
{
	if (ptr == NULL)
	{
		perror(msg);
        free_all(d);
        exit(1);
	}
}

/*same as e_mal_exit() but it also needs to free tab*/
void	e_ptr2_2x_mal_exit(char **ptr, char **tab, t_data *d, char *msg)
{
	if (ptr == NULL)
	{
		perror(msg);
        free_all(d);
		free_tab(tab);
        exit(1);
	}
}
