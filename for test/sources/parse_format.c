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

#include "printf.h"


char    parse_format(const char *format, va_list list, int i)
{
    char c;

    while (format[i] != 's' && format[i] != 'd' &&
		format[i] != 'i' && format[i] != 'c' &&
		format[i] != 'u' && format[i] != 'x' &&
		format[i] != 'X' && format[i] != 'o' &&
		format[i] != 'f' && format[i] != '%')
    {
       i++;
    }
	printf("%c", c);
	if ((format[i] == 'd' || format[i] == 'i') && format[i - 1] == '*')
		c = 42;
	else if (format[i - 1] == '.' && format[i] == 'i' && format[i + 1] == '.')
		c = 88;
    else if (format[i] == 's')
        c = 115;
    else if (format[i] == 'd')
		c = 100;
    else if (format[i] == 'i')
        c = 105;
    else if (format[i] == 'c')
        c = 99;
    else if (format[i] == 'x')    
        c = 120;
    else if (format[i] == 'X') 
        c = 88;
    else if (format[i] == 'u') 
        c = 117;
    else if (format[i] == 'o') 
        c = 111;
    else if (format[i] == 'f') 
        c = 102;
    else if (format[i] == '%')
        c = 37;
    return (c);
}