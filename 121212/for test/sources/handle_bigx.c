/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartyn- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:39:19 by jmartyn-          #+#    #+#             */
/*   Updated: 2019/09/14 15:52:36 by jmartyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

struct p	handle_bigx_continue(int j, int i, char *hexadecimal, struct p parsed)
{
	char tmp;

	while (j >= 0)
	{
		tmp = hexadecimal[j];
		write(1, &tmp, 1);
		parsed.ret++;
		j--;
		if (is_digit(hexadecimal[j] == 1))
		{
			write(1, &hexadecimal[j], 1);
			parsed.ret++;
			j--;
		}
	}
	return (parsed);
}

struct 		p handle_bigx(const char *format, va_list list, struct p parsed)
{
	char	hexadecimal[100];
	long	decimal;
	long	quotient;
	long	remainder;
	int		i;

	i = 0;
	decimal = va_arg(list, int);
	quotient = decimal;
	if (decimal < 0)
	{
		quotient = handle_negative_x(decimal);
	}
	if (quotient == 0)
	{
		write(1, "0", 1);
		parsed.ret++;
	}
	while (quotient != 0)
	{
		remainder = quotient % 16;
		if (remainder < 10)
			hexadecimal[i] = 48 + remainder;
		else
			hexadecimal[i] = 55 + remainder;
		i++;
		quotient = quotient / 16;
	}
	parsed = handle_bigx_continue((i - 1), i, hexadecimal, parsed);
	return (parsed);
}
