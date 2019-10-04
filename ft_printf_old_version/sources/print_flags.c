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


int		print_flags(const char *format, va_list list, int i, struct p parsed)
{
	int res;
	int count;
	count = 0;
	parsed.size = 0;

	parsed.size = flag_count_size(format, list, parsed);
//	hash_only
	if (parsed.hash_only == 1)
	{
		count = flag_hash_only(format, list, i, parsed) - parsed.size - 1;
		if (count == -1)
			count = 1;
		parsed.hash_only = 0;
	}

//	hash_and_zero
	if (parsed.hash_and_zero == 1)
	{
		res = flag_count_res(format, (i + 2));
		count = flag_hash_and_zero(format, list, res, parsed) + parsed.size + 2;
		parsed.hash_and_zero = 0;
	}

//	zero_and_hash
	if (parsed.zero_and_hash == 1)
	{
		flag_hash_and_zero(format, list, res, parsed);
		parsed.zero_and_hash = 0;
		count = 2;
	}

//	zero_and_hash_and_digit --- and --- hash_and_zero_and_digit
	if (parsed.zero_and_hash_and_digit == 1 || parsed.hash_and_zero_and_digit == 1)
	{
		count = flag_zero_and_hash_and_digit(format, list, i, parsed) - 1;
		parsed.zero_and_digit = 0;
		parsed.hash_and_zero_and_digit = 0;
	}

//	hash_and_digit
	if (parsed.hash_and_digit == 1)
	{
		count = flag_hash_and_digit(format, list, i, parsed) + 1;
		parsed.hash_and_digit = 0;
	}

//	hash_and_minus
	if (parsed.hash_and_minus == 1)
	{
		count = flag_hash_and_minus(format, list, i, parsed) - 1;
		parsed.hash_and_minus = 0;
	}
//	hash_and_minus_and_digit --- and --- minus_and_hash_and_digit
	if (parsed.hash_and_minus_and_digit == 1 || parsed.minus_and_hash_and_digit == 1)
	{
		count = flag_hash_and_minus_and_digit(format, list, i, parsed) + 2;
		parsed.hash_and_minus_and_digit = 0;
		parsed.minus_and_hash_and_digit = 0;
	}

//	minus_and_hash
	if (parsed.minus_and_hash == 1)
	{
		count = flag_hash_only(format, list, i, parsed) - parsed.size;
		if (count == 0)
			count = 2;
		parsed.minus_and_hash = 0;
	}
//	minus_and_digit 
	if (parsed.minus_and_digit == 1)
	{
		count = flag_minus_and_digit(format, list, i, parsed) + 1;
		parsed.minus_and_digit = 0;
	}

//	zero_and_digit
	if (parsed.zero_and_digit == 1)
	{
		count = flag_zero_and_digit(format, list, i, parsed) - 1; 
		parsed.zero_and_digit = 0;
	}

	return (count);
}
