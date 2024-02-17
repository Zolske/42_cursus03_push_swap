/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:45:23 by zkepes            #+#    #+#             */
/*   Updated: 2024/02/17 20:47:54 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <limits.h>

typedef struct s_node
{
    int val;
    int i_goal;
    struct s_node *prev;
    struct s_node *next;
} t_node;

typedef struct s_result
{
    char *bs_str;
    char *ats_str;
    struct s_result *next;
} t_result;

typedef enum
{
    STACK_A,
    STACK_B,
    STACK_AB,
    NO_WRITE,
} t_stack;

// list and nodes
void list_from_parameter(char argc, char **argv, t_node **head_ori);
void split_str_to_list(char *str, t_node **head);
void add_node(t_node **head, int value);
void add_node_res(t_result **head_re);
void write_ats(t_result **head_res, char *res);

// check
void error(t_node **head);
void error_check_para(t_node **head, char cha, long long num);
bool double_para(t_node **head, int num);
bool ch_2_nodes(t_node **head);

// commands
void co_rotate_a(t_node **head, t_result **head_res, void(*(f)(t_result **head_res, char *str)));
void co_rotate_b(t_node **head, t_result **head_res, void(*(f)(t_result **head_res, char *str)));
void co_rotate_both(t_node **head_a, t_node **head_b, t_result **head_res, void(*(f)(t_result **head_res, char *str)));
void co_rev_rotate_a(t_node **head, t_result **head_res, void(*(f)(t_result **head_res, char *str)));
void co_rev_rotate_b(t_node **head, t_result **head_res, void(*(f)(t_result **head_res, char *str)));
void co_rev_rotate_both(t_node **head_a, t_node **head_b, t_result **head_res, void(*(f)(t_result **head_res, char *str)));
void co_swap_a(t_node **head_a, t_result **head_res, bool write_res, void(*(f)(t_result **head_res, char *str)));
void co_swap_b(t_node **head_b, t_result **head_res, bool write_res, void(*(f)(t_result **head_res, char *str)));
void co_swap_both(t_node **head_a, t_node **head_b, t_result **head_res, void(*(f)(t_result **head_res, char *str)));
void co_push_a_to_b(t_node **head_a, t_node **head_b, t_node **head_res, void(*(f)(t_result **head_res, char *str)));
void co_push_b_to_a(t_node **head_b, t_node **head_a, t_node **head_res, void(*(f)(t_result **head_res, char *str)));
void push_head_from(t_node **head_from, t_node **new_head, t_node **old_head);
void push_head_to(t_node **head_to, t_node **new_head, t_node **old_head);

// print
void print_node(t_node **head);
void rev_print_node(t_node **head);
void print_ats(t_result **head_res);

// free
void free_node(t_node *head);

// goal
// void	add_goal_list(t_node **head, int *ptr_arr);
void add_goal_list(t_node **head);
int *create_value_array(t_node **head);
int *bubble_sort(int *ptr_arr, t_node **head);

// helper
int get_len(t_node *head);
void strcpy_nl(char *dst, char *src);