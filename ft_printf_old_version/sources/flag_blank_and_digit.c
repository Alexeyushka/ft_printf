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

struct p	print_flags_blank(const char *format, va_list list, int res, struct p parsed)
{
	int number;
	int number2;
	int number3;
	int size;

	size = 0;
	number = va_arg(list, int);
	number2 = number;
	number3 = number2;
	if (number < 0)
	{
		size = size + 2;
		number = number * (-1);
	}
	if (number == '0')
		size++;
	while (number > 0)
	{
		size++;
		number = number / 10;
	}
	res = res - size;
	if (res == 0)
	{
		write(1, " ", 1);
		parsed.ret++;
	}
	while (res > 0)
	{
		write(1, " ", 1);
		parsed.ret++;
		res--;
	}
	if (number3 < 0)
	{	
		write(1, " -", 2);
		parsed.ret++;
	}
	parsed = ft_s_putnbr(number2, parsed);
	return (parsed);
}

void		print_flags_blank_long(const char *format, va_list list, int res)
{
	long number;
	long number2;
	int size;

	size = 0;
	number = va_arg(list, long);
	number2 = number;
	if (number < 0)
	{	
		number = number * (-1);
	}
	if (number == '0')
		size++;
	while (number > 0)
	{
		size++;
		number = number / 10;
	}
	res = res - size;
	write(1, " ", 1);
	while (res > 0)
	{
		write(1, " ", 1);
		res--;
	}
	if (number2 < 0)
	{	
		number2 = number2 * (-1);
	}
	ft_putnbr_long(number2);
}

struct	p printf_flags_blank_and_zero_and_digit(const char *format, va_list list, int res, struct p parsed)
{
	int number;
	int number2;
	int size;

	size = 1;
	if (parsed.exception == 1)
	{	
		size = 0;
		parsed.exception = 0;
	}
	number = va_arg(list, int);
	number2 = number;
	if (number < 0)
	{
		number = number * (-1);
		size++;
		write(1, "-", 1);
		parsed.ret++;
	}
	else
	{
		write(1, " ", 1);
		parsed.ret++;
		size++;
	}
	while (number > 0)
	{
		size++;
		number = number / 10;
	}
	if (res == 0)
	{	
		write(1, " 0", 2);
		parsed.ret++;
		return (parsed);;
	}
	res = res - size;
	while (res > 0)
	{
		write(1, "0", 1);
		parsed.ret++;
		res--;
	}
	parsed = ft_s_putnbr(number2, parsed);
	return (parsed);
}

void	printf_flags_blank_and_zero_and_digit_long(const char *format, va_list list, int res, struct p parsed)
{
	long number;
	long number2;
	int size;
	size = 1;
	if (parsed.exception == 1)
	{
		size = 0;
		parsed.exception = 0;
	}
	number = va_arg(list, long);
	number2 = number;
	if (number < 0)
	{
		number = number * (-1);
		size++;
		write(1, "-", 1);
	}
	else
	{
		write(1, " ", 1);
		size++;
	}
	while (number > 0)
	{
		size++;
		number = number / 10;
	}
	if (res == 0)
	{	
		write(1, " 0", 2);
		return ;
	}
	res = res - size;
	while (res > 0)
	{
		write(1, "0", 1);
		res--;
	}
	ft_putnbr_long(number2);
}

struct	p print_flags_blanks_zero(const char *format, va_list list, int res, struct p parsed)
{
	int number;
	int number2;
	int size;
	size = 1;
	number = va_arg(list, int);
	number2 = number;
	while (number > 0)
	{
		size++;
		number = number / 10;
	}
	res = res - size;
	if (number2 >= 0)
	{
		write(1, " ", 1);
		parsed.ret++;
	}
	else
	{
		write(1, "-", 1);
		parsed.ret++;
	}
	while (res > 0)
	{
		write(1, "0", 1);
		parsed.ret++;
		res--;
	}
	parsed = ft_s_putnbr(number2, parsed);
	return (parsed);
}

void	print_flags_blanks_zero_long(const char *format, va_list list, int res)
{
	long number;
	long number2;
	int size;

	size = 1;
	number = va_arg(list, long);
	number2 = number;
	while (number > 0)
	{
		size++;
		number = number / 10;
	}
	res = res - size;
	if (number2 >= 0)
		write(1, " ", 1);
	else
		write(1, "-", 1);
	while (res > 0)
	{
		write(1, "0", 1);
		res--;
	}
	ft_putnbr_long(number2);
}


struct	p flag_blank_and_digit_d(const char *format, va_list list, int i, struct p parsed)
{
	int res;
	int count;
	int zero;

	res = 0;
	//count = 2;
	parsed.count = 2;
	zero = 0;
	if (format[i + parsed.count] == '0')
		zero = 1;
	if (parsed.l == 1 || parsed.ll == 1)
	{
		parsed.l = 0;
		parsed.ll = 0;
		parsed.count = count_long(format, list, i, parsed);
		res = count_long_res(format, list, i, parsed);
		if (zero == 0)
			print_flags_blank_long(format, list, res);
		else if (zero == 1 && (format[i + 3] == 'd' || format[i + 3] == 'h' || format[i + 3] == 'l' || format[i + 3] == 'i'))
			print_flags_blanks_zero_long(format, list, res);
		else
			printf_flags_blank_and_zero_and_digit_long(format, list, res, parsed);
	}
	else
	{
		while (format[i + parsed.count] >= 48 && format[i + parsed.count] <= 57)
		{
			res = res * 10;
			res = res + ((int)format[i + parsed.count] - '0');
			parsed.count++;
		}
		if (zero == 0)
			parsed = print_flags_blank(format, list, res, parsed);
		else if (zero == 1 && (format[i + 3] == 'd' || format[i + 3] == 'h' || format[i + 3] == 'i'))
			parsed = print_flags_blanks_zero(format, list, res, parsed);
		else
			parsed = printf_flags_blank_and_zero_and_digit(format, list, res, parsed);
	}
	return (parsed);
}