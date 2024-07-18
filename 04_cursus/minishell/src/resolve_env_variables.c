/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_env_variables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:29:54 by zkepes            #+#    #+#             */
/*   Updated: 2024/07/18 16:40:29 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	resolve_env_variables(t_token *current)
{
	t_sub_word	*cur;

	cur = current->list_sub_word;
	while (cur)
	{
		if (cur->token == VAR)
			printf("var: \t%s\n", cur->sub_word);
		else if (cur->token == VAR_EXIT)
			printf("var exit: \t%s\n", cur->sub_word);
		cur = cur->next;
	}
}