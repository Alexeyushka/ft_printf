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
#include <limits.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

typedef struct p
{
	int precision_zero;
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
	int	plus;
	int	plus_and_digit;
	int	minus;
	int zero;
	int	blank;
	int	blank_and_digit; 
	int h;
	int hh;
	int l;
	int ll;
	int largel;
	int exception;
	int precision;
	int precision_count;
	int width;
	int width_number;
	int digit;
	int width_and_plus;
	int width_and_minus;
	int width_and_zero;
	int string_precision;
} structp_x;


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

void	ft_putnbr_long(long nb)
{
	if (nb < 0)
	{
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr_long(nb / 10);
		ft_putnbr_long(nb % 10);
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

//end of lib

// handle x begin

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


void	handle_hui(const char *format, va_list list, struct p parsed)
{
	write(1, "LOVI HUICA\n", 12);
	write(1, "8===D\n", 6);
}

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

void     handle_s_precision(const char *format, va_list list, int len)
{
    int j;
	char *arg;
    
	j = 0;
	arg = va_arg(list, char*);

    while (arg[j] != '\0' && j < len)
    {
    	write(1, &arg[j], 1);
    	j++;
	}
}

void	handle_s_with_precision(const char *format, va_list list, struct p parsed)
{
	int len;
	len = va_arg(list, int);
	handle_s_precision(format, list, len);
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


void handle_f_ld(const char *format, va_list list, struct p parsed)
{
	long long int length, length2, number, i, position, sign;
	long double number2;
	long double number3;
	long double f;
	char *r;
	char *str;
	int len;
	int p;

	p = 0;
	f = va_arg(list, long double);
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
	while((number2 - (long double)number) != 0.0 && !((number2 - (long double)number) < 0.0) && length2 <= 5)
	{
		number2 = f * (n_tu(10.0, length2 + 1));
		number = number2;
		length2++;
	}
	number3 = f*(n_tu(10.0, length2 + 1));
	char *test;
	


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
	test = malloc(sizeof(char *) * length + 1);
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
	number = number3;
	//
	for (i = length + 1; i >= 0 ; i--)
	{
	if (i == (length + 1))
			test[i] = '\0';
		else if(i == (position))
			test[i] = '.';
		else if(sign == '-' && i == 0)
			test[i] = '-';
		else
		{
			test[i] = (number % 10) + '0';
			number /=10;
		}
	}
	//
	if (test[length] >= 53 && test[length] <= 57)
		r[length - 1] = r[length - 1] + 1;
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



// handle float

void handle_f(const char *format, va_list list, struct p parsed)
{
	long long int length, length2, number, i, position, sign;
	float number2;
	float f;
	char *r;
	char *str;
	int len;
	if (parsed.largel == 1)
	{	
		handle_f_ld(format, list, parsed);
		parsed.largel = 0;
		return ;
	}
	f = va_arg(list, double);
	sign = -1;   // -1 == positive number
	if (f < 0)
	{
		sign = '-';
		f *= -1;
	}
	if (f == 0 && parsed.precision_zero == 1)
	{	
		write(1, "0", 1);
		return ;
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
	if (parsed.precision > 6)
		k = 7 - len - (6 - parsed.precision);
	if (parsed.precision_zero == 1)
		k = k - 1;
	while (r[i] != '\0')
	{
		write(1, &r[i], 1);
		if (r[i] == '.')
		{
			if (parsed.precision != 0)
			{	
				len = parsed.precision + 1;
				parsed.res = 1;
			}
			while (len > 1 && r[i] != '\0')
			{
				i++;
				if (r[i] >= 48 && r[i] <= 57) 
				{	
					write(1, &r[i], 1);
				}
			len--;
			}
			if (parsed.res == 1)
			{	
				parsed.res = 0;
				break ;
			}
		}
		i++;
		if (r[i] == '.' && parsed.precision_zero == 1)
			break;
	}
	while (k > 0)
	{
		write(1, "0", 1);
		k--;
	}
	free(r);
}


// handle float end











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

int		count_long(const char *format, va_list list, int i, struct p parsed)
{
	int count;
	int res;

	res = 0;
	count = 2;
	while (format[i + count] >= 48 && format[i + count] <= 57)
	{
		res = res * 10;
		res = res + ((long)format[i + count] - '0');
		count++;
	}
	return (count);
}

int		count_long_res(const char *format, va_list list, int i, struct p parsed)
{
	int count;
	int res;

	res = 0;
	count = 2;
	while (format[i + count] >= 48 && format[i + count] <= 57)
	{
		res = res * 10;
		res = res + ((long)format[i + count] - '0');
		count++;
	}
	return (res);
}

int		flag_count_size(const char *format, va_list list, struct p parsed)
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

void	flag_hash_only_print_blanks_continue(const char *format, va_list list, struct p parsed_x)
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
	struct p parsed;
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

int		flag_hash_only(const char *format, va_list list, int i, struct p parsed)
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

void	flag_hash_and_zero_print(const char *format, va_list list, struct p parsed_x)
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

int		flag_hash_and_zero(const char *format, va_list list, int res, struct p parsed)
{
	res = res - parsed.size;
	flag_hash_and_zero_print(format, list, parsed);
	return (res);
}

// 	--------------------------       flag hash_and_zero end       -----------------------------

//	==========================      flag zero_and_hash begin     =============================

void	flag_zero_and_hash_print(const char *format, va_list list, struct p parsed_x)
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

void	flag_zero_and_hash_and_digit_print(const char *format, va_list list, int res, struct p parsed_x)
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


int		flag_zero_and_hash_and_digit(const char *format, va_list list, int i, struct p parsed)
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

void	flag_hash_and_digit_print(const char *format, va_list list, struct p parsed_x)
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
	struct p parsed;
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


int		flag_hash_and_digit(const char *format, va_list list, int i, struct p parsed)
{
	int size;
	int res;
	int digits;
	int zero_blanks;

	zero_blanks = count_zero_blanks(format, list, i);
	size = flag_hash_and_digit_blanks(format, list);
	res = flag_count_res(format, (i + 2));
	digits = ft_numlen(res);
	while (res - size - zero_blanks > 0)
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
	struct p parsed;
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
	handle_x(format, list);
	va_end(cpy);
}

int		flag_hash_and_minus(const char *format, va_list list, int i, struct p parsed)
{
	int result;

	result = 3;
	flag_hash_and_minus_continue(format, list);
	return (result);
}

//	-------------------------       flag hash_and_zero_and_digit end       -----------------------------


//	==========================      flag hash_and_minus_and_digit begin     =============================

void	flag_hash_and_minus_and_digit_print(const char *format, va_list list, struct p parsed_x)
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
	struct p parsed;
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


int		flag_hash_and_minus_and_digit(const char *format, va_list list, int i, struct p parsed)
{
	int size;
	int res;
	int digits;
	int zero_blanks;

	zero_blanks = count_zero_blanks(format, list, i);
	size = flag_hash_and_minus_and_digit_blanks(format, list);
	res = flag_count_res(format, (i + 3));
	digits = ft_numlen(res);
	flag_hash_and_minus_and_digit_print(format, list, parsed);
	while (res - size  - zero_blanks > 0)
	{
		write(1, " ", 1);
		res--;
	}
	return (digits);
}

//	-------------------------       flag hash_and_minus_and_digit end       -----------------------------

//	==========================      flag minus_and_digit begin     =============================
void	flag_minus_and_digit_print(const char *format, va_list list, struct p parsed_x)
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
	struct p parsed;
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


int		flag_minus_and_digit(const char *format, va_list list, int i, struct p parsed)
{
	int size;
	int res;
	int digits;
	int zero_blanks;

	zero_blanks = count_zero_blanks(format, list, i);
	size = flag_minus_and_digit_blanks(format, list);
	res = flag_count_res(format, (i + 2));
	digits = ft_numlen(res);
	flag_minus_and_digit_print(format, list, parsed);
	while (res - size  - zero_blanks > 0)
	{
		write(1, " ", 1);
		res--;
	}
	return (digits);
}

//	-------------------------       flag minus_and_digit end       -----------------------------

//	==========================      flag zero_and_digit begin     =============================

void	flag_zero_and_digit_printit(const char *format, va_list list, struct p parsed_x)
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

void	flag_zero_and_digit_print(const char *format, va_list list, int res, struct p parsed)
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


int		flag_zero_and_digit(const char *format, va_list list, int i, struct p parsed)
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

int		flag_minus_and_hash_and_digit(const char *format, va_list list, int i, struct p parsed)
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

//	-------------------------       flag minus_and_hash_and_digit end       -----------------------------

int		checksign(int number)
{
	if (number < 0)
	{
		write(1, "-", 1);
		return (1);
	}
	if (number >= 0)
		return (0);
	return (0);
}

int		checksign_long(long long int number)
{
	if (number < 0)
	{
		write(1, "-", 1);
		return (1);
	}
	if (number >= 0)
		return (0);
	return (0);
}

void	handle_long_flag(const char *format, va_list list, int i, struct p parsed)
{
	long number;
	number = va_arg(list, long);
	checksign_long(number);
	ft_putnbr_long(number);
	parsed.l = 0;

}

void    handle_d_without_flags(const char *format, va_list list, int i, struct p parsed)
{
	int number;

	if (parsed.l == 1 || parsed.ll == 1)
	{
		handle_long_flag(format, list, i, parsed);
		return ;
	}
	number = va_arg(list, int);
	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	checksign(number);
	ft_putnbr(number);
}

//	==========================      flag plus_and_digit begin     =============================
void    flag_plus_and_digit_print(const char *format, va_list list, int i, int k)
{
	int number;

	number = va_arg(list, int);
	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (checksign(number) == 0)
		write(1, "+", 1);
	ft_putnbr(number);
}

void    flag_plus_and_digit_print_long(const char *format, va_list list, int i, int k)
{
	long number;

	number = va_arg(list, long);
	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (checksign_long(number) == 0)
		write(1, "+", 1);
	ft_putnbr_long(number);
}

void	flag_plus_and_digit(const char *format, va_list list, int res, struct p parsed)
{
	int number;
	int size;
	va_list cpy;
	va_copy(cpy, list);
	size = 0;
	number = va_arg(cpy, int);
	if (number < 0)
	{
		number = number * (-1);
	}
	if (number == 0)
		size++;
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

void	flag_plus_and_digit_long(const char *format, va_list list, int res, struct p parsed)
{
	long number;
	int size;
	va_list cpy;
	va_copy(cpy, list);
	size = 0;
	number = va_arg(cpy, long);
	if (number < 0)
	{
		number = number * (-1);
	}
	if (number == 0)
		size++;
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

int		parse_flag_plus_and_digit(const char *format, va_list list, int i, struct p parsed)
{
	int res;
	int k;
	int count;
	res = 0;
	count = 2;
	k = 1;
	if (parsed.l == 1 || parsed.ll == 1)
	{
		parsed.l = 0;
		parsed.ll = 1;
		count = count_long(format, list, i, parsed);
		res = count_long_res(format, list, i, parsed);
		flag_plus_and_digit_long(format, list, res, parsed);
		flag_plus_and_digit_print_long(format, list, i, count);
		return (count);
	}
	while (format[i + count] >= 48 && format[i + count] <= 57)
	{
		res = res * 10;
		res = res + ((int)format[i + count] - '0');
		count++;
	}
	flag_plus_and_digit(format, list, res, parsed);
	flag_plus_and_digit_print(format, list, i, count);
	return (count);
}

//	-------------------------       flag plus_and_digit end       -----------------------------

//	==========================      flag plus begin     =============================

void    flag_plus_print(const char *format, va_list list, int i, int k)
{
	int number;

	number = va_arg(list, int);
	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (checksign(number) == 0)
		write(1, "+", 1);
	ft_putnbr(number);
}

void    flag_plus_print_long(const char *format, va_list list, int i, int k)
{
	long number;

	number = va_arg(list, long);
	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (checksign_long(number) == 0)
		write(1, "+", 1);
	ft_putnbr_long(number);
}

int		flag_plus(const char *format, va_list list, int i, struct p parsed)
{
	int k;
	k = 0;
	if (format[i + 1] == '+')	
	{
		if (format[i + 2] == 'd' || format[i + 2] == 'h' || format[i + 2] == 'i')
		{
			k++;
			flag_plus_print(format, list, i, k);
		}
		if (format[i + 2] == 'l')
		{
			k++;
			flag_plus_print_long(format, list, i, k);
		}
	}
	return (k);
}

//	-------------------------       flag plus end       -----------------------------

//	==========================      flag minus begin     =============================

int		print_flag_minus_corr(const char *format, va_list list, int res)
{
	int number;
	int size;
	number = 0;
	va_list cpy;
	va_copy(cpy, list);
	number = va_arg(cpy, int);
	size = 0;
	
	if (number < 0)
		number = number * (-1);
	if (number == 0)
		size++;
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

int		flag_minus(const char *format, va_list list, int i, struct p parsed)
{
	int res;
	if (format[i + 1] == '-' && (format[i + 2] == 'd' || format[i + 2] == 'h' || format[i + 2] == 'l' || format[i + 2] == 'i'))
	{
		
		handle_d_without_flags(format, list, i, parsed);
		res = print_flag_minus(format, list, i);
		while (res > 0)
		{
			write(1, " ", 1);
			res--;
		}
	}
	return (2);
}

//	-------------------------       flag minus end       -----------------------------

//	==========================      flag minus_and_digit begin     =============================

void    flag_minus_and_digit_print_d(const char *format, va_list list, int i, int number)
{
	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (number < 0)
	{	
		write(1, "-", 1);
		number = number * (-1);
	}
	ft_putnbr(number);
}

int		flag_minus_and_digit_cont_d(const char *format, va_list list, int res)
{
	int number;
	int size;
	size = 0;
	number = va_arg(list, int);
	if (number < 0)
	{
		size++;
	}
	if (number == 0)
		size++;
	flag_minus_and_digit_print_d(format, list, size, number);
	if (number < 0)
		number = number * (-1);
	while (number > 0)
	{
		size++;
		number = number / 10;
	}
	return (size);
}

void    flag_minus_and_digit_print_d_long(const char *format, va_list list, int i, long number)
{
	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (number < 0)
	{	
		write(1, "-", 1);
		number = number * (-1);
	}
	ft_putnbr_long(number);
}

int		flag_minus_and_digit_cont_d_long(const char *format, va_list list, int res)
{
	long number;
	int size;
	size = 0;
	number = va_arg(list, long);
	if (number < 0)
	{
		size++;
	}
	if (number == 0)
		size++;
	flag_minus_and_digit_print_d_long(format, list, size, number);
	if (number < 0)
		number = number * (-1);
	while (number > 0)
	{
		size++;
		number = number / 10;
	}
	return (size);
}

int		flag_minus_and_digit_d(const char *format, va_list list, int i, struct p parsed)
{
	int res;
	int k;
	int count;
	res = 0;
	count = 2;
	k = 1;
	if (parsed.l == 1 || parsed.ll == 1)
	{
		parsed.l = 0;
		parsed.ll = 0;
		count = count_long(format, list, i, parsed);
		res = count_long_res(format, list, i, parsed);
		res = res - flag_minus_and_digit_cont_d_long(format, list, res);
	}
	else
	{
		while (format[i + count] >= 48 && format[i + count] <= 57)
		{
			res = res * 10;
			res = res + ((int)format[i + count] - '0');
			count++;
		}
		res = res - flag_minus_and_digit_cont_d(format, list, res);
	}
	while (res > 0)
	{
		write(1, " ", 1);
		res--;
	}
	return (count);
}
//	-------------------------       flag minus_and_digit end       -----------------------------

//	==========================      flag zero begin     =============================
void		print_flags_zero_d(const char *format, va_list list, int res)
{
	int number;
	int number2;

	int size;
	size = 0;
	number = va_arg(list, int);
	number2 = number;
	if (number2 < 0)
	{	
		write(1, "-", 1);
		size = size + 2;
	}
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
	ft_putnbr(number2);
}

void		print_flags_zero_d_long(const char *format, va_list list, int res)
{
	long number;
	long number2;

	int size;
	size = 0;
	number = va_arg(list, long);
	number2 = number;
	if (number2 < 0)
	{	
		write(1, "-", 1);
		size = size + 2;
	}
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
	ft_putnbr_long(number2);
}

int		parse_flag_zero_d(const char *format, va_list list, int i, struct p parsed)
{
	int res;
	int k;
	int count;
	res = 0;
	count = 2;
	k = 1;
	if (parsed.l == 1 || parsed.ll == 1)
	{
		parsed.l = 0;
		parsed.ll = 0;
		count = count_long(format, list, i, parsed);
		res = count_long_res(format, list, i, parsed);
		print_flags_zero_d_long(format, list, res);
	}
	else
	{
		while (format[i + count] >= 48 && format[i + count] <= 57)
		{
			res = res * 10;
			res = res + ((int)format[i + count] - '0');
			count++;
		}
		print_flags_zero_d(format, list, res);
	}
	return (count);
}
//	-------------------------       flag zero end       -----------------------------
//	==========================      flag zero_and_digit begin     =============================
void		print_flags_zero_and_digit_d(const char *format, va_list list, int res)
{
	int number;
	int number2;

	int size;
	size = 0;
	number = va_arg(list, int);
	number2 = number;
	if (number < 0)
	{	
		write(1, "-", 1);
		size = size + 1;
		number = number * (-1);
	}
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
	if (number2 != 0)
		ft_putnbr(number2);
}

void		print_flags_zero_and_digit_d_long(const char *format, va_list list, int res)
{
	long number;
	long number2;

	int size;

	size = 0;
	number = va_arg(list, long);
	number2 = number;
	if (number < 0)
	{	
		write(1, "-", 1);
		size = size + 1;
		number = number * (-1);
	}
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
	if (number2 != 0)
		ft_putnbr_long(number2);
}


int		parse_flag_zero_and_digit_d(const char *format, va_list list, int i, struct p parsed)
{
	int res;
	int k;
	int count;
	res = 0;
	count = 2;
	k = 1;
	if (parsed.l == 1 || parsed.ll == 1)
	{
		parsed.l = 0;
		parsed.ll = 0;
		count = count_long(format, list, i, parsed);
		res = count_long_res(format, list, i, parsed);
		print_flags_zero_and_digit_d_long(format, list, res);
	}
	else
	{
		while (format[i + count] >= 48 && format[i + count] <= 57)
		{
			res = res * 10;
			res = res + ((int)format[i + count] - '0');
			count++;
		}
		print_flags_zero_and_digit_d(format, list, res);
	}
	return (count);
}
//	-------------------------       flag zero_and_digit end       -----------------------------

//	==========================      flag blank begin     =============================
void		print_flags_blank_wo_digits(const char *format, va_list list, int res)
{
	int number;
	number = va_arg(list, int);
	if (number < 0)
		write(1, "-", 1);
	else
		write(1, " ", 1);
	ft_putnbr(number);
}

void		print_flags_blank_wo_digits_long(const char *format, va_list list, int res)
{
	long number;
	number = va_arg(list, long);
	if (number < 0)
		write(1, "-", 1);
	else
		write(1, " ", 1);
	ft_putnbr_long(number);
}

int		flag_blank_d(const char *format, va_list list, int i, struct p parsed)
{
	int res;
	int k;
	int count;
	res = 0;
	count = 2;
	k = 1;
	if (parsed.l == 1 || parsed.ll == 1)
	{
		parsed.l = 0;
		parsed.ll = 0;
		count = count_long(format, list, i, parsed);
		res = count_long_res(format, list, i, parsed);
		print_flags_blank_wo_digits_long(format, list, res);
	}
	else
	{
		while (format[i + count] >= 48 && format[i + count] <= 57)
		{
			res = res * 10;
			res = res + ((int)format[i + count] - '0');
			count++;
		}
		print_flags_blank_wo_digits(format, list, res);
	}
	return (count);
}
//	-------------------------       flag blank end       -----------------------------

//	==========================      flag blank_and_digit begin     =============================
void		print_flags_blank(const char *format, va_list list, int res)
{
	int number;
	int number2;
	int number3;
	int size;
	size = 0;
	number = va_arg(list, int);
	number2 = number;
	number3 = number2;
	if (number < 0)
	{
		size = size + 2;
		number = number * (-1);
	}
	if (number == '0')
		size++;
	while (number > 0)
	{
		size++;
		number = number / 10;
	}
	res = res - size;
	if (res == 0)
		write(1, " ", 1);
	while (res > 0)
	{
		write(1, " ", 1);
		res--;
	}
	if (number3 < 0)
	{	
		write(1, " -", 2);
	}
	ft_putnbr(number2);
}

void		print_flags_blank_long(const char *format, va_list list, int res)
{
	long number;
	long number2;
	int size;
	size = 0;
	number = va_arg(list, long);
	number2 = number;
	if (number < 0)
	{	
		number = number * (-1);
	}
	if (number == '0')
		size++;
	while (number > 0)
	{
		size++;
		number = number / 10;
	}
	res = res - size;
	write(1, " ", 1);
	while (res > 0)
	{
		write(1, " ", 1);
		res--;
	}
	if (number2 < 0)
	{	
		number2 = number2 * (-1);
	}
	ft_putnbr_long(number2);
}

void	printf_flags_blank_and_zero_and_digit(const char *format, va_list list, int res, struct p parsed)
{
	int number;
	int number2;
	int size;
	size = 1;
	if (parsed.exception == 1)
	{	
		size = 0;
		parsed.exception = 0;
	}
	number = va_arg(list, int);
	number2 = number;
	if (number < 0)
	{
		number = number * (-1);
		size++;
		write(1, "-", 1);
	}
	else
	{
		write(1, " ", 1);
		size++;
	}
	while (number > 0)
	{
		size++;
		number = number / 10;
	}
	if (res == 0)
	{	
		write(1, " 0", 2);
		return ;
	}
	res = res - size;
	while (res > 0)
	{
		write(1, "0", 1);
		res--;
	}
	ft_putnbr(number2);
}

void	printf_flags_blank_and_zero_and_digit_long(const char *format, va_list list, int res, struct p parsed)
{
	long number;
	long number2;
	int size;
	size = 1;
	if (parsed.exception == 1)
	{
		size = 0;
		parsed.exception = 0;
	}
	number = va_arg(list, long);
	number2 = number;
	if (number < 0)
	{
		number = number * (-1);
		size++;
		write(1, "-", 1);
	}
	else
	{
		write(1, " ", 1);
		size++;
	}
	while (number > 0)
	{
		size++;
		number = number / 10;
	}
	if (res == 0)
	{	
		write(1, " 0", 2);
		return ;
	}
	res = res - size;
	while (res > 0)
	{
		write(1, "0", 1);
		res--;
	}
	ft_putnbr_long(number2);
}

void	print_flags_blanks_zero(const char *format, va_list list, int res)
{
	int number;
	int number2;
	int size;
	size = 1;
	number = va_arg(list, int);
	number2 = number;
	while (number > 0)
	{
		size++;
		number = number / 10;
	}
	res = res - size;
	if (number2 >= 0)
		write(1, " ", 1);
	else
		write(1, "-", 1);
	while (res > 0)
	{
		write(1, "0", 1);
		res--;
	}
	ft_putnbr(number2);
}

void	print_flags_blanks_zero_long(const char *format, va_list list, int res)
{
	long number;
	long number2;
	int size;
	size = 1;
	number = va_arg(list, long);
	number2 = number;
	while (number > 0)
	{
		size++;
		number = number / 10;
	}
	res = res - size;
	if (number2 >= 0)
		write(1, " ", 1);
	else
		write(1, "-", 1);
	while (res > 0)
	{
		write(1, "0", 1);
		res--;
	}
	ft_putnbr_long(number2);
}


int		flag_blank_and_digit_d(const char *format, va_list list, int i, struct p parsed)
{
	int res;
	int count;
	int zero;

	res = 0;
	count = 2;
	zero = 0;
	if (format[i + count] == '0')
		zero = 1;
	if (parsed.l == 1 || parsed.ll == 1)
	{
		parsed.l = 0;
		parsed.ll = 0;
		count = count_long(format, list, i, parsed);
		res = count_long_res(format, list, i, parsed);
		if (zero == 0)
			print_flags_blank_long(format, list, res);
		else if (zero == 1 && (format[i + 3] == 'd' || format[i + 3] == 'h' || format[i + 3] == 'l' || format[i + 3] == 'i'))
			print_flags_blanks_zero_long(format, list, res);
		else
			printf_flags_blank_and_zero_and_digit_long(format, list, res, parsed);
	}
	else
	{
		while (format[i + count] >= 48 && format[i + count] <= 57)
		{
			res = res * 10;
			res = res + ((int)format[i + count] - '0');
			count++;
		}
		if (zero == 0)
			print_flags_blank(format, list, res);
		else if (zero == 1 && (format[i + 3] == 'd' || format[i + 3] == 'h' || format[i + 3] == 'i'))
			print_flags_blanks_zero(format, list, res);
		else
			printf_flags_blank_and_zero_and_digit(format, list, res, parsed);
	}
	return (count);
}
//	-------------------------       flag blank_and_digit end       -----------------------------

// digit
void    flag_digit_print(const char *format, va_list list, int i, int k)
{
	int number;

	number = va_arg(list, int);
	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (checksign(number) < 0)
		write(1, "-", 1);
	ft_putnbr(number);
}

void    flag_digit_print_long(const char *format, va_list list, int i, int k)
{
	long number;

	number = va_arg(list, long);
	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (checksign_long(number) < 0)
		write(1, "-", 1);
	ft_putnbr_long(number);
}

void	flag_digit_cont(const char *format, va_list list, int res, struct p parsed)
{
	int number;
	int size;
	va_list cpy;
	va_copy(cpy, list);
	size = 0;
	number = va_arg(cpy, int);
	if (number < 0)
	{
		number = number * (-1);
		size++;
	}
	if (number == 0)
		size++;
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

void	flag_digit_long(const char *format, va_list list, int res, struct p parsed)
{
	long number;
	int size;
	va_list cpy;
	va_copy(cpy, list);
	size = 0;
	number = va_arg(cpy, long);
	if (number < 0)
	{
		number = number * (-1);
		size++;
	}
	if (number == 0)
		size++;
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

int		flag_digit(const char *format, va_list list, int i, struct p parsed)
{
	int res;
	int k;
	int count;
	res = 0;
	count = 1;
	k = 1;
	if (parsed.l == 1 || parsed.ll == 1)
	{
		parsed.l = 0;
		parsed.ll = 1;
		count = count_long(format, list, i, parsed);
		res = count_long_res(format, list, i, parsed);
		flag_digit_long(format, list, res, parsed);
		flag_digit_print_long(format, list, i, count);
		return (count);
	}
	while (format[i + count] >= 48 && format[i + count] <= 57)
	{
		res = res * 10;
		res = res + ((int)format[i + count] - '0');
		count++;
	}
	flag_digit_cont(format, list, res, parsed);
	flag_digit_print(format, list, i, count);
	return (count);
}
// end


//	field width

void    flag_field_width_print(const char *format, va_list list, int i, int k)
{
	int number;

	number = va_arg(list, int);
	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (checksign(number) < 0)
		write(1, "-", 1);
	ft_putnbr(number);
}

void    flag_field_width_print_long(const char *format, va_list list, int i, int k)
{
	long number;

	number = va_arg(list, long);
	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (checksign_long(number) < 0)
		write(1, "-", 1);
	ft_putnbr_long(number);
}

void	flag_field_width_cont(const char *format, va_list list, int res, struct p parsed)
{
	int number;
	int size;
	va_list cpy;
	va_copy(cpy, list);
	size = 0;
	number = va_arg(cpy, int);
	if (number < 0)
	{
		number = number * (-1);
		size++;
	}
	if (number == 0)
		size++;
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

void	flag_field_width_long(const char *format, va_list list, int res, struct p parsed)
{
	long number;
	int size;
	va_list cpy;
	va_copy(cpy, list);
	size = 0;
	number = va_arg(cpy, long);
	if (number < 0)
	{
		number = number * (-1);
		size++;
	}
	if (number == 0)
		size++;
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

int		flag_field_width(const char *format, va_list list, int i, struct p parsed)
{
	int res;
	int k;
	int count;
	int d;
	res = 0;
	count = 1;
	k = 1;
	if (parsed.l == 1 || parsed.ll == 1)
	{
		parsed.l = 0;
		parsed.ll = 1;
		count = count_long(format, list, i, parsed);
		res = count_long_res(format, list, i, parsed);
		flag_field_width_long(format, list, res, parsed);
		flag_field_width_print_long(format, list, i, count);
		return (count);
	}
	res = parsed.width_number;
	d = res;
	while (d / 10 != 0)
	{
		d = d/10;
		count++;
	}
	flag_field_width_cont(format, list, res, parsed);
	flag_field_width_print(format, list, i, count);
	return (count);
}

//	end

// field width and plus
void    flag_width_and_plus_print(const char *format, va_list list, int i, struct p parsed)
{
	int number;

	number = va_arg(list, int);
	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (checksign(number) == 0)
		write(1, "+", 1);
	ft_putnbr(number);
}

void    flag_width_and_plus_long_print(const char *format, va_list list, int i, int k)
{
	long number;

	number = va_arg(list, long);
	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (checksign_long(number) == 0)
		write(1, "+", 1);
	ft_putnbr_long(number);
}

void	flag__width_and_plus_blanks(const char *format, va_list list, int res, struct p parsed)
{
	int number;
	int size;
	va_list cpy;
	va_copy(cpy, list);
	size = 0;
	number = va_arg(cpy, int);
	if (number < 0)
	{
		number = number * (-1);
	}
	if (number == 0)
		size++;
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

void	flag_width_and_plus_long_blanks(const char *format, va_list list, int res, struct p parsed)
{
	long number;
	int size;
	va_list cpy;
	va_copy(cpy, list);
	size = 0;
	number = va_arg(cpy, long);
	if (number < 0)
	{
		number = number * (-1);
	}
	if (number == 0)
		size++;
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

int		flag_field_width_and_plus(const char *format, va_list list, int i, struct p parsed)
{
	int res;
	int k;
	int count;
	res = 0;
	count = 0;
	k = 1;
	int d;
	if (parsed.l == 1 || parsed.ll == 1)
	{
		parsed.l = 0;
		parsed.ll = 1;
		count = count_long(format, list, i, parsed);
		res = count_long_res(format, list, i, parsed);
		flag_width_and_plus_long_blanks(format, list, res, parsed);
		flag_width_and_plus_long_print(format, list, i, count);
		return (count);
	}
	res = parsed.width_number;
	d = res;
	while (d / 10 != 0)
	{
		d = d/10;
		count++;
	}
	flag__width_and_plus_blanks(format, list, parsed.width_number, parsed);
	flag_width_and_plus_print(format, list, i, parsed);
	parsed.width_number = 0;
	return (count);
}
// end width and plus

//	width minus and digit begin

int		flag_width_minus_and_digit_cont_d(const char *format, va_list list, int res)
{
	int number;
	int size;
	size = 0;
	number = va_arg(list, int);
	if (number < 0)
	{
		size++;
	}
	if (number == 0)
		size++;
	flag_minus_and_digit_print_d(format, list, size, number);
	if (number < 0)
		number = number * (-1);
	while (number > 0)
	{
		size++;
		number = number / 10;
	}
	return (size);
}


int		flag_field_width_and_minus(const char *format, va_list list, int i, struct p parsed)
{
	int res;
	int k;
	int count;
	res = 0;
	count = 0;
	k = 1;

	res = parsed.width_number - flag_width_minus_and_digit_cont_d(format, list, res);
	while (res > 0)
	{
		write(1, " ", 1);
		res--;
	}
	return (count);
}
// width minus and digit end

// width and zero begin
int		flag_field_width_and_zero(const char *format, va_list list, int i, struct p parsed)
{
	int res;
	int k;
	int count;
	res = 0;
	count = 0;
	k = 1;
	res = parsed.width_number;
	print_flags_zero_and_digit_d(format, list, res);
	return (count);
}
//	width and zero end

int		print_flags(const char *format, va_list list, int i, struct p parsed)
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
//	hash_and_minus_and_digit --- and --- minus_and_hash_and_digit
	if (parsed.hash_and_minus_and_digit == 1 || parsed.minus_and_hash_and_digit == 1)
	{
		count = flag_hash_and_minus_and_digit(format, list, i, parsed) + 2;
		parsed.hash_and_minus_and_digit = 0;
		parsed.minus_and_hash_and_digit = 0;
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

	return (count);
}


int		print_flags_more(const char *format, va_list list, int i, struct p parsed)
{
	int res;
	int count;
	count = 0;
//	field_width
	if (parsed.width == 1)
	{
		count = flag_field_width(format, list, i, parsed) - 2;
		parsed.width = 0;
	}
//	field_width_and plus
	if (parsed.width_and_plus == 1)
	{
		count = flag_field_width_and_plus(format, list, i, parsed);
		parsed.width_and_plus = 0;
	}
//	field_width_and minus
	if (parsed.width_and_minus == 1)
	{
		count = flag_field_width_and_minus(format, list, i, parsed);
		parsed.width_and_minus = 0;
	}

//	field_width_and zero
	if (parsed.width_and_zero == 1)
	{
		count = flag_field_width_and_zero(format, list, i, parsed);
		parsed.width_and_zero = 0;
	}

//	plus
	if (parsed.plus == 1)
	{
		count = flag_plus(format, list, i, parsed) + 1;
		parsed.plus = 0;
	}

//	plus_and_digit
	if (parsed.plus_and_digit == 1)
	{
		count = parse_flag_plus_and_digit(format, list, i, parsed);
		parsed.plus_and_digit = 0;
	}

// minus
	if (parsed.minus == 1)
	{
		count = flag_minus(format, list, i, parsed);
		parsed.minus = 0;
	}

// minus_and_digit
	if (parsed.minus_and_digit == 1)
	{
		count = flag_minus_and_digit_d(format, list, i, parsed);
		parsed.minus_and_digit = 0;
	}

//	zero
	if (parsed.zero == 1)
	{
		count = parse_flag_zero_d(format, list, i, parsed);
		parsed.zero = 0;
	}

//	zero_and_digit
	if (parsed.zero_and_digit == 1)
	{
		count = parse_flag_zero_and_digit_d(format, list, i, parsed);
		parsed.zero_and_digit = 0;
	}

//	blank
	if (parsed.blank == 1)
	{
		count = flag_blank_d(format, list, i, parsed);
		parsed.blank = 0;
	}

//	blank_and_digit
	if (parsed.blank_and_digit == 1)
	{
		count = flag_blank_and_digit_d(format, list, i, parsed);
		parsed.blank_and_digit = 0;
	}

//	digit
	if (parsed.digit == 1)
	{
		count = flag_digit(format, list, i, parsed);
		parsed.digit = 0;
	}

	return (count);
}

int		parse_arg_x_init(const char *format, va_list list, int i)
{
	int result;
	struct p parsed;
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
	else if (format[i + 1] == '0' && format[i + 2] == '#' && (format[i + 3] >= 48 && format[i + 3] <= 57))
		parsed.zero_and_hash_and_digit = 1;
	else if (format[i + 1] == '#' && (format[i + 2] >= 49 && format[i + 2] <= 57))
		parsed.hash_and_digit = 1;
	else if (format[i + 1] == '#' && format[i + 2] == '0' && (format[i + 3] >= 48 && format[i + 3] <= 57))
		parsed.hash_and_zero_and_digit = 1;
	else if (format[i + 1] == '#' && format[i + 2] == '-' && format[i + 3] == 'x')
		parsed.hash_and_minus = 1;
	else if (format[i + 1] == '#' && format[i + 2] == '-' && (format[i + 3] >= 48 && format[i + 3] <= 57))
		parsed.hash_and_minus_and_digit = 1;
	else if (format[i + 1] == '-' && format[i + 2] == '#' && format[i + 3] == 'x')
		parsed.minus_and_hash = 1;
	else if (format[i + 1] == '-' && (format[i + 2] >= 48 && format[i + 2] <= 57))
		parsed.minus_and_digit = 1;
	else if (format[i + 1] == '0' && (format[i + 2] >= 48 && format[i + 2] <= 57))
		parsed.zero_and_digit = 1;
	else if (format[i + 1] == '-' && format[i + 2] == '#' && (format[i + 3] >= 48 && format[i + 3] <= 57))
		parsed.minus_and_hash_and_digit = 1;
	else
	{
		handle_x(format, list);
		return (0);
	}
	result = print_flags(format, list, i, parsed);
	return (result);
}



// ========= d ========




int		handle_d(const char *format, va_list list, int i, struct p parsed)
{
	int result;
	parsed.plus = 0;
	parsed.plus_and_digit = 0;
	parsed.minus = 0;
	parsed.minus_and_digit = 0;
	parsed.zero = 0;
	parsed.zero_and_digit = 0;
	parsed.blank = 0;
	parsed.blank_and_digit = 0;
	parsed.width_and_minus = 0;
	parsed.width_and_zero = 0;
	parsed.width_and_plus = 0;
	parsed.width = 0;
	if (format[i + 1] == '+' && (format[i + 2] == 'd' || format[i + 2] == 'h' || format[i + 2] == 'l' || format[i + 2] == 'i'))
		parsed.plus = 1;
	else if (format[i + 1] == '+' && (format[i + 2] >= 48 && format[i + 2] <= 57))
		parsed.plus_and_digit = 1;
	else if (format[i + 1] == '-' && (format[i + 2] == 'd' || format[i + 2] == 'h' || format[i + 2] == 'l' || format[i + 2] == 'i'))
		parsed.minus = 1;
	else if (format[i + 1] == '-' && (format[i + 2] >= 48 && format[i + 2] <= 57))
		parsed.minus_and_digit = 1;
	else if (format[i + 1] == '0' && (format[i + 2] == 'd' || format[i + 2] == 'h' || format[i + 2] == 'l' || format[i + 2] == 'i'))
		parsed.zero = 1;
	else if (format[i + 1] == '0' && (format[i + 2] >= 48 && format[i + 2] <= 57))
		parsed.zero_and_digit = 1;
	else if (format[i + 1] == ' ' && (format[i + 2] == 'd' || format[i + 2] == 'h' || format[i + 2] == 'l' || format[i + 2] == 'i'))
		parsed.blank = 1;
	else if (format[i + 1] == ' ' && (format[i + 2] >= 48 && format[i + 2] <= 57))
		parsed.blank_and_digit = 1;
	else if (format[i + 1] >= 48 && format[i + 1] <= 57)
		parsed.digit = 1;
	else if (format[i] == '*' && (format[i - 1] != '+' && format[i - 1] != '-' && format[i - 1] != '0'))
		parsed.width = 1;
	else if (format[i - 1] == '+' && format[i] == '*')
		parsed.width_and_plus = 1;
	else if (format[i - 1] == '-' && format[i] == '*')
		parsed.width_and_minus = 1;
	else if (format[i - 1] == '0' && format[i] == '*')
		parsed.width_and_zero = 1;
	else
	{
		handle_d_without_flags(format, list, i, parsed);
		return (0);
	}
	result = print_flags_more(format, list, i, parsed);
	return (result);
}

// --------- d --------


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

char    parse_format_without_prec(const char *format, va_list list, int i)
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
    if (format[i] == 's')
        c = 115;
    else if (format[i] == 'd')
		c = 100;
    else if (format[i] == 'i' && format[i + 1] != '.')
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

struct	p flags_short_and_long(const char *format, va_list list, int i, struct p parsed_x)
{
	parsed_x.size = 0;
	parsed_x.precision = 0;
	parsed_x.string_precision = 0;
	parsed_x.width_and_zero = 0;
	parsed_x.width_and_minus = 0;
	parsed_x.width_and_plus = 0;
	parsed_x.width = 0; 
	parsed_x.l = 0;
	parsed_x.largel = 0;
	parsed_x.precision_zero = 0;
	parsed_x.precision = 0;
	parsed_x.precision_count = 0;
	parsed_x.res = 0;
	int tmp;
	tmp = 0;
	while (format[i] != 's' && format[i] != 'd' &&
		format[i] != 'i' && format[i] != 'c' &&
		format[i] != 'u' && format[i] != 'x' &&
		format[i] != 'X' && format[i] != 'o' &&
		format[i] != 'f' && format[i] != '%')
		{
			if (format[i] == 'h' && format[i + 1] != 'h')
			{	
				parsed_x.h = 1;
				parsed_x.size = 1;
			}
			if (format[i] == 'h' && format[i + 1] == 'h')
			{
				parsed_x.hh = 1;
				parsed_x.size = 2;
				parsed_x.exception = 1;
				return (parsed_x);
			}
			if (format[i] == 'l' && format[i + 1] != 'l')
			{	parsed_x.l = 1;
				parsed_x.size = 1;
			}
			if (format[i] == 'l' && format[i + 1] == 'l')
			{
				parsed_x.ll = 1;
				parsed_x.size = 2;
				parsed_x.exception = 1;
				return (parsed_x);
			}
			if (format[i] == 'L')
			{	
				parsed_x.largel = 1;
				parsed_x.size = 1;
			}
			if (format[i] == '.' && (format[i + 1] >= 48 && format[i + 1] <= 57))
			{
				if (format[i + 1] == '0')
					parsed_x.precision_zero = 1;
				parsed_x.precision = format[i + 1] - '0';
				parsed_x.precision_count = 2;
			}
			if (format[i] == '*' && !(format[i - 1] == '+' || format[i - 1] == '-' || format[i - 1] == '0'))
			{
				parsed_x.width = 1;
			}
			if (format[i - 1] == '+' && format[i] == '*')
			{	
				parsed_x.width_and_plus = 1;
				parsed_x.size = 1;
			}
			if (format[i - 1] == '-' && format[i] == '*')
			{	
				parsed_x.width_and_minus = 1;
				parsed_x.size = 1;
			}
			if (format[i - 1] == '0' && format[i] == '*')
			{	
				parsed_x.width_and_zero = 1;
				parsed_x.size = 1;
			}
			if (format[i] == '.' && format[i + 1] == '*' && format[i + 2] == 's')
				parsed_x.string_precision = 1;
		i++;
		}
	return (parsed_x);
}

int		handle_field_width(const char *format, va_list list, int i, struct p parsed_x)
{
	int number;
	number = va_arg(list, int);
	return (number);
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
    char ch;
	i = 0;
    d = 0;
    o = 0;
	va_start(list, format);
	struct p parsed_x;
	while (format[i] != '\0')
	{
        if (format[i] == '%')
		{
            ch = parse_format(format, list, (i + 1));
			parsed_x = flags_short_and_long(format, list, (i + 1), parsed_x);
			if (ch == '*')
			{
				parsed_x.width_number = handle_field_width(format, list, i, parsed_x);
				i = i + 1 + parsed_x.size;
				ch = parse_format_without_prec(format, list, (i + 1));
				parsed_x.size = 0;
			}
			if (ch == 's')
			{
				if (parsed_x.string_precision == 1)
				{
					handle_s_with_precision(format, list, parsed_x);
					i = i + 3;
					parsed_x.string_precision = 0;
				}
				else
				{	
					handle_s(format, list);
					i = i + 1;
				}
			}
    		if (ch == 'd' || ch == 'i')
			{
				d = handle_d(format, list, i, parsed_x);
				if (d == 0)
					d = 1;
				i = i + d + parsed_x.size;	
			}
			if (ch == 'c')
			{
				handle_c(format, list);
				i = i + 1;
			}
			if (ch == 'u')
			{
				handle_u(format, list, i);
				i = i + 1;
			}
			if (ch == 'x')
			{
				x = parse_arg_x_init(format, list, i);
				i = i + 1 + x;
			}
			if (ch == 'X')
			{
				handle_X(format, list);
				i = i + 1;
			}
			if (ch == 'o')
			{
				handle_o(format, list);
				i = i + 1 + o;
			}
			if (ch == 'f')
			{
				handle_f(format, list, parsed_x);
				i = i + 1 + parsed_x.l + parsed_x.largel + parsed_x.precision_count;
				// parsed_x.l = 0;
				// parsed_x.largel = 0;
				// parsed_x.precision_zero = 0;
				// parsed_x.precision = 0;
				// parsed_x.precision_count = 0;
				// parsed_x.res = 0;
			}
			if (ch == 88)
			{
				handle_hui(format, list, parsed_x);
				i = i + 3;
			}
			if (ch == '%')
			{
				write(1, "%", 1);
				i = i + 1;
			}
			if (format[i] == '\\' && format[i + 1] == 'n')
			{
				write(1, "\n", 1);
				i = i + 2;
			}
		}
		else
			write(1, &format[i], 1);
		parsed_x.width_number = 0;
		parsed_x.width = 0;
		i++;
	}
	va_end(list);
}

int main()
{
    const char *string;
	int number;
	number = 0;
	int number2;
	number2 = -1333;
    string = "John";
	const char *string2;
    string2 = "i am";
	char character;
	char character2;
	character = 'z';
	character2 = 'h';
	unsigned int unsignedint;
	unsigned int unsignedint2;
	unsignedint2 = 4294967295;
	unsignedint = -0;
	//int intx = -2147483648;
	//unsigned long long int intX = 18446744073709551615;
	int intx = 1;
	int intX = 14;
	int oct1 = 534;
	int oct2 = -134;
	float float1 = -1432420.14543;
	float float2 = -43.02109;
	float float3 = -1.54623;
	// float float1 = 0;
	// float float2 = 0;
	// float float3 = 0;
	int size;
	size = 10;
	short short1 = -21000;
	short short2 = 22000;
	long long1 = 9223372036854775807;
	long long llong1 = 9223372036854775807;
	long long llong2 = -9223372036854775806;
	long double ld1 = -1432423320.1435748649;
	long double ld2 = 43.0230;
	long double ld3 = 1.5462358;
	//long long1 = 9223372036854775806;
	long long2 = -922337203685477580;
    // printf("=====================\n");
    // printf("Printf output:\n");
  	// printf("String:\n");

//	printf("---> Hello %s %s %d end\n", string2, string, number);

	// printf("Integer d / i\n");
	// printf("---> Hello --- %i --- %i ---\n", number, number2);
	// printf("---> Hello --- %+i --- %+i --- %+i ---\n", number, number2, number);
	// printf("---> Hello --- %+6i --- %+10i --- %+16i ---\n", number, number2, number);
	// printf("---> Hello --- %-i --- %-i ---\n", number, number2);
	// printf("---> Hello --- %-7i --- %-14i ---\n", number, number2);
	// printf("---> Hello %0i %0i\n", number, number2);	
	// printf("---> Hello %010i %03i\n", number, number2);
	// printf("---> Hello % i % i\n", number, number2);
	// printf("---> Hello % 0i % 0i\n", number, number2);
	// printf("---> Hello % 05i % 02i\n", number, number2);
	// printf("---> Hello %+6hi %+10hi%+16hi\n", short1, short1, short2);
	// printf("---> Hello %+hi %+hi%+hi\n", short1, short1, short1);
	// printf("---> Hello %-hi %-hi\n", short1, short1);
	// printf("---> Hello --- %-7hi --- %-14hi ---\n", short1, short1);
	// printf("---> Hello %0hi %0hi\n ======= \n", short1, short1);
	// printf("---> Hello % 05hi % 02hi\n", short1, short1);
	// printf("---> Hello % hi\n", short1);
	// printf("---> Hello %+6hhi %+10hhi%+16hhi\n", character, character, character);
	// printf("---> Hello %+hhi %+hhi%+hhi\n", character, character, character);
	// printf("---> Hello %-hhi %-hhi\n", character, character);
	// printf("---> Hello --- %-7hhi --- %-14hhi ---\n", character, character);
	// printf("---> Hello %0hhi %0hhi\n", character, character);
	// printf("---> Hello %010hhi %03hhi\n", character, character);
	// printf("---> Hello % hhi % hhi\n", character, character);
	// printf("---> Hello % 0hhi % 0hhi\n", character, character);
	// printf("---> Hello % 015hhi % 025hhi\n", character, character);
	// printf("---> Hello % hhi", character);
	// printf("---> Hello %li %li %li\n", long1, long2, long1);
	// printf("---> Hello %+6li %+20li%+15li\n", long1, long2, long1);
	// printf("---> Hello %+li %+li%+li\n", long1, long2, long1);
	// printf("---> Hello %-li %-li\n", long1, long2);
	// printf("---> Hello --- %-7li --- %-14li ---\n", long1, long2);
	// printf("---> Hello %0li %0li\n", long1, long2);
	// printf("---> Hello %010li %03li\n", long1, long2);
	// printf("---> Hello % li % li\n", long1, long2);
	// printf("---> Hello % 0li % 0li\n", long1, long2);
	// printf("---> Hello % 05li % 020li\n", long1, long2);
	// printf("---> Hello % li\n", long1);
	// printf("---> Hello %li %li %li\n", long1, long1, long1);
	// printf("---> Hello %lli %lli %lli\n", llong1, llong2, llong1);
	// printf("---> Hello %+25lli %+28lli%+15lli\n", llong1, llong2, llong1);
	// printf("---> Hello %+lli %+lli%+lli\n", llong1, llong2, llong1);
	// printf("---> Hello %-lli %-lli\n", llong1, llong2);
	// printf("---> Hello --- %-20lli --- %-25lli ---\n", llong1, llong2);
	// printf("---> Hello %0lli %0lli\n", llong1, llong2);
	// printf("---> Hello %020lli %025lli\n", llong1, llong2);
	// printf("---> Hello % lli % lli\n", llong1, llong2);
	// printf("---> Hello % 0lli % 0lli\n", llong1, llong2);
	// printf("---> Hello % 025lli % 020lli\n", llong1, llong2);
	// printf("---> Hello % lli\n", llong1);
	// printf("---> Hello --- %*d --- %+*d --- %-*d --- %0*d ---\n ======================= \n", 10, number, 10, number, 30, number, 20, number);

	// printf("%.*s %.*s", 3, string, 2, string);
	// printf("\n");
	// ft_printf("%.*s %.*s\n", 3, string, 2, string);


	//ft_printf("---> Hello --- %i --- %i ---\n", number, number2);
	// ft_printf("---> Hello --- %+i --- %+i --- %+i ---\n", number, number2, number);
	// ft_printf("---> Hello --- %+6i --- %+10i --- %+16i ---\n", number, number2, number);
	// ft_printf("---> Hello --- %-i --- %-i ---\n", number, number2);
	// ft_printf("---> Hello --- %-7i --- %-14i ---\n", number, number2);
	// ft_printf("---> Hello %0i %0i\n", number, number2);	
	// ft_printf("---> Hello %010i %03i\n", number, number2);
	// ft_printf("---> Hello % i % i\n", number, number2);
	// ft_printf("---> Hello % 0i % 0i\n", number, number2);
	// ft_printf("---> Hello % 05i % 02i\n", number, number2);
	// ft_printf("---> Hello %+6hi %+10hi%+16hi\n", short1, short1, short2);
	// ft_printf("---> Hello %+hi %+hi%+hi\n", short1, short1, short1);
	// ft_printf("---> Hello %-hi %-hi\n", short1, short1);
	// ft_printf("---> Hello --- %-7hi --- %-14hi ---\n", short1, short1);
	// ft_printf("---> Hello %0hi %0hi\n", short1, short1);
	// ft_printf("---> Hello % 05hi % 02hi\n", short1, short1);
	// ft_printf("---> Hello % hi\n", short1);
	// ft_printf("---> Hello %+6hhi %+10hhi%+16hhi\n", character, character, character);
	// ft_printf("---> Hello %+hhi %+hhi%+hhi\n", character, character, character);
	// ft_printf("---> Hello %-hhi %-hhi\n", character, character);
	// ft_printf("---> Hello --- %-7hhi --- %-14hhi ---\n", character, character);
	// ft_printf("---> Hello %0hhi %0hhi\n", character, character);
	// ft_printf("---> Hello %010hhi %03hhi\n", character, character);
	// ft_printf("---> Hello % hhi % hhi\n", character, character);
	// ft_printf("---> Hello % 0hhi % 0hhi\n", character, character);
	// ft_printf("---> Hello % 015hhi % 025hhi\n", character, character);
	// ft_printf("---> Hello % hhi", character);
	// ft_printf("---> Hello %li %li %li\n", long1, long2, long1);
	// ft_printf("---> Hello %+6li %+20li%+15li\n", long1, long2, long1);
	// ft_printf("---> Hello %+li %+li%+li\n", long1, long2, long1);
	// ft_printf("---> Hello %-li %-li\n", long1, long2);
	// ft_printf("---> Hello --- %-7li --- %-14li ---\n", long1, long2);
	// ft_printf("---> Hello %0li %0li\n", long1, long2);
	// ft_printf("---> Hello %010li %03li\n", long1, long2);
	// ft_printf("---> Hello % li % li\n", long1, long2);
	// ft_printf("---> Hello % 0li % 0li\n", long1, long2);
	// ft_printf("---> Hello % 05li % 020li\n", long1, long2);
	// ft_printf("---> Hello % li\n", long1);
	// ft_printf("---> Hello %li %li %li\n", long1, long1, long1);
	// ft_printf("---> Hello %lli %lli %lli\n", llong1, llong2, llong1);
	// ft_printf("---> Hello %+25lli %+28lli%+15lli\n", llong1, llong2, llong1);
	// ft_printf("---> Hello %+lli %+lli%+lli\n", llong1, llong2, llong1);
	// ft_printf("---> Hello %-lli %-lli\n", llong1, llong2);
	// ft_printf("---> Hello --- %-20lli --- %-25lli ---\n", llong1, llong2);
	// ft_printf("---> Hello %0lli %0lli\n", llong1, llong2);
	// ft_printf("---> Hello %020lli %025lli\n", llong1, llong2);
	// ft_printf("---> Hello % lli % lli\n", llong1, llong2);
	// ft_printf("---> Hello % 0lli % 0lli\n", llong1, llong2);
	// ft_printf("---> Hello % 025lli % 020lli\n", llong1, llong2);
	// ft_printf("---> Hello % lli\n", llong1);
	// ft_printf("---> Hello --- %*d --- %+*i --- %-*i --- %0*i ---\n", 10, number, 10, number, 30, number, 20, number);
	// ft_printf ("=====");
	//ft_printf("%.i. %s", size, string);

	//printf("---> Hello --- % i --- % 8i ---\n", oct1, oct2);
	// printf("---> Hello --- %i --- %+i --- %+i ---\n", oct1, oct2, oct1);
	// printf("---> Hello --- %+6i --- %+10i --- %+16i ---\n", oct1, oct2, oct1);
	// printf("---> Hello --- %-i --- %-i ---\n", oct1, oct2);
	// printf("---> Hello --- %-7i --- %-14i ---\n", oct1, oct2);
	// printf("---> Hello %0i %0i\n", oct1, oct2);	
	// printf("---> Hello %010i %03i\n", oct1, oct2);
	// printf("---> Hello % i % i\n", oct1, oct2);
	// printf("---> Hello % 0i % 0i\n", oct1, oct2);
	// printf("---> Hello % 05i % 02i\n", number, number2);
	// printf("---> Hello %+6hi %+10hi%+16hi\n", short1, short1, short2);
	// printf("---> Hello %+hi %+hi%+hi\n", short1, short1, short1);
	// printf("---> Hello %-hi %-hi\n", short1, short1);
	// printf("---> Hello --- %-7hi --- %-14hi ---\n", short1, short1);
	// printf("---> Hello %0hi %0hi\n ======= \n", short1, short1);
	// printf("---> Hello % 05hi % 02hi\n", short1, short1);
	// printf("---> Hello % hi\n", short1);
	// printf("---> Hello %+6hhi %+10hhi%+16hhi\n", character, character, character);
	// printf("---> Hello %+hhi %+hhi%+hhi\n", character, character, character);
	// printf("---> Hello %-hhi %-hhi\n", character, character);
	// printf("---> Hello --- %-7hhi --- %-14hhi ---\n", character, character);
	// printf("---> Hello %0hhi %0hhi\n", character, character);
	// printf("---> Hello %010hhi %03hhi\n", character, character);
	// printf("---> Hello % hhi % hhi\n", character, character);
	// printf("---> Hello % 0hhi % 0hhi\n", character, character);
	// printf("---> Hello % 015hhi % 025hhi\n", character, character);
	// printf("---> Hello % hhi", character);
	// printf("---> Hello %li %li %li\n", long1, long2, long1);
	// printf("---> Hello %+6li %+20li%+15li\n", long1, long2, long1);
	// printf("---> Hello %+li %+li%+li\n", long1, long2, long1);
	// printf("---> Hello %-li %-li\n", long1, long2);
	// printf("---> Hello --- %-7li --- %-14li ---\n", long1, long2);
	// printf("---> Hello %0li %0li\n", long1, long2);
	// printf("---> Hello %010li %03li\n", long1, long2);
	// printf("---> Hello % li % li\n", long1, long2);
	// printf("---> Hello % 0li % 0li\n", long1, long2);
	// printf("---> Hello % 05li % 020li\n", long1, long2);
	// printf("---> Hello % li\n", long1);
	// printf("---> Hello %li %li %li\n", long1, long1, long1);
	// printf("---> Hello %lli %lli %lli\n", llong1, llong2, llong1);
	// printf("---> Hello %+25lli %+28lli%+15lli\n", llong1, llong2, llong1);
	// printf("---> Hello %+lli %+lli%+lli\n", llong1, llong2, llong1);
	// printf("---> Hello %-lli %-lli\n", llong1, llong2);
	// printf("---> Hello --- %-20lli --- %-25lli ---\n", llong1, llong2);
	// printf("---> Hello %0lli %0lli\n", llong1, llong2);
	// printf("---> Hello %020lli %025lli\n", llong1, llong2);
	// printf("---> Hello % lli % lli\n", llong1, llong2);
	// printf("---> Hello % 0lli % 0lli\n", llong1, llong2);
	// printf("---> Hello % 025lli % 020lli\n", llong1, llong2);
	// printf("---> Hello % lli\n", llong1);

	//ft_printf("---> Hello --- % i --- % 8i ---\n", oct1, oct2);
	// ft_printf("---> Hello --- %+i --- %+i --- %+i ---\n", oct1, oct2, oct1);
	// ft_printf("---> Hello --- %+6i --- %+10i --- %+16i ---\n", oct1, oct2, oct1);
	// ft_printf("---> Hello --- %-i --- %-i ---\n", oct1, oct2);
	// ft_printf("---> Hello --- %-7i --- %-14i ---\n", oct1, oct2);
	// ft_printf("---> Hello %0i %0i\n", oct1, oct2);	
	// ft_printf("---> Hello %010i %03i\n", oct1, oct2);
	// ft_printf("---> Hello % i % i\n", oct1, oct2);
	// ft_printf("---> Hello % 0i % 0i\n", oct1, oct2);
	// ft_printf("---> Hello % 05i % 02i\n", number, number2);
	// ft_printf("---> Hello %+6hi %+10hi%+16hi\n", short1, short1, short2);
	// ft_printf("---> Hello %+hi %+hi%+hi\n", short1, short1, short1);
	// ft_printf("---> Hello %-hi %-hi\n", short1, short1);
	// ft_printf("---> Hello --- %-7hi --- %-14hi ---\n", short1, short1);
	// ft_printf("---> Hello %0hi %0hi\n", short1, short1);
	// ft_printf("---> Hello % 05hi % 02hi\n", short1, short1);
	// ft_printf("---> Hello % hi\n", short1);
	// ft_printf("---> Hello %+6hhi %+10hhi%+16hhi\n", character, character, character);
	// ft_printf("---> Hello %+hhi %+hhi%+hhi\n", character, character, character);
	// ft_printf("---> Hello %-hhi %-hhi\n", character, character);
	// ft_printf("---> Hello --- %-7hhi --- %-14hhi ---\n", character, character);
	// ft_printf("---> Hello %0hhi %0hhi\n", character, character);
	// ft_printf("---> Hello %010hhi %03hhi\n", character, character);
	// ft_printf("---> Hello % hhi % hhi\n", character, character);
	// ft_printf("---> Hello % 0hhi % 0hhi\n", character, character);
	// ft_printf("---> Hello % 015hhi % 025hhi\n", character, character);
	// ft_printf("---> Hello % hhi", character);
	// ft_printf("---> Hello %li %li %li\n", long1, long2, long1);
	// ft_printf("---> Hello %+6li %+20li%+15li\n", long1, long2, long1);
	// ft_printf("---> Hello %+li %+li%+li\n", long1, long2, long1);
	// ft_printf("---> Hello %-li %-li\n", long1, long2);
	// ft_printf("---> Hello --- %-7li --- %-14li ---\n", long1, long2);
	// ft_printf("---> Hello %0li %0li\n", long1, long2);
	// ft_printf("---> Hello %010li %03li\n", long1, long2);
	// ft_printf("---> Hello % li % li\n", long1, long2);
	// ft_printf("---> Hello % 0li % 0li\n", long1, long2);
	// ft_printf("---> Hello % 05li % 020li\n", long1, long2);
	// ft_printf("---> Hello % li\n", long1);
	// ft_printf("---> Hello %li %li %li\n", long1, long1, long1);
	// ft_printf("---> Hello %lli %lli %lli\n", llong1, llong2, llong1);
	// ft_printf("---> Hello %+25lli %+28lli%+15lli\n", llong1, llong2, llong1);
	// ft_printf("---> Hello %+lli %+lli%+lli\n", llong1, llong2, llong1);
	// ft_printf("---> Hello %-lli %-lli\n", llong1, llong2);
	// ft_printf("---> Hello --- %-20lli --- %-25lli ---\n", llong1, llong2);
	// ft_printf("---> Hello %0lli %0lli\n", llong1, llong2);
	// ft_printf("---> Hello %020lli %025lli\n", llong1, llong2);
	// ft_printf("---> Hello % lli % lli\n", llong1, llong2);
	// ft_printf("---> Hello % 0lli % 0lli\n", llong1, llong2);
	// ft_printf("---> Hello % 025lli % 020lli\n", llong1, llong2);
	// ft_printf("---> Hello % lli\n", llong1);




	// printf("Char\n");
	// printf("---> Hello %c %c\n", character, character2);

	// printf("Unsigned int output u\n");
	// printf("---> Hello %u %u\n", unsignedint, unsignedint2);

	// printf("x, X\n");
	// printf("---> Hello %x %X\n", intx, intX);

	// printf("Octal\n");
	// printf("---> Hello %o %o\n", oct1, oct2);

	// printf("Float\n");
//	printf("---> Hello %f %f %f\n", float1, float2, float3);
/*	
	// printf("FLAGS: plus +6 +10\n");
	 printf("---> Hello %+6d %+10d%+16d\n", number, number2, number);

	// printf("FLAGS: plus +6 +10\n");
	 printf("---> Hello %+d %+d%+d\n", number, number2, number);

	// printf("FLAGS: minus -6 -10\n");
	  printf("---> Hello %-d %-d\n", number, number2);
	printf("---> Hello --- %-7d --- %-14d ---\n", number, number2);

	// // printf("FLAGS: 0\n");
	printf("---> Hello %0d %0d\n", number, number2);

	printf("---> Hello %010d %03d\n", number, number2);
	// // printf("FLAGS: blank\n");
	printf("---> Hello % d % d\n", number, number2);

	printf("---> Hello % 0d % 0d\n", number, number2);

	printf("---> Hello % 05d % 02d\n", number, number2);

	printf("---> Hello % d", number);
*/	// printf("FLAGS: #\n");
	// printf("---> Hello %+6hd %+10hd%+16hd\n", short1, short1, short2);

	// // printf("FLAGS: plus +6 +10\n");
	// printf("---> Hello %+hd %+hd%+hd\n", short1, short1, short1);

	// // printf("FLAGS: minus -6 -10\n");
	// printf("---> Hello %-hd %-hd\n", short1, short1);
	// ft_printf("---> Hello --- %-7hd --- %-14hd ---\n", short1, short1);

	// // // printf("FLAGS: 0\n");
	// printf("---> Hello %0hd %0hd\n", short1, short1);

	// printf("---> Hello %010hd %03hd\n", short1, short1);
	// // // printf("FLAGS: blank\n");
	// printf("---> Hello % hd % hd\n", short1, short1);

	// printf("---> Hello % 0hd % 0hd\n", short1, short1);

	//printf("---> Hello % 05hd % 02hd\n", short1, short1);

	// printf("---> Hello % hd\n", short1);

	// printf("---> Hello %+6hhd %+10hhd%+16hhd\n", character, character, character);

	// // printf("FLAGS: plus +6 +10\n");
	// printf("---> Hello %+hhd %+hhd%+hhd\n", character, character, character);

	// // printf("FLAGS: minus -6 -10\n");
	// printf("---> Hello %-hhd %-hhd\n", character, character);
	// printf("---> Hello --- %-7hhd --- %-14hhd ---\n", character, character);

	// // // printf("FLAGS: 0\n");
	// printf("---> Hello %0hhd %0hhd\n", character, character);

	// printf("---> Hello %010hhd %03hhd\n", character, character);
	// // // printf("FLAGS: blank\n");
	// printf("---> Hello % hhd % hhd\n", character, character);

	// printf("---> Hello % 0hhd % 0hhd\n", character, character);

	// printf("---> Hello % 015hhd % 025hhd\n", character, character);

	// printf("---> Hello % hhd", character);
	// printf("---> Hello %ld %ld %ld\n", long1, long2, long1);
	// printf("---> Hello %+6ld %+20ld%+15ld\n", long1, long2, long1);
	// printf("---> Hello %+ld %+ld%+ld\n", long1, long2, long1);
	// printf("---> Hello %-ld %-ld\n", long1, long2);
	// printf("---> Hello --- %-7ld --- %-14ld ---\n", long1, long2);
	// printf("---> Hello %0ld %0ld\n", long1, long2);
	// printf("---> Hello %010ld %03ld\n", long1, long2);
	// printf("---> Hello % ld % ld\n", long1, long2);
	// printf("---> Hello % 0ld % 0ld\n", long1, long2);
	// printf("---> Hello % 05ld % 020ld\n", long1, long2);
	// printf("---> Hello % ld\n", long1);
	
	//printf("---> Hello %ld %ld %ld\n", long1, long1, long1);
	// printf("---> Hello %lld %lld %lld\n", llong1, llong2, llong1);
	// printf("---> Hello %+25lld %+28lld%+15lld\n", llong1, llong2, llong1);
	// printf("---> Hello %+lld %+lld%+lld\n", llong1, llong2, llong1);
	// printf("---> Hello %-lld %-lld\n", llong1, llong2);
	// printf("---> Hello --- %-20lld --- %-25lld ---\n", llong1, llong2);
	// printf("---> Hello %0lld %0lld\n", llong1, llong2);
	// printf("---> Hello %020lld %025lld\n", llong1, llong2);
	// printf("---> Hello % lld % lld\n", llong1, llong2);
	// printf("---> Hello % 0lld % 0lld\n", llong1, llong2);
	// printf("---> Hello % 025lld % 020lld\n", llong1, llong2);
	// printf("---> Hello % lld\n", llong1);

//	printf("---> Hello --- %*d --- %*d --- %*d ---\n", 10, number, 30, number, 20, number);
// 	printf("---> Hello %lf %lf %lf\n", float1, float2, float3);
// 	printf("---> Hello %Lf %Lf %Lf\n", ld1, ld2, ld3);
// //
// 	printf("---> Hello %.9f %.0f %.8f\n", float1, float2, float3);
	printf("---> Hello %f %f %f\n", float1, float2, float3);

printf("===");
//	printf("---> Hello %#x xxxx %#0x xxxx 1 %0#x xxxx %#010x xxxx %#10x xxxx %#-x xxxx %#-10x xxxx %-#x xxxx 1 %-#10x xxxx %-10x xxxx %10x xxxx %010x \n", intx, intx, intx, intx, intx, intx, intx, intx, intx, intx, intx, intx);
//	printf("---> Hello %015x xxxx %-7x xxxx 1 %-#7x xxxx %#-7x xxxx %#07x xxxx %#09x xxxx %020x xxxx %-20x xxxx 1 %#020x xxxx %-#20x xxxx %#-20x xxxx %x xxxx %x\n", intx, intx, intx, intx, intx, intx, intx, intx, intx, intx, intx, intx, intx);
// //                 099999999999
//	printf("Percent \n");
//	printf("---> Hello %% and %%\n");
//	printf("---> Hello %d %d\n", short1, short2);
//	printf("---> Hello %hi %hi\n", short1, short2);
    // printf("\n===================\n\n");
    // printf("ft_printf output:\n");
	// printf("---> Hello --- % 012hd --- % 08hd ---\n", short1, short2);
//	ft_printf("String\n");
//	ft_printf("---> Hello %s %s %d end\n", string2, string, number);
	
//	ft_printf("Integer d / i\n");
//	ft_printf("---> Hello %d %i\n", number, number2);
	
	// ft_printf("Char\n");
	// ft_printf("---> Hello %c %c\n", character, character2);
/* 	
	ft_printf("Unsigned int\n");
	ft_printf("---> Hello %u %u\n", unsignedint, unsignedint2);

	ft_printf("x, X\n");
	ft_printf("---> Hello %x %X\n", intx, intX);

	ft_printf("Octal\n");
	ft_printf("---> Hello %o %o\n", oct1, oct2);

	ft_printf("Float\n");
	ft_printf("---> Hello %f %f %f\n", float1, float2, float3);
	// ft_printf("FLAGS: plus +6 +10\n");
	ft_printf("---> Hello %+6d %+10d%+16d\n", number, number2, number);

	// ft_printf("FLAGS: plus +6 +10\n");
	ft_printf("---> Hello %+d %+d%+d\n", number, number2, number);

	// // ft_printf("FLAGS: minus -6 -10\n");
	ft_printf("---> Hello %-d %-d\n", number, number2);
	ft_printf("---> Hello --- %-7d --- %-14d ---\n", number, number2);
	// // ft_printf("FLAGS: 0\n");
	ft_printf("---> Hello %0d %0d\n", number, number2);
	ft_printf("---> Hello %010d %03d\n", number, number2);
	// // ft_printf("FLAGS: blank\n");
	ft_printf("---> Hello % d % d\n", number, number2);
	ft_printf("---> Hello % 0d % 0d\n", number, number2);
*///	ft_printf("---> Hello %hd %d\n", short1, short2);
	// ft_printf("---> Hello %+6hd %+10hd%+16hd\n", short1, short1, short2);

	// // printf("FLAGS: plus +6 +10\n");
	// ft_printf("---> Hello %+hd %+hd%+hd\n", short1, short1, short1);

	// // printf("FLAGS: minus -6 -10\n");
	// ft_printf("---> Hello %-hd %-hd\n", short1, short1);
	// ft_printf("---> Hello --- %-7hd --- %-14hd ---\n", short1, short1);

	// // // printf("FLAGS: 0\n");
	// ft_printf("---> Hello %0hd %0hd\n", short1, short1);

	// ft_printf("---> Hello %010hd %03hd\n", short1, short1);
	// // // printf("FLAGS: blank\n");
	// ft_printf("---> Hello % hd % hd\n", short1, short1);

	// ft_printf("---> Hello % 0hd % 0hd\n", short1, short1);

	// ft_printf("---> Hello % 05hd % 02hd\n", short1, short1);

	// ft_printf("---> Hello % hd\n", short1);
	// ft_printf("---> Hello %+6hhd %+10hhd%+16hhd\n", character, character, character);

	// // printf("FLAGS: plus +6 +10\n");
	// ft_printf("---> Hello %+hhd %+hhd%+hhd\n", character, character, character);

	// // printf("FLAGS: minus -6 -10\n");
	// ft_printf("---> Hello %-hhd %-hhd\n", character, character);
	// ft_printf("---> Hello --- %-7hhd --- %-14hhd ---\n", character, character);

	// // // printf("FLAGS: 0\n");
	// ft_printf("---> Hello %0hhd %0hhd\n", character, character);

	// ft_printf("---> Hello %010hhd %03hhd\n", character, character);
	// // // printf("FLAGS: blank\n");
	// ft_printf("---> Hello % hhd % hhd\n", character, character);

	// ft_printf("---> Hello % 0hhd % 0hhd\n", character, character);

	// ft_printf("---> Hello % 015hhd % 025hhd\n", character, character);

	// ft_printf("---> Hello % hhd\n", character);

	// ft_printf("---> Hello %ld %ld %ld\n", long1, long2, long1);
	// ft_printf("---> Hello %+6ld %+20ld%+15ld\n", long1, long2, long1);
	// ft_printf("---> Hello %+ld %+ld%+ld\n", long1, long2, long1);
	// ft_printf("---> Hello %-ld %-ld\n", long1, long2);
	// ft_printf("---> Hello --- %-7ld --- %-14ld ---\n", long1, long2);
	// ft_printf("---> Hello %0ld %0ld\n", long1, long2);
	// ft_printf("---> Hello %010ld %03ld\n", long1, long2);
	// ft_printf("---> Hello % ld % ld\n", long1, long2);
	// ft_printf("---> Hello % 0ld % 0ld\n", long1, long2);
	// ft_printf("---> Hello % 05ld % 020ld\n", long1, long2);
	// ft_printf("---> Hello % ld\n", long1);

	// ft_printf("---> Hello %lld %lld %lld\n", llong1, llong2, llong1);
	// ft_printf("---> Hello %+25lld %+28lld%+15lld\n", llong1, llong2, llong1);
	// ft_printf("---> Hello %+lld %+lld%+lld\n", llong1, llong2, llong1);
	// ft_printf("---> Hello %-lld %-lld\n", llong1, llong2);
	// ft_printf("---> Hello --- %-20lld --- %-25lld ---\n", llong1, llong2);
	// ft_printf("---> Hello %0lld %0lld\n", llong1, llong2);
	// ft_printf("---> Hello %020lld %025lld\n", llong1, llong2);
	// ft_printf("---> Hello % lld % lld\n", llong1, llong2);
	// ft_printf("---> Hello % 0lld % 0lld\n", llong1, llong2);
	// ft_printf("---> Hello % 025lld % 020lld\n", llong1, llong2);
	// ft_printf("---> Hello % lld\n", llong1);

	// ft_printf("---> Hello %lf %lf %lf\n", float1, float2, float3);
	// ft_printf("---> Hello %Lf %Lf %Lf\n", ld1, ld2, ld3);

	// ft_printf("---> Hello %.9f %.0f %.8f\n", float1, float2, float3);
	ft_printf("---> Hello %f %f %f\n", float1, float2, float3);


	// ft_printf("---> Hello %lf %lf %lf\n", float1, float2, float3);
	// ft_printf("---> Hello %Lf %Lf %Lf\n", ld1, ld2, ld3);
//	ft_printf("FLAGS: #\n");
//	ft_printf("---> Hello --- %#x --- %#2147111111x --- %0#x --- %0#12x --- %#1x --- %#01x --- %#-x --- %#-1x --- %-#x --- %-1x --- %01x --- %-#1x ---", intx, intx, intx, intx, intx, intx, intx, intx, intx ,intx, intx, intx);
// 	printf("\n");
// 	ft_printf("---> Hello %015x xxxx %-7x xxxx 1 %-#7x xxxx %#-7x xxxx %#07x xxxx %#09x xxxx %020x xxxx %-20x xxxx 1 %#020x xxxx %-#20x xxxx %#-20x xxxx %x xxxx %x\n", intx, intx, intx, intx, intx, intx, intx, intx, intx, intx, intx, intx, intx);

//	ft_printf("Percent \n");
//	ft_printf("---> Hello %% and %%%%\n");

	//ft_printf("---> Hello --- %*d --- %10d --- %*d ---\n", 10, number, number, 20, number);
	//   printf("\n---> Hello --- %010d --- %02d --- %020d ---\n", number, number, number);
	 //  printf("---> Hello --- %+10d --- %+2d --- %+20d ---\n", number, number, number);
	//  printf("---> Hello --- %-10i --- %-2i --- %-20i ---\n", number, number, number);
	// //	 printf("\n---> Hello --- %0*d --- %0*d --- %0*d ---\n", 10, number, 2, number, 20, number);
	//  //  printf("---> Hello --- %+*d --- %+*d --- %+*d ---\n", 10, number, 2, number, 20, number);
	//    printf("---> Hello --- %-*i --- %-*i --- %-*i ---\n", 10, number, 2, number, 20, number);
	//  //  ft_printf("---> Hello --- %0*d --- %0*d --- %0*d ---\n", 10, number, 2, number, 20, number);
	//   //	ft_printf("---> Hello --- %+*d --- %+*d --- %+*d ---\n", 10, number, 2, number, 20, number);
	//    ft_printf("---> Hello --- %-*i --- %-*i --- %-*i ---\n", 10, number, 2, number, 20, number);
    return (0);
}
