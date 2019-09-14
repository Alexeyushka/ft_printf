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

void	handle_long_flag(const char *format, va_list list, int i, struct p parsed)
{
	long number;
	number = va_arg(list, long);
	checksign_long(number);
	ft_putnbr_long(number);
	parsed.l = 0;

}

void    handle_d_without_flags(const char *format, va_list list, int i, struct p parsed)
{
	int number;

	if (parsed.l == 1 || parsed.ll == 1)
	{
		handle_long_flag(format, list, i, parsed);
		return ;
	}
	number = va_arg(list, int);
	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	checksign(number);
	ft_putnbr(number);
}
