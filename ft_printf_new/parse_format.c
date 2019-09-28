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
	char		blank;
	short		width;
	short		prec;
	char		hh;
	char		h;
	char		l;
	char		z;
	char		ll;
	char		j;
	char		spec;
	short		size;
}				t_struct;

#endif

//
int    print_char(const char *format, int i)
{
    write(1, &format[i], 1);
	return (1);
}



//


int		ft_out(t_struct *list, va_list va)
{
	int		res;

	res = 0;
	if (lst->spec == '%')
		res = (ft_print_percent(lst, '%'));
	// else if (lst->spec == 'c' || lst->spec == 'C')
	// 	res = (ft_handling_char(lst, va_arg(va, void *)));
	// else if (lst->spec == 's' || lst->spec == 'S')
	// 	res = (ft_handling_str(lst, va_arg(va, void *)));
	else if (lst->spec == 'd' || lst->spec == 'i' || lst->spec == 'D')
		res = (ft_handling_digit(lst, va_arg(va, void *)));
	// else if (lst->spec == 'u' || lst->spec == 'U')
	// 	res = (ft_handling_unsigned_digit(lst, va_arg(va, void *)));
	// else if (lst->spec == 'x' || lst->spec == 'X')
	// 	res = (ft_handling_x(lst, va_arg(va, void *)));
	// else if (lst->spec == 'o' || lst->spec == 'O')
	// 	res = (ft_handling_o(lst, va_arg(va, void *)));
	// else if (lst->spec == 'p')
	// 	res = (ft_handling_ptr(lst, va_arg(va, void *)));
	// else
	// 	res = (ft_handling_char(lst, va_arg(va, void *)));
	// ft_strdel(&(lst->flags));
	return (res);
}

int				ft_atoi_f(const char *s, int i)
{
	int			res;
//	int			i;
	int			charge;

	res = 0;
	i = 0;
	charge = 1;
	while ('0' <= s[i] && s[i] <= '9')
	{
		res = res * 10 + s[i] - '0';
		i++;
	}
	return (res * charge);
}

static char				ft_double_hl(const char *format, int i, char c)
{
	char				res;

	res = 0;
	while (format[i] == '#' || format[i] == '0' || format[i] == '-'
		|| format[i] == '+' || format[i] == ' ' || format[i] == '.'
		|| (format[i] >= 49 && format[i] <= 57) || format[i] == 'h'
		|| format[i] == 'l')
	{
		if (format[i] == c)
			res++;
		i++;
	}
	if (res % 2 != 0)
		return (1);
	else
		return (0);
}

static void				found_h_hh_l_ll(const char *format, int i, t_struct *list)
{
	if (format[i] == 'h') //&& !(list->h) && !(list->hh))
	{
		//if (ft_double_hl(format, i, 'h'))
		list->h = 'h';
		//else
		//	list->hh = 1;
	}
	if (format[i] == 'l' && !(list->l) && !(list->ll))
	{
		if (ft_double_hl(format, i, 'l'))
			list->l = 1;
		else
			list->ll = 1;
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
}

static void		found_flags(const char *format, int i, t_struct *list)
{
	if (format[i] == '#')
		list->hash = '#';
	else if (format[i] == '0')
		list->zero = '0';
	else if (format[i] == '-')
		list->minus = '-';
	else if (format[i] == '+')
		list->plus = '+';
	else if (format[i] == ' ')
		list->blank = ' ';
}

static void		parse_format_continue(const char *format, int i, t_struct *list)
{
	if (format[i] == 's' || format[i] == 'p' || format[i] == 'd'
		|| format[i] == 'i' || format[i] == 'o' || format[i] == 'u'
		|| format[i] == 'x' || format[i] == 'X' || format[i] == 'c')
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
			list.width = ft_atoi_f(format, i);
		if (format[i] == '.')
			list.prec = ft_atoi_f(format, i);
		if (format[i] == 'h' || format[i] == 'l')
			found_h_hh_l_ll(format, i, &list);
		i++;
	}
	parse_format_continue(format, i, &list);
//	printf("---- %c - %c - %c - %c - %c ----", list.plus, list.prec, list.h, list.spec, list.width);
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

	ft_printf("hello %+9.hd hello", k);
	return (0);
}