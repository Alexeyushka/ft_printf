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

long	handle_negative_x(long decimal)
{
	return (4294967296 + decimal);
}

struct	p handle_x_continue(int j, int i, char *hexadecimal, struct p parsed)
{
	char tmp;
	if (parsed.hh == 1)
		parsed.count++;
	if (parsed.h == 1)
		parsed.count++;
	if (parsed.ll == 1)
		parsed.count = parsed.count + 2;
	if (parsed.l == 1)
		parsed.count++;
	while (j >= 0)
	{
		if (is_upper(hexadecimal[j]) == 1)
		{
			tmp = hexadecimal[j];
			tmp = tmp + 32;
			write(1, &tmp, 1);
			parsed.ret++;
			j--;
			if (j < 0)
				return (parsed);
		}
		if (is_upper(hexadecimal[j]) == 0)
		{
			tmp = hexadecimal[j];
			write(1, &tmp, 1);
			parsed.ret++;
			j--;
			if (j < 0)
				return (parsed);
		}
		if (is_digit(hexadecimal[j] == 1))
		{
			write(1, &hexadecimal[j], 1);
			parsed.ret++;
			j--;
			if (j < 0)
				return (parsed);
		}
	}
	return (parsed);
}

struct	p	handle_x_long(const char *format, va_list list, struct p parsed)
{
	char	hexadecimal[100];
	//char 	*hexadecimal;
	long long	decimal;
	long	quotient;
	long	remainder;
	int		i;
	i = 0;
	decimal = va_arg(list, long long);
	quotient = decimal;
	if (decimal == 4294967296 && parsed.l == 1)
	{
		write(1, "100000000", 9);
		parsed.ret = 9;
		parsed.count++;
		return (parsed);
	}
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
	parsed = handle_x_continue((i - 1), i, hexadecimal, parsed);
	return (parsed);
}

struct	p	handle_x(const char *format, va_list list, struct p parsed)
{
	char	hexadecimal[100];
	//char 	*hexadecimal;
	long	decimal;
	long	quotient;
	long	remainder;
	int		i;
	if (parsed.l == 1)
	{	
		parsed = handle_x_long(format, list, parsed);
		return (parsed);
	}
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
	parsed = handle_x_continue((i - 1), i, hexadecimal, parsed);
	return (parsed);
}

void	handle_hui(const char *format, va_list list, struct p parsed)
{
	write(1, "LOVI HUICA\n", 12);
	write(1, "8===D\n", 6);
}
