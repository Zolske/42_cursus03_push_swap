/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 11:24:33 by zkepes            #+#    #+#             */
/*   Updated: 2024/02/25 10:25:44 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void write_ats(t_result **head_res, char *res)
// {
//     t_result *current;
//     int len;

//     len = 0;
//     while (res[len])
//         len++;
//     if (*head_res == NULL)
//         add_node_res(head_res);
//     current = *head_res;
//     while (current != NULL)
//     {
//         if (current->ats_str == NULL)
//         {
//             current->ats_str = (char *)malloc(sizeof(char) * len + 2);
//             strcpy_nl(current->ats_str, res);
//             return;
//         }
//         current = current->next;
//     }
//     current = *head_res;
//     while (current->next != NULL)
//         current = current->next;
//     add_node_res(&current);
//     current->next->ats_str = (char *)malloc(sizeof(char) * len + 2);
//     strcpy_nl(current->next->ats_str, res);
// }

void write_ahb(t_result **head_res, char *res)
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
        if (current->ahb_str == NULL)
        {
            current->ahb_str = (char *)malloc(sizeof(char) * len + 2);
            strcpy_nl(current->ahb_str, res);
            return;
        }
        current = current->next;
    }
    current = *head_res;
    while (current->next != NULL)
        current = current->next;
    add_node_res(&current);
    current->next->ahb_str = (char *)malloc(sizeof(char) * len + 2);
    strcpy_nl(current->next->ahb_str, res);
}

void write_acs(t_result **head_res, char *res)
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
        if (current->acs_str == NULL)
        {
            current->acs_str = (char *)malloc(sizeof(char) * len + 2);
            strcpy_nl(current->acs_str, res);
            return;
        }
        current = current->next;
    }
    current = *head_res;
    while (current->next != NULL)
        current = current->next;
    add_node_res(&current);
    current->next->acs_str = (char *)malloc(sizeof(char) * len + 2);
    strcpy_nl(current->next->acs_str, res);
}