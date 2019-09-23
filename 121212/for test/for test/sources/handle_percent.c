/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartyn- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:39:19 by jmartyn-          #+#    #+#             */
/*   Updated: 2019/09/14 16:16:24 by jmartyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

struct  p count_digit_percent(const char *format, int i, int position, struct p parsed)
{
	int k;
	int count;

	parsed.res2 = 0;
	parsed.count = 1 + position;
	k = 1;
	while (format[i + parsed.count] >= 48 && format[i + parsed.count] <= 57)
	{
		parsed.res2 = parsed.res2 * 10;
		parsed.res2 = parsed.res2 + ((int)format[i + parsed.count] - '0');
		parsed.count++;
	}
    return (parsed);
}

struct  p print_percent_digit(const char *format, va_list list, int i, struct p parsed)
{
    parsed.count = 2;
	parsed.res2 = 0;
	parsed.ret++;
    int position;
    position = 0;
    parsed = count_digit_percent(format, i, position, parsed);
    parsed.res2--;
	//parsed = print_flag_minus(format, list, i, parsed);
	while (parsed.res2 > 0)
	{
		write(1, " ", 1);
		parsed.ret++;
		parsed.res2--;
	}
    write(1, "%", 1);
    return (parsed);
}

struct  p print_percent_minusdigit(const char *format, va_list list, int i, struct p parsed)
{
    int position;
    position = 1;
    parsed.count = 2;
	parsed.res2 = 0;
	write(1, "%", 1);
	parsed.ret++;
    parsed = count_digit_percent(format, i, position, parsed);
    parsed.res2--;
	//parsed = print_flag_minus(format, list, i, parsed);
	while (parsed.res2 > 0)
	{
		write(1, " ", 1);
		parsed.ret++;
		parsed.res2--;
	}
    return (parsed);
}

struct  p handle_percent(const char *format, va_list list, int i, struct p parsed)
{
    parsed.digit = 0;
    parsed.minus_and_digit = 0;
    parsed.blank = 0;
	if (format[i + 1] == '-' && (format[i + 2] >= 48 && format[i + 2] <= 57))
		parsed.minus_and_digit = 1;
	else if (format[i + 1] >= 48 && format[i + 1] <= 57)
		parsed.digit = 1;
    else if (format[i + 1] == ' ' || (format[i + 1] == ' ' && format[i + 2] == ' ')
        || (format[i + 1] == ' ' && format[i + 2] == ' ' && format[i + 3] == ' '))
        parsed.blank = 1;
	else
	{
		write(1, "%", 1);
        parsed.count = 1;
		parsed.ret++;
		return (parsed);
	}
    if (parsed.minus_and_digit == 1)
    {
	    parsed = print_percent_minusdigit(format, list, i, parsed);
        parsed.minus_and_digit = 0;
    }
    if (parsed.digit == 1)
    {
	    parsed = print_percent_digit(format, list, i, parsed);
        parsed.digit = 0;
    }
    if (parsed.blank == 1)
    {
	    write(1, "%", 1);
        parsed.count = 4;
		parsed.ret++;
    }
	return (parsed);
}