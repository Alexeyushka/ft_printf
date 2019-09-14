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

void    flag_plus_print(const char *format, va_list list, int i, int k)
{
	int number;

	number = va_arg(list, int);
	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (checksign(number) == 0)
		write(1, "+", 1);
	ft_putnbr(number);
}

void    flag_plus_print_long(const char *format, va_list list, int i, int k)
{
	long number;

	number = va_arg(list, long);
	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (checksign_long(number) == 0)
		write(1, "+", 1);
	ft_putnbr_long(number);
}

int		flag_plus(const char *format, va_list list, int i, struct p parsed)
{
	int k;

	k = 0;
	if (format[i + 1] == '+')	
	{
		if (format[i + 2] == 'd' || format[i + 2] == 'h' || format[i + 2] == 'i')
		{
			k++;
			flag_plus_print(format, list, i, k);
		}
		if (format[i + 2] == 'l')
		{
			k++;
			flag_plus_print_long(format, list, i, k);
		}
	}
	return (k);
}