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


void	flag_hash_and_minus_and_digit_print(const char *format, va_list list, struct p parsed_x)
{
	char hexadecimal[100];
	long decimal;
	long quotient;
	long remainder;
	int i;
	
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
	if (decimal != 0)
		write(1, "0x", 2);
	handle_x_continue_blanks((i - 1), i, hexadecimal);
}

int	flag_hash_and_minus_and_digit_blanks(const char *format, va_list list)
{
	char hexadecimal[100];
	long decimal;
	long quotient;
	long remainder;
	int i;

	i = 0;
	va_list cpy;
	va_copy(cpy, list);
	struct p parsed;
	decimal = va_arg(cpy, int);
	quotient = decimal;
	if (decimal < 0)
		quotient = handle_negative_x(decimal);
	if (quotient == 0)
		i--;
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
	if (decimal != 0)
		i = i + 2;
	va_end(cpy);
	return (i);
}


int		flag_hash_and_minus_and_digit(const char *format, va_list list, int i, struct p parsed)
{
	int size;
	int res;
	int digits;
	int zero_blanks;

	zero_blanks = count_zero_blanks(format, list, i);
	size = flag_hash_and_minus_and_digit_blanks(format, list);
	res = flag_count_res(format, (i + 3));
	digits = ft_numlen(res);
	flag_hash_and_minus_and_digit_print(format, list, parsed);
	while (res - size  - zero_blanks > 0)
	{
		write(1, " ", 1);
		res--;
	}
	return (digits);
}
