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


void	flag_hash_and_minus_continue(const char *format, va_list list)
{
	char hexadecimal[100];
	long decimal;
	long quotient;
	long remainder;
	int i;
	struct p parsed;

	i = 0;
	va_list cpy;
	va_copy(cpy, list);
	decimal = va_arg(cpy, int);
	quotient = decimal;
	if (decimal < 0)
		quotient = handle_negative_x(decimal);
	if (decimal == 0)
	{	
		i--;
		write(1, "0", 1);
		return ;
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
	if (decimal != 0)
		write(1, "0x", 2);
	handle_x(format, list);
	va_end(cpy);
}

int		flag_hash_and_minus(const char *format, va_list list, int i, struct p parsed)
{
	int result;

	result = 3;
	flag_hash_and_minus_continue(format, list);
	return (result);
}