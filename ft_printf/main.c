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

typedef struct parser
{
	int printed;
	int res;
	int size;
	int hash_only;
	int hash_and_zero;
	int zero_and_hash;
	int zero_and_hash_and_digit;
	int hash_and_digit;
	int hash_and_zero_and_digit;
	int hash_and_minus;
	int hash_and_minus_and_digit;
	int minus_and_hash;
	int minus_and_digit;
	int zero_and_digit;
	int minus_and_hash_and_digit;

} structparser_x;


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

void	handle_x(const char *format, va_list list, struct parser parsed_x)
{
	char hexadecimal[100];
	long decimal;
	long quotient;
	long remainder;
	int i;
	int j;
	
	i = 0;
	j = 0;

	if (parsed_x.printed == 1)
		parsed_x.printed = 0;
	else
	{
	decimal = va_arg(list, int);
	quotient = decimal;
	if (decimal < 0)
		quotient = handle_negative_x(decimal);
	if (quotient == 0 && parsed_x.printed == 0)
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
	struct parser parsed;
	parsed.printed = 0;
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
	if (decimal != 0)
		write(1, "0x", 2);
	handle_x(format, list, parsed);
	va_end(cpy);
	return (i);
}

void	handle_x_continue_blanks(int j, int i, char *hexadecimal)
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

void	handle_x_blanks(const char *format, va_list list, struct parser parsed_x)
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
	handle_x_continue_blanks(j, i, hexadecimal);
}

int	handle_x_flags_blanks(const char *format, va_list list)
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
	struct parser parsed;
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
	va_end(cpy);
	return (i);
}

int	handle_x_flags_blanks_print(const char *format, va_list list)
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
	struct parser parsed;
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
	if (decimal != 0)
		write(1, "0x", 2);
	//handle_x_blanks(format, list, parsed);
	va_end(cpy);
	return (i);
}

int		print_flag_hash_blanks_x(const char *format, va_list list, int res)
{
	int size;

	size = 0;
	size = handle_x_flags_blanks(format, list) + 1;
	res = res - size - 1;
	while (res > 0)
	{
		write(1, " ", 1);
		res--;
	}
	handle_x_flags_blanks_print(format, list);
	return (res);
}


int	handle_x_flags_wo_blanks_print(const char *format, va_list list)
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
	struct parser parsed;
	parsed.printed = 0;
	decimal = va_arg(cpy, int);
	quotient = decimal;
	if (decimal < 0)
	{
		quotient = handle_negative_x(decimal);
		i--;
	}
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
	handle_x(format, list, parsed);
	va_end(cpy);
	return (i);
}

int		print_flag_hash_wo_blanks_x(const char *format, va_list list, int res)
{
	int size;

	size = 0;

	size = handle_x_flags_wo_blanks_print(format, list) - 1;
	if (res == size)
	{
		write(1, " ", 1);
	}
	if (size == -2)
		size = 0;
	res = res - size - 1;
	while (res > 0)
	{
		write(1, " ", 1);
		res--;
	}
	res = 1;
	return (res);
}

int	handle_x_flags_wo_blanks_print_w_hash(const char *format, va_list list)
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
	struct parser parsed;
	parsed.printed = 0;
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
	if (decimal != 0)
		write(1, "0x", 2);
	handle_x(format, list, parsed);
	va_end(cpy);
	return (i);
}

int		print_flag_hash_wo_blanks_x_w_hash(const char *format, va_list list, int res)
{
	int size;

	size = 0;
	size = handle_x_flags_wo_blanks_print_w_hash(format, list) + 1;
	res = res - size - 1;
	while (res > 0)
	{
		write(1, " ", 1);
		res--;
	}
	if (res < 0)
	res = 1;
	return (res);
}

int	handle_x_flags_blanks_print_zero(const char *format, va_list list)
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
	struct parser parsed;
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
	if (decimal != 0)
		write(1, "0x", 2);
	va_end(cpy);
	return (i);
}
//=========================================================================================================== 

