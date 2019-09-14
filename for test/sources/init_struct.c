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


struct	p flags_short_and_long(const char *format, va_list list, int i, struct p parsed_x)
{
	parsed_x.size = 0;
	parsed_x.precision = 0;
	parsed_x.string_precision = 0;
	parsed_x.width_and_zero = 0;
	parsed_x.width_and_minus = 0;
	parsed_x.width_and_plus = 0;
	parsed_x.width = 0; 
	parsed_x.l = 0;
	parsed_x.largel = 0;
	parsed_x.precision_zero = 0;
	parsed_x.precision = 0;
	parsed_x.precision_count = 0;
	parsed_x.res = 0;
	int tmp;
	tmp = 0;
	while (format[i] != 's' && format[i] != 'd' &&
		format[i] != 'i' && format[i] != 'c' &&
		format[i] != 'u' && format[i] != 'x' &&
		format[i] != 'X' && format[i] != 'o' &&
		format[i] != 'f' && format[i] != '%')
		{
			if (format[i] == 'h' && format[i + 1] != 'h')
			{	
				parsed_x.h = 1;
				parsed_x.size = 1;
			}
			if (format[i] == 'h' && format[i + 1] == 'h')
			{
				parsed_x.hh = 1;
				parsed_x.size = 2;
				parsed_x.exception = 1;
				return (parsed_x);
			}
			if (format[i] == 'l' && format[i + 1] != 'l')
			{	parsed_x.l = 1;
				parsed_x.size = 1;
			}
			if (format[i] == 'l' && format[i + 1] == 'l')
			{
				parsed_x.ll = 1;
				parsed_x.size = 2;
				parsed_x.exception = 1;
				return (parsed_x);
			}
			if (format[i] == 'L')
			{	
				parsed_x.largel = 1;
				parsed_x.size = 1;
			}
			if (format[i] == '.' && (format[i + 1] >= 48 && format[i + 1] <= 57))
			{
				if (format[i + 1] == '0')
					parsed_x.precision_zero = 1;
				parsed_x.precision = format[i + 1] - '0';
				parsed_x.precision_count = 2;
			}
			if (format[i] == '*' && !(format[i - 1] == '+' || format[i - 1] == '-' || format[i - 1] == '0'))
			{
				parsed_x.width = 1;
			}
			if (format[i - 1] == '+' && format[i] == '*')
			{	
				parsed_x.width_and_plus = 1;
				parsed_x.size = 1;
			}
			if (format[i - 1] == '-' && format[i] == '*')
			{	
				parsed_x.width_and_minus = 1;
				parsed_x.size = 1;
			}
			if (format[i - 1] == '0' && format[i] == '*')
			{	
				parsed_x.width_and_zero = 1;
				parsed_x.size = 1;
			}
			if (format[i] == '.' && format[i + 1] == '*' && format[i + 2] == 's')
				parsed_x.string_precision = 1;
		i++;
		}
	return (parsed_x);
}

int		handle_field_width(const char *format, va_list list, int i, struct p parsed_x)
{
	int number;
	number = va_arg(list, int);
	return (number);
}