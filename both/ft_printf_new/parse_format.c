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

//#include "ft_printf.h"


#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>

#include <stdio.h>

# define ABS(x) ((x < 0) ? -(x) : (x))

typedef	struct	s_struct
{
	char		plus;
	char 		minus;
	char		hash;
	char		zero;
	char		morezero;
	char		blank;
	int			width;
	int			prec;
	char		hh;
	char		h;
	char		l;
	char		z;
	char		ll;
	char		j;
	char		spec;
	short		size;
	int			len;
}				t_struct;

#endif

//
int    print_char(const char *format, int i)
{
    write(1, &format[i], 1);
	return (1);
}

int		ft_print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int					ft_print_percent(t_struct *list, char c)
{
	int				len;

	len = 0;
	if (list->zero == '0')
		list->morezero = '0';
	if (list->minus != '-' && list->width > 1)
		while (((list->width)-- - 1))
			len += ft_print_char(list->morezero);
	len += ft_print_char(c);
	if (list->width > 1 && list->minus == '-')
		while ((list->width)-- - 1)
			len += ft_print_char(' ');
	return (len);
}

//

//digit
static char				ft_size_digit(intmax_t digit)
{
	char				res;

	res = 1;
	digit /= 10;
	while (digit)
	{
		digit /= 10;
		res++;
	}
	return (res);
}

static char				ft_strlen_digit(t_struct *list, intmax_t digit)
{
	char				res;
	char				tmp;

	tmp = 0;
	res = ft_size_digit(digit);
	if (list->prec != -1 && list->prec > res)
	{
		tmp = (list->prec - res);
		res = list->prec;
	}
	if (tmp > 0)
		list->prec = tmp;
	else if (digit == 0 && list->prec == 0)
	{
		list->prec = -2;
		res = 0;
	}
	else
		list->prec = -1;
	if ((digit < 0) || ((list->plus == '+' || list->blank == ' ') &&
	digit >= 0))
		res++;
	return (res);
}

static char				ft_print_digit(intmax_t digit, t_struct *list)
{
	char len;

	len = 0;
	if (digit == 0 && list->prec == -2)
		return (0);
	if (-10 < digit && digit < 10)
		len += ft_print_char(ABS(digit) + '0');
	else
	{
		len += ft_print_digit(digit / 10, list);
		len += ft_print_digit(digit % 10, list);
	}
	return (len);
}

static short			ft_hend_digit(t_struct *list, intmax_t digit, int *len)
{
	// if ((list->flags)[2] == '0' && list->prec == -1)
	// 	(list->flags)[0] = '0';
	list->size = ft_strlen_digit(list, digit);
	// if (digit < 0 && list->flags[0] == '0')
	// 	*len += ft_print_char('-');
	// else if (digit >= 0 && list->flags[0] == '0' && list->flags[4] == '+')
	// 	*len += ft_print_char('+');
	// else if (list->flags[0] == '0' && list->flags[5] == ' ')
	// 	*len += ft_print_char(' ');
	while (list->minus != '-' && list->width > list->size)
		(*len += ft_print_char(list->morezero)) && list->width--;
	// if ((list->flags)[4] == '+' && digit >= 0 && list->flags[0] != '0')
	// 	*len += ft_print_char('+');
	// else if (digit < 0 && list->flags[0] == ' ' && list->flags[0] != '0')
	// 	*len += ft_print_char('-');
	// else if ((list->flags)[5] == ' ' && digit >= 0 && list->flags[0] != '0')
	// 	*len += ft_print_char(' ');
	// while (list->prec != -1 && list->prec > 0)
	// 	(*len += ft_print_char('0')) && list->prec--;
	// *len += ft_print_digit(digit, list);
	// while (list->width > list->size && (list->flags)[3] == '-')
	// 	(*len += ft_print_char(' ')) && list->width--;
	return (*len);
}

int						ft_handling_digit(t_struct *list, void *digit)
{
	int len;

	len = 0;
	if (list->spec == 'D')
		(ft_hend_digit(list, (long)digit, &len));
	else if (list->j)
		(ft_hend_digit(list, (intmax_t)digit, &len));
	else if (list->ll)
		(ft_hend_digit(list, (long long)digit, &len));
	else if (list->z)
		(ft_hend_digit(list, (size_t)digit, &len));
	else if (list->l)
		(ft_hend_digit(list, (long)digit, &len));
	else if (list->h)
		(ft_hend_digit(list, (short)digit, &len));
	else if (list->hh)
		(ft_hend_digit(list, (char)digit, &len));
	else
		(ft_hend_digit(list, (int)digit, &len));
	return (len);
}
//end digit



int		ft_out(t_struct *list, va_list va)
{
	int		res;

	res = 0;
	if (list->spec == '%')
		res = (ft_print_percent(list, '%'));
	// // else if (list->spec == 'c' || list->spec == 'C')
	// // 	res = (ft_handling_char(list, va_arg(va, void *)));
	// // else if (list->spec == 's' || list->spec == 'S')
	// // 	res = (ft_handling_str(list, va_arg(va, void *)));
	else if (list->spec == 'd' || list->spec == 'i' || list->spec == 'D')
		res = (ft_handling_digit(list, va_arg(va, void *))); //+ list->len;
	// else if (list->spec == 'u' || list->spec == 'U')
	// 	res = (ft_handling_unsigned_digit(list, va_arg(va, void *)));
	// else if (list->spec == 'x' || list->spec == 'X')
	// 	res = (ft_handling_x(list, va_arg(va, void *)));
	// else if (list->spec == 'o' || list->spec == 'O')
	// 	res = (ft_handling_o(list, va_arg(va, void *)));
	// else if (list->spec == 'p')
	// 	res = (ft_handling_ptr(list, va_arg(va, void *)));
	// else
	// 	res = (ft_handling_char(list, va_arg(va, void *)));
	// ft_strdel(&(list->flags));
	return (res);
}