int		print_flag_hash_blanks_x_zero(const char *format, va_list list, int res)
{
	int size;
	struct parser parsed;
	size = 0;
	size = handle_x_flags_blanks(format, list) + 1;
	res = res - size;
	handle_x_flags_blanks_print_zero(format, list);
	//if (res == 1)
	//	res = 0;
	while (res - 1 > 0)
	{
		write(1, "0", 1);
		res--;
	}
	handle_x_blanks(format, list, parsed);
	return (res);
}

int		print_flag_hash_blanks_x_hash_minus(const char *format, va_list list, int res)
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

int	handle_x_flags_minus_y(const char *format, va_list list)
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
	struct parser parsed;
	parsed.printed = 0;
	decimal = va_arg(cpy, int);
	quotient = decimal;
	if (decimal < 0)
		quotient = handle_negative_x(decimal);
	if (decimal == 0)
	{	
		i--;
		write(1, "0", 1);
		return (i);
	}
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
	if (decimal != 0)
		write(1, "0x", 2);
	handle_x(format, list, parsed);
	va_end(cpy);
	return (i);
}

int		print_flag_hash_blanks_x_hash_minus_y(const char *format, va_list list, int res)
{
	int size;

	size = 0;
	size = handle_x_flags_minus_y(format, list) + 1;
	res = res - size - 1;
	while (res > 0)
		{
			write(1, " ", 1);
			res--;
		}
	return (res);
}

