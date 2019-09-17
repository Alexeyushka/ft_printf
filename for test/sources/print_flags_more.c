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

int		print_flags_more(const char *format, va_list list, int i, struct p parsed)
{
	int res;
	int count;
	count = 0;
//	field_width
	if (parsed.width == 1)
	{
		count = flag_field_width(format, list, i, parsed) - 2;
		parsed.width = 0;
	}
//	field_width_and plus
	if (parsed.width_and_plus == 1)
	{
		count = flag_field_width_and_plus(format, list, i, parsed);
		parsed.width_and_plus = 0;
	}
//	field_width_and minus
	if (parsed.width_and_minus == 1)
	{
		count = flag_field_width_and_minus(format, list, i, parsed);
		parsed.width_and_minus = 0;
	}

//	field_width_and zero
	if (parsed.width_and_zero == 1)
	{
		count = flag_field_width_and_zero(format, list, i, parsed);
		parsed.width_and_zero = 0;
	}

//	plus
	if (parsed.plus == 1)
	{
		count = flag_plus(format, list, i, parsed) + 1;
		parsed.plus = 0;
	}

//	plus_and_digit
	if (parsed.plus_and_digit == 1)
	{
		count = parse_flag_plus_and_digit(format, list, i, parsed);
		parsed.plus_and_digit = 0;
	}

// minus
	if (parsed.minus == 1)
	{
		count = flag_minus(format, list, i, parsed);
		parsed.minus = 0;
	}

// minus_and_digit
	if (parsed.minus_and_digit == 1)
	{
		count = flag_minus_and_digit_d(format, list, i, parsed);
		parsed.minus_and_digit = 0;
	}

//	zero
	if (parsed.zero == 1)
	{
		count = parse_flag_zero_d(format, list, i, parsed);
		parsed.zero = 0;
	}

//	zero_and_digit
	if (parsed.zero_and_digit == 1)
	{
		count = parse_flag_zero_and_digit_d(format, list, i, parsed);
		parsed.zero_and_digit = 0;
	}

//	blank
	if (parsed.blank == 1)
	{
		count = flag_blank_d(format, list, i, parsed);
		parsed.blank = 0;
	}

//	blank_and_digit
	if (parsed.blank_and_digit == 1)
	{
		count = flag_blank_and_digit_d(format, list, i, parsed);
		parsed.blank_and_digit = 0;
	}

//	digit
	if (parsed.digit == 1)
	{
		count = flag_digit(format, list, i, parsed);
		parsed.digit = 0;
	}

	return (count);
}