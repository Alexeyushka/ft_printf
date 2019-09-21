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

int		ft_numlen(int n)
{
	if (n < 0)
		return (ft_numlen(n * -1) + 1);
	if (n >= 10)
		return (ft_numlen(n / 10) + 1);
	return (1);
}

int		flag_count_res(const char *format, int i)
{
	int res;

	res = 0;
	while (format[i] >= 48 && format[i] <= 57)
	{
		res = res * 10;
		res = res + ((int)format[i] - '0');
		i++;
	}
	return (res);
}

int		count_long(const char *format, va_list list, int i, struct p parsed)
{
	int count;
	int res;

	res = 0;
	count = 2;
	while (format[i + count] >= 48 && format[i + count] <= 57)
	{
		res = res * 10;
		res = res + ((long)format[i + count] - '0');
		count++;
	}
	return (count);
}

int		count_long_res(const char *format, va_list list, int i, struct p parsed)
{
	int count;
	int res;

	res = 0;
	count = 2;
	while (format[i + count] >= 48 && format[i + count] <= 57)
	{
		res = res * 10;
		res = res + ((long)format[i + count] - '0');
		count++;
	}
	return (res);
}