int		parse_flag_hash_x(const char *format, va_list list, int i)
{
	int count;
	int res;
	int hash;
	int zero;
	zero = 0;
	hash = 0;
	res = 0;
	count = 2;
	int minus;
	minus = 0;
	int k;
	if (format[i] == '%')
	{
		if (format[i + 1] == '#')
		{
			while (format[i + count] >= 48 && format[i + count] <= 57)
			{
				if (format[i + count] == '0')
					zero = 1;
				res = res * 10;
				res = res + ((int)format[i + count] - '0');
				count++;
			}
			if (format[i + count] == 'x' && zero == 0)
				k = print_flag_hash_blanks_x(format, list, res);
			if (format[i + count] == 'x' && zero == 1)
				k = print_flag_hash_blanks_x_zero(format, list, res);					
				//if (k == 0)
				//	k = print_flag_hash_blanks_x(format, list, 1);
			if (format[i + count] == 'x' && k != 0 && zero != 1)
			{
				write(1, "0x", 2);
			}
			if (format[i + 2] == '-')
			{
				minus = 1;
				count++;
				while (format[i + count] >= 48 && format[i + count] <= 57)
				{
					res = res * 10;
					res = res + ((int)format[i + count] - '0');
					count++;
				}
				if (format[i + count] == 'x')
				{	
					if (minus == 0)
						k = print_flag_hash_blanks_x_hash_minus(format, list, res);
					if (minus == 1)
					{
						k = print_flag_hash_blanks_x_hash_minus_y(format, list, res);
						k = 0;
						minus = 0;
					}
					//if (k == 0)
						//k = print_flag_hash_blanks_x(format, list, 1);
				}
				if (format[i + count] == 'x' && k != 0)
				{
					write(1, "0x", 2);
				}
			}

		}
		if (format[i + 1] == '-')
		{
			if (format[i + 2] == '#')
			{	
				count++;
				hash = 1;
			}
			while (format[i + count] >= 48 && format[i + count] <= 57)
			{
				res = res * 10;
				res = res + ((int)format[i + count] - '0');
				count++;
			}
			if (format[i + count] == 'x')
			{	
				if (hash == 0)
					k = print_flag_hash_wo_blanks_x(format, list, res);
				if (hash == 1)
				{	
					k = print_flag_hash_wo_blanks_x_w_hash(format, list, res);
					hash = 0;
				}
			}
			if (k == 1)
			{	
				return (count);
			}	//k = print_flag_hash_blanks_x(format, list, 1);	
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
			//k = parse_flag_zero(format, list, i) - 1;
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

void	handle_x_with_zero(const char *format, va_list list, struct parser parsed_x)
{
	char hexadecimal[100];
	long decimal;
	long quotient;
	long remainder;
	int i;
	int j;
	
	i = 0;
	j = 0;
	write(1, "0", 1);
	decimal = va_arg(list, int);
	quotient = decimal;
	if (decimal != 0)
	{
	if (decimal < 0)
		quotient = handle_negative_x(decimal);

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
}

int	handle_x_print_only_blanks(const char *format, va_list list)
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
	struct parser parsed;
	decimal = va_arg(cpy, int);
	quotient = decimal;
	if (decimal < 0)
	{
		quotient = handle_negative_x(decimal);
		i++;
	}
	if (decimal == 0)
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
	if (decimal == 0)
		handle_x_with_zero(format, list, parsed);
//	else
//		handle_x(format, list, parsed);
	va_end(cpy);
	return (i);
}

int		print_blanks_for_x(const char *format, va_list list, int i)
{
	int count;
	int res;
	int size;
	int zero;
	zero = 0;
	size = 0;
	res = 0;
	count = 1;
	// if (format[i + count] == '0')
	// 	{
	// 		write(1, "0", 1);
	// 		zero = 1;
	// 	}
	while (format[i + count] >= 48 && format[i + count] <= 57)
	{
		res = res * 10;
		res = res + ((int)format[i + count] - '0');
		count++;
	}
	size = handle_x_print_only_blanks(format, list);
	if (size == -1)
		size = 1;
	if (size != 1)
	{
		while (res - size > 0)
		{
			write(1, " ", 1);
			res--;
		}
	}
	return (count);
}

int		parse_arg_x(const char *format, va_list list, int i)
{
	int k;
	struct parser parsed;
	if (format[i + 1] == '#' || format[i + 1] == '-')
		k = check_flags_x(format, list, i);
	else if (format[i + 1] >= 48 && format[i + 1] <= 57)
	{
		if (format[i + 1] != 0)
			k = print_blanks_for_x(format, list, i) - 1;
		if (format[i + 1] == '0')
		{
			handle_x_with_zero(format, list, parsed);	
		}
		else
			handle_x(format, list, parsed);
	}
	else
		return (0);
	return (k);
}

// 	=========================     flag count_size begin   =============================

int		ft_numlen(int n)
{
	if (n < 0)
		return (ft_numlen(n * -1) + 1);
	if (n >= 10)
		return (ft_numlen(n / 10) + 1);
	return (1);
}

int		flag_count_res(const char *format, int i)
{
	int res;

	res = 0;
	while (format[i] >= 48 && format[i] <= 57)
	{
		res = res * 10;
		res = res + ((int)format[i] - '0');
		i++;
	}
	return (res);
}

int		flag_count_size(const char *format, va_list list, struct parser parsed)
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
		i = 1;
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
	va_end(cpy);
	return (i);
}
// 	-------------------------       flag count_size end    -----------------------------

// 	=========================      flag hash_only_begin    =============================


void	flag_hash_only_print_blanks_continue_more(int j, int i, char *hexadecimal)
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

void	flag_hash_only_print_blanks_continue(const char *format, va_list list, struct parser parsed_x)
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
	flag_hash_only_print_blanks_continue_more(j, i, hexadecimal);
}

int	flag_hash_only_print_blanks(const char *format, va_list list)
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
	struct parser parsed;
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
	if (decimal != 0)
		write(1, "0x", 2);
	flag_hash_only_print_blanks_continue(format, list, parsed);
	va_end(cpy);
	return (i);
}

int		flag_hash_only(const char *format, va_list list, int i, struct parser parsed)
{
	int res;
	int digit;

	digit = 0;
	res = 0;

	va_list cpy;
	va_copy(cpy, list);
	digit = va_arg(cpy, int);
	if (digit != '0')
		res = 2;
	res = res + flag_hash_only_print_blanks(format, list);
	if (res == 1)
		write(1, "0", 1);
	va_end(cpy);
	return (res);
}
//	-------------------------          flag hash_only_end       -----------------------------

