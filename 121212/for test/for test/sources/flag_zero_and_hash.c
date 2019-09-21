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


void	flag_zero_and_hash_print(const char *format, va_list list, struct p parsed_x)
{
	char hexadecimal[100];
	long decimal;
	long quotient;
	long remainder;
	int i;
	
	i = 0;
	decimal = va_arg(list, int);
	quotient = decimal;
	if (decimal != 0)
	{
	if (decimal < 0)
		quotient = handle_negative_x(decimal);

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
	handle_x_continue((i - 1), i, hexadecimal, parsed_x);
	}
	else
		write(1, "0", 1);
}
