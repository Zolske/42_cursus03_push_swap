/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_cut_variable_subwords.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:46:56 by zkepes            #+#    #+#             */
/*   Updated: 2024/08/12 11:47:00 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*All functions are part of the "cut_variable_subwords()", its purpose is to
break the "sub words" further into variables. There are 3 types of variables:
1. "exit variables '$?'" id=VAR_EXIT, sub_word=NULL ('$?' removed from string);
2. "variables '$' followed by '_' or alphabetic character, can after 2nd char
contain also numbers" id=VAR, sub_word=(var name without '$');
3. "invalid variable names" are removed from the string, they are not marked.
The original sub_word string is saved in "char **tmp" and gets updated when a
variable is removed which is marked by "char *idx_var". NOTE: both pointers
point to the same malloc but at different addresses. The extracted informaiton
is saved to "t_sub_list *cur", a new node is added which is then returned to
advance the list.*/

#include "../include/minishell.h"

/*cut "non var string" before variable from '**tmp', write to node, id=STRING*/
t_sub_list	*cut_string_before_var(t_sub_list *cur, char **tmp, char *idx_var)
{
    if ('\0' == idx_var[1] || ' ' == idx_var[1])
        idx_var = ft_strchr(&(idx_var[1]), '$');
    if (idx_var)
    {
        cur->sub_word = ft_substr(*tmp, 0, idx_var - *tmp);
        idx_var = ft_strdup(idx_var);
        free(*tmp);
        *tmp = idx_var;
    }
    else
    {
        cur->sub_word = *tmp;
        *tmp = ft_strdup("");
    }
    cur->sub_id = STRING;
    insert_node_sub_word(cur, UNPROCESSED, NULL);
    return (cur->next);
}

/*cut "$?" from '**tmp', write to node id=VAR_EXIT, sub_word=NULL*/
t_sub_list	*cut_var_exit(t_sub_list *cur, char **tmp, char *idx_var)
{
    const int	LEN_EXIT_VAR = 2;

    cur->sub_word = NULL;
    cur->sub_id = VAR_EXIT;
    idx_var = ft_strdup(idx_var);
    free(*tmp);
    *tmp = ft_strdup(&(idx_var[LEN_EXIT_VAR]));
    free(idx_var);
    insert_node_sub_word(cur, UNPROCESSED, NULL);
    return (cur->next);
}

/*cut variable name from '**tmp', id=VAR*/
t_sub_list	*cut_var(t_sub_list *cur, char **tmp,  char *idx_var)
{
    int	len;

    len = 2;
    idx_var = ft_strdup(idx_var);
    free(*tmp);
    while ('_' == idx_var[len] || ft_isalnum(idx_var[len]))
        len++;
    cur->sub_word = ft_substr(idx_var, 1, len - 1);
    cur->sub_id = VAR;
    *tmp = ft_strdup(&(idx_var[len]));
    free(idx_var);
    insert_node_sub_word(cur, UNPROCESSED, NULL);
    return (cur->next);
}

/*cut invalid var name from '**tmp', e.g. "$5hello" cut "$5" leave "hello"*/
void	cut_invalid_var(char **tmp,  char *idx_var)
{
    const int	LEN_INVALID_VAR = 2;

    idx_var = ft_strdup(idx_var);
    free(*tmp);
    *tmp = ft_strdup(&(idx_var[LEN_INVALID_VAR]));
    free(idx_var);
}

/*remaining str after last var is passed to sub_word, else node is removed*/
void	add_remaining_string(t_sub_list **cur, char **tmp)
{
    t_sub_list	*next;

    if (*tmp && '\0' != (*tmp)[0])
    {
        (*cur)->sub_word = *tmp;
        (*cur)->sub_id = STRING;
    }
    else
    {
        if ((*cur)->prev && (*cur)->next)
        {
            (*cur)->prev->next = (*cur)->next;
            next = (*cur)->next;
            free(*cur);
            *cur = next;
        }
        free(*tmp);
        *tmp = NULL;
    }
}
