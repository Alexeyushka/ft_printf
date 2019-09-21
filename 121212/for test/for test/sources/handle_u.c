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

struct	p handle_u(const char *format, va_list list, int i, struct p parsed)
{
	unsigned int number;

	number = va_arg(list, unsigned int);
	if (format[i] == '%' && format[i + 1] == 'u')
	{
		parsed.count = 1;
		if (number == -1)
		{
			write(1, "4294967295", 10);
			parsed.ret = 10;
			return (parsed);
		}
		if (number == 4294967295)
		{
			write(1, "4294967295", 10);
			parsed.ret = 10;
			return (parsed);
		}
		parsed = ft_putnbr_s_uint(number, parsed);
	}
	return (parsed);
}
