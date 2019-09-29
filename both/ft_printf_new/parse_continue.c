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

int			ft_out(t_struct *list, va_list va)
{
	int		res;

	res = 0;
	if (list->spec == '%')
		res = (ft_print_percent(list, '%'));
	else if (list->spec == 'c' || list->spec == 'C')
		res = (ft_handling_char(list, va_arg(va, void *)));
	else if (list->spec == 's' || list->spec == 'S')
		res = (ft_handling_str(list, va_arg(va, void *)));
	else if (list->spec == 'd' || list->spec == 'i' || list->spec == 'D')
		res = (ft_handling_digit(list, va_arg(va, void *)));
	else if (list->spec == 'u' || list->spec == 'U')
		res = (ft_handling_unsigned_digit(list, va_arg(va, void *)));
	else if (list->spec == 'x' || list->spec == 'X')
		res = (ft_handling_x(list, va_arg(va, void *)));
	else if (list->spec == 'o' || list->spec == 'O')
		res = (ft_handling_o(list, va_arg(va, void *)));
	else if (list->spec == 'p')
		res = (ft_handling_ptr(list, va_arg(va, void *)));
	else if (list->spec == 'f')
		res = (ft_handling_f(list, va));
	else
		res = (ft_handling_char(list, va_arg(va, void *)));
	return (res);
}