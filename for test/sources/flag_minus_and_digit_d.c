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


void    flag_minus_and_digit_print_d(const char *format, va_list list, int i, int number)
{
	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (number < 0)
	{	
		write(1, "-", 1);
		number = number * (-1);
	}
	ft_putnbr(number);
}

int		flag_minus_and_digit_cont_d(const char *format, va_list list, int res)
{
	int number;
	int size;
	size = 0;
	number = va_arg(list, int);
	if (number < 0)
	{
		size++;
	}
	if (number == 0)
		size++;
	flag_minus_and_digit_print_d(format, list, size, number);
	if (number < 0)
		number = number * (-1);
	while (number > 0)
	{
		size++;
		number = number / 10;
	}
	return (size);
}

void    flag_minus_and_digit_print_d_long(const char *format, va_list list, int i, long number)
{
	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (number < 0)
	{	
		write(1, "-", 1);
		number = number * (-1);
	}
	ft_putnbr_long(number);
}

int		flag_minus_and_digit_cont_d_long(const char *format, va_list list, int res)
{
	long number;
	int size;

	size = 0;
	number = va_arg(list, long);
	if (number < 0)
	{
		size++;
	}
	if (number == 0)
		size++;
	flag_minus_and_digit_print_d_long(format, list, size, number);
	if (number < 0)
		number = number * (-1);
	while (number > 0)
	{
		size++;
		number = number / 10;
	}
	return (size);
}

int		flag_minus_and_digit_d(const char *format, va_list list, int i, struct p parsed)
{
	int res;
	int k;
	int count;
	res = 0;
	count = 2;
	k = 1;
	if (parsed.l == 1 || parsed.ll == 1)
	{
		parsed.l = 0;
		parsed.ll = 0;
		count = count_long(format, list, i, parsed);
		res = count_long_res(format, list, i, parsed);
		res = res - flag_minus_and_digit_cont_d_long(format, list, res);
	}
	else
	{
		while (format[i + count] >= 48 && format[i + count] <= 57)
		{
			res = res * 10;
			res = res + ((int)format[i + count] - '0');
			count++;
		}
		res = res - flag_minus_and_digit_cont_d(format, list, res);
	}
	while (res > 0)
	{
		write(1, " ", 1);
		res--;
	}
	return (count);
}