/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartyn- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:39:19 by jmartyn-          #+#    #+#             */
/*   Updated: 2019/09/14 16:16:24 by jmartyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_s(const char *format, va_list list, struct p parsed)
{
	int		i;
	int		j;
	char	*arg;

	arg = va_arg(list, char*);
	j = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] == 's')
		{
			while (arg[j] != '\0')
			{
				write(1, &arg[j], 1);
				parsed.ret++;
				j++;
			}
			i = i + 2;
		}
		i++;
	}
	return (parsed.ret);
}

int		handle_s_precision(const char *format, va_list list, int len, struct p parsed)
{
	int		j;
	char	*arg;

	j = 0;
	arg = va_arg(list, char*);
	while (arg[j] != '\0' && j < len)
	{
		write(1, &arg[j], 1);
		parsed.ret++;
		j++;
	}
	return (parsed.ret);
}

int		handle_s_w_prec(const char *format, va_list list, struct p parsed)
{
	int len;

	len = va_arg(list, int);
	return (handle_s_precision(format, list, len, parsed));
}
