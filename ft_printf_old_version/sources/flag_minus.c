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


struct	p print_flag_minus(const char *format, va_list list, int i, struct p parsed)
{
	//int res;
	int k;
	int count;
	parsed.res2 = 0;
	parsed.count = 2;
	k = 1;

	while (format[i + parsed.count] >= 48 && format[i + parsed.count] <= 57)
	{
		parsed.res2 = parsed.res2 * 10;
		parsed.res2 = parsed.res2 + ((int)format[i + parsed.count] - '0');
		parsed.count++;
	}
	parsed.res2 = parsed.res2 - print_flag_minus_corr(format, list, parsed.res);
	return (parsed);
}

struct	p flag_minus(const char *format, va_list list, int i, struct p parsed)
{
	//int res;
	parsed.count = 2;
	parsed.res2 = 0;
	if (format[i + 1] == '-' && (format[i + 2] == 'd' || format[i + 2] == 'h' || format[i + 2] == 'l' || format[i + 2] == 'i'))
	{
		
		parsed = handle_d_without_flags(format, list, i, parsed);
		parsed = print_flag_minus(format, list, i, parsed);
		while (parsed.res2 > 0)
		{
			write(1, " ", 1);
			parsed.ret++;
			parsed.res2--;
		}
	}
	return (parsed);
}