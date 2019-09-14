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


void    ft_printf(const char *format, ...)
{
    int i;
	va_list list;
	int d;
	int o;
	int x;
	int tmp;
	int res;
    char ch;
	i = 0;
    d = 0;
    o = 0;
	va_start(list, format);
	struct p parsed_x;
	while (format[i] != '\0')
	{
        if (format[i] == '%')
		{
            ch = parse_format(format, list, (i + 1));
			parsed_x = flags_short_and_long(format, list, (i + 1), parsed_x);
			if (ch == '*')
			{
				parsed_x.width_number = handle_field_width(format, list, i, parsed_x);
				i = i + 1 + parsed_x.size;
				ch = parse_format_without_prec(format, list, (i + 1));
				parsed_x.size = 0;
			}
			if (ch == 's')
			{
				if (parsed_x.string_precision == 1)
				{
					handle_s_w_prec(format, list, parsed_x);
					i = i + 3;
					parsed_x.string_precision = 0;
				}
				else
				{	
					handle_s(format, list);
					i = i + 1;
				}
			}
    		if (ch == 'd' || ch == 'i')
			{
				d = handle_d(format, list, i, parsed_x);
				if (d == 0)
					d = 1;
				i = i + d + parsed_x.size;	
			}
			if (ch == 'c')
			{
				handle_c(format, list);
				i = i + 1;
			}
			if (ch == 'u')
			{
				handle_u(format, list, i);
				i = i + 1;
			}
			if (ch == 'x')
			{
				x = parse_arg_x_init(format, list, i);
				i = i + 1 + x;
			}
			if (ch == 'X')
			{
				handle_bigx(format, list);
				i = i + 1;
			}
			if (ch == 'o')
			{
				handle_o(format, list);
				i = i + 1 + o;
			}
			if (ch == 'f')
			{
				handle_f(format, list, parsed_x);
				i = i + 1 + parsed_x.l + parsed_x.largel + parsed_x.precision_count;
				// parsed_x.l = 0;
				// parsed_x.largel = 0;
				// parsed_x.precision_zero = 0;
				// parsed_x.precision = 0;
				// parsed_x.precision_count = 0;
				// parsed_x.res = 0;
			}
			if (ch == 88)
			{
				handle_hui(format, list, parsed_x);
				i = i + 3;
			}
			if (ch == '%')
			{
				write(1, "%", 1);
				i = i + 1;
			}
			if (format[i] == '\\' && format[i + 1] == 'n')
			{
				write(1, "\n", 1);
				i = i + 2;
			}
		}
		else
			write(1, &format[i], 1);
		parsed_x.width_number = 0;
		parsed_x.width = 0;
		i++;
	}
	va_end(list);
}