/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartyn- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 22:09:38 by jmartyn-          #+#    #+#             */
/*   Updated: 2019/07/05 23:01:33 by jmartyn-         ###   ########.fr       */
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

//x begin
int		is_upper(char c)
{
	if (c >= 65 && c <= 90)
		return (1);
	else
		return (0);
}

void	handle_x(const char *format, va_list list)
{
	long decimal;
	long quotient;
	long remainder;
	int i;
	int j;
	
	i = 0;
	j = 0;
	char hexadecimal[100];
	
	decimal = va_arg(list, int);
	quotient = decimal;
	if (quotient == 0)
		write(1, "0", 1);
	while (quotient != 0)
	{
		remainder = quotient % 16;
		if (remainder < 10)
		{
			hexadecimal[i] = 48 + remainder;
			i++;
		}
		else
		{
			hexadecimal[i] = 55 + remainder;
			i++;
		}
		quotient = quotient / 16;
	}
	j = i - 1;
	char tmp;
	while (j >= 0)
	{
		if (is_upper(hexadecimal[j]) == 1)
		{
			tmp = hexadecimal[j];
			tmp = tmp + 32;
			write(1, &tmp, 1);
			j--;
		}	
		write(1, &hexadecimal[j], 1);
		j--;
	}
}
// x end


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
	if ((format[i] == '%' && format[i + 1] == 'd') ||
			(format[i] == '%' && format[i + 1] == 'i')) 
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
    		if (format[i + 1] == 'd' || format[i + 1] == 'i')
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
			if (format[i + 1] == 'x')
			{
				handle_x(format, list);
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
	character2 = 'h';
	unsigned int unsignedint;
	unsigned int unsignedint2;
	unsignedint2 = 29;
	unsignedint = 30;
	int intx = -10000; //something wrong with <0 numbers, debug this shit
	int intX = -10001;

    printf("=====================\n");
    printf("Printf output:\n");
//  string output	
//	printf("Hello %s %s %d end\n", string2, string, number);
//	
//	integer output %d / %i
//	printf("hello %i %i\n", number, number2);
//
//	char output
//	printf("hello %c %c\n", character, character2);
//
//	unsigned int output %u
//	printf("hello %u %u\n", unsignedint, unsignedint2);
//
//	unsigned int output | %x, %X
	printf("Hello %x %x\n", intx, intX);

    printf("=======\n");
    printf("ft_printf output:\n");
//  string output
//	ft_printf("Hello %s %s %d end\n", string2, string, number);
//	
//	integer output %d / %i
//	ft_printf("Hello %i %i\n", number, number2);
//	
//	char output
//	ft_printf("hello %c %c\n", character, character2);
//	
//	unsigned int output
//	ft_printf("hello %u %u\n", unsignedint, unsignedint2);
//
	ft_printf("Hello %x %x\n", intx, intX);
    return (0);
}
