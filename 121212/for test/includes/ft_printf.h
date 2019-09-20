/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartyn- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:53:15 by jmartyn-          #+#    #+#             */
/*   Updated: 2019/09/14 17:53:18 by jmartyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>

# include "../libft/libft.h"

// typedef struct p
// {
// 	int precision_zero;
// 	int res;
// 	int size;
// 	int hash_only;
// 	int hash_and_zero;
// 	int zero_and_hash;
// 	int zero_and_hash_and_digit;
// 	int hash_and_digit;
// 	int hash_and_zero_and_digit;
// 	int hash_and_minus;
// 	int hash_and_minus_and_digit;
// 	int minus_and_hash;
// 	int minus_and_digit;
// 	int zero_and_digit;
// 	int minus_and_hash_and_digit;
// 	int	plus;
// 	int	plus_and_digit;
// 	int	minus;
// 	int zero;
// 	int	blank;
// 	int	blank_and_digit; 
// 	int h;
// 	int hh;
// 	int l;
// 	int ll;
// 	int largel;
// 	int exception;
// 	int precision;
// 	int precision_count;
// 	int width;
// 	int width_number;
// 	int digit;
// 	int width_and_plus;
// 	int width_and_minus;
// 	int width_and_zero;
// 	int string_precision;
// 	int ret;
// 	int	result;
// } structp_x;

typedef struct f
{
	long long int length;
	long long int length2;
	long long int number;
	long long int i;
	long long int position;
	long long int sign;
	long double number2;
	long double number3;
	long double f;
	char *r;
	char *str;
	char *test;
	int len;
	int p;
	int k;
} structf_x;

long	handle_negative_x(long decimal);
struct	p handle_x_continue(int j, int i, char *hexadecimal, struct p parsed);
struct	p handle_x(const char *format, va_list list, struct p parsed);
void	handle_hui(const char *format, va_list list, struct p parsed);
struct 	p	handle_bigx_continue(int j, int i, char *hexadecimal, struct p parsed);
struct	p	handle_bigx(const char *format, va_list list, struct p parsed);
int		handle_c(const char *format, va_list list);
int     handle_o_decimal_zero(long decimal);
void	handle_o(const char *format, va_list list);
void	handle_u(const char *format, va_list list, int i);
int 	handle_s(const char *format, va_list list, struct p parsed);
int	    handle_s_precision(const char *format, va_list list, int len, struct p parsed);
int		handle_s_w_prec(const char *format, va_list list, struct p parsed);
int     n_tu(int number, int count);
struct	f innitiaize_struct_float(struct f f_nums);
struct  f float_tenth_len(struct f f_nums);
struct  f float_decimal_len(struct f f_nums);
struct  f float_dot(struct f f_nums);
struct  f float_count_last(struct f f_nums);
struct  f float_count_precision(struct f f_nums, struct p parsed);
struct  f float_print(struct f f_nums, struct p parsed);
struct  f float_print_zeros(struct f f_nums);
void	handle_fl(const char *format, va_list list, struct p pa, struct f fn);
void	handle_f(const char *format, va_list list, struct p par);
int		ft_numlen(int n);
int		flag_count_res(const char *format, int i);
int		count_long(const char *format, va_list list, int i, struct p parsed);
int		count_long_res(const char *format, va_list list, int i, struct p parsed);
int		flag_count_size(const char *format, va_list list, struct p parsed);
void	handle_x_continue_blanks(int j, int i, char *hexadecimal);
void	flag_hash_only_print_blanks_continue_more(int j, int i, char *hexadecimal);
void	flag_hash_only_print_blanks_continue(const char *format, va_list list, struct p parsed_x);
int	    flag_hash_only_print_blanks(const char *format, va_list list);
int		flag_hash_only(const char *format, va_list list, int i, struct p parsed);
void	flag_hash_and_zero_print_continue(int j, int i, char *hexadecimal);
void	flag_hash_and_zero_print(const char *format, va_list list, struct p parsed_x);
int		flag_hash_and_zero(const char *format, va_list list, int res, struct p parsed);
void	flag_zero_and_hash_print(const char *format, va_list list, struct p parsed_x);
void	flag_zero_and_hash_and_digit_print_continue(int j, int i, char *hexadecimal);
void	flag_zero_and_hash_and_digit_print(const char *format, va_list list, int res, struct p parsed_x);
int		flag_zero_and_hash_and_digit(const char *format, va_list list, int i, struct p parsed);
void	flag_hash_and_digit_print(const char *format, va_list list, struct p parsed_x);
int	    flag_hash_and_digit_blanks(const char *format, va_list list);
int	    count_zero_blanks(const char *format, va_list list, int i);
int		flag_hash_and_digit(const char *format, va_list list, int i, struct p parsed);
void	flag_hash_and_minus_continue(const char *format, va_list list, struct p parsed);
int		flag_hash_and_minus(const char *format, va_list list, int i, struct p parsed);
void	flag_hash_and_minus_and_digit_print(const char *format, va_list list, struct p parsed_x);
int	    flag_hash_and_minus_and_digit_blanks(const char *format, va_list list);
int		flag_hash_and_minus_and_digit(const char *format, va_list list, int i, struct p parsed);
void	flag_minus_and_digit_print(const char *format, va_list list, struct p parsed_x);
int	    flag_minus_and_digit_blanks(const char *format, va_list list);
int		flag_minus_and_digit(const char *format, va_list list, int i, struct p parsed);
void	flag_zero_and_digit_printit(const char *format, va_list list, struct p parsed_x);
void	flag_zero_and_digit_print(const char *format, va_list list, int res, struct p parsed);
int		flag_zero_and_digit(const char *format, va_list list, int i, struct p parsed);
int		flag_minus_and_hash_and_digit(const char *format, va_list list, int i, struct p parsed);
int		checksign(int number);
int		checksign_long(long long int number);
void	handle_long_flag(const char *format, va_list list, int i, struct p parsed);
struct	p handle_d_without_flags(const char *format, va_list list, int i, struct p parsed);
void    flag_plus_and_digit_print(const char *format, va_list list, int i, int k);
void    flag_plus_and_digit_print_long(const char *format, va_list list, int i, int k);
void	flag_plus_and_digit(const char *format, va_list list, int res, struct p parsed);
void	flag_plus_and_digit_long(const char *format, va_list list, int res, struct p parsed);
int		parse_flag_plus_and_digit(const char *format, va_list list, int i, struct p parsed);
void    flag_plus_print(const char *format, va_list list, int i, int k);
void    flag_plus_print_long(const char *format, va_list list, int i, int k);
int		flag_plus(const char *format, va_list list, int i, struct p parsed);
int		print_flag_minus_corr(const char *format, va_list list, int res);
int		print_flag_minus(const char *format, va_list list, int i);
int		flag_minus(const char *format, va_list list, int i, struct p parsed);
void    flag_minus_and_digit_print_d(const char *format, va_list list, int i, int number);
int		flag_minus_and_digit_cont_d(const char *format, va_list list, int res);
void    flag_minus_and_digit_print_d_long(const char *format, va_list list, int i, long number);
int		flag_minus_and_digit_cont_d_long(const char *format, va_list list, int res);
int		flag_minus_and_digit_d(const char *format, va_list list, int i, struct p parsed);
void	print_flags_zero_d(const char *format, va_list list, int res);
void	print_flags_zero_d_long(const char *format, va_list list, int res);
int		parse_flag_zero_d(const char *format, va_list list, int i, struct p parsed);
void	print_flags_zero_and_digit_d(const char *format, va_list list, int res);
void	print_flags_zero_and_digit_d_long(const char *format, va_list list, int res);
int		parse_flag_zero_and_digit_d(const char *format, va_list list, int i, struct p parsed);
struct	p print_flags_blank_wo_digits(const char *format, va_list list, int res, struct p parsed);
void	print_flags_blank_wo_digits_long(const char *format, va_list list, int res);
struct	p flag_blank_d(const char *format, va_list list, int i, struct p parsed);
void	print_flags_blank(const char *format, va_list list, int res);
void	print_flags_blank_long(const char *format, va_list list, int res);
void	printf_flags_blank_and_zero_and_digit(const char *format, va_list list, int res, struct p parsed);
void	printf_flags_blank_and_zero_and_digit_long(const char *format, va_list list, int res, struct p parsed);
void	print_flags_blanks_zero(const char *format, va_list list, int res);
void	print_flags_blanks_zero_long(const char *format, va_list list, int res);
int		flag_blank_and_digit_d(const char *format, va_list list, int i, struct p parsed);
void    flag_digit_print(const char *format, va_list list, int i, int k);
void    flag_digit_print_long(const char *format, va_list list, int i, int k);
void	flag_digit_cont(const char *format, va_list list, int res, struct p parsed);
void	flag_digit_long(const char *format, va_list list, int res, struct p parsed);
int		flag_digit(const char *format, va_list list, int i, struct p parsed);
void    flag_field_width_print(const char *format, va_list list, int i, int k);
void    flag_field_width_print_long(const char *format, va_list list, int i, int k);
void	flag_field_width_cont(const char *format, va_list list, int res, struct p parsed);
void	flag_field_width_long(const char *format, va_list list, int res, struct p parsed);
int		flag_field_width(const char *format, va_list list, int i, struct p parsed);
void    flag_width_and_plus_print(const char *format, va_list list, int i, struct p parsed);
void    flag_width_and_plus_long_print(const char *format, va_list list, int i, int k);
void	flag__width_and_plus_blanks(const char *format, va_list list, int res, struct p parsed);
void	flag_width_and_plus_long_blanks(const char *format, va_list list, int res, struct p parsed);
int		flag_field_width_and_plus(const char *format, va_list list, int i, struct p parsed);
int		flag_width_minus_and_digit_cont_d(const char *format, va_list list, int res);
int		flag_field_width_and_minus(const char *format, va_list list, int i, struct p parsed);
int		flag_field_width_and_zero(const char *format, va_list list, int i, struct p parsed);
int		print_flags(const char *format, va_list list, int i, struct p parsed);
struct	p print_flags_more(const char *format, va_list list, int i, struct p parsed);
struct	p parse_arg_x_init(const char *format, va_list list, int i, struct p parsed);
struct 	p handle_d(const char *format, va_list list, int i, struct p parsed);
char    parse_format(const char *format, va_list list, int i);
char    parse_format_without_prec(const char *format, va_list list, int i);
struct	p flags_short_and_long(const char *format, va_list list, int i, struct p parsed_x);
int		handle_field_width(const char *format, va_list list, int i, struct p parsed_x);
int    ft_printf(const char *format, ...);
void    ft_putchar(char c);
void  	ft_putnbr(int nb);
void	ft_putnbr_long(long nb);
void	ft_putnbr_uint(unsigned int nb);
int		ft_strlen_double(char *str);
int		is_upper(char c);
int		is_digit(char c);
struct	p ft_s_putnbr(int nb, struct p parsed);

#endif
