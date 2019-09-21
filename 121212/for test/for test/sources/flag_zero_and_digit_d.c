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
struct p print_flags_zero_and_digit_d(const char *format, va_list list, int res, struct p parsed)
{
	int number;
	int number2;
	int size;

	size = 0;
	number = va_arg(list, int);
	number2 = number;
	if (number < 0)
	{	
		write(1, "-", 1);
		size = size + 1;
		number = number * (-1);
	}
	while (number > 0)
	{
		size++;
		number = number / 10;
	}
	res = res - size;
	while (res > 0)
	{
		write(1, "0", 1);
		parsed.ret++;
		res--;
	}
	if (number2 != 0)
		parsed = ft_s_putnbr(number2, parsed);
	return (parsed);
}

void		print_flags_zero_and_digit_d_long(const char *format, va_list list, int res)
{
	long number;
	long number2;
	int size;

	size = 0;
	number = va_arg(list, long);
	number2 = number;
	if (number < 0)
	{	
		write(1, "-", 1);
		size = size + 1;
		number = number * (-1);
	}
	while (number > 0)
	{
		size++;
		number = number / 10;
	}
	res = res - size;
	while (res > 0)
	{
		write(1, "0", 1);
		res--;
	}
	if (number2 != 0)
		ft_putnbr_long(number2);
}


struct p parse_flag_zero_and_digit_d(const char *format, va_list list, int i, struct p parsed)
{
	int res;
	int k;
	int count;

	res = 0;
	//count = 2;
	parsed.count = 2;
	k = 1;
	if (parsed.l == 1 || parsed.ll == 1)
	{
		parsed.l = 0;
		parsed.ll = 0;
		parsed.count = count_long(format, list, i, parsed);
		res = count_long_res(format, list, i, parsed);
		print_flags_zero_and_digit_d_long(format, list, res);
	}
	else
	{
		while (format[i + parsed.count] >= 48 && format[i + parsed.count] <= 57)
		{
			res = res * 10;
			res = res + ((int)format[i + parsed.count] - '0');
			parsed.count++;
		}
		parsed = print_flags_zero_and_digit_d(format, list, res, parsed);
	}
	return (parsed);
}