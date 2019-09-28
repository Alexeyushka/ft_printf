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

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>

# define ABS(x) ((x < 0) ? -(x) : (x))

typedef	struct	s_struct
{
	char		*parsedflags;
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

struct s_struct	define_list(t_struct list)
{
	//list.parsedflags[3] = '\0';
	list.parsedflags = " *****\0";
	list.width = -1;
	list.prec = -1;
	list.h = 0;
	list.hh = 0;
	list.l = 0;
	list.ll = 0;
	list.z = 0;
	list.j = 0;
	return (list);
}

struct s_struct   parse_format(const char *format, int i, va_list va, t_struct list)
{

	list = define_list(list);
	return (list);
}

int    print_char(const char *format, int i)
{
    write(1, &format[i], 1);
	return (1);
}

int    ft_printf(const char *format, ...)
{
    int i;
	int len;
	va_list va;
	t_struct list;
	i = 0;
	len = 0;
	va_start(va, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
			len = len + print_char(format, i);
		else
		{
			//i++;
			list = parse_format(format, i, va, list);
		}
		i++;
	}
	printf("%s", list.parsedflags);
	va_end(va);
	return (len);
}

int main(void)
{
	ft_printf("zzz");
	return (0);
}