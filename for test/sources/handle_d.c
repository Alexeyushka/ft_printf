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


int		handle_d(const char *format, va_list list, int i, struct p parsed)
{
	int result;
	parsed.plus = 0;
	parsed.plus_and_digit = 0;
	parsed.minus = 0;
	parsed.minus_and_digit = 0;
	parsed.zero = 0;
	parsed.zero_and_digit = 0;
	parsed.blank = 0;
	parsed.digit = 0;
	parsed.blank_and_digit = 0;
	parsed.width_and_minus = 0;
	parsed.width_and_zero = 0;
	parsed.width_and_plus = 0;
	parsed.width = 0;
	if (format[i + 1] == '+' && (format[i + 2] == 'd' || format[i + 2] == 'h' || format[i + 2] == 'l' || format[i + 2] == 'i'))
		parsed.plus = 1;
	else if (format[i + 1] == '+' && (format[i + 2] >= 48 && format[i + 2] <= 57))
		parsed.plus_and_digit = 1;
	else if (format[i + 1] == '-' && (format[i + 2] == 'd' || format[i + 2] == 'h' || format[i + 2] == 'l' || format[i + 2] == 'i'))
		parsed.minus = 1;
	else if (format[i + 1] == '-' && (format[i + 2] >= 48 && format[i + 2] <= 57))
		parsed.minus_and_digit = 1;
	else if (format[i + 1] == '0' && (format[i + 2] == 'd' || format[i + 2] == 'h' || format[i + 2] == 'l' || format[i + 2] == 'i'))
		parsed.zero = 1;
	else if (format[i + 1] == '0' && (format[i + 2] >= 48 && format[i + 2] <= 57))
		parsed.zero_and_digit = 1;
	else if (format[i + 1] == ' ' && (format[i + 2] == 'd' || format[i + 2] == 'h' || format[i + 2] == 'l' || format[i + 2] == 'i'))
		parsed.blank = 1;
	else if (format[i + 1] == ' ' && (format[i + 2] >= 48 && format[i + 2] <= 57))
		parsed.blank_and_digit = 1;
	else if (format[i + 1] >= 48 && format[i + 1] <= 57)
		parsed.digit = 1;
	else if (format[i] == '*' && (format[i - 1] != '+' && format[i - 1] != '-' && format[i - 1] != '0'))
		parsed.width = 1;
	else if (format[i - 1] == '+' && format[i] == '*')
		parsed.width_and_plus = 1;
	else if (format[i - 1] == '-' && format[i] == '*')
		parsed.width_and_minus = 1;
	else if (format[i - 1] == '0' && format[i] == '*')
		parsed.width_and_zero = 1;
	else
	{
		handle_d_without_flags(format, list, i, parsed);
		return (0);
	}
	result = print_flags_more(format, list, i, parsed);
	return (result);
}