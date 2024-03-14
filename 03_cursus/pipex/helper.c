/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:26:20 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/14 10:35:13 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	skip_space(char *str)
{
	int	idx;
	idx = 0;
	while (str[idx] == ' ' && str[idx] != '\0')
		idx++;
	return (idx);
}

int	skip_characters(char *str)
{
	int	idx;
	idx = 0;
	while (str[idx] != ' ' && str[idx] != '\0')
		idx++;
	return (idx);
}