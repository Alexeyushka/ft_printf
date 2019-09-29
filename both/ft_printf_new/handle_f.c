/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartyn- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:39:19 by jmartyn-          #+#    #+#             */
/*   Updated: 2019/09/14 15:39:54 by jmartyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen_double(char *str)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '.')
		{
			while (str[i] != '\0')
			{
				len++;
				i++;
			}
		}
		i++;
	}
	return (len);
}

// static void     	float_count_last(t_float *f_nums)
// {
// 	f_nums->number = f_nums->number3;
// 	f_nums->i = f_nums->length + 1;
// 	while (f_nums->i >= 0)
// 	{
// 		if (f_nums->i == (f_nums->length + 1))
// 			f_nums->r[f_nums->i] = '\0';
// 		else if (f_nums->i == (f_nums->position))
// 			f_nums->r[f_nums->i] = '.';
// 		else if (f_nums->sign == '-' && f_nums->i == 0)
// 			f_nums->r[f_nums->i] = '-';
// 		else
// 		{
// 			f_nums->r[f_nums->i] = (f_nums->number % 10) + '0';
// 			f_nums->number /= 10;
// 		}
// 		f_nums->i--;
// 	}
// 	if (f_nums->r[f_nums->length] >= 53 && f_nums->r[f_nums->length] <= 57)
// 		f_nums->r[f_nums->length - 1] = f_nums->r[f_nums->length - 1] + 1;
// }

static void  	float_count_precision(t_float *f_nums, t_struct *list)
{
	f_nums->i = 0;
	f_nums->k = 7 - f_nums->len - (6 - list->prec);
	if (list->prec > 6)
		f_nums->k = 7 - f_nums->len - (6 - list->prec);
	if (list->morezero == 1)
		f_nums->k = f_nums->k - 1;
}

static void  	float_print(t_float *f_nums, t_struct *list)
{
	while (f_nums->r[f_nums->i] != '\0')
	{
		write(1, &f_nums->r[f_nums->i], 1);
		if (f_nums->r[f_nums->i] == '.')
		{
			// if (list->prec != 0)
			// {
			// 	f_nums->len = list->prec + 1;
			// 	list->res = 1;
			// }
			while (f_nums->len-- > 1 && f_nums->r[f_nums->i++] != '\0')
			{
				write(1, &f_nums->r[f_nums->i], 1);
			}
			if (list->res == 1)
			{
				list->res = 0;
				break ;
			}
		}
		f_nums->i++;
		if (f_nums->r[f_nums->i] == '.' && list->morezero == 1)
			break ;
	}
}


static void 	float_print_zeros(t_float *f_nums)
{
	while (f_nums->k > 0)
	{
		write(1, "0", 1);
		f_nums->k--;
	}
}

int n_tu(int number, int count)
{
	int result = 1;
	while (count-- > 0)
		result *= number;

	return result;
}

static void         innitiaize_struct_float(t_float *f_nums)
{
	f_nums->length = 0;
	f_nums->length2 = 0;
	f_nums->number = 0;
	f_nums->i = 0;
	f_nums->position = 0;
	f_nums->sign = 0;
	f_nums->number2 = 0;
	f_nums->number3 = 0;
	f_nums->f = 0;
	f_nums->p = 0;
	f_nums->len = 0;
	f_nums->k = 0;
}

static void	float_tenth_len(t_float *f_nums)
{
	f_nums->sign = -1;
	if (f_nums->f < 0)
	{
		f_nums->sign = '-';
		f_nums->f *= -1;
	}
	f_nums->number2 = f_nums->f;
	f_nums->number = f_nums->f;
	f_nums->length = 0;
	f_nums->length2 = 0;
	while ((f_nums->number2 - (long double)f_nums->number) != 0.0 &&
		!((f_nums->number2 - (long double)f_nums->number) < 0.0)
		&& f_nums->length2 <= 5)
	{
		f_nums->number2 = f_nums->f * (n_tu(10.0, f_nums->length2 + 1));
		f_nums->number = f_nums->number2;
		f_nums->length2++;
	}
	f_nums->number3 = f_nums->f * (n_tu(10.0, f_nums->length2 + 1));
}

static void	float_decimal_len(t_float *f_nums)
{
	while (f_nums->f > 1)
	{
		if (f_nums->length > -1)
			f_nums->f /= 10;
		f_nums->length++;
	}
	f_nums->position = f_nums->length;
	f_nums->length = f_nums->length + 1 + f_nums->length2;
	f_nums->number = f_nums->number2;
	if (f_nums->sign == '-')
	{
		f_nums->length++;
		f_nums->position++;
	}
}

static void 	float_dot(t_float *f_nums)
{
	f_nums->i = f_nums->length;
    f_nums->number = f_nums->number + 1;
	while (f_nums->i >= 0)
	{
		if (f_nums->i == (f_nums->length))
			f_nums->r[f_nums->i] = '\0';
		else if (f_nums->i == (f_nums->position))
			f_nums->r[f_nums->i] = '.';
		else if (f_nums->sign == '-' && f_nums->i == 0)
			f_nums->r[f_nums->i] = '-';
		else
		{
			f_nums->r[f_nums->i] = (f_nums->number % 10) + '0';
			f_nums->number /= 10;
		}
		f_nums->i--;
	}
}

void	handle_fl(t_struct *list, va_list va, int *len)
{
    t_float f_nums;

	innitiaize_struct_float(&f_nums);

	f_nums.f = va_arg(va, long double);
	float_tenth_len(&f_nums);
	float_decimal_len(&f_nums);
//	f_nums.test = malloc(sizeof(char *) * (f_nums.length + 1));
	f_nums.r = malloc(sizeof(char *) * f_nums.length);
	float_dot(&f_nums);
//	float_count_last(&f_nums);
	f_nums.len = ft_strlen_double(f_nums.r);
    float_count_precision(&f_nums, list);
	float_print(&f_nums, list);
	float_print_zeros(&f_nums);
	free(f_nums.r);
    len = len + f_nums.len;
}

static void	            handle_f(t_struct *list, va_list va, int *len)
{
	t_float f_nums;

	innitiaize_struct_float(&f_nums);
	// if (list->largel == 1)
	// {
	// 	handle_fl(format, list, par, f_nums);
	// 	par.largel = 0;
	// 	return ;
	// }
	f_nums.f = va_arg(va, double);
	float_tenth_len(&f_nums);
	float_decimal_len(&f_nums);
	f_nums.r = malloc(sizeof(char *) * f_nums.length);
	float_dot(&f_nums);
	f_nums.len = ft_strlen_double(f_nums.r);
	float_count_precision(&f_nums, list);
	float_print(&f_nums, list);
	float_print_zeros(&f_nums);
	free(f_nums.r);
    len = len + f_nums.len;
}

// static void	            handle_double(t_struct *list, va_list va, int *len)
// {
// 	if (list->largel == 1)
// 	{
// 		handle_fl(list, va, len);
// 		list->largel = 0;
// 		return ;
// 	}
// }

int						ft_handling_f(t_struct *list, va_list va)
{
	int len;

    if (list->l)
		(handle_f(list, va, &len));
	else if (list->largel)
		(handle_fl(list, va, &len));
	else
		(handle_f(list, va, &len));
	return (len);
    
}