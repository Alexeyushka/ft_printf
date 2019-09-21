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

#include "ft_printf.h"

void	flag_hash_only_print_blanks_continue_more(int j, int i, char *hexadecimal)
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

void	flag_hash_only_print_blanks_continue(const char *format, va_list list, struct p parsed_x)
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
	flag_hash_only_print_blanks_continue_more((i - 1), i, hexadecimal);
}

int	flag_hash_only_print_blanks(const char *format, va_list list)
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
		write(1, "0x", 2);
	flag_hash_only_print_blanks_continue(format, list, parsed);
	va_end(cpy);
	return (i);
}

int		flag_hash_only(const char *format, va_list list, int i, struct p parsed)
{
	int res;
	int digit;

	digit = 0;
	res = 0;

	va_list cpy;
	va_copy(cpy, list);
	digit = va_arg(cpy, int);
	if (digit != '0')
		res = 2;
	res = res + flag_hash_only_print_blanks(format, list);
	if (res == 1)
		write(1, "0", 1);
	va_end(cpy);
	return (res);
}