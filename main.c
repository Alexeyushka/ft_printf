/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartyn- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 22:09:38 by jmartyn-          #+#    #+#             */
/*   Updated: 2019/08/06 00:21:45 by jmartyn-         ###   ########.fr       */
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

int		ft_strlen_double(char *str)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '.')
		{
			while(str[i] != '\0')
			{
				len++;
				i++;
			}
		}
		i++;
	}
	return (len);
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

void    handle_d(const char *format, va_list list, int i, int k)
{
	int number;
	
	number = va_arg(list, int);
	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	checksign(number);
	if ((format[i] == '%' && format[i + 1 + k] == 'd') ||
			(format[i] == '%' && format[i + 1 + k] == 'i')) 
	{
		ft_putnbr(number);
	}
}
// handle integer end

// handle o begin
void	handle_o(const char *format, va_list list)
{
	long decimal;
	int tmp;
	long octal[100];
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
	if (decimal < 0)
		decimal = 4294967296 + decimal;
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

// handle float let's try

int n_tu(int number, int count)
{
	int result = 1;
	while (count-- > 0)
		result *= number;

	return result;
}

/*** Convert float to string ***/
void handle_f(const char *format, va_list list)
{
	long long int length, length2, number, i, position, sign;
	float number2;
	float f;
	char *r;
	char *str;
	int len;

	f = va_arg(list, double);
	sign = -1;   // -1 == positive number
	if (f < 0)
	{
		sign = '-';
		f *= -1;
	}

	number2 = f;
	number = f;
	length = 0;  // Size of decimal part
	length2 = 0; // Size of tenth

	/* Calculate length2 tenth part */
	while((number2 - (float)number) != 0.0 && !((number2 - (float)number) < 0.0) )
	{
		number2 = f * (n_tu(10.0, length2 + 1));
		//printf("%f\n", number2);
		number = number2;

		length2++;
	}

	/* Calculate length decimal part */
	for (length = (f > 1) ? 0 : 1; f > 1; length++)
		f /= 10;

	position = length;
	length = length + 1 + length2;
	number = number2;
	if (sign == '-')
	{
		length++;
		position++;
	}
	r = malloc(sizeof(char *) * length);
	for (i = length; i >= 0 ; i--)
	{
	if (i == (length))
			r[i] = '\0';
		else if(i == (position))
			r[i] = '.';
		else if(sign == '-' && i == 0)
			r[i] = '-';
		else
		{
			r[i] = (number % 10) + '0';
			number /=10;
		}
	}

	len = ft_strlen_double(r);
	i = 0;
	int k;
	k = 7 - len;
	while (r[i] != '\0')
	{
		write(1, &r[i], 1);
		if (r[i] == '.')
		{
			while (len > 1 && r[i] != '\0')
			{
				i++;
				if (r[i] >= 48 && r[i] <= 57) 
				{	
					write(1, &r[i], 1);
				}
			len--;
			}
		}
		i++;
	}
	while (k > 0)
	{
		write(1, "0", 1);
		k--;
	}
	free(r);
}


// handle float end

// parse argument
// parse argument flags
// parse argument flags PLUS 

void		print_flags_plus(const char *format, va_list list, int res)
{
	int number;
	int size;
	va_list cpy;
	va_copy(cpy, list);
	size = 0;
	number = va_arg(cpy, int);
	while (number > 0)
	{
		size++;
		number = number / 10;
	}
	res = res - size - 1;
	while (res > 0)
	{
		write(1, " ", 1);
		res--;
	}
	write(1, "+", 1);
	va_end(cpy);
}


int		parse_flag_plus(const char *format, va_list list, int i)
{
	int res;
	int k;
	int count;
	res = 0;
	count = 2;
	k = 1;

	while (format[i + count] >= 48 && format[i + count] <= 57)
	{
		res = res * 10;
		res = res + ((int)format[i + count] - '0');
		count++;
	}
	print_flags_plus(format, list, res);
	return (count);
}
// Parse argument flags PLUS end

// Parse argument flags MINUS begin

int		print_flag_minus_corr(const char *format, va_list list, int res)
{
	int number;
	int size;
	va_list cpy;
	va_copy(cpy, list);
	size = 0;
	number = va_arg(cpy, int);
	while (number > 0)
	{
		size++;
		number = number / 10;
	}
	va_end(cpy);
	return (size);
}


int		print_flag_minus(const char *format, va_list list, int i)
{
	int res;
	int k;
	int count;
	res = 0;
	count = 2;
	k = 1;

	while (format[i + count] >= 48 && format[i + count] <= 57)
	{
		res = res * 10;
		res = res + ((int)format[i + count] - '0');
		count++;
	}
	res = res - print_flag_minus_corr(format, list, res);
	return (res);
}

int		parse_flag_minus(const char *format, va_list list, int i)
{
	int res;
	int k;
	int count;
	res = 0;
	count = 2;
	k = 1;

	while (format[i + count] >= 48 && format[i + count] <= 57)
	{
		res = res * 10;
		res = res + ((int)format[i + count] - '0');
		count++;
	}
	return (count);
}
// FLAG minus end

// FLAG Zero begin
void		print_flags_zero(const char *format, va_list list, int res)
{
	int number;
	int size;
	va_list cpy;
	va_copy(cpy, list);
	size = 0;
	number = va_arg(cpy, int);
	while (number > 0)
	{
		size++;
		number = number / 10;
	}
	res = res - size;
	while (res > 0)
	{
		write(1, "0", 1);
		res--;
	}
	va_end(cpy);
}


int		parse_flag_zero(const char *format, va_list list, int i)
{
	int res;
	int k;
	int count;
	res = 0;
	count = 2;
	k = 1;

	while (format[i + count] >= 48 && format[i + count] <= 57)
	{
		res = res * 10;
		res = res + ((int)format[i + count] - '0');
		count++;
	}
	print_flags_zero(format, list, res);
	return (count);
}
// FLAG zero end

// FLAG blank begin
void		print_flags_blank(const char *format, va_list list, int res)
{
	int number;
	int size;
	va_list cpy;
	va_copy(cpy, list);
	size = 0;
	number = va_arg(cpy, int);
	while (number > 0)
	{
		size++;
		number = number / 10;
	}
	res = res - size;
	while (res > 0)
	{
		write(1, " ", 1);
		res--;
	}
	va_end(cpy);
}


int		parse_flag_blank(const char *format, va_list list, int i)
{
	int res;
	int k;
	int count;
	res = 0;
	count = 2;
	k = 1;

	while (format[i + count] >= 48 && format[i + count] <= 57)
	{
		res = res * 10;
		res = res + ((int)format[i + count] - '0');
		count++;
	}
	print_flags_blank(format, list, res);
	return (count);
}
// FLAG blank end

// FLAG hash begin

void		print_flag_hash_blanks(const char *format, va_list list, int res)
{
	int number;
	int size;
	va_list cpy;
	va_copy(cpy, list);
	size = 0;
	number = va_arg(cpy, int);
	while (number > 0)
	{
		size++;
		number = number / 10;
	}
	res = res - size - 1;
	while (res > 0)
	{
		write(1, " ", 1);
		res--;
	}
	va_end(cpy);
}

void		print_flag_hash_blanks_o(const char *format, va_list list, int res)
{
	int number;
	int size;
	va_list cpy;
	va_copy(cpy, list);
	size = 0;
	number = va_arg(cpy, int);
	while (number > 0)
	{
		size++;
		number = number / 10;
	}
	res = res - size;
	while (res > 0)
	{
		write(1, " ", 1);
		res--;
	}
	va_end(cpy);
}

int	handle_x_flags(const char *format, va_list list)
{
	char hexadecimal[100];
	long decimal;
	long quotient;
	long remainder;
	int i;
	int j;

	i = 0;
	j = 0;
	va_list cpy;
	va_copy(cpy, list);

	decimal = va_arg(cpy, int);
	quotient = decimal;
	if (decimal < 0)
		quotient = handle_negative_x(decimal);
	if (quotient == 0)
		i--;
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
	write(1, "0x", 2);
	handle_x(format, list);
	va_end(cpy);
	return (i);
}

int		print_flag_hash_blanks_x(const char *format, va_list list, int res)
{
	int size;

	size = 0;
	size = handle_x_flags(format, list) + 1;
	res = res - size - 1;
	while (res > 0)
	{
		write(1, " ", 1);
		res--;
	}
	return (res);
}

int		print_flag_hash_blanks_x_hash_minus(const char *format, va_list list, int res)
{
	int size;

	size = 0;
	size = handle_x_flags(format, list) + 1;
	printf("%d", size);
	res = res - size;
	printf("%d", res);
	while (res > 0)
		{
			write(1, " ", 1);
			res--;
		}
	return (res);
}

int		print_flag_hash_wo_blanks_x(const char *format, va_list list, int res)
{
	int size;

	size = 0;
	size = handle_x_flags(format, list) + 1;
	res = res - size - 1;
	return (res);
}

int		parse_flag_hash_x(const char *format, va_list list, int i)
{
	int count;
	int res;
	res = 0;
	count = 2;
	int k;
	if (format[i] == '%')
	{
		if (format[i + 1] == '#')
		{
			while (format[i + count] >= 48 && format[i + count] <= 57)
			{
				res = res * 10;
				res = res + ((int)format[i + count] - '0');
				count++;
			}
			if (format[i + count] == 'x')
				k = print_flag_hash_blanks_x(format, list, res);					
				if (k == 0)
					k = print_flag_hash_blanks_x(format, list, 1);
			if (format[i + count] == 'x' && k != 0)
			{
				write(1, "0x", 2);
			}
			if (format[i + 2] == '-')
			{
				count++;
				while (format[i + count] >= 48 && format[i + count] <= 57)
				{
					res = res * 10;
					res = res + ((int)format[i + count] - '0');
					count++;
				}
				if (format[i + count] == 'x')
					k = print_flag_hash_blanks_x_hash_minus(format, list, res);
					// if (k == 0)
					// 	k = print_flag_hash_blanks_x(format, list, 1);
				if (format[i + count] == 'x' && k != 0)
				{
					write(1, "0x", 2);
				}
			}

		}
		if (format[i + 1] == '-')
		{
			if (format[i + 2] == '#')
				count++;
			while (format[i + count] >= 48 && format[i + count] <= 57)
			{
				res = res * 10;
				res = res + ((int)format[i + count] - '0');
				count++;
			}
			if (format[i + count] == 'x')
				k = print_flag_hash_wo_blanks_x(format, list, 2);
				if (k == 1)
					k = print_flag_hash_blanks_x(format, list, 1);	
			if (format[i + count] == 'x' && k != 0)
			{
				write(1, "0x", 2);
			}
		}
	}
	return (count);
}


int		parse_flag_hash_o(const char *format, va_list list, int i)
{
	int count;
	int res;
	res = 0;
	count = 2;
	if (format[i] == '%')
	{
		if (format[i + 1] == '#')
		{
			while (format[i + count] >= 48 && format[i + count] <= 57)
			{
				res = res * 10;
				res = res + ((int)format[i + count] - '0');
				count++;
			}
			if (format[i + count] == 'o')
				print_flag_hash_blanks_o(format, list, i);
			if (format[i + count] == 'o')
			{
				write(1, "0", 1);
			}
		}
	}
	return (count);
}

int		parse_flag_hash(const char *format, va_list list, int i)
{
	int count;
	int res;
	res = 0;
	count = 2;
	if (format[i] == '%')
	{
		if (format[i + 1] == '#')
		{
			while (format[i + count] >= 48 && format[i + count] <= 57)
			{
				res = res * 10;
				res = res + ((int)format[i + count] - '0');
				count++;
			}
			print_flag_hash_blanks(format, list, res);
			if (format[i + count] == 'x')
			{
				write(1, "0x", 2);
			}
		}
	}
	return (count);
}

int		check_flags_x(const char *format, va_list list, int i)
{
	int k;
	k = 0;
	if (format[i] == '%')
	{
		if (format[i + 1] == '#' || format[i + 1] == '-')
		{
			k = parse_flag_hash_x(format, list, i) - 1;
		}
	}
	return (k);
}

int		check_flags_o(const char *format, va_list list, int i)
{
	int k;
	k = 0;
	if (format[i] == '%')
	{
		if (format[i + 1] == '#')
		{
			k = parse_flag_hash_o(format, list, i) - 1;
		}
	}
	return (k);
}

int		check_flags(const char *format, va_list list, int i)
{
	int k;
	k = 0;
	if (format[i] == '%')
	{
		if (format[i + 1] == '+')	
		{
			if (format[i + 2] == 'd')
			{
				write(1, "+", 1);
				k++;
			}
			if (format[i + 2] != 'd')
			{
				k = parse_flag_plus(format, list, i) - 1;
			}
		}
		if (format[i + 1] == '-')
		{
			k = parse_flag_minus(format, list, i) - 1;
		}
		if (format[i + 1] == '0')
		{
			k = parse_flag_zero(format, list, i) - 1;
		}
		if (format[i + 1] == ' ')
		{
			k = parse_flag_blank(format, list, i) - 1;
		}
	}
	return (k);
}

int		start_checking_arg(const char *format, va_list list, int i)
{
	int k;
	k = check_flags(format, list, i);

	return (k);
}

int		parse_arg(const char *format, va_list list, int i)
{
	int k;
	k = 0;
	if (format[i] == '%' && (
				format[i + 1] == 's' ||
				format[i + 1] == 'd' ||
				format[i + 1] == 'i' ||
				format[i + 1] == 'c' ||
				format[i + 1] == 'u' ||
				format[i + 1] == 'x' ||
				format[i + 1] == 'X' ||
				format[i + 1] == 'o' ||
				format[i + 1] == 'f' ||
				format[i + 1] == '%' ||
				format[i + 1] == '#'))
	{
		return(k);
	}
	else
		k = start_checking_arg(format, list,  i);
	return (k);
}

int		parse_arg_o(const char *format, va_list list, int i)
{
	int k;

	if (format[i + 1] == '#')
		k  = check_flags_o(format, list, i);
	else
		return (0);
	return (k);
}

int		parse_arg_x(const char *format, va_list list, int i)
{
	int k;

	if (format[i + 1] == '#' || format[i + 1] == '-')
		k = check_flags_x(format, list, i);
	else
		return (0);
	return (k);
}


void    ft_printf(const char *format, ...)
{
    int i;
	va_list list;
	int d;
	int o;
	int x;
	int tmp;
	int res;
	i = 0;
	va_start(list, format);

	while (format[i] != '\0')
	{
        if (format[i] == '%')
		{
			d = parse_arg(format, list, i);
			o = parse_arg_o(format, list, i);
			x = parse_arg_x(format, list, i);
			if (format[i + 1] == 's')
			{
				handle_s(format, list);
				i = i + 1;
			}
    		if (format[i + 1 + d] == 'd' || format[i + 1] == 'i')
			{
				handle_d(format, list, i, d);
				if (format[i + 1] == '-')
				{
					res = print_flag_minus(format, list, i);
					while (res > 0)
					{
						write(1, " ", 1);
						res--;
					}
				}
				i = i + 1 + d;	
			}
			if (format[i + 1] == 'c')
			{
				handle_c(format, list);
				i = i + 1;
			}
			if (format[i + 1] == 'u')
			{
				handle_u(format, list, i);
				i = i + 1;
			}
			if (format[i + 1 + x] == 'x')
			{
				handle_x(format, list);
				i = i + 1 + x;
			}
			if (format[i + 1] == 'X')
			{
				handle_X(format, list);
				i = i + 1;
			}
			if (format[i + 1 + o] == 'o')
			{
				handle_o(format, list);
				i = i + 1 + o;
			}
			if (format[i + 1] == 'f')
			{
				handle_f(format, list);
				i = i + 1;
			}
			if (format[i] == '%' && format[i + 1] == '%')
			{
				write(1, "%", 1);
				i = i + 1;
			}
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
	number = 27;
	int number2;
	number2 = 30;
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
	int intx = 1212121;
	int intX = 14;
	int oct1 = 10;
	int oct2 = -2147483647;
	float float1 = -1432423320.1435783543;
	float float2 = 43.0;
	float float3 = 1.546235;
    printf("=====================\n");
    printf("Printf output:\n");
//  	printf("String:\n");
/*
	printf("---> Hello %s %s %d end\n", string2, string, number);
	
	printf("Integer d / i\n");
	printf("---> Hello %d %i\n", number, number2);

	printf("Char\n");
	printf("---> Hello %c %c\n", character, character2);

	printf("Unsigned int output u\n");
	printf("---> Hello %u %u\n", unsignedint, unsignedint2);

	printf("x, X\n");
	printf("---> Hello %x %X\n", intx, intX);

	printf("Octal\n");
	printf("---> Hello %o %o\n", oct1, oct2);

	printf("Float\n");
	printf("---> Hello %f %f %f\n", float1, float2, float3);
*/	
//	printf("FLAGS: plus +6 +10\n");
//	printf("---> Hello %+6d %+10d\n", number, number2);

//	printf("FLAGS: minus -6 -10\n");
//	printf("---> Hello %-2147483649d %-10d\n", number, number2);

//	printf("FLAGS: 0\n");
//	printf("---> Hello %04d %015d\n", number, number2);

//	printf("FLAGS: blank\n");
//	printf("---> Hello % 4d % 15d\n", number, number2);

	printf("FLAGS: #\n");
	printf("---> Hello %20x %-#20x %#-20x %#20x \n", intx, intx, intx, intx);

//                 099999999999
//	printf("Percent \n");
//	printf("---> Hello %% and %%\n");
    printf("===================\n\n");
    printf("ft_printf output:\n");
/*	ft_printf("String\n");
	ft_printf("---> Hello %s %s %d end\n", string2, string, number);
	
	ft_printf("Integer d / i\n");
	ft_printf("---> Hello %d %i\n", number, number2);
	
	ft_printf("Char\n");
	ft_printf("---> Hello %c %c\n", character, character2);
	
	ft_printf("Unsigned int\n");
	ft_printf("---> Hello %u %u\n", unsignedint, unsignedint2);

	ft_printf("x, X\n");
	ft_printf("---> Hello %x %X\n", intx, intX);

	ft_printf("Octal\n");
	ft_printf("---> Hello %o %o\n", oct1, oct2);

	ft_printf("Float\n");
	ft_printf("---> Hello %f %f %f\n", float1, float2, float3);

	ft_printf("FLAGS: plus +6 +10\n");
	ft_printf("---> Hello %+6d %+10d\n", number, number2);
*/
//	ft_printf("FLAGS: minus -6 -10\n");
//	ft_printf("---> Hello %-2147483649d %-10d\n", number, number2);

//	ft_printf("FLAGS: 0\n");
//	ft_printf("---> Hello %04d %015d\n", number, number2);

//	ft_printf("FLAGS: blank\n");
//	ft_printf("---> Hello % 4d % 15d\n", number, number2);

	ft_printf("FLAGS: #\n");
	ft_printf("---> Hello %20x %-#20x %#-20x %#20x \n", intx, intx, intx, intx);

//	ft_printf("Percent \n");
//	ft_printf("---> Hello %% and %%\n");

    return (0);
}
