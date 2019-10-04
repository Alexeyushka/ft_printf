/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartyn- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:39:19 by jmartyn-          #+#    #+#             */
/*   Updated: 2019/09/14 16:36:30 by jmartyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_fl(const char *format, va_list list, struct p pa, struct f fn)
{
	fn.f = va_arg(list, long double);
	fn = float_tenth_len(fn);
	fn = float_decimal_len(fn);
	fn.test = malloc(sizeof(char *) * fn.length + 1);
	fn.r = malloc(sizeof(char *) * fn.length);
	fn = float_dot(fn);
	fn = float_count_last(fn);
	fn.len = ft_strlen_double(fn.r);
	fn = float_count_precision(fn, pa);
	fn = float_print(fn, pa);
	fn = float_print_zeros(fn);
	free(fn.r);
}

void	handle_f(const char *format, va_list list, struct p par)
{
	struct f f_nums;

	f_nums = innitiaize_struct_float(f_nums);
	if (par.largel == 1)
	{
		handle_fl(format, list, par, f_nums);
		par.largel = 0;
		return ;
	}
	f_nums.f = va_arg(list, double);
	f_nums = float_tenth_len(f_nums);
	f_nums = float_decimal_len(f_nums);
	f_nums.r = malloc(sizeof(char *) * f_nums.length);
	f_nums = float_dot(f_nums);
	f_nums.len = ft_strlen_double(f_nums.r);
	f_nums = float_count_precision(f_nums, par);
	f_nums = float_print(f_nums, par);
	f_nums = float_print_zeros(f_nums);
	free(f_nums.r);
}