//	==========================      flag hash_and_zero begin     =============================

void	flag_hash_and_zero_print_continue(int j, int i, char *hexadecimal)
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

void	flag_hash_and_zero_print(const char *format, va_list list, struct parser parsed_x)
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
		if (decimal != 0)
		write(1, "0x", 2);
	flag_hash_and_zero_print_continue(j, i, hexadecimal);
}

int		flag_hash_and_zero(const char *format, va_list list, int res, struct parser parsed)
{
	res = res - parsed.size;
	flag_hash_and_zero_print(format, list, parsed);
	return (res);
}

// 	--------------------------       flag hash_and_zero end       -----------------------------

//	==========================      flag zero_and_hash begin     =============================

void	flag_zero_and_hash_print(const char *format, va_list list, struct parser parsed_x)
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
	if (decimal != 0)
	{
	if (decimal < 0)
		quotient = handle_negative_x(decimal);

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
	else
		write(1, "0", 1);
}


//	-------------------------       flag zero_and_hash end       -----------------------------


//	==========================      flag zero_and_hash_and_digit begin     =============================

void	flag_zero_and_hash_and_digit_print_continue(int j, int i, char *hexadecimal)
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

void	flag_zero_and_hash_and_digit_print(const char *format, va_list list, int res, struct parser parsed_x)
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
	if (decimal != 0)
	{
		write(1, "0x", 2);
		res = res - 2;
	}
	while (res - parsed_x.size > 0)
	{
		write(1, "0", 1);
		res--;
	}
	flag_zero_and_hash_and_digit_print_continue(j, i, hexadecimal);
}


int		flag_zero_and_hash_and_digit(const char *format, va_list list, int i, struct parser parsed)
{
	int res;
	int count;
	res = 0;
	count = 3;

	while (format[i + count] >= 48 && format[i + count] <= 57)
	{
		res = res * 10;
		res = res + ((int)format[i + count] - '0');
		count++;
	}
	flag_zero_and_hash_and_digit_print(format, list, res, parsed);
	return (count);
}


//	-------------------------       flag zero_and_hash_and_digit end       -----------------------------

//	==========================      flag hash_and_digit begin     =============================

void	flag_hash_and_digit_print(const char *format, va_list list, struct parser parsed_x)
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
	if (decimal != 0)
		write(1, "0x", 2);
	handle_x_continue_blanks(j, i, hexadecimal);
}

int	flag_hash_and_digit_blanks(const char *format, va_list list)
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
	struct parser parsed;
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
	if (decimal != 0)
		i = i + 2;
	va_end(cpy);
	return (i);
}

int	count_zero_blanks(const char *format, va_list list, int i)
{
	long decimal;
	int zero_blanks;

	zero_blanks = 0;
	va_list cpy;
	va_copy(cpy, list);
	decimal = va_arg(cpy, int);
	if (decimal == 0)
		zero_blanks = 2;
	va_end(cpy);
	return (zero_blanks);
}


int		flag_hash_and_digit(const char *format, va_list list, int i, struct parser parsed)
{
	int size;
	int res;
	int digits;
	int zero_blanks;

	zero_blanks = count_zero_blanks(format, list, i);
	size = flag_hash_and_digit_blanks(format, list);
	res = flag_count_res(format, (i + 2)) - zero_blanks;
	digits = ft_numlen(res);
	while (res - size > 0)
	{
		write(1, " ", 1);
		res--;
	}
	flag_hash_and_digit_print(format, list, parsed);
	return (digits);
}

//	-------------------------       flag hash_and_digit end       -----------------------------

//	==========================      flag hash_and_zero_and_digit begin     =============================

void	flag_hash_and_minus_continue(const char *format, va_list list)
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
	struct parser parsed;
	parsed.printed = 0;
	decimal = va_arg(cpy, int);
	quotient = decimal;
	if (decimal < 0)
		quotient = handle_negative_x(decimal);
	if (decimal == 0)
	{	
		i--;
		write(1, "0", 1);
		return ;
	}
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
	if (decimal != 0)
		write(1, "0x", 2);
	handle_x(format, list, parsed);
	va_end(cpy);
}

