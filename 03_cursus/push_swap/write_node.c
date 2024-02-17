/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 11:24:33 by zkepes            #+#    #+#             */
/*   Updated: 2024/02/17 19:23:38 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void write_ats(t_result **head_res, char *res)
{
    t_result *current;
    int len;

    len = 0;
    while (res[len])
        len++;
    if (*head_res == NULL)
        add_node_res(head_res);
    current = *head_res;
    while (current != NULL)
    {
        if (current->ats_str == NULL)
        {
            current->ats_str = (char *)malloc(sizeof(char) * len + 2);
            strcpy_nl(current->ats_str, res);
            return;
        }
        current = current->next;
    }
    current = *head_res;
    while (current->next != NULL)
        current = current->next;
    add_node_res(&current);
    current->next->ats_str = (char *)malloc(sizeof(char) * len + 2);
    strcpy_nl(current->next->ats_str, res);
}