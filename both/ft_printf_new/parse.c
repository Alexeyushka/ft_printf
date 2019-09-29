/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartyn- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 20:27:50 by jmartyn-          #+#    #+#             */
/*   Updated: 2019/09/29 20:51:27 by jmartyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	found_h_hh_l_ll(const char *format, int i, t_struct *list)
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

static void	parse_format_continue(const char *format, int i, t_struct *list)
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

static void	found_number(const char *s, int i, t_struct *list)
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

static void	define_list(t_struct *list)
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

int			pa(const char *format, int i, va_list va, t_struct *list)
{
	define_list(list);
	while (check_format(format, i) == 1)
	{
		if (check_flags(format, i) == 1)
			found_flags(format, i, list);
		if (format[i] >= 49 && format[i] <= 57)
		{
			found_number(format, i, list);
			i = continue_digit(format, i);
			i--;
		}
		if (format[i] == '.')
		{
			i++;
			list->len++;
			found_prec(format, i, list);
			i = continue_digit(format, i);
			i--;
		}
		if (format[i] == 'h' || format[i] == 'l' || format[i] == 'L')
			found_h_hh_l_ll(format, i, list);
		i++;
	}
	parse_format_continue(format, i, list);
	return (ft_out(list, va));
}
