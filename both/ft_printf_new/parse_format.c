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


int		ft_out(t_struct *list, va_list va)
{
	int		res;

	res = 0;
	if (list->spec == '%')
		res = (ft_print_percent(list, '%'));
	else if (list->spec == 'c' || list->spec == 'C')
		res = (ft_handling_char(list, va_arg(va, void *)));
	else if (list->spec == 's' || list->spec == 'S')
		res = (ft_handling_str(list, va_arg(va, void *)));
	else if (list->spec == 'd' || list->spec == 'i' || list->spec == 'D')
		res = (ft_handling_digit(list, va_arg(va, void *))); //+ list->len;
	else if (list->spec == 'u' || list->spec == 'U')
		res = (ft_handling_unsigned_digit(list, va_arg(va, void *)));
	else if (list->spec == 'x' || list->spec == 'X')
		res = (ft_handling_x(list, va_arg(va, void *)));
	else if (list->spec == 'o' || list->spec == 'O')
		res = (ft_handling_o(list, va_arg(va, void *)));
	else if (list->spec == 'p')
		res = (ft_handling_ptr(list, va_arg(va, void *)));
	else if (list->spec == 'f')
		res = (ft_handling_f(list, va));
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


static void				found_h_hh_l_ll(const char *format, int i, t_struct *list)
{
	if (format[i] == 'h' && format[i + 1] != 'h' && format[i - 1] != 'h')
	{
		list->h = 'h';
		list->len++;
	}
	if (format[i] == 'h' && format[i + 1] == 'h')
	{	
		list->hh = 'y';
		list->len = list->len + 2;
	}
	if (format[i] == 'l' && format[i + 1] != 'l' && format[i - 1] != 'l')
	{
		list->l = 'l';
		list->len++;
	}
	if (format[i] == 'l' && format[i + 1] == 'l')
	{	
		list->ll = 'y';
		list->len = list->len + 2;
	}
	if (format[i] == 'L')
	{	
		list->largel = 1;
		list->len = list->len + 1;
	}
}


static void		define_list(t_struct *list)
{
	list->plus = 0;
	list->morezero = ' ';
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
	list->largel = 0;
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
		|| format[i] == 'f' || format[i] == '%')
		list->spec = format[i];
	else
	{
		list->spec = format[i];	
	}
}

int    parse_format(const char *format, int i, va_list va, t_struct *list)
{
	define_list(list);
	while (format[i] == '#' || format[i] == '0' || format[i] == '-'
		|| format[i] == '+' || format[i] == ' ' || format[i] == '.'
		|| (format[i] >= 48 && format[i] <= 57) || format[i] == 'h'
		|| format[i] == 'l' || format[i] == 'L')
	{
		if (format[i] == '#' || format[i] == '0' || format[i] == '-'
		|| format[i] == '+' || format[i] == ' ')
			found_flags(format, i, list);
		if (format[i] >= 49 && format[i] <= 57)
		{
			found_number(format, i, list);
			while (format[i] >= 48 && format[i] <= 57)
				i++;
			i--;
		}
		if (format[i] == '.')
		{
			i++;
			list->len++;
			found_prec(format, i, list);
			while (format[i] >= 48 && format[i] <= 57)
				i++;
			i--;
		}
		if (format[i] == 'h' || format[i] == 'l' || format[i] == 'L')
			found_h_hh_l_ll(format, i, list);
		i++;
	}
	parse_format_continue(format, i, list);
	return (ft_out(list, va));
}
