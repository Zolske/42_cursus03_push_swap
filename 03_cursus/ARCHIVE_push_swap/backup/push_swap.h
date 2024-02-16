/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:45:23 by zkepes            #+#    #+#             */
/*   Updated: 2024/02/07 17:50:19 by zkepes           ###   ########.fr       */
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

void add_node(t_node **head, int value);
void print_node(t_node **head);
void rev_print_node(t_node **head);
void free_all(t_node *head);
void push(t_node **head_from, t_node **head_to);
// void	update_idx(t_node **head);
void rotate(t_node **head);
void rev_rotate(t_node **head);
void	swap(t_node **head);
void	switch_node(t_node **head);
int	get_len(t_node *head);
int	ft_atoi(const char *str);
void	update_idx(t_node *head);
int	value_at_idx(int idx, t_node *node);
void	val_switch(int idx, t_node *node);
int	*buble_sort(int *ptr_arr);
void	add_goal_list(t_node **head, int *ptr_arr);
int	*create_value_array(t_node **head);
bool is_sorted(t_node **head);
bool sor_need_rotate(t_node **head);
void sor_buble(t_node **head);

void	co_rotate(t_node **head);
void	co_swap(t_node **head);
void	co_rot_start(t_node **head);