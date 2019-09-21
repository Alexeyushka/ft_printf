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


int		flag_width_minus_and_digit_cont_d(const char *format, va_list list, int res, struct p parsed)
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
	return (parsed.digitsize);
}


int		flag_field_width_and_minus(const char *format, va_list list, int i, struct p parsed)
{
	int res;
	int k;
	int count;
	res = 0;
	count = 0;
	k = 1;

	res = parsed.width_number - flag_width_minus_and_digit_cont_d(format, list, res, parsed);
	while (res > 0)
	{
		write(1, " ", 1);
		res--;
	}
	return (count);
}