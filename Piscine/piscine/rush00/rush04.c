/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raviz-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 09:18:15 by raviz-es          #+#    #+#             */
/*   Updated: 2023/06/10 13:49:29 by adevine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

/*
 * Function to solve the first line. 
 * Print A at first colum, B between the second until the last, 
 * and print C at the last colum
 *
 */
void	write_line(int col, char first_char, char second_char, char third_char)
{
	int	x;

	ft_putchar(first_char);
	x = 2;
	while (x <= col)
	{
		if (col >= 2 && x < col)
		{
			ft_putchar(second_char);
		}
		else
		{	
			ft_putchar(third_char);
		}
		x++;
	}
}

void	rush(int col, int lin)
{
	int	y;

	y = 1;
	while (y <= lin)
	{
		if (y == 1)
		{
			write_line(col, 'A', 'B', 'C');
			ft_putchar('\n');
		}
		else if (y < lin)
		{
			write_line(col, 'B', ' ', 'B');
			ft_putchar('\n');
		}
		else
		{
			write_line(col, 'C', 'B', 'A');
			ft_putchar('\n');
		}
		y++;
	}
}
