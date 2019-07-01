/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartyn- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 22:09:38 by jmartyn-          #+#    #+#             */
/*   Updated: 2019/07/01 22:31:05 by jmartyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h> //atoi

void    handle_d(const char *format, int arg)
{

    printf("%d", arg); //need to debug
    
}

void     handle_s(const char *format, char *arg)
{
    int i;
    int j;
    
    j = 0;
    i = 0;
    while (format[i] != '\0')
    {
        if (format[i] == '%' && format[i + 1] == 's')
        {
            while (arg[j] != '\0')
            {
                write(1, &arg[j], 1);
                j++;
            }
            i = i + 2;
        }
        write(1, &format[i], 1);
        i++;
    }
}

int        parse_arg(const char *print)
{
    int i;
    
    i = 0;
	while (print[i] != '\0')
	{
        if (print[i] == '%')
		{
        	if (print[i + 1] == 's')
            {
                return (1);
            }
            if (print[i + 1] == 'd')
            {
                return (2);
            }
        }
        i++;
    }
    return (0);
}

void    ft_printf(const char *format, ...)
{
    char *arg;
    int number;
    va_list list;
	va_start(list, format);
	arg = va_arg(list, char*);
    
    number = ((int)va_arg(list, char*)); //need to debug

    if (parse_arg(format) == 1)
        handle_s(format, arg);
    if (parse_arg(format) == 2)
    {
        handle_d(format, number);
    }
    va_end(list);
}

int main()
{
    const char *name;
	int number;
	number = 42;
    //name = "John";
    
    printf("=====================\n");
    printf("Printf output:\n");
//  char output
//    printf("Hello %s\n", name);
	printf("hello %d\n", number);

    printf("=======\n");
    printf("ft_printf output:\n");
//  char output
//    ft_printf("Hello %s\n", name);
	ft_printf("Hello %d\n", number);
    return (0);
}
