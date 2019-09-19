/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartyn- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:43:15 by jmartyn-          #+#    #+#             */
/*   Updated: 2019/09/14 17:43:29 by jmartyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>

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
	int ret;
	int	result;
} structp_x;


void    ft_putchar(char c);
struct  p ft_s_putnbr(int nb, struct p parsed);
void    ft_putnbr(int nb);
void	ft_putnbr_long(long nb);
void	ft_putnbr_uint(unsigned int nb);
int		ft_strlen_double(char *str);
int		is_upper(char c);
int		is_digit(char c);

#endif