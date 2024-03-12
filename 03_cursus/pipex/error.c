/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:20:17 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/12 19:31:53 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*free all malloc, write error msg to stderr, exit program with error code 1*/
void e_free_exit(t_data **d, char *msg)
{
    free_all(d);
    write(2, msg, ft_strlen(msg));
    exit(1);
}