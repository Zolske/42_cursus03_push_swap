/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:45:23 by zkepes            #+#    #+#             */
/*   Updated: 2024/01/24 18:54:40 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_node {
    int index;
    int val;
    struct s_node *next;
} t_node;

void add_node(t_node **head, int val);
void print_node(t_node *start);
int	ft_atoi(const char *str);
int	value_at_idx(int idx, t_node *node);
void	val_switch(int idx, t_node *node);
void	buble_sort(t_node *cp_head, int len);