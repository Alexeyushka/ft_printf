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

void    flag_width_and_plus_print(const char *format, va_list list, int i, struct p parsed)
{
	int number;

	number = va_arg(list, int);
	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (checksign(number) == 0)
		write(1, "+", 1);
	ft_putnbr(number);
}

void    flag_width_and_plus_long_print(const char *format, va_list list, int i, int k)
{
	long number;

	number = va_arg(list, long);
	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (checksign_long(number) == 0)
		write(1, "+", 1);
	ft_putnbr_long(number);
}

void	flag__width_and_plus_blanks(const char *format, va_list list, int res, struct p parsed)
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
	}
	if (number == 0)
		size++;
	while (number > 0)
	{
		size++;
		number = number / 10;
	}

	res = res - size - 1;
	while (res > 0)
	{
		write(1, " ", 1);
		res--;
	}
	va_end(cpy);
}

void	flag_width_and_plus_long_blanks(const char *format, va_list list, int res, struct p parsed)
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
	}
	if (number == 0)
		size++;
	while (number > 0)
	{
		size++;
		number = number / 10;
	}
	res = res - size - 1;
	
	while (res > 0)
	{
		write(1, " ", 1);
		res--;
	}
	va_end(cpy);
}

int		flag_field_width_and_plus(const char *format, va_list list, int i, struct p parsed)
{
	int res;
	int k;
	int count;
	res = 0;
	count = 0;
	k = 1;
	int d;
	if (parsed.l == 1 || parsed.ll == 1)
	{
		parsed.l = 0;
		parsed.ll = 1;
		count = count_long(format, list, i, parsed);
		res = count_long_res(format, list, i, parsed);
		flag_width_and_plus_long_blanks(format, list, res, parsed);
		flag_width_and_plus_long_print(format, list, i, count);
		return (count);
	}
	res = parsed.width_number;
	d = res;
	while (d / 10 != 0)
	{
		d = d/10;
		count++;
	}
	flag__width_and_plus_blanks(format, list, parsed.width_number, parsed);
	flag_width_and_plus_print(format, list, i, parsed);
	parsed.width_number = 0;
	return (count);
}