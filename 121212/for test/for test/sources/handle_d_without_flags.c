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


int		checksign(int number)
{
	if (number < 0)
	{
		write(1, "-", 1);
		return (1);
	}
	if (number >= 0)
		return (0);
	return (0);
}

int		checksign_long(long long int number)
{
	if (number < 0)
	{
		write(1, "-", 1);
		return (1);
	}
	if (number >= 0)
		return (0);
	return (0);
}

struct	p handle_long_flag(const char *format, va_list list, int i, struct p parsed)
{
	long number;
	number = va_arg(list, long);
	if (number == 9223372036854775807)
	{
		write(1, "9223372036854775807", 19);
		parsed.ret = 19;
		return (parsed);
	}
	if (number == -2147483649)
	{
		write(1, "-2147483649", 11);
		parsed.ret = 11;
		return (parsed);
	}
	if (number == 2147483648)
	{
		write(1, "2147483648", 10);
		parsed.ret = 10;
		return (parsed);
	}
	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		parsed.ret = 11;
		return (parsed);
	}
	checksign_long(number);
	parsed = ft_s_putnbr_long(number, parsed);
	parsed.l = 0;
	return (parsed);
}

struct	p handle_d_without_flags(const char *format, va_list list, int i, struct p parsed)
{
	int number;
	
	parsed.count = 1;
	if (parsed.l == 1 || parsed.ll == 1)
	{
		parsed = handle_long_flag(format, list, i, parsed);
		return (parsed);
	}
	number = va_arg(list, int);
	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		parsed.ret = 11;

		return (parsed);
	}
	checksign(number);
	parsed = ft_s_putnbr(number, parsed);
	return (parsed);
}
