/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartyn- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 22:09:38 by jmartyn-          #+#    #+#             */
/*   Updated: 2019/07/03 23:12:38 by jmartyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h> //atoi

//begin of lib

void	ft_putchar(char c)
{
		write (1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

//end of lib

void    handle_d(const char *format, va_list list)
{

    int i;
	int number;

	i = 0;
	number = va_arg(list, int);
	while(format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] == 'd')
		{
			ft_putnbr(number);
			i = i + 2;
		}
		write(1, &format[i], 1);
		i++;
	}
}

void     handle_s(const char *format, va_list list)
{
    int i;
    int j;
	char *arg;
    
	arg = va_arg(list, char*);
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
		//write(1, &print[i], 1);
        i++;
    }
    return (0);
}

void    ft_printf(const char *format, ...)
{
    va_list list;
	va_start(list, format);
    
    if (parse_arg(format) == 1)
        handle_s(format, list);
    if (parse_arg(format) == 2)
        handle_d(format, list);
    va_end(list);
}

int main()
{
    const char *name;
	int number;
	number = 42;
    name = "John";
	const char *hi;
    hi = "i am";

    printf("=====================\n");
    printf("Printf output:\n");
//  char output
	printf("Hello %s %s\n", hi, name);
//	printf("hello %d\n", number);

    printf("=======\n");
    printf("ft_printf output:\n");
//  char output
    ft_printf("Hello %s %s\n", hi, name);
//	ft_printf("Hello %d\n", number);
    return (0);
}
