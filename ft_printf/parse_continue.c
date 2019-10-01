/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartyn- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 20:27:50 by jmartyn-          #+#    #+#             */
/*   Updated: 2019/09/29 20:51:27 by jmartyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_format_continue(const char *format, int i, t_struct *list)
{
	if (format[i] == 's' || format[i] == 'p' || format[i] == 'd'
		|| format[i] == 'i' || format[i] == 'o' || format[i] == 'u'
		|| format[i] == 'x' || format[i] == 'X' || format[i] == 'c'
		|| format[i] == 'f' || format[i] == '%')
		list->spec = format[i];
	else
	{
		list->spec = format[i];
	}
}

int			ft_out(t_struct *list, va_list va)
{
	int		res;

	res = 0;
	if (list->spec == '%')
		res = (ft_print_percent(list, '%'));
	else if (list->spec == 'c')
		res = (ft_handling_char(list, va_arg(va, void *)));
	else if (list->spec == 's')
		res = (ft_handling_str(list, va_arg(va, void *)));
	else if (list->spec == 'd' || list->spec == 'i')
		res = (ft_handling_digit(list, va_arg(va, void *)));
	else if (list->spec == 'u')
		res = (ft_handling_unsigned_digit(list, va_arg(va, void *)));
	else if (list->spec == 'x' || list->spec == 'X')
		res = (ft_handling_x(list, va_arg(va, void *)));
	else if (list->spec == 'o')
		res = (ft_handling_o(list, va_arg(va, void *)));
	else if (list->spec == 'p')
		res = (ft_handling_ptr(list, va_arg(va, void *)));
	else if (list->spec == 'f')
		res = (ft_handling_f(list, va));
	else
		res = (ft_handling_char(list, va_arg(va, void *)));
	return (res);
}