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


struct	p flag_minus_and_digit_print_d(const char *format, va_list list, struct p parsed, int number)
{
	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		parsed.count = 11;
		return (parsed);
	}
	if (number < 0)
	{	
		write(1, "-", 1);
		parsed.ret++;
		number = number * (-1);
	}
	parsed = ft_s_putnbr(number, parsed);
	return (parsed);
}

struct	p flag_minus_and_digit_cont_d(const char *format, va_list list, struct p parsed)
{
	int number;
	int size;
	parsed.digitsize = 0;
	number = va_arg(list, int);
	if (number < 0)
	{
		parsed.digitsize++;
	}
	if (number == 0)
		parsed.digitsize++;
	parsed = flag_minus_and_digit_print_d(format, list, parsed, number);
	if (number < 0)
		number = number * (-1);
	while (number > 0)
	{
		parsed.digitsize++;
		number = number / 10;
	}
	return (parsed);
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

struct	p flag_minus_and_digit_d(const char *format, va_list list, int i, struct p parsed)
{
	int res;
	int k;
	int count;
	parsed.res2 = 0;
	parsed.count = 2;
	k = 1;
	if (parsed.l == 1 || parsed.ll == 1)
	{
		parsed.l = 0;
		parsed.ll = 0;
		count = count_long(format, list, i, parsed);
		parsed.res2 = count_long_res(format, list, i, parsed);
		
		parsed.res2 = parsed.res2 - flag_minus_and_digit_cont_d_long(format, list, parsed.res2);
	}
	else
	{
		while (format[i + parsed.count] >= 48 && format[i + parsed.count] <= 57)
		{
			parsed.res2 = parsed.res2 * 10;
			parsed.res2 = parsed.res2 + ((int)format[i + parsed.count] - '0');
			parsed.count++;
		}
		parsed = flag_minus_and_digit_cont_d(format, list, parsed);
		parsed.res2 = parsed.res2 - parsed.digitsize;
	}
	while (parsed.res2 > 0)
	{
		write(1, " ", 1);
		parsed.ret++;
		parsed.res2--;
	}
	return (parsed);
}