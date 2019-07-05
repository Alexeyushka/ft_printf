/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartyn- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 22:09:38 by jmartyn-          #+#    #+#             */
/*   Updated: 2019/07/05 20:50:18 by jmartyn-         ###   ########.fr       */
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

void	ft_putnbr_uint(unsigned int nb)
{
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

void    handle_d(const char *format, va_list list, int i)
{
	int number;
	
	number = va_arg(list, int);
	checksign(number);
	if (format[i] == '%' && format[i + 1] == 'd')
	{
		ft_putnbr(number);
	}
}
//integer end

//unsigned integer begin
void	handle_u(const char *format, va_list list, int i)
{
	uintmax_t number;

	number = va_arg(list, uintmax_t);
	if (format[i] == '%' && format[i + 1] == 'u')
	{
		ft_putnbr_uint(number);
	}
}
//unsigned integer end


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
				handle_d(format, list, i);
				i = i + 2;
			}
			if (format[i + 1] == 'c')
			{
				handle_c(format, list);
				i = i + 2;
			}
			if (format[i + 1] == 'u')
			{
				handle_u(format, list, i);
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
	int number2;
	number2 = -101;
    string = "John";
	const char *string2;
    string2 = "i am";
	char character;
	char character2;
	character = 'c';
	character2 = 'd';
	unsigned int unsignedint;
	unsigned int unsignedint2;
	unsignedint2 = 4294967295;
	unsignedint = 4294967295;

    printf("=====================\n");
    printf("Printf output:\n");
//  string output	
//	printf("Hello %s %s %d end\n", string2, string, number);
//	
//	integer output
//	printf("hello %d %d\n", number, number2);
//
//	char output
	printf("hello %c %c\n", character, character2);
//
//	unsigned int output
//	printf("hello %u %u\n", unsignedint, unsignedint2);

    printf("=======\n");
    printf("ft_printf output:\n");
//  string output
//  ft_printf("Hello %s %s %d end\n", string2, string, number);
//	
//	integer output
//	ft_printf("Hello %d %d\n", number, number2);
//	
//	char output
	ft_printf("hello %c %c\n", character, character2);
//	
//	unsigned int output
//	ft_printf("hello %u %u\n", unsignedint, unsignedint2);
    return (0);
}
