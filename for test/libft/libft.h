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

void    ft_putchar(char c);
void	ft_putnbr(int nb);
void	ft_putnbr_long(long nb);
void	ft_putnbr_uint(unsigned int nb);
int		ft_strlen_double(char *str);
int		is_upper(char c);
int		is_digit(char c);

#endif