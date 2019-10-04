/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartyn- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:39:19 by jmartyn-          #+#    #+#             */
/*   Updated: 2019/09/14 16:26:28 by jmartyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

struct f	float_count_last(struct f f_nums)
{
	f_nums.number = f_nums.number3;
	f_nums.i = f_nums.length + 1;
	while (f_nums.i >= 0)
	{
		if (f_nums.i == (f_nums.length + 1))
			f_nums.test[f_nums.i] = '\0';
		else if (f_nums.i == (f_nums.position))
			f_nums.test[f_nums.i] = '.';
		else if (f_nums.sign == '-' && f_nums.i == 0)
			f_nums.test[f_nums.i] = '-';
		else
		{
			f_nums.test[f_nums.i] = (f_nums.number % 10) + '0';
			f_nums.number /= 10;
		}
		f_nums.i--;
	}
	if (f_nums.test[f_nums.length] >= 53 && f_nums.test[f_nums.length] <= 57)
		f_nums.r[f_nums.length - 1] = f_nums.r[f_nums.length - 1] + 1;
	return (f_nums);
}

struct f	float_count_precision(struct f f_nums, struct p parsed)
{
	f_nums.i = 0;
	f_nums.k = 7 - f_nums.len - (6 - parsed.precision);
	if (parsed.precision > 6)
		f_nums.k = 7 - f_nums.len - (6 - parsed.precision);
	if (parsed.precision_zero == 1)
		f_nums.k = f_nums.k - 1;
	return (f_nums);
}

struct f	float_print(struct f f_nums, struct p parsed)
{
	while (f_nums.r[f_nums.i] != '\0')
	{
		write(1, &f_nums.r[f_nums.i], 1);
		if (f_nums.r[f_nums.i] == '.')
		{
			if (parsed.precision != 0)
			{
				f_nums.len = parsed.precision + 1;
				parsed.res = 1;
			}
			while (f_nums.len-- > 1 && f_nums.r[f_nums.i++] != '\0')
			{
				write(1, &f_nums.r[f_nums.i], 1);
			}
			if (parsed.res == 1)
			{
				parsed.res = 0;
				break ;
			}
		}
		f_nums.i++;
		if (f_nums.r[f_nums.i] == '.' && parsed.precision_zero == 1)
			break ;
	}
	return (f_nums);
}

struct f	float_print_zeros(struct f f_nums)
{
	while (f_nums.k > 0)
	{
		write(1, "0", 1);
		f_nums.k--;
	}
	return (f_nums);
}
