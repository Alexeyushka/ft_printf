/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartyn- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:53:15 by jmartyn-          #+#    #+#             */
/*   Updated: 2019/09/14 17:53:18 by jmartyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
//# include <wchar.h>

#include <stdio.h>

# define ABS(x) ((x < 0) ? -(x) : (x))

typedef	struct	s_struct
{
	char		plus;
	char 		minus;
	char		hash;
	char		zero;
	char		morezero;
	char		blank;
	int			width;
	int			prec;
	char		hh;
	char		h;
	char		l;
	char		z;
	char		ll;
	char		j;
	char		spec;
	short		size;
	int			len;
	int 		largel;
}				t_struct;

typedef struct s_float
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
} 				t_float;

int		ft_out(t_struct *list, va_list va);
int						ft_handling_digit(t_struct *list, void *digit);
int					ft_handling_str(t_struct *list, void *str);
int						ft_print_str(char *str, int precision);
int					ft_strlen(const char *s);
int					ft_handling_char(t_struct *list, void *c);
int					ft_print_percent(t_struct *list, char c);
int		ft_print_char(char c);
int    print_char(const char *format, int i);
int    ft_printf(const char *format, ...);
int    parse_format(const char *format, int i, va_list va, t_struct *list);
int						ft_handling_unsigned_digit(t_struct *list, void *digit);
int					ft_handling_x(t_struct *list, void *digit);
int					ft_handling_o(t_struct *list, void *digit);
int						ft_handling_ptr(t_struct *list, void *digit);
int						ft_handling_f(t_struct *list, va_list va);

#endif