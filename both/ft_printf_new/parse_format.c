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

int			check_format(const char *format, int i)
{
	if (format[i] == '#' || format[i] == '0' || format[i] == '-'
		|| format[i] == '+' || format[i] == ' ' || format[i] == '.'
		|| (format[i] >= 48 && format[i] <= 57) || format[i] == 'h'
		|| format[i] == 'l' || format[i] == 'L')
		return (1);
	else
		return (0);
}

int			check_flags(const char *format, int i)
{
	if (format[i] == '#' || format[i] == '0' || format[i] == '-'
		|| format[i] == '+' || format[i] == ' ')
		return (1);
	else
		return (0);
}

int			continue_digit(const char *format, int i)
{
	while (format[i] >= 48 && format[i] <= 57)
		i++;
	return (i);
}

static void	found_prec(const char *s, int i, t_struct *list)
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

static void	found_flags(const char *format, int i, t_struct *list)
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