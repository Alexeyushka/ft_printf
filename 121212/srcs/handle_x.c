/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartyn- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:39:19 by jmartyn-          #+#    #+#             */
/*   Updated: 2019/09/14 15:39:54 by jmartyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

long	handle_negative_x(long decimal)
{
	return (4294967296 + decimal);
}

void	handle_x_continue(int j, int i, char *hexadecimal)
{
	char tmp;

	while (j >= 0)
	{
		if (is_upper(hexadecimal[j]) == 1)
		{
			tmp = hexadecimal[j];
			tmp = tmp + 32;
			write(1, &tmp, 1);
			j--;
		}
		if (is_upper(hexadecimal[j]) == 0)
		{
			tmp = hexadecimal[j];
			write(1, &tmp, 1);
			j--;
		}
		if (is_digit(hexadecimal[j] == 1))
		{
			write(1, &hexadecimal[j], 1);
			j--;
		}
	}
}

void	handle_x(const char *format, va_list list)
{
	char	hexadecimal[100];
	long	decimal;
	long	quotient;
	long	remainder;
	int		i;

	i = 0;
	decimal = va_arg(list, int);
	quotient = decimal;
	if (decimal < 0)
		quotient = handle_negative_x(decimal);
	if (quotient == 0)
		write(1, "0", 1);
	while (quotient != 0)
	{
		remainder = quotient % 16;
		if (remainder < 10)
			hexadecimal[i] = 48 + remainder;
		else
			hexadecimal[i] = 55 + remainder;
		i++;
		quotient = quotient / 16;
	}
	handle_x_continue((i - 1), i, hexadecimal);
}

void	handle_hui(const char *format, va_list list, struct p parsed)
{
	write(1, "LOVI HUICA\n", 12);
	write(1, "8===D\n", 6);
}
