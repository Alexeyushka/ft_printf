/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartyn- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:39:19 by jmartyn-          #+#    #+#             */
/*   Updated: 2019/09/14 16:11:19 by jmartyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_o_decimal_zero(long decimal)
{
	if (decimal == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
		return (0);
}

void	handle_o(const char *format, va_list list)
{
	long	decimal;
	int		tmp;
	long	octal[100];
	int		i;

	i = 0;
	decimal = va_arg(list, int);
	if (handle_o_decimal_zero(decimal) == 1)
		return ;
	if (decimal < 0)
		decimal = 4294967296 + decimal;
	while (decimal != 0)
	{
		octal[i] = decimal % 8;
		decimal = decimal / 8;
		i++;
	}
	i = i - 1;
	while (i >= 0)
	{
		tmp = octal[i];
		ft_putnbr(tmp);
		i--;
	}
}

