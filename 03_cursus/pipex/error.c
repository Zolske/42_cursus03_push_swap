/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:20:17 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/13 14:37:04 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*free all malloc, write error msg to stderr, exit program with error code 1*/
void e_free_exit(t_data **d, char *msg)
{
    free_all(*d);
    write(2, msg, ft_strlen(msg));
    exit(1);
}

/*Error in allocating memory to array of pointers, free everything and exit*/
void e_arr_mal(char **parray, t_data **d, char *msg)
{
    if (parray == NULL)
    {
        perror(msg);
        free_all(*d);
        // write(2, msg, ft_strlen(msg));
        exit(1);
    }
}

/*Error in allocating memory to pointer, free everything and exit*/
void e_ptr_mal(char *ptr, t_data **d, char *msg)
{
    if (ptr == NULL)
    {
        perror(msg);
        free_all(*d);
        // write(2, msg, ft_strlen(msg));
        exit(1);
    }
}