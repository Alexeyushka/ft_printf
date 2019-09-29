/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartyn- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 20:27:50 by jmartyn-          #+#    #+#             */
/*   Updated: 2019/09/29 20:30:33 by jmartyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	int			i;
	int			len;
	va_list		va;
	t_struct	list;

	i = 0;
	len = 0;
	va_start(va, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
			len = len + print_char(format, i);
		else
		{
			if (format[i] == '%' && format[i + 1] == '\0')
				return (0);
			i++;
			len = len + pa(format, i, va, &list);
			i = i + list.len;
			list.len = 0;
		}
		i++;
	}
	va_end(va);
	return (len);
}
