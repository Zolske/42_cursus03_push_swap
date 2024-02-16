/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:45:23 by zkepes            #+#    #+#             */
/*   Updated: 2024/02/16 17:15:33 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <limits.h>

typedef struct s_node {
    int val;
    int i_goal;
    struct s_node *prev;
    struct s_node *next;
} t_node;

typedef struct s_result
{
    char *bs_str;
    struct s_result *next;
} t_result;

// list and nodes
void list_from_parmeter(char argc, char **argv, t_node **head_ori);
void split_str_to_list(char *str, t_node **head);
void add_node(t_node **head, int value);

// check
void error(t_node **head);
void error_check_para(t_node **head, char cha, long long num);
bool double_para(t_node **head, int num);

// print
void print_node(t_node **head);
void rev_print_node(t_node **head);

// free
void free_node(t_node *head);

// goal
// void	add_goal_list(t_node **head, int *ptr_arr);
void	add_goal_list(t_node **head);
int	*create_value_array(t_node **head);
int	*buble_sort(int *ptr_arr, t_node **head);

// helper
int	get_len(t_node *head);