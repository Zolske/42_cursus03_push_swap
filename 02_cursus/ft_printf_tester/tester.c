/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:29:23 by zkepes            #+#    #+#             */
/*   Updated: 2023/12/21 16:11:06 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
// #include "ft_printf.h"
#include "ft_printf_bonus.h"

// int		ft_printf(const char *str_p, ...);

int     main(void)
{
    printf("|ft: %d|\n", ft_printf(">>some text $ form_1: %d,  form_2: %d<<", 42, 42 * 2));
    printf("|ft: %d|\n",    printf(">>some text $ form_1: %d,  form_2: %d<<", 42, 42 * 2));
}