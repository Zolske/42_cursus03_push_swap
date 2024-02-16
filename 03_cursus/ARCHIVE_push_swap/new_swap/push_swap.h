/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:45:23 by zkepes            #+#    #+#             */
/*   Updated: 2024/02/14 18:49:32 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

typedef struct s_node {
    int val;
    int i_is;
    int i_goal;
    bool lock;
    struct s_node *prev;
    struct s_node *next;
} t_node;

typedef struct s_result
{
    char *bs_str;
    struct s_result *next;
} t_result;

void add_node(t_node **head, int value);
void print_node(t_node **head);
void rev_print_node(t_node **head);
void push(t_node **head_from, t_node **head_to);
// void	update_idx(t_node **head);
void rotate(t_node **head);
void rev_rotate(t_node **head);
void	swap(t_node **head);
void	switch_node(t_node **head);
int	get_len(t_node *head);
void	str_to_list(const char *str, t_node **head);
void	update_idx(t_node *head);
int	value_at_idx(int idx, t_node *node);
void	val_switch(int idx, t_node *node);
int	*buble_sort(int *ptr_arr, t_node **head);
void	add_goal_list(t_node **head, int *ptr_arr);
int	*create_value_array(t_node **head);
bool is_sorted(t_node **head);
bool sor_need_rotate(t_node **head);
void sor_buble(t_node **head, t_result **head_re);

// void	co_swap(t_node **head);
void co_swap(t_node **head);
// void	co_rot_start(t_node **head);
void       co_rotate(t_node **head, t_result **head_re, char *a_or_b);
void	co_rot_start(t_node **head, t_result **head_re, char *a_or_b);
bool	ch_atleast_2_nodes(t_node **head);
void	co_rev_rotate(t_node **head);
void	co_push(t_node **head_from, t_node **head_to);

void add_result(t_result **head_re);
void write_res_bs(t_result **head_re, char *res);
void strcpy_nl(char *dst, char *src);
void print_res_bs(t_result **head_re);
void split_str_to_list(char *str, t_node **head);
void	error(void);

// FREE
void free_all(t_node *head_a, t_node *head_b, t_result *head_re);
void free_res_bs(t_result *head_re);
void free_res_node(t_result *head_re);
void free_node(t_node *head);


// list
t_node	*cop_node(t_node *ori_head);
int count_nodes(t_node *head);

// algo
void	half_buble_sort(t_node **head, t_result **head_re);
