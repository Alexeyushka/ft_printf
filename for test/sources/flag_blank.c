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

void		print_flags_blank_wo_digits(const char *format, va_list list, int res)
{
	int number;

	number = va_arg(list, int);
	if (number < 0)
		write(1, "-", 1);
	else
		write(1, " ", 1);
	ft_putnbr(number);
}

void		print_flags_blank_wo_digits_long(const char *format, va_list list, int res)
{
	long number;

	number = va_arg(list, long);
	if (number < 0)
		write(1, "-", 1);
	else
		write(1, " ", 1);
	ft_putnbr_long(number);
}

int		flag_blank_d(const char *format, va_list list, int i, struct p parsed)
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
		print_flags_blank_wo_digits_long(format, list, res);
	}
	else
	{
		while (format[i + count] >= 48 && format[i + count] <= 57)
		{
			res = res * 10;
			res = res + ((int)format[i + count] - '0');
			count++;
		}
		print_flags_blank_wo_digits(format, list, res);
	}
	return (count);
}