int		flag_hash_and_minus(const char *format, va_list list, int i, struct parser parsed)
{
	int result;

	result = 3;
	flag_hash_and_minus_continue(format, list);
	return (result);
}

//	-------------------------       flag hash_and_zero_and_digit end       -----------------------------


//	==========================      flag hash_and_minus_and_digit begin     =============================

void	flag_hash_and_minus_and_digit_print(const char *format, va_list list, struct parser parsed_x)
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
	if (decimal != 0)
		write(1, "0x", 2);
	handle_x_continue_blanks(j, i, hexadecimal);
}

int	flag_hash_and_minus_and_digit_blanks(const char *format, va_list list)
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
	struct parser parsed;
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
	if (decimal != 0)
		i = i + 2;
	va_end(cpy);
	return (i);
}


int		flag_hash_and_minus_and_digit(const char *format, va_list list, int i, struct parser parsed)
{
	int size;
	int res;
	int digits;
	int zero_blanks;

	zero_blanks = count_zero_blanks(format, list, i);
	size = flag_hash_and_minus_and_digit_blanks(format, list);
	res = flag_count_res(format, (i + 3)) - zero_blanks;
	digits = ft_numlen(res);
	flag_hash_and_minus_and_digit_print(format, list, parsed);
	while (res - size > 0)
	{
		write(1, " ", 1);
		res--;
	}
	return (digits);
}

//	-------------------------       flag hash_and_minus_and_digit end       -----------------------------

//	==========================      flag minus_and_digit begin     =============================
void	flag_minus_and_digit_print(const char *format, va_list list, struct parser parsed_x)
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
	// if (decimal != 0)
	// 	write(1, "0x", 2);
	handle_x_continue_blanks(j, i, hexadecimal);
}

int	flag_minus_and_digit_blanks(const char *format, va_list list)
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
	struct parser parsed;
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
	// if (decimal != 0)
	// 	i = i + 2;
	va_end(cpy);
	return (i);
}


int		flag_minus_and_digit(const char *format, va_list list, int i, struct parser parsed)
{
	int size;
	int res;
	int digits;
	int zero_blanks;

	zero_blanks = count_zero_blanks(format, list, i);
	size = flag_minus_and_digit_blanks(format, list);
	res = flag_count_res(format, (i + 2)) - zero_blanks;
	digits = ft_numlen(res);
	flag_minus_and_digit_print(format, list, parsed);
	while (res - size > 0)
	{
		write(1, " ", 1);
		res--;
	}
	return (digits);
}

//	-------------------------       flag minus_and_digit end       -----------------------------

//	==========================      flag zero_and_digit begin     =============================

void	flag_zero_and_digit_printit(const char *format, va_list list, struct parser parsed_x)
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

void	flag_zero_and_digit_print(const char *format, va_list list, int res, struct parser parsed)
{
	int number;
	int size;
	va_list cpy;
	va_copy(cpy, list);
	size = 0;
	size = flag_count_size(format, list, parsed);
	number = va_arg(cpy, int);
	res = res - size;
	while (res > 0)
	{
		write(1, "0", 1);
		res--;
	}
	va_end(cpy);
	flag_zero_and_digit_printit(format, list, parsed);
}


int		flag_zero_and_digit(const char *format, va_list list, int i, struct parser parsed)
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
	flag_zero_and_digit_print(format, list, res, parsed);
	return (count);
}
//	-------------------------       flag zero_and_digit end       -----------------------------

//	==========================      flag minus_and_hash_and_digit begin     =============================

int		flag_minus_and_hash_and_digit(const char *format, va_list list, int i, struct parser parsed)
{
	int size;
	int res;
	int digits;
	int zero_blanks;

	zero_blanks = count_zero_blanks(format, list, i);
	size = flag_minus_and_digit_blanks(format, list);
	res = flag_count_res(format, (i + 2)) - zero_blanks;
	digits = ft_numlen(res);
	flag_minus_and_digit_print(format, list, parsed);
	printf("zero_blanks = %d, size = %d, res = %d, digits = %d", zero_blanks, size, res, digits);
	while (res - size > 0)
	{
		write(1, " ", 1);
		res--;
	}
	return (digits);
}

