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

int		parse_arg_x_init(const char *format, va_list list, int i)
{
	int result;
	struct p parsed;
	parsed.hash_only = 0;
	parsed.hash_and_zero = 0;
	parsed.zero_and_hash = 0;
	parsed.zero_and_hash_and_digit = 0;
	parsed.hash_and_digit = 0;
	parsed.hash_and_zero_and_digit = 0;
	parsed.minus_and_hash = 0;
	parsed.minus_and_digit = 0;
	parsed.zero_and_digit = 0;
	parsed.minus_and_hash_and_digit = 0;
	if (format[i + 1] == '#' && format[i + 2] == 'x')
		parsed.hash_only = 1;
	else if (format[i + 1] == '#' && format[i + 2] == '0' && format[i + 3] == 'x')
		parsed.hash_and_zero = 1;
	else if (format[i + 1] == '0' && format[i + 2] == '#' && format[i + 3] == 'x')
		parsed.zero_and_hash = 1;
	else if (format[i + 1] == '0' && format[i + 2] == '#' && (format[i + 3] >= 48 && format[i + 3] <= 57))
		parsed.zero_and_hash_and_digit = 1;
	else if (format[i + 1] == '#' && (format[i + 2] >= 49 && format[i + 2] <= 57))
		parsed.hash_and_digit = 1;
	else if (format[i + 1] == '#' && format[i + 2] == '0' && (format[i + 3] >= 48 && format[i + 3] <= 57))
		parsed.hash_and_zero_and_digit = 1;
	else if (format[i + 1] == '#' && format[i + 2] == '-' && format[i + 3] == 'x')
		parsed.hash_and_minus = 1;
	else if (format[i + 1] == '#' && format[i + 2] == '-' && (format[i + 3] >= 48 && format[i + 3] <= 57))
		parsed.hash_and_minus_and_digit = 1;
	else if (format[i + 1] == '-' && format[i + 2] == '#' && format[i + 3] == 'x')
		parsed.minus_and_hash = 1;
	else if (format[i + 1] == '-' && (format[i + 2] >= 48 && format[i + 2] <= 57))
		parsed.minus_and_digit = 1;
	else if (format[i + 1] == '0' && (format[i + 2] >= 48 && format[i + 2] <= 57))
		parsed.zero_and_digit = 1;
	else if (format[i + 1] == '-' && format[i + 2] == '#' && (format[i + 3] >= 48 && format[i + 3] <= 57))
		parsed.minus_and_hash_and_digit = 1;
	else
	{
		handle_x(format, list);
		return (0);
	}
	result = print_flags(format, list, i, parsed);
	printf("zzz");
	return (result);
}
