/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartyn- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:39:19 by jmartyn-          #+#    #+#             */
/*   Updated: 2019/09/14 15:39:54 by jmartyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    ft_printf(const char *format, ...)
{
    int i;
	int len;
	va_list va;
	t_struct list;

	i = 0;
	len = 0;
	va_start(va, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
			len = len + print_char(format, i);
		else
		{
			i++;
			len = len + parse_format(format, i, va, &list);
			i = i + list.len;
			list.len = 0;
		}
		i++;
	}
	va_end(va);
	return (len);
}