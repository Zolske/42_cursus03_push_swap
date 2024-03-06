/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:45:23 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/04 16:12:07 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int				val;
	int				i_goal;
	int				pos;
	int				idx;
	int				cost;
	int				instr_a;
	int				instr_b;
	bool			move;
	bool			upper;
	struct s_node	*tar;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_var
{
	int				len;
	int				count;
	int				start;
	struct s_node	*current;
}	t_var;

// list and nodes
void	list_from_parameter(int argc, char **argv, t_node **head_ori);
void	split_str_to_list(char *str, t_node **head);
void	add_node(t_node **head, int value);

// check
void	error(t_node **head);
void	error_check_para(t_node **head, char cha, long long num);
bool	double_para(t_node **head, int num);
bool	ch_2_nodes(t_node **head);

// commands
void	co_rotate_a(t_node **head);
void	co_rotate_b(t_node **head);
void	co_rotate_both(t_node **head_a, t_node **head_b);
void	co_rev_rotate_a(t_node **head);
void	co_rev_rotate_b(t_node **head);
void	co_rev_rotate_both(t_node **head_a, t_node **head_b);
void	co_swap_a(t_node **head_a);
void	co_swap_b(t_node **head_b);
void	co_swap_both(t_node **head_a, t_node **head_b);
void	co_push_a_to_b(t_node **head_a, t_node **head_b);
void	co_push_b_to_a(t_node **head_b, t_node **head_a);
void	push_head_from(t_node **head_from, t_node **new_head, \
						t_node **old_head);
void	push_head_to(t_node **head_to, t_node **new_head, t_node **old_head);

// goal
void	add_goal_list(t_node **head);
int		*create_value_array(t_node **head);
int		*bubble_sort(int *ptr_arr, t_node **head);

// update metadata
void	update_all(t_node **head_a, t_node **head_b);
void	update_idx(t_node **head);
void	update_pos(t_node **head);
void	update_target(t_node **head_b, t_node **head_a);
void	update_cost_instruc(t_node **head_b);
void	update_move(t_node **head_b);

// find target and calculate cost
t_node	*next_bigger_goal(t_node **head_a, t_node *current_b);
t_node	*smallest_goal(t_node **head_a, t_node *current_b);
int		both_up(t_node **head_cur, int len_a, int len_b, bool write);
int		both_down(t_node **head_cur, int len_a, int len_b, bool write);
int		down_a_up_b(t_node **head_cur, int len_a, int len_b, bool write);
int		up_a_down_b(t_node **head_cur, int len_a, int len_b, bool write);
int		mv_instr_upper_a(t_node **head_cur, int len, bool move_up, bool write);
int		mv_instr_below_a(t_node **head_cur, int len, bool move_up, bool write);
int		mv_instr_upper_b(t_node **head_cur, int len, bool move_up, bool write);
int		mv_instr_below_b(t_node **head_cur, int len, bool move_up, bool write);

// move and sort
t_node	*find_node_move(t_node **head_b);
t_node	*move_b_and_a_top(t_node **head_a, t_node **head_b);
void	move_a_top(t_node **head_a, t_node **move_node);
void	move_b_top(t_node **head_b, t_node **move_node);
void	move_cheapest_node(t_node **head_a, t_node **head_b);
void	reset_moves(t_node **head_b);
void	sort_3_node_a(t_node **head_a);
void	cheap_sort(t_node **head_ori);
void	sort_start(t_node **head_a);

// helper functions
int		get_len(t_node *head);
void	init_var(t_var *var, t_node **head);
void	init_node(t_node **new_node, t_node **head, int value);

// free
bool	is_sorted(t_node *head);
bool	is_sorted_just_rotate(t_node **head);
bool	is_sorted_just_rotate(t_node **head);
void	free_node(t_node **head);
void	sort_5_node_a(t_node **head_a);
void	sort_more_node(t_node **head_a, int len);
#endif