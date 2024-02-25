/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:45:23 by zkepes            #+#    #+#             */
/*   Updated: 2024/02/25 14:45:03 by zkepes           ###   ########.fr       */
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
    int cost;
    int idx;
    struct s_node *prev;
    struct s_node *next;
} t_node;

typedef struct s_result
{
    char *bs_str;
    char *acs_str;
    char *ahb_str;
    struct s_result *next;
} t_result;

typedef enum
{
    NOTHING = 0,
    STACK_A = 1,
    STACK_B = 2,
    STACK_AB = 3,
    STACK_R_A = 4,
    STACK_R_B = 5,
    STACK_R_AB = 6
} t_stack;

// list and nodes
void list_from_parameter(int argc, char **argv, t_node **head_ori);
void split_str_to_list(char *str, t_node **head);
void add_node(t_node **head, int value);
void add_node_res(t_result **head_re);
t_node *cop_node(t_node **head_ori);

// write
// void write_ats(t_result **head_res, char *res);
void write_ahb(t_result **head_res, char *res);
void write_acs(t_result **head_res, char *res);

// check
void error(t_node **head);
void error_check_para(t_node **head, char cha, long long num);
bool double_para(t_node **head, int num);
bool ch_2_nodes(t_node **head);

// commands
void co_rotate_a(t_node **head, t_result **head_res, void (*f)(t_result **head_res, char *str));
void co_rotate_b(t_node **head, t_result **head_res, void (*f)(t_result **head_res, char *str));
void co_rotate_both(t_node **head_a, t_node **head_b, t_result **head_res, void((*f)(t_result **head_res, char *str)));
void co_rev_rotate_a(t_node **head, t_result **head_res, void((*f)(t_result **head_res, char *str)));
void co_rev_rotate_b(t_node **head, t_result **head_res, void((*f)(t_result **head_res, char *str)));
void co_rev_rotate_both(t_node **head_a, t_node **head_b, t_result **head_res, void((*f)(t_result **head_res, char *str)));
void co_swap_a(t_node **head_a, t_result **head_res, bool write_res, void((*f)(t_result **head_res, char *str)));
void co_swap_b(t_node **head_b, t_result **head_res, bool write_res, void((*f)(t_result **head_res, char *str)));
void co_swap_both(t_node **head_a, t_node **head_b, t_result **head_res, void((*f)(t_result **head_res, char *str)));
void co_push_a_to_b(t_node **head_a, t_node **head_b, t_result **head_res, void((*f)(t_result **head_res, char *str)));
void co_push_b_to_a(t_node **head_b, t_node **head_a, t_result **head_res, void((*f)(t_result **head_res, char *str)));
void push_head_from(t_node **head_from, t_node **new_head, t_node **old_head);
void push_head_to(t_node **head_to, t_node **new_head, t_node **old_head);

// print
void print_node(t_node **head);
void print_node_both(t_node **head_a, t_node **head_b);
void rev_print_node(t_node **head);
// void print_ats(t_result **head_res);
void print_ahb(t_result **head_res);
void print_acs(t_result **head_res);

// free
void free_node(t_node **head);
void free_ahb(t_result **head_res);
void free_write(t_result **head);

// goal
// void	add_goal_list(t_node **head, int *ptr_arr);
void add_goal_list(t_node **head);
int *create_value_array(t_node **head);
int *bubble_sort(int *ptr_arr, t_node **head);

// helper
int get_len(t_node *head);
void strcpy_nl(char *dst, char *src);

// algorithm
void algo_half_bubble(t_node **head_ori, t_result **head_res);
void sor_bubble_both(t_node **head_a, t_node **head_b, t_result **head_res, int len);
bool ch_rotate_b(t_node **head_b);
void if_low_push_b(t_node **head_a, t_node **head_b, t_result **head_res, int len);
int ch_need_swap(t_node **head_a, t_node **head_b, int message, int len);
void swap_stack(t_node **head_a, t_node **head_b, t_result **head_res, int message);
int ch_need_rotate(t_node **head_a, t_node **head_b, int message, int len);
void rotate_stack(t_node **head_a, t_node **head_b, t_result **head_res, int message);
bool not_sorted(t_node **head, bool acending);

void cheap_sort(t_node **head_ori, t_result **head_res);

bool not_sorted_b(t_node **head, bool acending);

// sorting
void sort_3_node_a(t_node **head_a, t_result **head_res);
void update_idx(t_node **head);
void update_cost_base(t_node **head);