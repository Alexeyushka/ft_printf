/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartyn- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 22:09:38 by jmartyn-          #+#    #+#             */
/*   Updated: 2019/07/11 00:08:19 by jmartyn-         ###   ########.fr       */
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

// handle x begin
int		is_upper(char c)
{
	if (c >= 65 && c <= 90)
		return (1);
	else
		return (0);
}

int		is_digit(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

long	handle_negative_x(long decimal)
{
	return (4294967296 + decimal);
}

void	handle_x_continue(int j, int i, char *hexadecimal)
{
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
		if (is_upper(hexadecimal[j]) == 0)
		{
			tmp = hexadecimal[j];
			write(1, &tmp, 1);
			j--;
		}
		if (is_digit(hexadecimal[j] == 1))
		{
			
			write(1, &hexadecimal[j], 1);
			j--;
		}
	}
}

void	handle_x(const char *format, va_list list)
{
	char hexadecimal[100];
	long decimal;
	long quotient;
	long remainder;
	int i;
	int j;
	
	i = 0;
	j = 0;
	decimal = va_arg(list, int);
	quotient = decimal;
	if (decimal < 0)
		quotient = handle_negative_x(decimal);
	if (quotient == 0)
		write(1, "0", 1);
	while (quotient != 0)
	{
		remainder = quotient % 16;
		if (remainder < 10)
			hexadecimal[i] = 48 + remainder;
		else
			hexadecimal[i] = 55 + remainder;
		i++;
		quotient = quotient / 16;
	}
	handle_x_continue(j, i, hexadecimal);
}
// handle x end

// handle X begin
void	handle_X_continue(int j, int i, char *hexadecimal)
{
	j = i - 1;
	char tmp;
	while (j >= 0)
	{
		tmp = hexadecimal[j];
		write(1, &tmp, 1);
		j--;
		if (is_digit(hexadecimal[j] == 1))
		{	
			write(1, &hexadecimal[j], 1);
			j--;
		}
	}
}

void	handle_X(const char *format, va_list list)
{
	char hexadecimal[100];
	long decimal;
	long quotient;
	long remainder;
	int i;
	int j;
	
	i = 0;
	j = 0;
	decimal = va_arg(list, int);
	quotient = decimal;
	if (decimal < 0)
		quotient = handle_negative_x(decimal);
	if (quotient == 0)
		write(1, "0", 1);
	while (quotient != 0)
	{
		remainder = quotient % 16;
		if (remainder < 10)
			hexadecimal[i] = 48 + remainder;
		else
			hexadecimal[i] = 55 + remainder;
		i++;
		quotient = quotient / 16;
	}
	handle_X_continue(j, i, hexadecimal);
}


// handle X end


// handle char begin
void	handle_c(const char *format, va_list list)
{
	char character;

	character = va_arg(list, int);
	write(1, &character, 1);
}
// handle char end

// handle integer begin
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
	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	checksign(number);
	if ((format[i] == '%' && format[i + 1] == 'd') ||
			(format[i] == '%' && format[i + 1] == 'i')) 
	{
		ft_putnbr(number);
	}
}
// handle integer end

// handle o begin
void	handle_o(const char *format, va_list list)
{
	int decimal;
	long remainder;
	long quotient;
	int tmp;
	int octal[100];
	int i;
	int j;

	i = 0;
	j = 0;
	decimal = va_arg(list, int);
	if (decimal == 0)
	{
		write(1, "0", 1);
		return ;
	}
	while (decimal != 0)
	{
		octal[i] = decimal % 8;
		decimal = decimal / 8;
		i++;
	}
	j = i - 1;
	while (j >= 0)
	{
		tmp = octal[j];
		ft_putnbr(tmp);
		j--;
	}
}

// handle o end

// handle unsigned integer begin
void	handle_u(const char *format, va_list list, int i)
{
	uintmax_t number;

	number = va_arg(list, uintmax_t);
	if (format[i] == '%' && format[i + 1] == 'u')
	{
		ft_putnbr_uint(number);
	}
}
// handle unsigned integer end


// handle string begin
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
// handle string end

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
			if (format[i + 1] == 'X')
			{
				handle_X(format, list);
				i = i + 2;
			}
			if (format[i + 1] == 'o')
			{
				handle_o(format, list);
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
	number = -2147483648;
	int number2;
	number2 = 2147483647;
    string = "John";
	const char *string2;
    string2 = "i am";
	char character;
	char character2;
	character = 'c';
	character2 = 'h';
	unsigned int unsignedint;
	unsigned int unsignedint2;
	unsignedint2 = 4294967295;
	unsignedint = -0;
	//int intx = -2147483648;
	//unsigned long long int intX = 18446744073709551615;
	int intx = -112;
	int intX = -1221313;
	int oct1 = 2147483647;
	int oct2 = 0;

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
//	x, X output
//	printf("Hello %x %X\n", intx, intX);
//
//	Octal output
	printf("Hello %o %o\n", oct1, oct2);


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
//	x, X output
//	ft_printf("Hello %x %X\n", intx, intX);
//
//	Octal output
	ft_printf("Hello %o %o\n", oct1, oct2);

    return (0);
}
