/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartyn- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 22:09:38 by jmartyn-          #+#    #+#             */
/*   Updated: 2019/07/05 20:17:21 by jmartyn-         ###   ########.fr       */
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



//char begin
void	handle_c(const char *format, va_list list)
{
	char character;

	character = va_arg(list, int);
	write(1, &character, 1);
}
//char end

//integer begin
int		checksign(int number)
{
	if (number < 0)
		write(1, "-", 1);
	if (number > 0)
		return (0);
	return (0);	
}

void    handle_d(const char *format, va_list list)
{

    int i;
	int number;

	i = 0;
	number = va_arg(list, int);
	checksign(number);
	while(format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] == 'd')
		{
			ft_putnbr(number);
			i = i + 2;
		}
		i++;
	}
}
//integer end

void	handle_u(const char *format, va_list list)
{
	int i;
	unsigned int number;

	i = 0;
	number = va_arg(list, uint16_t);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] == 'u')
		{
			ft_putnbr(number);
			i = i + 2;
		}
		i++;
	}
}

//string begin
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
        i++;
    }
}
//string end

void    ft_printf(const char *format, ...)
{
    int i;
	va_list list;

	i = 0;
	va_start(list, format);
   
	while (format[i] != '\0')
	{
        if (format[i] == '%')
		{
			if (format[i + 1] == 's')
			{
				handle_s(format, list);
				i = i + 2;
			}
    		if (format[i + 1] == 'd')
			{
				handle_d(format, list);
				i = i + 2;
			}
			if (format[i + 1] == 'c')
			{
				handle_c(format, list);
				i = i + 2;
			}
			if (format[i + 1] == 'u')
			{
				handle_u(format, list);
				i = i + 2;
			}
			i--;
		}
		else
			write(1, &format[i], 1);
		i++;
	}
	va_end(list);
}

int main()
{
    const char *string;
	int number;
	number = -42;
    string = "John";
	const char *string2;
    string2 = "i am";
	char character;
	character = 'c';
	unsigned int unsignedint;
	unsignedint = 4294967294;

    printf("=====================\n");
    printf("Printf output:\n");
//  string output	
//	printf("Hello %s %s %d end\n", string2, string, number);
//	
//	integer output
//	printf("hello %d\n", number);
//
//	char output
//	printf("hello %c\n", character);
//
//	unsigned int output
	printf("hello %u\n", unsignedint);

    printf("=======\n");
    printf("ft_printf output:\n");
//  string output
//  ft_printf("Hello %s %s %d end\n", string2, string, number);
//	
//	integer output
//	ft_printf("Hello %d\n", number);
//	
//	char output
//	ft_printf("hello %c\n", character);
//	
//	unsigned int output
	ft_printf("hello %u\n", unsignedint);
    return (0);
}
