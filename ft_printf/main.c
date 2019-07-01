/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartyn- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 22:09:38 by jmartyn-          #+#    #+#             */
/*   Updated: 2019/07/01 21:30:25 by jmartyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

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
        }
        i++;
    }
    return (0);
}

void    ft_printf(const char *format, ...)
{
    
    va_list list;
	va_start(list, format);
    char *arg = va_arg(list, char*);

    int i;
    int j;
    
    j = 0;
    i = 0;
    if (parse_arg(format) == 1)
    {
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
    va_end(list);
}

int main()
{
    const char *name;
    name = "John";
    
    printf("=====================\n");
    printf("Printf output:\n");
    printf("Hello %s\n", name);
    printf("=======\n");
    printf("ft_printf output:\n");
    ft_printf("Hello %s", name);
    //    printf("\n======================\n");
    return (0);
}
