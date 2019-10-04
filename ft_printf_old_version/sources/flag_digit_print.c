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

struct	p flag_digit_print(const char *format, va_list list, int i, struct p parsed)
{
	int number;

	number = va_arg(list, int);
	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		parsed.ret = 11;
		return (parsed);
	}
	if (checksign(number) < 0)
	{
		write(1, "-", 1);
		parsed.ret++;
	}
	parsed = ft_s_putnbr(number, parsed);
	return (parsed);
}

void    flag_digit_print_long(const char *format, va_list list, int i, int k)
{
	long number;

	number = va_arg(list, long);
	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (checksign_long(number) < 0)
		write(1, "-", 1);
	ft_putnbr_long(number);
}

struct	p flag_digit_cont(const char *format, va_list list, int res, struct p parsed)
{
	int number;
	int size;
	va_list cpy;
	va_copy(cpy, list);
	size = 0;
	number = va_arg(cpy, int);
	if (number < 0)
	{
		number = number * (-1);
		size++;
	}
	if (number == 0)
		size++;
	while (number > 0)
	{
		size++;
		number = number / 10;
	}

	res = res - size;
	while (res > 0)
	{
		write(1, " ", 1);
		parsed.ret++;
		res--;
	}
	va_end(cpy);
	return (parsed);
}

void	flag_digit_long(const char *format, va_list list, int res, struct p parsed)
{
	long number;
	int size;
	va_list cpy;
	va_copy(cpy, list);
	size = 0;
	number = va_arg(cpy, long);
	if (number < 0)
	{
		number = number * (-1);
		size++;
	}
	if (number == 0)
		size++;
	while (number > 0)
	{
		size++;
		number = number / 10;
	}
	res = res - size;
	
	while (res > 0)
	{
		write(1, " ", 1);
		res--;
	}
	va_end(cpy);
}

struct	p flag_digit(const char *format, va_list list, int i, struct p parsed)
{
	int res;
	int k;
	int count;
	parsed.count = 1;
	res = 0;
	//count = 1;
	k = 1;
	if (parsed.l == 1 || parsed.ll == 1)
	{
		parsed.l = 0;
		parsed.ll = 1;
		count = count_long(format, list, i, parsed);
		res = count_long_res(format, list, i, parsed);
		flag_digit_long(format, list, res, parsed);
		flag_digit_print_long(format, list, i, count);
		return (parsed);
	}
	while (format[i + parsed.count] >= 48 && format[i + parsed.count] <= 57)
	{
		res = res * 10;
		res = res + ((int)format[i + parsed.count] - '0');
		parsed.count++;
	}
	parsed = flag_digit_cont(format, list, res, parsed);
	parsed = flag_digit_print(format, list, i, parsed);
	return (parsed);
}