//	-------------------------       flag minus_and_hash_and_digit end       -----------------------------


int		print_flags(const char *format, va_list list, int i, struct parser parsed)
{
	int res;
	int count;
	count = 0;
	parsed.size = 0;

	parsed.size = flag_count_size(format, list, parsed);
//	hash_only
	if (parsed.hash_only == 1)
	{
		count = flag_hash_only(format, list, i, parsed) - parsed.size - 1;
		if (count == -1)
			count = 1;
		parsed.hash_only = 0;
	}

//	hash_and_zero
	if (parsed.hash_and_zero == 1)
	{
		res = flag_count_res(format, (i + 2));
		count = flag_hash_and_zero(format, list, res, parsed) + parsed.size + 2;
		parsed.hash_and_zero = 0;
	}

//	zero_and_hash
	if (parsed.zero_and_hash == 1)
	{
		flag_hash_and_zero(format, list, res, parsed);
		parsed.zero_and_hash = 0;
		count = 2;
	}

//	zero_and_hash_and_digit --- and --- hash_and_zero_and_digit
	if (parsed.zero_and_hash_and_digit == 1 || parsed.hash_and_zero_and_digit == 1)
	{
		count = flag_zero_and_hash_and_digit(format, list, i, parsed) - 1;
		parsed.zero_and_digit = 0;
		parsed.hash_and_zero_and_digit = 0;
	}

//	hash_and_digit
	if (parsed.hash_and_digit == 1)
	{
		count = flag_hash_and_digit(format, list, i, parsed) + 1;
		parsed.hash_and_digit = 0;
	}

//	hash_and_minus
	if (parsed.hash_and_minus == 1)
	{
		count = flag_hash_and_minus(format, list, i, parsed) - 1;
		parsed.hash_and_minus = 0;
	}
//	hash_and_minus_and_digit
	if (parsed.hash_and_minus_and_digit == 1)
	{
		count = flag_hash_and_minus_and_digit(format, list, i, parsed) + 2;		
		parsed.hash_and_minus_and_digit = 0;
	}

//	minus_and_hash
	if (parsed.minus_and_hash == 1)
	{
		count = flag_hash_only(format, list, i, parsed) - parsed.size;
		if (count == 0)
			count = 2;
		parsed.minus_and_hash = 0;
	}
//	minus_and_digit 
	if (parsed.minus_and_digit == 1)
	{
		count = flag_minus_and_digit(format, list, i, parsed) + 1;
		parsed.minus_and_digit = 0;
	}

//	zero_and_digit
	if (parsed.zero_and_digit == 1)
	{
		count = flag_zero_and_digit(format, list, i, parsed) - 1; 
		parsed.zero_and_digit = 0;
	}

//	minus_and_hash_and_digit
	if(parsed.minus_and_hash_and_digit == 1)
	{
		count = flag_hash_and_minus_and_digit(format, list, i, parsed) + 2; //debug below size
		parsed.minus_and_hash_and_digit = 0;
	}
	return (count);


}


