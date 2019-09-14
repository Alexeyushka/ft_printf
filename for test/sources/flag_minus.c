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


int		print_flag_minus_corr(const char *format, va_list list, int res)
{
	int number;
	int size;

	number = 0;
	va_list cpy;
	va_copy(cpy, list);
	number = va_arg(cpy, int);
	size = 0;
	
	if (number < 0)
		number = number * (-1);
	if (number == 0)
		size++;
	while (number > 0)
	{
		size++;
		number = number / 10;
	}
	va_end(cpy);
	return (size);
}


int		print_flag_minus(const char *format, va_list list, int i)
{
	int res;
	int k;
	int count;
	res = 0;
	count = 2;
	k = 1;

	while (format[i + count] >= 48 && format[i + count] <= 57)
	{
		res = res * 10;
		res = res + ((int)format[i + count] - '0');
		count++;
	}
	res = res - print_flag_minus_corr(format, list, res);
	return (res);
}

int		flag_minus(const char *format, va_list list, int i, struct p parsed)
{
	int res;
	if (format[i + 1] == '-' && (format[i + 2] == 'd' || format[i + 2] == 'h' || format[i + 2] == 'l' || format[i + 2] == 'i'))
	{
		
		handle_d_without_flags(format, list, i, parsed);
		res = print_flag_minus(format, list, i);
		while (res > 0)
		{
			write(1, " ", 1);
			res--;
		}
	}
	return (2);
}