static void				found_number(const char *s, int i, t_struct *list)
{
	list->width = 0;
	while (s[i] >= 48 && s[i] <= 57)
	{
		list->width = list->width * 10;
		list->width = list->width + ((int)s[i] - '0');
		i++;
		list->len++;
	}
}

static void				found_prec(const char *s, int i, t_struct *list)
{
	list->prec = 0;
	while (s[i] >= 48 && s[i] <= 57)
	{
		list->prec = list->prec * 10;
		list->prec = list->prec + ((int)s[i] - '0');
		i++;
		list->len++;
	}
}

// static char				ft_double_hl(const char *format, int i, char c)
// {
// 	char				res;

// 	res = 0;
// 	while (format[i] == '#' || format[i] == '0' || format[i] == '-'
// 		|| format[i] == '+' || format[i] == ' ' || format[i] == '.'
// 		|| (format[i] >= 49 && format[i] <= 57) || format[i] == 'h'
// 		|| format[i] == 'l')
// 	{
// 		if (format[i] == c)
// 			res++;
// 		i++;
// 	}
// 	if (res % 2 != 0)
// 		return (1);
// 	else
// 		return (0);
// }

static void				found_h_hh_l_ll(const char *format, int i, t_struct *list)
{
	if (format[i] == 'h' && format[i + 1] != 'h')
	{
		list->h = 'h';
		list->len++;
	}
	if (format[i] == 'h' && format[i + 1] == 'h')
	{	
		list->hh = 'y';
		list->len = list->len + 2;
	}
	if (format[i] == 'l' && format[i + 1] != 'l')
	{
		list->l = 'l';
		list->len++;
	}
	if (format[i] == 'l' && format[i + 1] == 'l')
	{	
		list->ll = 'y';
		list->len = list->len + 2;
	}
}


static void		define_list(t_struct *list)
{
	list->plus = 0;
	list->minus = 0;
	list->hash = 0;
	list->zero = 0;
	list->blank = 0;
	list->width = -1;
	list->prec = -1;
	list->h = 0;
	list->hh = 0;
	list->l = 0;
	list->ll = 0;
	list->z = 0;
	list->j = 0;
	list->len = 0;
}

static void		found_flags(const char *format, int i, t_struct *list)
{
	if (format[i] == '#')
	{	
		list->hash = '#';
		list->len++;
	}
	else if (format[i] == '0')
	{	
		list->zero = '0';
		list->len++;
	}
	else if (format[i] == '-')
	{	
		list->minus = '-';
		list->len++;
	}
	else if (format[i] == '+')
	{	
		list->plus = '+';
		list->len++;
	}
	else if (format[i] == ' ')
	{	
		list->blank = ' ';
		list->len++;
	}
}

static void		parse_format_continue(const char *format, int i, t_struct *list)
{
	if (format[i] == 's' || format[i] == 'p' || format[i] == 'd'
		|| format[i] == 'i' || format[i] == 'o' || format[i] == 'u'
		|| format[i] == 'x' || format[i] == 'X' || format[i] == 'c'
		|| format[i] == '%')
		list->spec = format[i];
	else
	{
		list->spec = format[i];	
	}
}

int    parse_format(const char *format, int i, va_list va)
{
    t_struct list;

	define_list(&list);
	while (format[i] == '#' || format[i] == '0' || format[i] == '-'
		|| format[i] == '+' || format[i] == ' ' || format[i] == '.'
		|| (format[i] >= 49 && format[i] <= 57) || format[i] == 'h'
		|| format[i] == 'l')
	{
		if (format[i] == '#' || format[i] == '0' || format[i] == '-'
		|| format[i] == '+' || format[i] == ' ')
			found_flags(format, i, &list);
		if (format[i] >= 49 && format[i] <= 57)
		{
			found_number(format, i, &list);
			while (format[i] >= 49 && format[i] <= 57)
				i++;
		}
		if (format[i] == '.')
		{
			i++;
			list.len++;
			found_prec(format, i, &list);
			while (format[i] >= 49 && format[i] <= 57)
				i++;
		}
		if (format[i] == 'h' || format[i] == 'l')
			found_h_hh_l_ll(format, i, &list);
		i++;
	}
	parse_format_continue(format, i, &list);
//	printf("---- %c - %d - %c - %c - %d ----", list.plus, list.prec, list.hh, list.spec, list.width);
	return (ft_out(&list, va));
}


//
int    ft_printf(const char *format, ...)
{
    int i;
	int len;
	va_list va;

	i = 0;
	len = 0;
	va_start(va, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
			len = len + print_char(format, i);
		else
		{
			i++;
			len = len + parse_format(format, i, va);
		}
		i++;
	}
	va_end(va);
	return (len);
}




///

int main()
{
	int k;
	k = 20;

	ft_printf("%5d", k);
	printf("\n");

	printf("%5d", k);
	return (0);
}