int		parse_arg_x_init(const char *format, va_list list, int i)
{
	int result;
	struct parser parsed;
	parsed.hash_only = 0;
	parsed.hash_and_zero = 0;
	parsed.zero_and_hash = 0;
	parsed.zero_and_hash_and_digit = 0;
	parsed.hash_and_digit = 0;
	parsed.hash_and_zero_and_digit = 0;
	parsed.minus_and_hash = 0;
	parsed.minus_and_digit = 0;
	parsed.zero_and_digit = 0;
	parsed.minus_and_hash_and_digit = 0;
	if (format[i + 1] == '#' && format[i + 2] == 'x')
		parsed.hash_only = 1;
	else if (format[i + 1] == '#' && format[i + 2] == '0' && format[i + 3] == 'x')
		parsed.hash_and_zero = 1;
	else if (format[i + 1] == '0' && format[i + 2] == '#' && format[i + 3] == 'x')
		parsed.zero_and_hash = 1;
	else if (format[i + 1] == '0' && format[i + 2] == '#' && (format[i + 3] >= 49 && format[i + 3] <= 57))
		parsed.zero_and_hash_and_digit = 1;
	else if (format[i + 1] == '#' && (format[i + 2] >= 49 && format[i + 2] <= 57))
		parsed.hash_and_digit = 1;
	else if (format[i + 1] == '#' && format[i + 2] == '0' && (format[i + 3] >= 49 && format[i + 3] <= 57))
		parsed.hash_and_zero_and_digit = 1;
	else if (format[i + 1] == '#' && format[i + 2] == '-' && format[i + 3] == 'x')
		parsed.hash_and_minus = 1;
	else if (format[i + 1] == '#' && format[i + 2] == '-' && (format[i + 3] >= 49 && format[i + 3] <= 57))
		parsed.hash_and_minus_and_digit = 1;
	else if (format[i + 1] == '-' && format[i + 2] == '#' && format[i + 3] == 'x')
		parsed.minus_and_hash = 1;
	else if (format[i + 1] == '-' && (format[i + 2] >= 49 && format[i + 2] <= 57))
		parsed.minus_and_digit = 1;
	else if (format[i + 1] == '0' && (format[i + 2] >= 49 && format[i + 2] <= 57))
		parsed.zero_and_digit = 1;
	else if (format[i + 1] == '-' && format[i + 2] == '#' && (format[i + 3] >= 49 && format[i + 3] <= 57))
		parsed.minus_and_hash_and_digit = 1;
	else
		return (0);
	result = print_flags(format, list, i, parsed);
	return (result);
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
	struct parser parsed_x;
	parsed_x.printed = 0;
	while (format[i] != '\0')
	{
        if (format[i] == '%')
		{
			d = parse_arg(format, list, i);
			o = parse_arg_o(format, list, i);
			x = parse_arg_x_init(format, list, i);
			if (x != 0)
			{
				parsed_x.printed = 1;
			}
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
				handle_x(format, list, parsed_x);
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
	int intx = -123;
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
//	printf("---> Hello %#x xxxx %#0x xxxx 1 %0#x xxxx %#010x xxxx %#10x xxxx %#-x xxxx %#-10x xxxx %-#x xxxx 1 %-#10x xxxx %-10x xxxx %10x xxxx %010x \n", intx, intx, intx, intx, intx, intx, intx, intx, intx, intx, intx, intx);
	printf("---> Hello --- %#x --- %#0x --- %0#x --- %0#15x --- %#17x --- %#017x --- %#-x --- %#-17x --- %-#x --- %-8x --- %04x --- %-#11x ---", intx, intx, intx,  intx, intx, intx, intx, intx, intx ,intx, intx, intx);
//                 099999999999
//	printf("Percent \n");
//	printf("---> Hello %% and %%\n");
    printf("\n===================\n\n");
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

//	ft_printf("FLAGS: #\n");
	ft_printf("---> Hello --- %#x --- %#0x --- %0#x --- %0#15x --- %#17x --- %#017x --- %#-x --- %#-17x --- %-#x --- %-8x --- %04x --- %-#17x ---", intx, intx, intx, intx, intx, intx, intx, intx, intx ,intx, intx, intx);
	printf("\n");
//	ft_printf("---> Hello %015x xxxx %-7x xxxx 1 %-#7x xxxx %#-7x xxxx %#07x xxxx %#09x xxxx %020x xxxx %-20x xxxx 1 %#020x xxxx %-#20x xxxx %#-20x 1\n", intx, intx, intx, intx, intx, intx, intx, intx, intx, intx, intx);

//	ft_printf("Percent \n");
//	ft_printf("---> Hello %% and %%\n");

    return (0);
}
