/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   half_bubble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 09:57:45 by zkepes            #+#    #+#             */
/*   Updated: 2024/02/25 10:02:52 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void algo_half_bubble(t_node **head_ori, t_result **head_res)
{
    int len;
    t_node *head_a;
    t_node *head_b;

    len = get_len(*head_ori);
    head_a = cop_node(head_ori);
    head_b = NULL;
    if_low_push_b(&head_a, &head_b, head_res, len);

    // printf("second stack ///////////////////////////////////////////////////////////////////\n");
    // print_node_both(&head_a, &head_b);
    // printf("b after creation ///////////////////////////////////////////////////////////////////\n");
    // print_node(&head_b);

    // printf("sor bubble ////////////////////////////////////////////////////////\n");
    // printf("b after creation //////////////////////////////////////////////////\n");
    // print_node(&head_b);
    sor_bubble_both(&head_a, &head_b, head_res, len);

    // printf("after bubble sort ///////////////////////////////////////////////////////////////////\n");
    // print_node_both(&head_a, &head_b);

    free_node(&head_a);
    free_node(&head_b);
    print_ahb(head_res);
}

void if_low_push_b(t_node **head_a, t_node **head_b, t_result **head_res, int len)
{
    t_node *current;
    t_node *temp;
    int idx;
    int count;

    current = *head_a;
    idx = 0;
    count = len / 2;
    while (idx++ <= len && count > 0)
    {
        // only half of the numbers need to be pushed
        if (current->i_goal < len / 2 && count--)
        {
            co_push_a_to_b(&current, head_b, head_res, write_ahb);
            temp = current;
            // function is already changing current to next
            continue;
        }
        if (ch_rotate_b(head_b))
        {
            co_rotate_both(&current, head_b, head_res, write_ahb);
        }
        else
            co_rotate_a(&current, head_res, write_ahb);
    }
    *head_a = temp;
}

void sor_bubble_both(t_node **head_a, t_node **head_b, t_result **head_res, int len)
{
    bool sorted;
    int message;
    int idx = 10;

    sorted = false;
    // print_node_both(head_a, head_b);
    // printf("before bubble /////////////////////////////////////////////////////////\n");
    while (sorted == false)
    {
        if (message = ch_need_swap(head_a, head_b, message, len))
        {
            // printf(">>> swap <<<\n");
            // print_node_both(head_a, head_b);
            // printf("swap message is: %d\n", message);
            swap_stack(head_a, head_b, head_res, message);
        }
        if (message = ch_need_rotate(head_a, head_b, message, len))
        {
            // printf(">>> rotate <<<\n");
            // print_node_both(head_a, head_b);
            // printf("rotate message is: %d\n", message);
            rotate_stack(head_a, head_b, head_res, message);
        }

        if (!not_sorted(head_a, true) && !not_sorted(head_b, false))
            sorted = true;
    }
    // print_node_both(head_a, head_a);
    // printf("after bubble /////////////////////////////////////////////////////////\n");
    while (*head_b != NULL)
        co_push_b_to_a(head_b, head_a, head_res, write_ahb);
}

void rotate_stack(t_node **head_a, t_node **head_b, t_result **head_res, int message)
{
    if (message == STACK_A)
        co_rotate_a(head_a, head_res, write_ahb);
    else if (message == STACK_B)
        co_rotate_b(head_b, head_res, write_ahb);
    else if (message == STACK_AB)
        co_rotate_both(head_a, head_b, head_res, write_ahb);
    else if (message == STACK_R_A)
        co_rev_rotate_a(head_a, head_res, write_ahb);
    else if (message == STACK_R_B)
        co_rev_rotate_b(head_b, head_res, write_ahb);
    else if (message == STACK_R_AB)
        co_rev_rotate_both(head_a, head_b, head_res, write_ahb);
}

void swap_stack(t_node **head_a, t_node **head_b, t_result **head_res, int message)
{
    if (message == STACK_A)
        co_swap_a(head_a, head_res, true, write_ahb);
    else if (message == STACK_B)
        co_swap_b(head_b, head_res, true, write_ahb);
    else if (message == STACK_AB)
        co_swap_both(head_a, head_b, head_res, write_ahb);
}