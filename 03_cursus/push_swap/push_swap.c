/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:42:43 by zkepes            #+#    #+#             */
/*   Updated: 2024/02/16 17:13:18 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(char argc, char **argv)
{
    t_node *head_ori = NULL;
    
    if (argc == 1)
        return (0);
    else
        list_from_parmeter(argc, argv, &head_ori);
    add_goal_list(&head_ori);
    printf("///////////////////////////////////////////////////////////////////\n");

    print_node(&head_ori);
    free_node(head_ori);
    return (0);
}