/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:25:46 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/22 11:15:53 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*check malloc, if 'ptr' is NULL then malloc failed:
-> error message based on the error code in variable errno and parameter 'msg'
-> free all previous created mallocs
-> end program*/

#include "pipex.h"

/*check malloc, single pointer, cast pointer to "(void*)"*/
void	e_mal_exit(void *ptr, t_data *d, char *msg)
{
	if (ptr == NULL)
	{
		perror(msg);
		free_all(d);
		exit(1);
	}
}

/*check malloc, double pointer, cast pointer to "(void**)"*/
void	e_ptr2_mal_exit(void **ptr, t_data *d, char *msg)
{
	if (ptr == NULL)
	{
		perror(msg);
		free_all(d);
		exit(1);
	}
}

/*check malloc, triple pointer, cast pointer to "(void***)"*/
void	e_ptr3_mal_exit(void ***ptr, t_data *d, char *msg)
{
	if (ptr == NULL)
	{
		perror(msg);
		free_all(d);
		exit(1);
	}
}

/*same as "e_ptr2_mal_exit()", but also free tab*/
void	e_ptr2_2x_mal_exit(void **ptr, char **tab, t_data *d, char *msg)
{
	if (ptr == NULL)
	{
		perror(msg);
		free_all(d);
		free_tab(tab);
		exit(1);
	}
}

/*displays msg + error code from the "Errno env variable", free all mallocs
and exist program with error code ("Program terminated unsuccessfully" == 1)*/
void	e_message_free_exit(t_data *d, char *msg)
{
	perror(msg);
	free_all(d);
	exit(1);
}
