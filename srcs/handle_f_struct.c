/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartyn- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:39:19 by jmartyn-          #+#    #+#             */
/*   Updated: 2019/09/14 16:21:02 by jmartyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

struct	f	innitiaize_struct_float(struct f f_nums)
{
	f_nums.length = 0;
	f_nums.length2 = 0;
	f_nums.number = 0;
	f_nums.i = 0;
	f_nums.position = 0;
	f_nums.sign = 0;
	f_nums.number2 = 0;
	f_nums.number3 = 0;
	f_nums.f = 0;
	f_nums.p = 0;
	f_nums.len = 0;
	f_nums.k = 0;
	return (f_nums);
}

struct f	float_tenth_len(struct f f_nums)
{
	f_nums.sign = -1;
	if (f_nums.f < 0)
	{
		f_nums.sign = '-';
		f_nums.f *= -1;
	}
	f_nums.number2 = f_nums.f;
	f_nums.number = f_nums.f;
	f_nums.length = 0;
	f_nums.length2 = 0;
	while ((f_nums.number2 - (long double)f_nums.number) != 0.0 &&
		!((f_nums.number2 - (long double)f_nums.number) < 0.0)
		&& f_nums.length2 <= 5)
	{
		f_nums.number2 = f_nums.f * (n_tu(10.0, f_nums.length2 + 1));
		f_nums.number = f_nums.number2;
		f_nums.length2++;
	}
	f_nums.number3 = f_nums.f * (n_tu(10.0, f_nums.length2 + 1));
	return (f_nums);
}

struct f	float_decimal_len(struct f f_nums)
{
	while (f_nums.f > 1)
	{
		if (f_nums.length > -1)
			f_nums.f /= 10;
		f_nums.length++;
	}
	f_nums.position = f_nums.length;
	f_nums.length = f_nums.length + 1 + f_nums.length2;
	f_nums.number = f_nums.number2;
	if (f_nums.sign == '-')
	{
		f_nums.length++;
		f_nums.position++;
	}
	return (f_nums);
}

struct f	float_dot(struct f f_nums)
{
	f_nums.i = f_nums.length;
	while (f_nums.i >= 0)
	{
		if (f_nums.i == (f_nums.length))
			f_nums.r[f_nums.i] = '\0';
		else if (f_nums.i == (f_nums.position))
			f_nums.r[f_nums.i] = '.';
		else if (f_nums.sign == '-' && f_nums.i == 0)
			f_nums.r[f_nums.i] = '-';
		else
		{
			f_nums.r[f_nums.i] = (f_nums.number % 10) + '0';
			f_nums.number /= 10;
		}
		f_nums.i--;
	}
	return (f_nums);
}
