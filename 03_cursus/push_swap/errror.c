/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errror.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:53:51 by zkepes            #+#    #+#             */
/*   Updated: 2024/02/27 17:54:37 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*end programm with the "error()" if invalid input*/
void    valid_input(int argc, char **argv)
{
    if (argc == 1)
        error();
    else if (argc == 2)
        if (error_arg_1(argv[1]))
            error();
    else
        if (error_args())
            error();
}

/*write "Error\n" to the "stderr" output and exit programm*/
void error()
{
    write(2, "Error\n", 6);
    exit(1);
}

void    ascii_array(char *str)
{
    
}