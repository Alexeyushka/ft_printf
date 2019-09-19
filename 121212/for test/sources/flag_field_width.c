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

void    flag_field_width_print(const char *format, va_list list, int i, int k)
{
	int number;

	number = va_arg(list, int);
	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (checksign(number) < 0)
		write(1, "-", 1);
	ft_putnbr(number);
}

void    flag_field_width_print_long(const char *format, va_list list, int i, int k)
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

void	flag_field_width_cont(const char *format, va_list list, int res, struct p parsed)
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
		res--;
	}
	va_end(cpy);
}

void	flag_field_width_long(const char *format, va_list list, int res, struct p parsed)
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

int		flag_field_width(const char *format, va_list list, int i, struct p parsed)
{
	int res;
	int k;
	int count;
	int d;
	res = 0;
	count = 1;
	k = 1;
	if (parsed.l == 1 || parsed.ll == 1)
	{
		parsed.l = 0;
		parsed.ll = 1;
		count = count_long(format, list, i, parsed);
		res = count_long_res(format, list, i, parsed);
		flag_field_width_long(format, list, res, parsed);
		flag_field_width_print_long(format, list, i, count);
		return (count);
	}
	res = parsed.width_number;
	d = res;
	while (d / 10 != 0)
	{
		d = d/10;
		count++;
	}
	flag_field_width_cont(format, list, res, parsed);
	flag_field_width_print(format, list, i, count);
	return (count);
}